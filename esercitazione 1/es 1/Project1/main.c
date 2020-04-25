#include<string.h>
#include<stdio.h>
void main(int argc, char *argv[]) {
	int len_str = strlen(argv[1]), conta1 = 0,conta2=0;
	for (int i = 0; i < len_str + 1; i++) {
		if (argv[1][i] == argv[2][0]) {
			conta1++;
		}
	}
	for (int i = 0; i < len_str + 1; i++) {
		if (argv[1][i] == argv[3][0]) {
			conta2++;
		}
	}
	if (conta1 > conta2) {
		printf("%c", argv[2][0]);
	}
	else {
		printf("%c", argv[3][0]);
	}
}