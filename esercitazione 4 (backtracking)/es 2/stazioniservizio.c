#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<float.h>
typedef struct {
	double prezzo;
	bool *stazioni;
}piano;
void Backtrack(int m,int n,int i,piano *vcurr,piano*vbest,double *d,double *p,double Km){
	if (i == n) {//caso base
		if (vcurr->prezzo < vbest->prezzo) {// se il prezzo é minore
			vbest->prezzo = vcurr->prezzo;
			memcpy(vbest->stazioni, vcurr->stazioni, n * sizeof(int));
		}
		return;
	}
	else {
		Km += d[i];
		vcurr->stazioni[i] = 1;
		vcurr->prezzo += p[i] * 0.05*Km;
		Backtrack(m, n, i + 1, vcurr, vbest, d, p, 0);
		vcurr->stazioni[i] = 0;
		vcurr->prezzo -= p[i] * 0.05*Km;
		if (Km + d[i + 1] < 600) {
			vcurr->stazioni[i] = 0;
			Backtrack(m, n, i + 1, vcurr, vbest, d, p, Km);
			
		}
		
	}
	if (i == 0) {
		if (vbest->prezzo == DBL_MAX) {
			printf("Non esistono soluzioni");
			free(vcurr->stazioni);
			free(vbest->stazioni);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (vbest->stazioni[i] == 1) {
				printf("%i ", i);
			}
		}
		printf("\nSpesa totale %f euro", vbest->prezzo);
		free(vbest->stazioni);
		free(vcurr->stazioni);

	}
}

void StazioniServizio(double m, int n, double *d, double *p) { //come indice i uso n e lo decremneto ad ogni chiamata ricorsiva
	piano vcurr = { .prezzo = 0,.stazioni = calloc(n,sizeof(int) )};
	piano vbest = { .prezzo = DBL_MAX,.stazioni = calloc(n,sizeof(int)) };
	//controllo errori
	for (int y = 0; y < n; y++) {
		if (d[y] > 600) {
			printf("Non esistono soluzioni");
			free(vcurr.stazioni);
			free(vbest.stazioni);

			return;

		}
	}
	


	Backtrack(m, n, 0, &vcurr, &vbest,d,p,0);


}
