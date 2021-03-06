#include <stdio.h>
#include <string.h>

#include "py/runtime.h"
#include "py/smallint.h"
#include "py/obj.h"
#include "lib/timeutils/timeutils.h"
#include "extmod/utime_mphal.h"

STATIC const mp_rom_map_elem_t time_module_globals_table[] = {
	{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_utime) },
	{ MP_ROM_QSTR(MP_QSTR_sleep), MP_ROM_PTR(&mp_utime_sleep_obj) },
	{ MP_ROM_QSTR(MP_QSTR_sleep_ms), MP_ROM_PTR(&mp_utime_sleep_ms_obj) },
	{ MP_ROM_QSTR(MP_QSTR_sleep_us), MP_ROM_PTR(&mp_utime_sleep_us_obj) },
	{ MP_ROM_QSTR(MP_QSTR_ticks_ms), MP_ROM_PTR(&mp_utime_ticks_ms_obj) },
	{ MP_ROM_QSTR(MP_QSTR_ticks_us), MP_ROM_PTR(&mp_utime_ticks_us_obj) },
	{ MP_ROM_QSTR(MP_QSTR_ticks_cpu), MP_ROM_PTR(&mp_utime_ticks_cpu_obj) },
	{ MP_ROM_QSTR(MP_QSTR_ticks_add), MP_ROM_PTR(&mp_utime_ticks_add_obj) },
	{ MP_ROM_QSTR(MP_QSTR_ticks_diff),
	  MP_ROM_PTR(&mp_utime_ticks_diff_obj) },
};

STATIC MP_DEFINE_CONST_DICT(time_module_globals, time_module_globals_table);

const mp_obj_module_t mp_module_utime = {
	.base    = { &mp_type_module },
	.globals = (mp_obj_dict_t *)&time_module_globals,
};

// Register the module to make it available in Python
MP_REGISTER_MODULE(MP_QSTR_utime, mp_module_utime, MODULE_UTIME_ENABLED);
