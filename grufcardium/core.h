#ifndef __G_CORE
#define __G_CORE

#include <string.h>

#include "epicardium.h"

void g_exit(const char *string);

void g_sleep_us(int us);
void g_sleep_ms(int ms);
void g_sleep_s(int s);

#endif