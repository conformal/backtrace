/* $backtrace$ */
/*
 * Copyright (c) 2010 Marco Peereboom <marco@conformal.com>
 * Copyright (c) 2010 Conformal Systems LLC <info@conformal.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __GNUC__
#error "this library must be compiled with gcc"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>

#include <dlfcn.h>

#include "backtrace.h"

__attribute__((unused)) static const char *cvstag = "$backtrace$";

#define BT_GET_DEPTH		(1)
#define BT_ADD_CR		(1)

#define HANDLE_FRAME(depth, idx, btaddr)				\
	case depth:							\
		if (!__builtin_frame_address(depth + 1))		\
			goto done;					\
		btaddr = __builtin_return_address(depth);		\
		break;							\

int
bt_create_backtrace(void **buffer, int depth, int flags)
{
	void			*addr;
	unsigned int		i = 0;
	void			**p = NULL;

	if (depth <= 0)
		return (-1);

	if (flags == BT_GET_DEPTH)
		p = buffer;
	do {
		/* number of HANDLE_FRAME must match BT_MAX_DEPTH */
		switch (i) {
		HANDLE_FRAME(0, i, addr);
		HANDLE_FRAME(1, i, addr);
		HANDLE_FRAME(2, i, addr);
		HANDLE_FRAME(3, i, addr);
		HANDLE_FRAME(4, i, addr);
		HANDLE_FRAME(5, i, addr);
		HANDLE_FRAME(6, i, addr);
		HANDLE_FRAME(7, i, addr);
		HANDLE_FRAME(8, i, addr);
		HANDLE_FRAME(9, i, addr);
		HANDLE_FRAME(10, i, addr);
		HANDLE_FRAME(11, i, addr);
		HANDLE_FRAME(12, i, addr);
		HANDLE_FRAME(13, i, addr);
		HANDLE_FRAME(14, i, addr);
		HANDLE_FRAME(15, i, addr);
		HANDLE_FRAME(16, i, addr);
		HANDLE_FRAME(17, i, addr);
		HANDLE_FRAME(18, i, addr);
		HANDLE_FRAME(19, i, addr);
		HANDLE_FRAME(20, i, addr);
		HANDLE_FRAME(21, i, addr);
		HANDLE_FRAME(22, i, addr);
		HANDLE_FRAME(23, i, addr);
		HANDLE_FRAME(24, i, addr);
		HANDLE_FRAME(25, i, addr);
		HANDLE_FRAME(26, i, addr);
		HANDLE_FRAME(27, i, addr);
		HANDLE_FRAME(28, i, addr);
		HANDLE_FRAME(29, i, addr);
		HANDLE_FRAME(30, i, addr);
		HANDLE_FRAME(31, i, addr);
		HANDLE_FRAME(32, i, addr);
		HANDLE_FRAME(33, i, addr);
		HANDLE_FRAME(34, i, addr);
		HANDLE_FRAME(35, i, addr);
		HANDLE_FRAME(36, i, addr);
		HANDLE_FRAME(37, i, addr);
		HANDLE_FRAME(38, i, addr);
		HANDLE_FRAME(39, i, addr);
		HANDLE_FRAME(40, i, addr);
		HANDLE_FRAME(41, i, addr);
		HANDLE_FRAME(42, i, addr);
		HANDLE_FRAME(43, i, addr);
		HANDLE_FRAME(44, i, addr);
		HANDLE_FRAME(45, i, addr);
		HANDLE_FRAME(46, i, addr);
		HANDLE_FRAME(47, i, addr);
		HANDLE_FRAME(48, i, addr);
		HANDLE_FRAME(49, i, addr);
		HANDLE_FRAME(50, i, addr);
		HANDLE_FRAME(51, i, addr);
		HANDLE_FRAME(52, i, addr);
		HANDLE_FRAME(53, i, addr);
		HANDLE_FRAME(54, i, addr);
		HANDLE_FRAME(55, i, addr);
		HANDLE_FRAME(56, i, addr);
		HANDLE_FRAME(57, i, addr);
		HANDLE_FRAME(58, i, addr);
		HANDLE_FRAME(59, i, addr);
		HANDLE_FRAME(60, i, addr);
		HANDLE_FRAME(61, i, addr);
		HANDLE_FRAME(62, i, addr);
		HANDLE_FRAME(63, i, addr);
		HANDLE_FRAME(64, i, addr);
		HANDLE_FRAME(65, i, addr);
		HANDLE_FRAME(66, i, addr);
		HANDLE_FRAME(67, i, addr);
		HANDLE_FRAME(68, i, addr);
		HANDLE_FRAME(69, i, addr);
		HANDLE_FRAME(70, i, addr);
		HANDLE_FRAME(71, i, addr);
		HANDLE_FRAME(72, i, addr);
		HANDLE_FRAME(73, i, addr);
		HANDLE_FRAME(74, i, addr);
		HANDLE_FRAME(75, i, addr);
		HANDLE_FRAME(76, i, addr);
		HANDLE_FRAME(77, i, addr);
		HANDLE_FRAME(78, i, addr);
		HANDLE_FRAME(79, i, addr);
		HANDLE_FRAME(80, i, addr);
		HANDLE_FRAME(81, i, addr);
		HANDLE_FRAME(82, i, addr);
		HANDLE_FRAME(83, i, addr);
		HANDLE_FRAME(84, i, addr);
		HANDLE_FRAME(85, i, addr);
		HANDLE_FRAME(86, i, addr);
		HANDLE_FRAME(87, i, addr);
		HANDLE_FRAME(88, i, addr);
		HANDLE_FRAME(89, i, addr);
		HANDLE_FRAME(90, i, addr);
		HANDLE_FRAME(91, i, addr);
		HANDLE_FRAME(92, i, addr);
		HANDLE_FRAME(93, i, addr);
		HANDLE_FRAME(94, i, addr);
		HANDLE_FRAME(95, i, addr);
		HANDLE_FRAME(96, i, addr);
		HANDLE_FRAME(97, i, addr);
		HANDLE_FRAME(98, i, addr);
		HANDLE_FRAME(99, i, addr);
		HANDLE_FRAME(100, i, addr);
		HANDLE_FRAME(101, i, addr);
		HANDLE_FRAME(102, i, addr);
		HANDLE_FRAME(103, i, addr);
		HANDLE_FRAME(104, i, addr);
		HANDLE_FRAME(105, i, addr);
		HANDLE_FRAME(106, i, addr);
		HANDLE_FRAME(107, i, addr);
		HANDLE_FRAME(108, i, addr);
		HANDLE_FRAME(109, i, addr);
		HANDLE_FRAME(110, i, addr);
		HANDLE_FRAME(111, i, addr);
		HANDLE_FRAME(112, i, addr);
		HANDLE_FRAME(113, i, addr);
		HANDLE_FRAME(114, i, addr);
		HANDLE_FRAME(115, i, addr);
		HANDLE_FRAME(116, i, addr);
		HANDLE_FRAME(117, i, addr);
		HANDLE_FRAME(118, i, addr);
		HANDLE_FRAME(119, i, addr);
		HANDLE_FRAME(120, i, addr);
		HANDLE_FRAME(121, i, addr);
		HANDLE_FRAME(122, i, addr);
		HANDLE_FRAME(123, i, addr);
		HANDLE_FRAME(124, i, addr);
		HANDLE_FRAME(125, i, addr);
		HANDLE_FRAME(126, i, addr);
		HANDLE_FRAME(127, i, addr);
		default:
			goto done;
		}

		if (addr == NULL)
			goto done;

		if (flags == BT_GET_DEPTH) {
			p[i] = addr;
			continue;
		}

	} while (++i < depth);
done:
	return (i);
}

/* compatibility functions for libexecinfo and glibc */
int
backtrace(void **bt, int depth)
{
	return (bt_create_backtrace(bt, depth, BT_GET_DEPTH));
}

char **
_backtrace_symbols(void *const *buffer, int depth, int add_cr)
{
	struct bt_frame		bt[BT_MAX_DEPTH];
	char			*line[BT_MAX_DEPTH];
	int			i, x;
	char			**rv = NULL, *current;
	char			*cr, *s;
	size_t			sz, csz;

	if (buffer == NULL || depth <= 0)
		return (NULL);

	if (add_cr == BT_ADD_CR)
		cr = "\n";
	else
		cr = "";

	for (i = 0, sz = 0; i < depth; i++) {
		if (dladdr(buffer[i], &bt[i].bt_dlinfo) == 0) {
			/* try something */
			if (asprintf(&line[i], "%p%s",
			    buffer[i],
			    cr) == -1)
				goto unwind;
		} else {
			s = (char *)bt[i].bt_dlinfo.dli_sname;
			if (s == NULL)
				s = "???";
			if (asprintf(&line[i], "%p <%s+%ld> at %s%s",
			    buffer[i],
			    s,
			    buffer[i] - bt[i].bt_dlinfo.dli_saddr,
			    bt[i].bt_dlinfo.dli_fname,
			    cr) == -1)
				goto unwind;
		}
		sz += strlen(line[i]) + 1;
	}

	/* adjust for array */
	sz += depth * sizeof(char *);

	rv = malloc(sz);
	if (rv == NULL)
		goto unwind;

	current = (char *)&rv[depth];
	for (x = 0; x < depth; x++) {
		rv[x] = current;
		csz = strlcpy(current, line[x], sz - (current - (char *)rv));
		if (csz >= sz) {
			free(rv);
			rv = NULL;
			goto unwind;
		}
		current += csz + 1;
	}
unwind:
	while (--i >= 0)
		free(line[i]);

	return (rv);
}

char **
backtrace_symbols(void *const *buffer, int depth)
{
	return (_backtrace_symbols(buffer, depth, 0));
}

void
backtrace_symbols_fd(void *const *buffer, int depth, int fd)
{
	char			**strings;
	size_t			sz;
	int			i;

	strings = _backtrace_symbols(buffer, depth, BT_ADD_CR);
	if (strings == NULL)
		return;

	for (i = 0; i < depth; i++) {
		sz = strlen(strings[i]);
		if (write(fd, strings[i], sz) == -1)
			return;
	}

	free(strings);
}
