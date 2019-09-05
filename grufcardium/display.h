#ifndef __G_DISPLAY
#define __G_DISPLAY

#include "epicardium.h"

void g_disp_init();
void g_disp_putc(char c);
void g_disp_putc(char c, int x, int y);
void g_disp_puts(char *string);
void g_disp_puts(char *string, int y);
void g_disp_puts(char *string, int x, int y);
void g_disp_clearln(int y);
void g_disp_clear();
void g_disp_refreshln();
void g_disp_refresh();
void g_disp_close();

#endif