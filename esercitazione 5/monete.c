/#include<stdlib.h>
#include<stdio.h>
int *Monete(int *t, int size, int b) { // t array dei tagli disponibili esempio 50 20 10 5 2 1
									   // size é la dimeensione dell'array size
									   //b é il budge
	int i = 0;
	if (b <= 0) {
		return NULL;
	}
	int *res = calloc(size, sizeof(int));
	while (i < size) {
		if (b >= t[i]) {
			b -= t[i];
			res[i] += 1;
		}
		else {
			i++;
		}
	}
	for (int j = 0; j < size; j++) {
		printf("%d ", t[j]);
	}
	printf("\n");
	for (int j = 0; j < size; j++) {
		printf("%d  ", res[j]);
	}
	return res;
}
