/*
 * Copyright (c) 2021-2022 Simon, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#include "system.h"

int isspace(int c)
{
	return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
