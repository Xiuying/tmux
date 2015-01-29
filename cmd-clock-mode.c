/* $OpenBSD$ */

/*
 * Copyright (c) 2009 Nicholas Marriott <nicm@users.sourceforge.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include "tmux.h"

/*
 * Enter clock mode.
 */

enum cmd_retval	 cmd_clock_mode_exec(struct cmd *, struct cmd_q *);

const struct cmd_entry cmd_clock_mode_entry = {
	"clock-mode", NULL,
	"t:", 0, 0,
	CMD_TARGET_PANE_USAGE,
	CMD_PREP_PANE_T,
	cmd_clock_mode_exec
};

enum cmd_retval
cmd_clock_mode_exec(unused struct cmd *self, struct cmd_q *cmdq)
{
	window_pane_set_mode(cmdq->state.tflag.wp, &window_clock_mode);

	return (CMD_RETURN_NORMAL);
}
