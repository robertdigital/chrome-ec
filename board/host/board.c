/* Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
/* Emulator board-specific configuration */

#include "button.h"
#include "extpower.h"
#include "gpio.h"
#include "host_command.h"
#include "inductive_charging.h"
#include "lid_switch.h"
#include "motion_sense.h"
#include "motion_lid.h"
#include "power_button.h"
#include "temp_sensor.h"
#include "timer.h"
#include "util.h"

/*
 * GPIO_0 is the name generated by the gpio.inc GPIO macros for all of the host
 * GPIO ports.  This maps back to 0, which is then ignored by the host GPIO mock
 * code.
 */
#define GPIO_0  0

#include "gpio_list.h"

test_mockable_static int dummy_temp_get_val(int idx, int *temp_ptr)
{
	*temp_ptr = 0;
	return EC_SUCCESS;
}

const struct temp_sensor_t temp_sensors[] = {
	{"CPU", TEMP_SENSOR_TYPE_CPU, dummy_temp_get_val, 0, 3},
	{"Board", TEMP_SENSOR_TYPE_BOARD, dummy_temp_get_val, 1, 3},
	{"Case", TEMP_SENSOR_TYPE_CASE, dummy_temp_get_val, 2, 0},
	{"Battery", TEMP_SENSOR_TYPE_BOARD, dummy_temp_get_val, 3, 0},
};
BUILD_ASSERT(ARRAY_SIZE(temp_sensors) == TEMP_SENSOR_COUNT);

test_mockable void button_interrupt(enum gpio_signal signal)
{
};

#ifdef CONFIG_BUTTON_COUNT
const struct button_config buttons[] = {
	{"Volume Down", KEYBOARD_BUTTON_VOLUME_DOWN, GPIO_BUTTON_VOLUME_DOWN_L,
	 30 * MSEC, 0},
	{"Volume Up", KEYBOARD_BUTTON_VOLUME_UP, GPIO_BUTTON_VOLUME_UP,
	 60 * MSEC, BUTTON_FLAG_ACTIVE_HIGH},
};
BUILD_ASSERT(ARRAY_SIZE(buttons) == CONFIG_BUTTON_COUNT);
#endif

