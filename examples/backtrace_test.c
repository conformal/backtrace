/* $backtrace$ */
/*
 * Copyright (c) 2010 Marco Peereboom <marco@conformal.com>
 * Copyright (c) 2010 Conformal Systems LLC.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>

#include "backtrace.h"

void
f2(void)
{
	void			*bt[BT_MAX_DEPTH];
	int			fd, d;

	fd = open("mybacktrace", O_CREAT | O_WRONLY, 0600);
	if (fd == -1)
		err(1, "open");

        d = backtrace(bt, BT_MAX_DEPTH);
	if (d == -1)
		errx(1, "backtrace");

	backtrace_symbols_fd(bt, d, fd);

	close(fd);
}

void
f1(void)
{
	void			*bt[BT_MAX_DEPTH];
	char			**strings;
	int			i, d;

        d = backtrace(bt, BT_MAX_DEPTH);
	if (d == -1)
		errx(1, "backtrace");

	strings = backtrace_symbols(bt, d);

	if (strings == NULL)
		errx(1, "backtrace_symbols");

	for (i = 0; i < d; i++)
		printf("%s\n", strings[i]);

	free(strings);
}

void
f0(void)
{
	f1();
	f2();
}

int
main(int argc, char *argv[])
{
	f0();
	return (0);
}
