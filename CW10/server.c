#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (getuid() == 0) {
        fprintf(stderr, "Błąd: Serwer nie może być uruchamiany jako root (z użyciem sudo na etapie działania).\n");
        fprintf(stderr, "Aby użyć portu poniżej 1024, nadaj uprawnienia poleceniem setcap.\n");
        exit(EXIT_FAILURE);
    }

    int port = 80;
    if (argc > 1) {
        port = atoi(argv[1]);
        if (port <= 0 || port > 65535) {
            fprintf(stderr, "Błąd: Nieprawidłowy numer portu.\n");
            exit(EXIT_FAILURE);
        }
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Błąd: socket()");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Błąd: setsockopt()");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset((char*)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Błąd: bind()");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Błąd: listen()");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Serwer uruchomiony iteracyjnie na porcie: %d\n", port);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Błąd: accept()");
            continue;
        }

        char buffer[2048];
        ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            perror("Błąd: recv()");
            close(client_fd);
            continue;
        }

        FILE *uptime_file = fopen("/proc/uptime", "r");
        char uptime_val[64] = "0.00";
        if (uptime_file != NULL) {
            if (fscanf(uptime_file, "%63s", uptime_val) != 1) {
                perror("Błąd: odczyt wartości z /proc/uptime");
            }
            fclose(uptime_file);
        } else {
            perror("Błąd: fopen(/proc/uptime)");
        }

        const char* http_header = "HTTP/1.0 200 OK\r\n"
                                  "Content-Type: text/plain; charset=UTF-8\r\n"
                                  "Connection: close\r\n";
        
        char response_headers[512];
        snprintf(response_headers, sizeof(response_headers), 
                 "%sContent-Length: %zu\r\n\r\n", 
                 http_header, strlen(uptime_val));

        if (send(client_fd, response_headers, strlen(response_headers), 0) < 0) {
            perror("Błąd: send() - nagłówki");
        } 
        else if (send(client_fd, uptime_val, strlen(uptime_val), 0) < 0) {
            perror("Błąd: send() - ciało odpowiedzi");
        }

        if (shutdown(client_fd, SHUT_WR) < 0) {
            perror("Błąd: shutdown()");
        }

        if (close(client_fd) < 0) {
            perror("Błąd: close() klienta");
        }
    }

    if (close(server_fd) < 0) {
        perror("Błąd: close() serwera");
    }

    return 0;
}