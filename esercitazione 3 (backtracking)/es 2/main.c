#include<stdbool.h>
extern void BabboNatale(int p, int const *pacchi, int n, unsigned i,
	bool *vcurr, bool *vbest, unsigned *max, unsigned cnt,
	int sum);
int main(void) {
	int p = 20;
	int n = 4;
	const int pacchi[4] = {10,11,1,3}, vcurr[4], vbest[4];
	int max = 0;
	BabboNatale(p, pacchi, n, 0, vcurr, vbest, &max, 0, 0);
}

/*
• p : portata massima della slitta;
• pacchi : array dei pesi dei regali disponibili;
• n : dimensione dell'array pacchi;
• i : la posizione attuale.Si noti che questo valore corrisponde al livello
dell'albero di backtrack che la funzione corrente sta esplorando;
• vcurr : un array che indica i regali attualmente caricati nella soluzione
corrente(ad esempio 1 = caricato, 0 = NON caricato);
• vbest : un array che indica i regali caricati nella miglior soluzione fino
ad ora trovata(ad esempio 1 = caricato, 0 = NON caricato);
• max : numero di regali caricati nella soluzione best;
• cnt : numero di regali caricati nella soluzione vcurr;
• sum : somma dei pesi dei regali caricati nella soluzione vcurr; */