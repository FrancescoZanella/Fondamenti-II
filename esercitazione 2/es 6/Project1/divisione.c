#include<stdlib.h>

int DivisioneNegativi(int a, int b) {
	if (b == a)return 1;
	if (b == -a)return -1;

	else {
		if ((b*a)>0) {
			return 1 + DivisioneNegativi(a - b, b);
		}
		else {
			return -1 + DivisioneNegativi(a + b, b);
		}
	}	
}