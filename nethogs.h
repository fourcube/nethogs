#ifndef __NETHOGS_H
#define __NETHOGS_H

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <iostream>

#define _BSD_SOURCE 1

/* take the average speed over the last 5 seconds */
#define PERIOD 5

/* the amount of time after the last packet was recieved
 * after which a process is removed */
#define PROCESSTIMEOUT 150

/* the amount of time after the last packet was recieved
 * after which a connection is removed */
#define CONNTIMEOUT 50

/* Set to '0' when compiling for a system that uses Linux Capabilities,
 * like www.adamantix.org: in that case nethogs shouldn't check if it's
 * running as root. Take care to give it sufficient privileges though. */
#ifndef NEEDROOT
#define NEEDROOT 1
#endif

#define DEBUG 0

#define REVERSEHACK 0

// 2 times: 32 characters, 7 ':''s, a ':12345'.
// 1 '-'
// -> 2*45+1=91. we make it 92, for the null.
#define HASHKEYSIZE 92

#define PROGNAME_WIDTH 512

void forceExit(const char *msg, ...);

class local_addr {
public:
	/* ipv4 constructor takes an in_addr_t */
	local_addr (in_addr_t m_addr, local_addr * m_next = NULL)
	{
		addr = m_addr;
		next = m_next;
		sa_family = AF_INET;
		string = (char*) malloc (16);
		inet_ntop (AF_INET, &m_addr, string, 15);
	}
	/* this constructor takes an char address[33] */
	local_addr (struct in6_addr *m_addr, local_addr * m_next = NULL)
	{
		addr6 = *m_addr;
		next = m_next;
		sa_family = AF_INET6;
		string = (char*) malloc (64);
		inet_ntop (AF_INET6, &m_addr, string, 63);
	}

	bool contains (const in_addr_t & n_addr);
	bool contains (const struct in6_addr & n_addr);
	char * string;
	local_addr * next;
private:

	in_addr_t addr;
	struct in6_addr addr6;
	short int sa_family;
};

void quit_cb (int i);

#endif
