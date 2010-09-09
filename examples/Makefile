# $backtrace$

PROG=backtrace_test
NOMAN=

SRCS= backtrace_test.c
COPTS= -O0
DEBUG+= -ggdb3
CFLAGS+= -Wall -Werror
CPPFLAGS+= -I/usr/local/include -I ../../libbacktrace
LDFLAGS+= -L/usr/local/lib -L ../../libbacktrace/obj -lbacktrace
# required to print function names using the compat API
LDFLAGS+= -Wl,--export-dynamic

.include <bsd.prog.mk>
