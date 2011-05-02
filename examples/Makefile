# $backtrace$

LOCALBASE?=/usr/local

PROG=backtrace_test
NOMAN=

SRCS= backtrace_test.c
COPTS= -O0
DEBUG+= -ggdb3
CFLAGS+= -Wall -Werror
CPPFLAGS+= -I${LOCALBASE}/include -I../../libbacktrace -I../libbacktrace
LDFLAGS+= -L${LOCALBASE}/lib -L../../libbacktrace/obj -L../libbacktrace/ -lbacktrace
# required to print function names using the compat API
LDFLAGS+= -Wl,--export-dynamic

.include <bsd.prog.mk>
