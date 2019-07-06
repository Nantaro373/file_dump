#include <stdio.h>


int bin_dump(unsigned char *buf, const unsigned int size, const int base) {
	unsigned int len;
	unsigned char *c_buf;
	unsigned short *s_buf;
	unsigned int *i_buf;
	unsigned long *l_buf;

	if ((!buf) || (size <= 0)) {
		printf("bin_dump エラー base %d\n", base);
		return -1;
	}

	len = 0;

	while (len < size) {
		switch (base) {
		case 1:
			c_buf = (unsigned char *)&buf[len];
			len += 1;
			printf("%02x ", *c_buf);
			break;

		case 2:
			s_buf = (unsigned short *)&buf[len];
			len += 2;
			printf("%04x ", *s_buf);
			break;

		case 4:
			i_buf = (unsigned int *)&buf[len];
			len += 4;
			printf("%08x ", *i_buf);
			break;

		case 8:
			l_buf = (unsigned long *)&buf[len];
			len += 8;
			printf("%016lx ", *l_buf);
			break;

		default:
		printf("base エラー base %d\n", base);
			return -1;
		}

		if (len % 16 == 0 && len != 0)
			printf("\n");
	}

	printf("\n");

	return 0;
}
