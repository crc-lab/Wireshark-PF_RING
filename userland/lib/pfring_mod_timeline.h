/*
 *
 * (C) 2016 - ntop.org
 *
 */

#ifndef _PFRING_MOD_TIMELINE_H_
#define _PFRING_MOD_TIMELINE_H_

#include "pfring.h"

int  pfring_timeline_open(pfring *ring);
void pfring_timeline_close(pfring *ring);
int  pfring_timeline_stats(pfring *ring, pfring_stat *stats);
int  pfring_timeline_recv(pfring *ring, u_char** buffer, u_int buffer_len, struct pfring_pkthdr *hdr, u_int8_t wait_for_incoming_packet);
int  pfring_timeline_send(pfring *ring, char *pkt, u_int pkt_len, u_int8_t flush_packet);
int  pfring_timeline_set_poll_watermark(pfring *ring, u_int16_t watermark);
int  pfring_timeline_set_poll_duration(pfring *ring, u_int duration);
int  pfring_timeline_poll(pfring *ring, u_int wait_duration);
int  pfring_timeline_set_socket_mode(pfring *ring, socket_mode mode);
int  pfring_timeline_set_direction(pfring *ring, packet_direction direction);
int  pfring_timeline_enable_ring(pfring *ring);
int  pfring_timeline_get_bound_device_ifindex(pfring *ring, int *if_index);
u_int32_t pfring_timeline_get_interface_speed(pfring *ring);

#endif /* _PFRING_MOD_TIMELINE_H_ */

