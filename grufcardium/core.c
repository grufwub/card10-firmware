#include "core.h"

void g_exit(int ret_code, const char *string)
{
	epic_uart_write_str(string + '\n', strlen(string) + 1);
	epic_exit(ret_code);
}

void g_sleep_us(int us)
{
	mxc_delay(us);
}

void g_sleep_ms(int ms)
{
	g_sleep_us(ms * 1000);
}

void g_sleep_s(int s)
{
	g_sleep_ms(s * 1000);
}