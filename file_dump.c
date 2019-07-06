#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#define		A_LEN			(1024)
#define		DEV_RANDOM		"/dev/urandom"

/* main */
int main(int argc, char *argv[]) {
	FILE *fp;
	struct stat st;
	int base;
	int ret;
	char *bin_file;
	char *file_path;

	base = 0;
	fp = NULL;
	bin_file = NULL;
	file_path = NULL;

	file_path = malloc(A_LEN);
	memset(file_path, 0, A_LEN);

	if (argc == 3) {
		strncpy(file_path, argv[1], A_LEN - 1);
		base = strtoll(argv[2], NULL, 10);
	} else {
		printf("%s [file_path] [base]\n", argv[0]);
		goto err;
	}

	ret = stat(file_path, &st);
	if (ret < 0 || st.st_size <= 0) {
		printf("ファイル情報取得失敗");
		goto err;
	}

	bin_file = malloc(st.st_size);
	if (!bin_file)
		goto err;

	fp = fopen(file_path, "rb");
	if (fp == NULL) {
		printf("ファイルオープン失敗");
		return -1;
	}

	ret = fread(bin_file, st.st_size, 1, fp);
	if (ret < 1)
		goto err;

	ret = bin_dump((unsigned char *)bin_file, st.st_size, base);
	if (ret)
		goto err;

err:
	if (fp)
		fclose(fp);
	if (bin_file)
		free(bin_file);
	if (file_path)
		free(file_path);

	return 0;
}
