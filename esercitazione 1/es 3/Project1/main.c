#include<stdio.h>
#include<stdlib.h>
void main(void) {
	char s[100];
	scanf("%s", s);
	int i = 0;
	while (*(s+i) !=0) {
		if ( *(s+i)> 90) {
			*(s+i) -= 32;
		}
		printf("%c",*(s+i));
		i++;
	}

}