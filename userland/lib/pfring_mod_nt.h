/*
 *
 * (C) 2013-14 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesses General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 *
 */

#ifndef _PFRING_MOD_NT_H_
#define _PFRING_MOD_NT_H_

#include "pfring.h"

int  pfring_nt_open(pfring *ring);
void pfring_nt_close(pfring *ring);
int  pfring_nt_stats(pfring *ring, pfring_stat *stats);
int  pfring_nt_recv(pfring *ring, u_char** buffer, u_int buffer_len, struct pfring_pkthdr *hdr, u_int8_t wait_for_incoming_packet);
int  pfring_nt_send(pfring *ring, char *pkt, u_int pkt_len, u_int8_t flush_packet);
int  pfring_nt_set_poll_watermark(pfring *ring, u_int16_t watermark);
int  pfring_nt_set_poll_duration(pfring *ring, u_int duration);
int  pfring_nt_poll(pfring *ring, u_int wait_duration);
int  pfring_nt_set_direction(pfring *ring, packet_direction direction);
int  pfring_nt_enable_ring(pfring *ring);
int  pfring_nt_set_socket_mode(pfring *ring, socket_mode mode);
int  pfring_nt_get_bound_device_ifindex(pfring *ring, int *if_index);
int  pfring_nt_enable_chunk_mode(pfring *ring);
int  pfring_nt_recv_chunk(pfring *ring, void **chunk, pfring_chunk_info *chunk_info,  u_int8_t wait_for_incoming_chunk); 
int  pfring_nt_recv_chunk_pkt(pfring *ring, u_char** buffer, u_int buffer_len, struct pfring_pkthdr *hdr, u_int8_t wait_for_incoming_packet);
u_int32_t pfring_nt_get_interface_speed(pfring *ring);
pfring_if_t *pfring_nt_findalldevs();

#endif /* _PFRING_MOD_NT_H_ */
