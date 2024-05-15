/*
 * SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
print_class(const char *class)
{
	assert(class);
	assert(*class);
	assert(isupper(*class));

	printf("final class %s", class);
	printf(" {\n");
	printf("}\n");
}

static void
print_package(const char *package)
{
	assert(package);
	assert(*package);
	assert(islower(*package));

	printf("package %s;\n", package);
	printf("\n");
}

static void
print_full_class(const char *full_class)
{
	assert(full_class != NULL);
	assert(*full_class != '\0');

	if (isupper(*full_class)) {
		print_class(full_class);
		return;
	}

	char *class = strrchr(full_class, '.');
	assert(class);
	char *package = strndup(full_class, class - full_class);
	assert(package);
	class++;

	print_package(package);
	print_class(class);
}

int
main(int argc, char **argv)
{
	if (argc != 2)
		abort();

	const char *full_class = argv[1];

	print_full_class(full_class);
}
