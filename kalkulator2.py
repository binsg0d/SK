import sys 

def ip_to_int(ip_str):
    parts = ip_str.split('.')
    return (int(parts[0]) << 24) | (int(parts[1]) << 16) | (int(parts[2]) << 8) | int(parts[3])

def int_to_ip(ip_int):
    p1 = (ip_int >> 24) & 0xFF
    p2 = (ip_int >> 16) & 0xFF
    p3 = (ip_int >> 8) & 0xFF
    p4 = (ip_int >> 0) & 0xFF
    return f"{p1}.{p2}.{p3}.{p4}"

def int_to_bin(ip_int):
    b1 = (ip_int >> 24) & 0xFF
    b2 = (ip_int >> 16) & 0xFF
    b3 = (ip_int >> 8) & 0xFF
    b4 = (ip_int >> 0) & 0xFF
    return f"{b1:08b}.{b2:08b}.{b3:08b}.{b4:08b}"

def calculator(cidr):
    try: 
        ip_str, prefix_str = cidr.split('/')
        prefix = int(prefix_str)
        if prefix < 0 or prefix > 32:
            raise ValueError("Invalid mask (must be between 0 and 32)")
            
        # 1. IP to integer
        ip_int = ip_to_int(ip_str)
        
        # 2. Subnet Mask
        mask_int = (0xFFFFFFFF << (32 - prefix)) & 0xFFFFFFFF
        
        # 3. Network Address
        net_int = ip_int & mask_int
        
        # 4. Broadcast Address and Host Parameters
        inv_mask = (~mask_int) & 0xFFFFFFFF
        broadcast_int = net_int | inv_mask
        num_hosts = 0
        first_host = net_int
        last_host = net_int
        
        if prefix <= 30:
            first_host = net_int + 1
            last_host = broadcast_int - 1
            num_hosts = broadcast_int - net_int - 1
        if prefix > 30:
            num_hosts = 0
            first_host = net_int
            last_host = broadcast_int
        # Printing the results
        print(f"Network IP address:")
        print(f"  Decimal: {int_to_ip(net_int)}")
        print(f"  Binary:  {int_to_bin(net_int)}\n")

        print(f"Subnet mask (/{prefix}):")
        print(f"  Decimal: {int_to_ip(mask_int)}")
        print(f"  Binary:  {int_to_bin(mask_int)}\n")

        print(f"Number of hosts in the network: {num_hosts}\n")

        print(f"First host IP address:")
        print(f"  Decimal: {int_to_ip(first_host)}")
        print(f"  Binary:  {int_to_bin(first_host)}\n")

        print(f"Last host IP address:")
        print(f"  Decimal: {int_to_ip(last_host)}")
        print(f"  Binary:  {int_to_bin(last_host)}\n")

        print(f"Broadcast address:")
        print(f"  Decimal: {int_to_ip(broadcast_int)}")
        print(f"  Binary:  {int_to_bin(broadcast_int)}")

    except Exception as e:
        print(f"Error while processing the address: {e}", file=sys.stderr)
        print("Usage: python calculator2.py a.b.c.d/x", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python calculator2.py <ip_address/mask>")
        print("Example: python calculator2.py 192.168.1.10/24")
    else:
        calculator(sys.argv[1])