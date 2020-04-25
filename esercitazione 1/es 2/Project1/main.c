#include<stdlib.h>
#include<stdio.h>
void main(int argc, char *argv[]) {
	int ris = 1,n;
	for (int i = 1; i < argc; i++) {
		n=atoi(argv[i]);
		ris *= n;
	}
	printf("%d", ris);
}