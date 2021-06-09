#ifndef _OS_TERMINAL_INCLUDED_H_
#define _OS_TERMINAL_INCLUDED_H_

#include "terminal_constants.h"
#include <wchar.h>

static const char VT_ESC = '\x1B';

/* CURSOR SIMPLE POSITIONING */

#define OS_VT_CURSOR_POSITION(pos) wprintf(L"%c%c", VT_ESC, pos)
#define OS_VT_CURSOR_REVERSE_IDX() wprintf(L"%cM", VT_ESC)
#define OS_VT_CURSOR_SAVE_MEM() wprintf(L"%c7", VT_ESC)
#define OS_VT_CURSOR_RESTORE_MEM() wprintf(L"%c8", VT_ESC)

/* CURSOR POSITIONING */

#define OS_VT_CURSOR_POSITION_N(pos, n) wprintf(L"%c[%d%c", VT_ESC, n, pos)
#define OS_VT_CURSOR_LINE(line, n) wprintf(L"%c[%d%c", VT_ESC, n, line)
#define OS_VT_CURSOR_ABSOLUTE(abs, n) wprintf(L"%c[%d%c", VT_ESC, n, abs)
#define OS_VT_CURSOR_XY(x, y) wprintf(L"%c[%d;%dH", VT_ESC, x, y)
#define OS_VT_CURSOR_HORIZ_VERT_POS(x, y) wprintf(L"%c[%d;%dH", VT_ESC, x, y)
#define OS_VT_CURSOR_SAVE() wprintf(L"%c[s", VT_ESC)
#define OS_VT_CURSOR_RESTORE() wprintf(L"%c[u", VT_ESC)

/* CURSOR VISIBILITY */

#define OS_VT_CURSOR_BLINKING(blink) wprintf(L"%c[?12%c", VT_ESC, blink)
#define OS_VT_CURSOR_VISIBILITY(visible) wprintf(L"%c[?25%c", VT_ESC, visible)

/* VIEWPORT POSITIONING */

#define OS_VT_VIEWPORT_SCROLL_UP(n) wprintf(L"%c[%dS", VT_ESC, n)
#define OS_VT_VIEWPORT_SCROLL_DOWN(n) wprintf(L"%c[%dT", VT_ESC, n)

/* TEXT MODIFICATION */

#define OS_VT_INSERT_CHAR(n) wprintf(L"%c[%d@", VT_ESC, n)
#define OS_VT_DELETE_CHAR(n) wprintf(L"%c[%dP", VT_ESC, n)
#define OS_VT_ERASE_CHAR(n) wprintf(L"%c[%dX", VT_ESC, n)
#define OS_VT_INSERT_LINE(n) wprintf(L"%c[%dL", VT_ESC, n)
#define OS_VT_DELETE_LINE(n) wprintf(L"%c[%dM", VT_ESC, n)
#define OS_VT_ERASE_IN_DISPLAY(n) wprintf(L"%c[%dJ", VT_ESC, n)
#define OS_VT_ERASE_IN_LINE(n) wprintf(L"%c[%dK", VT_ESC, n)

/* TEXT FORMATTING */

#define OS_VT_SET_GRAPHICS_RENDITION(n) wprintf(L"%c[%dm", VT_ESC, n)
#define OS_VT_SGR_FOREGROUND_EXT(r, g, b) wprintf(L"%c[38;2;%d;%d;%dm", VT_ESC, r, g, b)
#define OS_VT_SGR_BACKGROUND_EXT(r, g, b) wprintf(L"%c[48;2;%d;%d;%dm", VT_ESC, r, g, b)

/* MODE CHANGES */

#define OS_VT_KEYPAD_APPLICATION_ENABLE() wprintf(L"%c=", VT_ESC)
#define OS_VT_KEYPAD_NUMERIC_ENABLE() wprintf(L"%c>", VT_ESC)
#define OS_VT_CURSOR_KEYS_APPLICATION_ENABLE() wprintf(L"%c[?1h", VT_ESC)
#define OS_VT_CURSOR_KEYS_APPLICATION_DISABLE() wprintf(L"%c[?1l", VT_ESC)

/* DESIGNATE CHARACTER SET */

#define OS_VT_DEC_ENABLE() wprintf(L"%c(0", VT_ESC)
#define OS_VT_ASCII_ENABLE() wprintf(L"%c(B", VT_ESC)

/* SCROLLING MARGINS */

#define OS_VT_SET_SCROLLING_REGION(t, b) wprintf(L"%c[%d;%dr", VT_ESC, t, b)

/* ALTERNATE SCREEN BUFFER */

#define OS_VT_SET_SCREEN_BUFFER(buffer) wprintf(L"%c[?1049%c", VT_ESC, buffer)

/* TERMINAL SIZE */

#define OS_VT_TERMINAL_SIZE(rows, cols) wprintf(L"%c[8;%d;%dt", VT_ESC, rows, cols)

#endif // _OS_TERMINAL_INCLUDED_H_
