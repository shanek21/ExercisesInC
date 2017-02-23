#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define MAXLINE 4096

typedef void Sigfunc(int);        /* for signal handlers */
/* the following are prototypes for the Stevens utilities in util.c */
void tv_sub (struct timeval *out, struct timeval *in);
char *icmpcode_v4(int code);
void *Calloc(size_t n, size_t size);
Sigfunc *Signal(int signo, Sigfunc *func);
struct addrinfo *Host_serv(const char *host, const char *serv,
               int family, int socktype);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
         struct sockaddr *sa, socklen_t *salenptr);
void err_quit (char *fmt, ...);
void loop_ttl();
