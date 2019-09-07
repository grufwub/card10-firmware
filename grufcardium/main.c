#include "epicardium.h"
#include "api/caller.h"
#include "card10-version.h"

#include "max32665.h"

#include <stdio.h>

#include "test.h"

/* Defined in linker script */
extern void *__StackTop, *__StackLimit;
extern void *__HeapBase, *__HeapLimit;

int main(void)
{
	test_serial();

	test_display(50, "test string");

	test_vibrate();

	g_exit(0, "exit success!");
}