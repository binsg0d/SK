# Zadanie: Podstawowe polecenia sieciowe
**Termin zadania:** 2026-04-08

---

### 1. Lista interfejsów sieciowych w systemie w postaci par nazwa-status

**Źródło (polecenie):**
```bash
ip -br link
```

**Właściwa odpowiedź (wynik):**
```text
lo               UNKNOWN        00:00:00:00:00:00 <LOOPBACK,UP,LOWER_UP> 
enp0s31f6        UP             cc:96:e5:0c:83:57 <BROADCAST,MULTICAST,UP,LOWER_UP> 
virbr0           DOWN           52:54:00:f8:3b:b7 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-b577f0de8e19  DOWN           e6:67:08:fd:96:c7 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-c2c76b48eb27  DOWN           0e:10:0e:ee:ba:39 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-c2d58d5db3bf  DOWN           0a:c1:0d:29:86:5e <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-df67ba73b67b  DOWN           fa:46:af:b9:95:79 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-e270fb02a15f  DOWN           1e:9e:11:a0:92:d0 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-5cc7d5c0a356  UP             be:45:e4:68:53:85 <BROADCAST,MULTICAST,UP,LOWER_UP> 
docker0          UP             0a:e8:eb:a7:52:b0 <BROADCAST,MULTICAST,UP,LOWER_UP> 
br-813593f6b092  DOWN           f2:ac:b1:c1:4a:2e <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-c058572e79d6  UP             aa:41:96:f5:c1:aa <BROADCAST,MULTICAST,UP,LOWER_UP> 
br-d50221502901  DOWN           ce:f6:58:ef:32:72 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-5c4ff0e61303  DOWN           9e:54:a7:cf:c9:79 <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-9b273425498f  DOWN           da:ef:b9:69:17:4a <NO-CARRIER,BROADCAST,MULTICAST,UP> 
br-a01eef478d1f  UP             ce:c6:df:93:f3:c8 <BROADCAST,MULTICAST,UP,LOWER_UP> 
veth17d5bde@if2  UP             f2:cb:d3:9d:5b:29 <BROADCAST,MULTICAST,UP,LOWER_UP> 
vethfb81bc2@if2  UP             1e:62:da:52:c8:7e <BROADCAST,MULTICAST,UP,LOWER_UP> 
vethf60d007@if2  UP             1e:58:28:6d:20:7d <BROADCAST,MULTICAST,UP,LOWER_UP> 
veth913961f@if2  UP             7e:d8:e6:e3:3c:1c <BROADCAST,MULTICAST,UP,LOWER_UP> 
veth246ea98@if2  UP             e6:a2:6e:c8:c6:26 <BROADCAST,MULTICAST,UP,LOWER_UP> 
vethe17a9a5@if2  UP             1a:87:72:69:30:d5 <BROADCAST,MULTICAST,UP,LOWER_UP> 
veth7b7d429@if2  UP             ba:ff:96:46:38:b3 <BROADCAST,MULTICAST,UP,LOWER_UP> 

```

---

### 2. Adres MAC routera, który łączy sieć pracowni z internetem

**Źródło (polecenie):**
```bash
arp -a
```

**Właściwa odpowiedź (wynik):**
```text
? (192.168.48.2) at 00:15:5d:64:81:01 [ether] on enp0s31f6
? (192.168.48.85) at cc:96:e5:12:18:91 [ether] on enp0s31f6
? (192.168.48.81) at cc:96:e5:12:07:35 [ether] on enp0s31f6
? (192.168.48.77) at cc:96:e5:12:10:1c [ether] on enp0s31f6
? (192.168.48.73) at cc:96:e5:25:83:10 [ether] on enp0s31f6
? (192.168.48.90) at cc:96:e5:12:00:bc [ether] on enp0s31f6
_gateway (192.168.48.1) at d4:76:a0:e4:71:ef [ether] on enp0s31f6
? (192.168.48.87) at cc:96:e5:12:0f:f3 [ether] on enp0s31f6
? (192.168.48.79) at cc:96:e5:25:8a:2e [ether] on enp0s31f6
? (192.168.48.84) at cc:96:e5:12:19:36 [ether] on enp0s31f6

```

---

### 3. Zmiana adresu MAC karty sieciowej Ethernet na inną wartość

**Źródło (polecenia):**
```bash
sudo ip link set dev eth0 down
sudo ip link set dev eth0 address 00:11:22:33:44:55
sudo ip link set dev eth0 up
```

**Właściwa odpowiedź (wynik/weryfikacja):**
```text
nie zmienilem
```

---

### 4. Ping wszystkich urządzeń jednocześnie w podsieci pracowni

**Źródło (polecenie):**
```bash
nmap -sn 192.168.48.255/24
```

**Właściwa odpowiedź (wynik):**
```text
Starting Nmap 7.94SVN ( [https://nmap.org](https://nmap.org) ) at 2026-03-25 11:54 CET
Nmap scan report for 192.168.48.2
Host is up (0.0021s latency).
Nmap scan report for user-Precision-3460 (192.168.48.72)
Host is up (0.000065s latency).
Nmap scan report for 192.168.48.77
Host is up (0.0014s latency).
Nmap scan report for 192.168.48.79
Host is up (0.0011s latency).
Nmap scan report for 192.168.48.81
Host is up (0.0012s latency).
Nmap scan report for 192.168.48.84
Host is up (0.0012s latency).
Nmap scan report for 192.168.48.85
Host is up (0.0011s latency).
Nmap scan report for 192.168.48.87
Host is up (0.00045s latency).
Nmap scan report for 192.168.48.90
Host is up (0.00054s latency).
Nmap done: 256 IP addresses (9 hosts up) scanned in 2.32 seconds
```

---

### 5. Skan całej podsieci pracowni w poszukiwaniu urządzeń z otwartym portem 22

**Źródło (polecenie):**
```bash
nmap -p 22 --open 192.168.48.0/24
```

**Właściwa odpowiedź (wynik):**
```text
Starting Nmap 7.94SVN ( [https://nmap.org](https://nmap.org) ) at 2026-03-25 11:56 CET
Nmap scan report for 192.168.48.2
Host is up (0.00093s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for user-Precision-3460 (192.168.48.72)
Host is up (0.000046s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.77
Host is up (0.00058s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.79
Host is up (0.00062s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.81
Host is up (0.00037s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.84
Host is up (0.00050s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.85
Host is up (0.00049s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.87
Host is up (0.00030s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap scan report for 192.168.48.90
Host is up (0.00056s latency).

PORT   STATE SERVICE
22/tcp open  ssh

Nmap done: 256 IP addresses (9 hosts up) scanned in 2.32 seconds
```

---

### 6. Skan wszystkich portów, które są otwarte na interfejsie lo (loopback)

**Źródło (polecenie):**
```bash
nmap -p- 127.0.0.1
```

**Właściwa odpowiedź (wynik):**
```text
Starting Nmap 7.94SVN ( [https://nmap.org](https://nmap.org) ) at 2026-03-25 11:51 CET
Nmap scan report for localhost (127.0.0.1)
Host is up (0.000039s latency).
Not shown: 65525 closed tcp ports (conn-refused)
PORT      STATE SERVICE
22/tcp    open  ssh
631/tcp   open  ipp
3000/tcp  open  ppp
3308/tcp  open  tns-server
5040/tcp  open  unknown
5432/tcp  open  postgresql
5433/tcp  open  pyrrho
8082/tcp  open  blackice-alerts
11434/tcp open  unknown
27017/tcp open  mongod

Nmap done: 1 IP address (1 host up) scanned in 1.48 seconds
```

---

### 7. Porty otwarte w systemie wraz z numerem PID procesu i nazwą programu

**Źródło (polecenie):**
```bash
sudo netstat -tulnp
```

**Właściwa odpowiedź (wynik):**
```text
Active Internet connections (only servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name    
tcp        0      0 0.0.0.0:3000            0.0.0.0:* LISTEN      4809/docker-proxy   
tcp        0      0 127.0.0.1:5415          0.0.0.0:* LISTEN      39394/code          
tcp        0      0 127.0.0.1:5432          0.0.0.0:* LISTEN      2596/postgres       
tcp        0      0 192.168.122.1:53        0.0.0.0:* LISTEN      2704/dnsmasq        
tcp        0      0 127.0.0.53:53           0.0.0.0:* LISTEN      1175/systemd-resolv 
tcp        0      0 0.0.0.0:3308            0.0.0.0:* LISTEN      4967/docker-proxy   
tcp        0      0 0.0.0.0:22              0.0.0.0:* LISTEN      1/init              
tcp        0      0 0.0.0.0:8082            0.0.0.0:* LISTEN      4749/docker-proxy   
tcp        0      0 127.0.0.1:631           0.0.0.0:* LISTEN      2441/cupsd          
tcp        0      0 127.0.0.54:53           0.0.0.0:* LISTEN      1175/systemd-resolv 
tcp        0      0 0.0.0.0:5040            0.0.0.0:* LISTEN      4665/docker-proxy   
tcp        0      0 127.0.0.1:11434         0.0.0.0:* LISTEN      3039/ollama         
tcp        0      0 127.0.0.1:27017         0.0.0.0:* LISTEN      3552/mongod         
tcp        0      0 0.0.0.0:5433            0.0.0.0:* LISTEN      4936/docker-proxy   
tcp6       0      0 :::3000                 :::* LISTEN      4821/docker-proxy   
tcp6       0      0 ::1:631                 :::* LISTEN      2441/cupsd          
tcp6       0      0 :::3308                 :::* LISTEN      4978/docker-proxy   
tcp6       0      0 :::22                   :::* LISTEN      1/init              
tcp6       0      0 :::8082                 :::* LISTEN      4756/docker-proxy   
tcp6       0      0 :::5040                 :::* LISTEN      4673/docker-proxy   
tcp6       0      0 :::5433                 :::* LISTEN      4942/docker-proxy   
udp        0      0 192.168.122.1:53        0.0.0.0:* 2704/dnsmasq        
udp        0      0 127.0.0.54:53           0.0.0.0:* 1175/systemd-resolv 
udp        0      0 127.0.0.53:53           0.0.0.0:* 1175/systemd-resolv 
udp        0      0 0.0.0.0:67              0.0.0.0:* 2704/dnsmasq        
udp        0      0 0.0.0.0:5353            0.0.0.0:* 1774/avahi-daemon:  
udp        0      0 0.0.0.0:39712           0.0.0.0:* 1774/avahi-daemon:  
udp6       0      0 :::58945                :::* 1774/avahi-daemon:  
udp6       0      0 :::5353                 :::* 1774/avahi-daemon:  
```

---

### 8. Wyświetl trasę domyślną w systemie

**Źródło (polecenie):**
```bash
ip route | grep default
```

**Właściwa odpowiedź (wynik):**
```text
default via 192.168.48.1 dev enp0s31f6 proto dhcp src 192.168.48.72 metric 100 
```

---

### 9. Trasa pakietów, które trafiają do serwera kosmatka.pl

**Źródło (polecenie):**
```bash
traceroute kosmatka.pl
```

**Właściwa odpowiedź (wynik):**
```text
traceroute to kosmatka.pl (217.28.148.190), 30 hops max, 60 byte packets
 1  * * *
 2  * * *
 3  * * *
 4  * * *
 5  * * *
 6  * * *
 7  * * *
 8  * * *
 9  * * *
10  * * *
11  * * *
12  * * *
13  * * *
14  * * *
15  * * *
16  * * *
17  * * *
18  * * *
19  * * *
20  * * *
21  * * *
22  * * *
23  * * *
24  * * *
25  * * *
26  * * *
27  * * *
28  * * *
29  * * *
30  * * *
```
> **Uwaga:** Taki wynik oznacza, że zapora sieciowa (firewall) uczelni/pracowni filtruje i blokuje pakiety narzędzia traceroute.

---

### 10. Adres serwera DNS ustawiony w systemie

**Źródło (plik):**
```bash
cat /etc/resolv.conf
```

**Właściwa odpowiedź (zawartość):**
```text
nameserver 127.0.0.53
options edns0 trust-ad
search .
```

---

### 11. Lista statycznych wpisów DNS w systemie

**Źródło (plik):**
```bash
cat /etc/hosts
```

**Właściwa odpowiedź (zawartość):**
```text
127.0.0.1 localhost
127.0.1.1 user-Precision-3460

# The following lines are desirable for IPv6 capable hosts
::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
```

---

### 12. Rekord DNS poczty e-mail kosmatka.pl korzystając z serwera DNS 8.8.8.8

**Źródło (polecenie):**
```bash
dig MX kosmatka.pl @8.8.8.8 +short
```

**Właściwa odpowiedź (wynik):**
```text
10 mx2.privateemail.com.
10 mx1.privateemail.com.
```

---

### 13. Adres IPv6 hosta google.pl

**Źródło (polecenie):**
```bash
dig AAAA google.pl +short
```

**Właściwa odpowiedź (wynik):**
```text
2a00:1450:4025:807::5e
```

---

### 14. Data rejestracji domeny kosmatka.pl i do kiedy jest opłacona

**Źródło (polecenie):**
```bash
whois kosmatka.pl
```

**Właściwa odpowiedź (wynik):**
```text
created:                        2022.12.02 12:27:10
last modified:                  2022.12.02 12:33:53
renewal date:                   2032.12.02 12:27:10
```

---

### 15. Adres strony z listą domen .pl usuniętych dzisiejszego dnia

**Źródło (Strona internetowa):**
```text
Strona oficjalnego rejestru NASK
```

**Właściwa odpowiedź (URL):**
```text
[https://dns.pl/lista_domen_usunietych](https://dns.pl/lista_domen_usunietych)
```
