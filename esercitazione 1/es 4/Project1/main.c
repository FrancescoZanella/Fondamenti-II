#include<stdlib.h>
#include<stdio.h>
void main(int argc, char *argv[]) {
	int n=atoi(argv[1]);
	int secondi = 0,millisecondi=n;
	if (n >= 1000) {
		secondi=n / 1000; 
		millisecondi = n % 1000;
	}
	int minuti = 0;
	if (secondi >= 60) {
		minuti=secondi / 60;
		secondi %= 60;
	}
	printf("%d millisecondi sono %d minuti %d secondi e %d millisecondi", n, minuti, secondi,millisecondi);
}