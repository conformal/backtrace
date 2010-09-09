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

#ifndef __GNUC__
#error "this library must be compiled with gcc"
#endif

#define BT_MAX_DEPTH            (128)

struct bt_frame {
	Dl_info			bt_dlinfo;
	unsigned int		line;
};

/* compatability functions with libexecinfo and glibc */
int			backtrace(void **, int);
char			**backtrace_symbols(void *const *, int);
void			backtrace_symbols_fd(void *const *, int, int);
