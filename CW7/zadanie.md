# Konfiguracja serwera DHCP (ISC DHCP Server)

## Instalacja serwera DHCP

```bash
sudo apt update && sudo apt install isc-dhcp-server -y
```

## Konfiguracja interfejsu sieciowego

```bash
sudo ip link set enxf8e43b0c2e0d down
sudo ip addr add 10.123.69.1/24 dev eth0
sudo ip link set enxf8e43b0c2e0d up
sudo ip route add default via 10.123.69.254
echo "nameserver 1.1.1.1" | sudo tee /etc/resolv.conf
```

## Filtry Wireshark dla pakietów DHCP

| Typ pakietu | Filtr Wireshark |
|-------------|------------------|
| DHCP Discover | `dhcp.option.dhcp == 1` |
| DHCP Offer    | `dhcp.option.dhcp == 2` |
| DHCP Request  | `dhcp.option.dhcp == 3` |
| DHCP ACK      | `dhcp.option.dhcp == 5` |

## Konfiguracja serwera DHCP (`/etc/dhcp/dhcpd.conf`)

```plaintext
default-lease-time 600;
max-lease-time 7200;
authoritative;

subnet 10.123.69.0 netmask 255.255.255.0 {
  range 10.123.69.100 10.123.69.200;
  option routers 10.123.69.1;
  option domain-name-servers 1.1.1.1;
}
```

## Uruchomienie serwera DHCP

```bash
sudo systemctl start isc-dhcp-server
```

## Podgląd logów serwera DHCP

```bash
journalctl -u isc-dhcp-server -f
```

## Sprawdzenie przydzielonych adresów IP na kliencie

```bash
ip addr show   # lub ip a
```

## Przydzielone adresy IP

- **Przed zmianą MAC:** `10.123.69.100`
- **Po zmianie MAC:** `10.123.69.101`
