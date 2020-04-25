#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void BabboNatale(int p, int const *pacchi, int n, unsigned i,
	bool *vcurr, bool *vbest, unsigned *max, unsigned cnt,
	int sum) {	
	if (i == n) {
		if (cnt > *max){
			*max = cnt;
			memcpy(vbest, vcurr,n);
			
		}	
		return;
	}
	vcurr[i] = 0;
	BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);	
	if ((sum+pacchi[i]<=p)) {
		vcurr[i]=1;
		BabboNatale(p,pacchi,n,i+1,vcurr,vbest,max,cnt+1,sum+pacchi[i]);
	}

	if (i == 0) {
		for (int y = 0; y < n; y++) {
			printf("%d", vbest[y]);
		}
		return;
	}







}
/*
• p: portata massima della slitta;
• pacchi: array dei pesi dei regali disponibili;
• n: dimensione dell'array pacchi;
• i: la posizione attuale. Si noti che questo valore corrisponde al livello
dell'albero di backtrack che la funzione corrente sta esplorando;
• vcurr: un array che indica i regali attualmente caricati nella soluzione
corrente (ad esempio 1 = caricato, 0 = NON caricato);
• vbest: un array che indica i regali caricati nella miglior soluzione fino
ad ora trovata (ad esempio 1 = caricato, 0 = NON caricato);
• max: numero di regali caricati nella soluzione best;
• cnt: numero di regali caricati nella soluzione vcurr;
• sum: somma dei pesi dei regali caricati nella soluzione vcurr;*/
