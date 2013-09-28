/* 
 * exportRelocation.c
 *
 * Author: z00189112 Date: 2013/09/28
 */

/* 
 * exportRelocation.exe: export the symbol in objdump.txt matching PPC_32 & listed int list.txt 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exportRelocation.h"

void usage(void)
{
	printf("\nUsage: exportRelocation.exe objdump.txt redircsym.txt out.txt\n");
}

void main(int argc, char *argv[])
{
	if (argc < 4) {
		usage();
		return;
	}

	FILE *objdump = NULL;
	FILE *redircsym = NULL;
	FILE *out = NULL;
	char line_buff[MAX_LINE_NUM];

	if ((objdump = fopen(argv[1], "r")) == NULL) {
		printf("open %s error!\n", argv[1]);
		return;
	}

	if ((redircsym = fopen(argv[2], "r")) == NULL) {
		printf("open %s error!\n", argv[2]);
		goto objdump_error;
	}

	if ((out = fopen(argv[3], "w")) == NULL) {
		printf("open %s error!\n", argv[3]);
		goto redircsym_error;
	}

	while (fgets(line_buff, SYM_NAME_LEN, redircsym)) {
		if (!redircsym_map_add(line_buff)) {
			printf("redircsym_map_add %s error!\n", line_buff);
			return;
		}
	}
	redircsym_map_show();

	char symaddr[SYM_ADDR_LEN];
	char symtype[SYM_TYPE_LEN];
	char symname[SYM_NAME_LEN];
	struct list *tmp;

	while (fgets(line_buff, MAX_LINE_NUM, objdump)) {
		if (!redircsym_info_isppc(line_buff, symaddr, symtype, symname) 
				&& (tmp = redircsym_map_find(symname))) {
			redircsym_map_set_matchflag(tmp);
			if (!redircsym_info_add(symaddr, symtype, tmp)) {
				printf("redircsym_info_add %s error!\n", symname);
				return;
			}
		}
	}
	redircsym_info_show();

	redircsym_map_set_offset();
	redircsym_info_set_offset();

	redircsym_map_write_to_file(out);
	redircsym_info_write_to_file(out);

out_error:
	fclose(out);
redircsym_error:
	fclose(redircsym);
objdump_error:
	fclose(objdump);

return;
}
