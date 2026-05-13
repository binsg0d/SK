# Serwer Uptime (CW10)

Prosty serwer HTTP napisany w języku C, który zwraca czas pracy systemu (uptime).

## Opis zadania
Zadanie polegało na implementacji iteracyjnego serwera TCP, który:
1. Akceptuje połączenia na określonym porcie (domyślnie 80).
2. Blokuje możliwość uruchomienia z uprawnieniami roota ze względów bezpieczeństwa.
3. Pobiera wartość uptime z pliku systemowego `/proc/uptime`.
4. Formułuje i wysyła odpowiedź HTTP/1.0 z nagłówkiem `Content-Type: text/plain`.
5. Obsługuje klientów sekwencyjnie (jeden po drugim).

## Uruchomienie
Kompilacja:
```bash
gcc server.c -o server
```

Uruchomienie na porcie 8080:
```bash
./server 8080
```

Dostęp przez przeglądarkę lub curl:
```bash
curl http://localhost:8080
```
