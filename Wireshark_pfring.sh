#!/bin/bash
#
# By: Cyber Reconnaissance & Combat Lab
# Date : 11/02/2020
#
#
#
#
# Author: Mubbashir Adnan
# Installation and integration of PF_RING with Wireshark
# 
#

set -e
echo "Starting Setup..."


function checker() { 
        which wireshark | grep -o wireshark > /dev/null &&  return 0 || return 1 
}

if checker == 0 ; then echo "Wireshark already installed"; else sudo apt install wireshark; fi #install wireshark if not already installed


#Compiling PF_RING and integrating external capture module for wireshark

cd Wireshark-PF_RING/kernel #compiling pfring kernel module
make
sudo make install

#sudo rmmod pf_ring.ko
sudo insmod ./pf_ring.ko min_num_slots=65536 #loading kernel module by specifying ring buffer size

cd .. 
cd userland/lib
./configure && make
sudo make install
cd ../libpcap
./configure && make
sudo make install
cd .. #compiling userland
sudo make


cd wireshark/extcap/ #compiling external capture module for wireshark
sudo make
cp ntopdump /usr/lib/x86_64-linux-gnu/wireshark/extcap/ #copying external capture module in wireshark extcap where it will look for external capture
#if above path not valid (already downloaded wireshark from external source ) then use '/usr/local/lib/wireshark/extcap/'
echo "Success"


