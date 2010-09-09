# $backtrace$

PROG=backtrace_test
NOMAN=

SRCS= backtrace_test.c
COPT+= -O0
DEBUG+= -ggdb3
CFLAGS+= -Wall -Werror
CPPFLAGS+= -I/usr/local/include -I ../../libbacktrace
LDFLAGS+= -L/usr/local/lib -L ../../libbacktrace/obj -lbacktrace

.include <bsd.prog.mk>

