#include "epicardium.h"
#include "api/caller.h"
#include "card10-version.h"

#include "max32665.h"

#include "core.h"
#include "test.h"

/* Defined in linker script */
extern void *__StackTop, *__StackLimit;
extern void *__HeapBase, *__HeapLimit;

int main(void)
{
	test_serial();

	test_display(50, "test string");

	test_vibrate();

	test_display(50, "resetting");

	epic_system_reset();
}