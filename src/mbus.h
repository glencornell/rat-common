/*
 * FILE:    mbus.h
 * AUTHORS: Colin Perkins
 *
 * Copyright (c) 1997-2000 University College London
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, is permitted, provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MBUS_H
#define _MBUS_H

/* Error codes... */
#define MBUS_MESSAGE_LOST           1
#define MBUS_DESTINATION_UNKNOWN    2
#define MBUS_DESTINATION_NOT_UNIQUE 3
#define MBUS_ERR_MAX		    4

extern char mbus_errlist[][30];

struct mbus;

#if defined(__cplusplus)
extern "C" {
#endif

struct mbus *mbus_init(void  (*cmd_handler)(const char *src, const char *cmd, char *arg, void *dat),
		       void  (*err_handler)(int seqnum, int reason),
		       const char  *addr);
void         mbus_cmd_handler(struct mbus *m, void  (*cmd_handler)(const char *src, const char *cmd, char *arg, void *dat));
void         mbus_exit(struct mbus *m);
int          mbus_addr_valid(struct mbus *m, const char *addr);
void         mbus_qmsg(struct mbus *m, const char *dest, const char *cmnd, const char *args, int reliable);
void         mbus_qmsgf(struct mbus *m, const char *dest, int reliable, const char *cmnd, const char *format, ...);
void         mbus_send(struct mbus *m);
int          mbus_recv(struct mbus *m, void *data, struct timeval *timeout);
void         mbus_retransmit(struct mbus *m);
void         mbus_heartbeat(struct mbus *m, int interval);
int          mbus_waiting_ack(struct mbus *m);
int          mbus_sent_all(struct mbus *m);
char        *mbus_rendezvous_waiting(struct mbus *m, const char *addr, const char *token, void *data, const long rendezvous_timeout_usec);
char        *mbus_rendezvous_go(struct mbus *m, const char *token, void *data, const long rendezvous_timeout_usec);

#if defined(__cplusplus)
}
#endif

#endif
