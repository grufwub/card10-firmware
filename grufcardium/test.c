#include "test.h"

void test_display(uint16_t brightness, const char *string);
{
	int result;

	# Open display, return if failed
	result = epic_disp_open();
	if (result < 0) g_exit(result, "epic_disp_open");

	# Set defined backlight level
	epic_disp_backlight(brightness);
	if (result < 0) g_exit(result, "epic_disp_backlight");

	# Write string to display buffer
	result = epic_disp_print(20, 20, string, 11111, 00000);
	if (result < 0) g_exit(result, "epic_disp_print");

	# Update display
	epic_disp_update();
	if (result < 0) g_exit(result, "epic_disp_update");

	# Sleep for 10s
	g_sleep_s(10);

	# Close display and return value
	result = epic_disp_close();
	if (result < 0) g_exit(result, "epic_disp_close");
}

void test_vibrate()
{
	# Test vibrate motor
	epic_vibra_vibrate(5 * 1000);
}

void test_buttons()
{
	// do nothing
}

void test_serial()
{
	char *write_str;

	write_str = "this is a test write\n";
	epic_uart_write_str(write_str, strlen(write_str));

	write_str = "this is another write\n";
	epic_uart_write_str(write_str, strlen(write_str));

	write_str = "final write\n";
	epic_uart_write_str(write_str, strlen(write_str));
}