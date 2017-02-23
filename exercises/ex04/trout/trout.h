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
#define BUFSIZE 1500

#define max(a,b) ((a) > (b) ? (a) : (b))
typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

extern int datalen;
extern int max_ttl;
extern Sockaddr *sasend;
extern Sockaddr *sarecv;
extern Sockaddr *salast;
extern Sockaddr *sabind;
extern socklen_t salen;

char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
int sock_cmp_addr(const struct sockaddr *sa1,
          const struct sockaddr *sa2, socklen_t salen);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void alarm(int);
void err_sys (char *fmt, ...);
void Gettimeofday(struct timeval *tv, void *foo);
void Setsockopt(int fd, int level, int optname, const void *optval,
        socklen_t optlen);
void Pipe(int *fds);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
