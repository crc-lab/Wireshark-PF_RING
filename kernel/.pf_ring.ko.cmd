cmd_/home/mubbashir/PF_RING/kernel/pf_ring.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /home/mubbashir/PF_RING/kernel/pf_ring.ko /home/mubbashir/PF_RING/kernel/pf_ring.o /home/mubbashir/PF_RING/kernel/pf_ring.mod.o ;  true