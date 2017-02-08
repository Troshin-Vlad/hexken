#define true 1
#define false 0

int addr_len = 7;
char fmtaddr[11];

struct {
    unsigned int addrs:1;
} display;

struct {
    char ch;
} fmt;
