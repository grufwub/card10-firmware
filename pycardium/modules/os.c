#include "epicardium.h"

#include "py/obj.h"
#include "py/runtime.h"

#include <string.h>

static mp_obj_t mp_os_exit(size_t n_args, const mp_obj_t *args)
{
	int ret = 0;
	if (n_args == 1) {
		ret = mp_obj_get_int(args[0]);
	}

	epic_exit(ret);

	/* unreachable */
	return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(exit_obj, 0, 1, mp_os_exit);

static mp_obj_t mp_os_exec(mp_obj_t name_in)
{
	const char *name_ptr;
	char name_str[256];
	size_t len, maxlen;

	name_ptr = mp_obj_str_get_data(name_in, &len);

	/*
	 * The string retrieved from MicroPython is not NULL-terminated so we
	 * first need to copy it and add a NULL-byte.
	 */
	maxlen = len < (sizeof(name_str) - 1) ? len : (sizeof(name_str) - 1);
	memcpy(name_str, name_ptr, maxlen);
	name_str[maxlen] = '\0';

	int ret = epic_exec(name_str);

	/*
	 * If epic_exec() returns, something went wrong.  We can raise an
	 * exception in all cases.
	 */
	mp_raise_OSError(-ret);

	/* unreachable */
	return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(exec_obj, mp_os_exec);

static mp_obj_t mp_os_listdir(mp_obj_t py_path)
{
	const char *path = mp_obj_str_get_str(py_path);
	int fd           = epic_file_opendir(path);

	if (fd < 0) {
		mp_raise_OSError(-fd);
	}
	struct epic_stat entry;
	mp_obj_list_t *list = mp_obj_new_list(0, NULL);
	for (;;) {
		int res = epic_file_readdir(fd, &entry);
		if (res < 0) {
			m_del_obj(mp_obj_list_t, list);
			epic_file_close(fd);
			mp_raise_OSError(-res);
		}
		if (entry.type == EPICSTAT_NONE) {
			break;
		}
		mp_obj_list_append(
			list, mp_obj_new_str(entry.name, strlen(entry.name))
		);
	}
	epic_file_close(fd);
	return MP_OBJ_FROM_PTR(list);
}
static MP_DEFINE_CONST_FUN_OBJ_1(listdir_obj, mp_os_listdir);

static mp_obj_t mp_os_unlink(mp_obj_t py_path)
{
	const char *path = mp_obj_str_get_str(py_path);
	int rc           = epic_file_unlink(path);

	if (rc < 0) {
		mp_raise_OSError(-rc);
	}
	return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(unlink_obj, mp_os_unlink);

static const mp_rom_map_elem_t os_module_globals_table[] = {
	{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_os) },
	{ MP_ROM_QSTR(MP_QSTR_exit), MP_ROM_PTR(&exit_obj) },
	{ MP_ROM_QSTR(MP_QSTR_exec), MP_ROM_PTR(&exec_obj) },
	{ MP_ROM_QSTR(MP_QSTR_listdir), MP_ROM_PTR(&listdir_obj) },
	{ MP_ROM_QSTR(MP_QSTR_unlink), MP_ROM_PTR(&unlink_obj) },
};

static MP_DEFINE_CONST_DICT(os_module_globals, os_module_globals_table);

// Define module object.
const mp_obj_module_t os_module = {
	.base    = { &mp_type_module },
	.globals = (mp_obj_dict_t *)&os_module_globals,
};

/* This is a special macro that will make MicroPython aware of this module */
/* clang-format off */
MP_REGISTER_MODULE(MP_QSTR_os, os_module, MODULE_OS_ENABLED);