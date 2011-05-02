# $backtrace$

LOCALBASE?=/usr/local
BINDIR=${LOCALBASE}/bin
LIBDIR=${LOCALBASE}/lib

#WANTLINT=
LIB= backtrace
SRCS= backtrace.c
.if defined(${COMPILER_VERSION})  &&  ${COMPILER_VERSION:L} == "gcc4"
CFLAGS+= -fdiagnostics-show-option -Wall -Werror
.else
CFLAGS+= -Wall -Werror
.endif
CFLAGS+= -ggdb3
CFLAGS+= -I${LOCALBASE}/include
LDFLAGS+= -Wl,--export-dynamic
HDRS= backtrace.h

MAN= backtrace.3
MANDIR= ${LOCALBASE}/man/cat
MLINKS+= backtrace.3 backtrace_symbols.3
MLINKS+= backtrace.3 backtrace_symbols_fd.3

CLEANFILES+= backtrace.cat3

includes:
	@cd ${.CURDIR}; for i in ${HDRS}; do \
	cmp -s $$i ${LOCALBASE}/include/$$i || \
	${INSTALL} ${INSTALL_COPY} -m 444 -o $(BINOWN) -g $(BINGRP) $$i ${LOCALBASE}/include; \
	echo ${INSTALL} ${INSTALL_COPY} -m 444 -o $(BINOWN) -g $(BINGRP) $$i ${LOCALBASE}/include;\
	done

beforeinstall: includes

.include <bsd.own.mk>
.include <bsd.lib.mk>
