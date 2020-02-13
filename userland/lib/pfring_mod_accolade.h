/*
 *
 * (C) 2015-2019 - ntop.org
 *
 */

#ifndef _PFRING_MOD_ACCOLADE_H_
#define _PFRING_MOD_ACCOLADE_H_

#include "pfring.h"

int  pfring_anic_open(pfring *ring);
void pfring_anic_close(pfring *ring);
int  pfring_anic_stats(pfring *ring, pfring_stat *stats);
int  pfring_anic_recv(pfring *ring, u_char** buffer, u_int buffer_len, struct pfring_pkthdr *hdr, u_int8_t wait_for_incoming_packet);
int  pfring_anic_send(pfring *ring, char *pkt, u_int pkt_len, u_int8_t flush_packet);
int  pfring_anic_set_poll_watermark(pfring *ring, u_int16_t watermark);
int  pfring_anic_set_poll_duration(pfring *ring, u_int duration);
int  pfring_anic_poll(pfring *ring, u_int wait_duration);
int  pfring_anic_set_direction(pfring *ring, packet_direction direction);
int  pfring_anic_enable_ring(pfring *ring);
int  pfring_anic_set_socket_mode(pfring *ring, socket_mode mode);
int  pfring_anic_get_bound_device_ifindex(pfring *ring, int *if_index);
u_int32_t pfring_anic_get_interface_speed(pfring *ring);
int pfring_anic_add_hw_rule(pfring *ring, hw_filtering_rule *rule);
int pfring_anic_remove_hw_rule(pfring *ring, u_int16_t rule_count);

#endif /* _PFRING_MOD_ACCOLADE_H_ */
