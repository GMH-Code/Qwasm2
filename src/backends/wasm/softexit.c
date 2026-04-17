/*
 * Copyright (C) 2026 Gregory Maynard-Hoare
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 * =======================================================================
 *
 * Quake 2 WebAssembly soft exit code
 *
 * =======================================================================
 */

#include "header/softexit.h"

#include <emscripten.h>

static int soft_exit_code;

void wasm_soft_exit(int exit_code)
{
	soft_exit_code = exit_code;
	emscripten_set_main_loop(wasm_soft_exit_fs_check, 0, 1);
}

void wasm_soft_exit_fs_check(void)
{
	// Called repeatedly on program exit until everything is saved
	if (!EM_ASM_INT(
		return Module.save_counter;
	)) {
		emscripten_cancel_main_loop();
		EM_ASM({
			if (typeof Module.softExit === 'function')
				Module.softExit($0);
		}, soft_exit_code);
	}
}
