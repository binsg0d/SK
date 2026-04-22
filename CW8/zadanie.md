#!/bin/bash

X=75

for Y in {71..90}; do 
	if [ "$Y" -ne "$X" ]; then
		sudo ip route add 10.192.$Y.0/30 via 192.168.48.$Y
		echo "Dodano trase: 10.192.$Y.0/30 via 192.168.48.$Y"
	fi
done
echo "Gotowe"
