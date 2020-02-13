#
# Makefile for both static and dynamic PF_RING user libraries
#
#

BUILD_KERNEL=$(shell uname -r)
PF_RING_KERNEL=../../kernel

#
# Search directories
#
INCLUDE   = -I$(PF_RING_KERNEL) -I../libpcap

#
# Installation directories
#
prefix = /usr/local
exec_prefix = ${prefix}
libdir =  ${exec_prefix}/lib
includedir = ${prefix}/include

#
# PF_RING ZC
#
PF_RING_ZC_OBJS  = pfring_zc_dev_e1000.o pfring_zc_dev_e1000e.o pfring_zc_dev_ixgbe.o pfring_zc_dev_ixgbevf.o pfring_zc_dev_igb.o pfring_zc_dev_i40e.o pfring_zc_dev_fm10k.o pfring_zc_dev_rss.o pfring_zc_dev_sal.o pfring_mod_zc.o pfring_mod_zc_dev.o pfring_mod_zc_spsc.o pfring_zc_cluster.o pfring_zc_mm.o uio_lib.o hugetlb_lib.o numa_lib.o pfring_zc_kvm.o pfring_zc_kvm_utils.o silicom_ts_card.o 

#
# PF_RING FT
#
PF_RING_FT_OBJS  = pfring_ft_flow.o pfring_ft_hash.o pfring_ft_list.o pfring_ft_dpi.o pfring_ft_utils.o pfring_ft_table.o pfring_ft_fragment_hash.o 

#
# AF_XDP
#
AF_XDP_OBJS  = 

#
# DAG
#
DAG_OBJS  = pfring_mod_dag.o 

#
# FIBERBLAZE
#
FIBERBLAZE_OBJS = pfring_mod_fiberblaze.o 

#
# NT
#
NT_OBJS  = pfring_mod_nt.o 

#
# Accolade
#
ACCOLADE_OBJS  = pfring_mod_accolade.o 

#
# Myricom
#
MYRICOM_OBJS  = pfring_mod_myricom.o 

#
# Netcope
#
NETCOPE_OBJS  = pfring_mod_netcope.o 

#
# Exablaze
#
EXABLAZE_OBJS  = 

#
# nPCAP
#
NPCAP_OBJS  = pfring_mod_timeline.o npcap_extract.o index_match.o npcap_utils.o npcap_compression.o npcap_index.o npcap_timeline.o npcap_storage.o lzf_c.o lzf_d.o 

#
# nBPF
#
NBPF_HOME = ../nbpf
NBPF_HDR = ${NBPF_HOME}/nbpf.h
NBPF_LIB = ${NBPF_HOME}/libnbpf.a
NBPF_OBJS = `$(AR) t ${NBPF_LIB} | grep -F .o | tr '\n' ' '`

#
# Object files
#
OBJS      = pfring.o pfring_mod.o pfring_utils.o pfring_mod_stack.o pfring_hw_filtering.o \
	    pfring_hw_timestamp.o pfring_mod_sysdig.o ${PF_RING_ZC_OBJS} ${PF_RING_FT_OBJS} ${AF_XDP_OBJS} ${DAG_OBJS} ${FIBERBLAZE_OBJS} ${NT_OBJS} ${ACCOLADE_OBJS} ${MYRICOM_OBJS} ${NETCOPE_OBJS} ${EXABLAZE_OBJS} ${NPCAP_OBJS}

#
# C compiler and flags
#
#
# CROSS_COMPILE=arm-mv5sft-linux-gnueabi-
#
CC        = ${CROSS_COMPILE}gcc
CFLAGS    += -O2  -Wall -Wno-stringop-truncation -fPIC ${INCLUDE} -D HAVE_PF_RING_ZC -D HAVE_PF_RING_FT  -D HAVE_DAG -D HAVE_FIBERBLAZE -D HAVE_ACCOLADE -D HAVE_MYRICOM -D HAVE_NETCOPE  -D ENABLE_BPF -D ENABLE_HW_TIMESTAMP -D HAVE_NT -D HAVE_NPCAP
LDFLAGS   += -g -shared
SYSLIBS   = -lpthread  -lrt -ldl  -lm -ldl -lm -ldl 

# How to make an object file
%.o: %.c %.h Makefile
#	@echo "=*= making object $@ =*="
	${CC} ${CFLAGS} -c $< -o $@

#
# Main targets
#
STATICLIB  = libpfring.a
DYNAMICLIB = libpfring.so
TARGETS    = ${STATICLIB} ${DYNAMICLIB}
RING_H     = $(PF_RING_KERNEL)/linux/pf_ring.h
AR ?= ar
RANLIB ?= ranlib

all: ${TARGETS}

${STATICLIB}: Makefile extract_nbpf extract_pfring_zc_lib extract_pfring_ft_lib   extract_nt_lib extract_myricom_lib extract_dag_lib extract_fiberblaze_lib extract_accolade_lib extract_netcope_lib extract_npcap_lib ${OBJS} pfring.h ${RING_H}
	@echo "=*= making library $@ =*="
	$(AR) rs $@ ${OBJS} ${NBPF_OBJS}
	$(RANLIB) $@

${DYNAMICLIB}: ${OBJS} extract_nbpf extract_pfring_zc_lib extract_pfring_ft_lib   extract_nt_lib extract_myricom_lib extract_dag_lib extract_fiberblaze_lib extract_accolade_lib extract_netcope_lib extract_npcap_lib pfring.h ${RING_H} Makefile
	@echo "=*= making library $@ =*="
	${CC} -Wl,-soname,$@.1 ${LDFLAGS} ${OBJS} ${NBPF_OBJS} ${SYSLIBS} -o $@

extract_pfring_zc_lib:
	ar x libs/libpfring_zc_x86_64.a

extract_pfring_ft_lib:
	ar x libs/libpfring_ft_x86_64_dl.a

extract_myricom_lib:
	ar x libs/libpfring_myricom_x86_64.a

extract_nt_lib:
	ar x libs/libpfring_nt_x86_64.a

extract_dag_lib:
	ar x libs/libpfring_dag_x86_64.a

extract_exablaze_lib:
	ar x @MOD_EXABLAZE_LIB@

extract_fiberblaze_lib:
	ar x libs/libpfring_fiberblaze_x86_64.a

extract_accolade_lib:
	ar x libs/libpfring_accolade_x86_64.a

extract_netcope_lib:
	ar x libs/libpfring_netcope_x86_64.a

extract_npcap_lib:
	ar x libs/libnpcap_x86_64.a

extract_nbpf: ${NBPF_LIB}
	$(AR) x ${NBPF_LIB}
	cp ${NBPF_HDR} .

copy_if_xdp:
	cp /usr/src/linux-headers-$(BUILD_KERNEL)/include/uapi/linux/if_xdp.h $(PF_RING_KERNEL)/linux/

${NBPF_LIB}:
	$(MAKE) -C ../nbpf

install: install-static install-shared

install-includes:
	mkdir -p $(DESTDIR)$(includedir)
	cp pfring.h pfring_mod_sysdig.h pfring_zc.h pfring_ft.h npcap.h ${NBPF_HDR} $(DESTDIR)$(includedir)/

install-static: ${STATICLIB} install-includes
	mkdir -p $(DESTDIR)$(libdir)
	cp ${STATICLIB} $(DESTDIR)$(libdir)/

install-shared:	${DYNAMICLIB} install-includes
	mkdir -p $(DESTDIR)$(libdir)
	cp ${DYNAMICLIB} $(DESTDIR)$(libdir)/
	cd $(DESTDIR)$(libdir); ln -sf ${DYNAMICLIB} ${DYNAMICLIB}.7.5.0
	cd $(DESTDIR)$(libdir); ln -sf ${DYNAMICLIB} ${DYNAMICLIB}.7
	-@if test "$(USER)" = "root"; then \
		ldconfig; \
	fi

clean:
	@rm -f ${TARGETS} *.o *~
