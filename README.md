# Wireshark-PF_RING
 
## Installing PF_RING by ntop and Integrating external capture module for Wireshark with Wireshark_pfring.sh

1) In directory Wireshark_PF_RING, find bash script Wireshark_pfring.sh
   Script will check for already installed wireshark, if not then it will install latest versrion available.
   Then it will automatically install PF_RING and integrate external capture pfring module for wireshark

2) Run bash script with
   ./Wirehsark_pfring.sh

3) If you have already installed wireshark from external source, an error might occur due to 
   invalid extcap path i.e. '/usr/lib/x86_64-linux-gnu/wireshark/extcap/'
   In this case, open Wireshark_pfring.sh and override the path with '/usr/local/lib/wireshark/extcap/' 

   To find the actual external capture path use wireshark menu as mentioned below, 
   open wireshark in sudo su mode from terminal with command 'wireshark'
   
  'Help'->'About Wireshark'->'Folders'->'Extcap path'
    

4) After successful execution of the script, prfing interface for wireshark will be invoked for capture.

5) When wireshark is open, you will see two external interfaces
   'PF_RING interface' and 'n2disk timeline'

6) Double click the gear icon next to PF_RING interface to open interface configuration menu
   Click on Restore Defaults and press start for capturing   
   Restore Defaults is required before each capture

7) You can check PF_RING kernel module status while capturing is inprocess i.e. num of rings and ring slots by 
   cat /proc/net/pf_ring/info

*  If you need to change the ring buffer settings then do the following
   
   cd PF_RING/kernel
   rmmod pf_ring.ko #remove kernel module
   
   insmod pf_ring.ko min_num_slots='your value' #configured with 65536 ring buffer size 
