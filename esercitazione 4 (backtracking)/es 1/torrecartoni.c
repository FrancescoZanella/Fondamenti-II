#include"torrecartoni.h"

typedef struct {
	unsigned int a; //altezza torre
	int *index;     // indici cartoni che costituiscono torre
	int size;       // quanti cartoni ho preso
}torre;
void Backtrack(cartone *c, int n, torre *vcurr, torre *vbest, bool *usati, int i, int *psopra) {
	if (i == n) {//caso base
		if (vcurr->a > vbest->a) {//se l'altezza corrente é maggiore altezza migliore
			vbest->a = vcurr->a;
			vbest->size = vcurr->size;
			memcpy(vbest->index, vcurr->index, vcurr->size *sizeof(int));
		}
		return;
	}
	for (int j = 0; j < n; j++) {
		if (!usati[j]) {
			if (c[j].l >= *psopra) {
				vcurr->index[i] = j;
				vcurr->a += c[j].a;
				vcurr->size++;//
				*psopra += c[j].p;//
				usati[j] = 1; //
				Backtrack(c, n, vcurr, vbest, usati, i + 1, psopra);
				usati[j] = 0;
				*psopra -= c[j].p;
				vcurr->size--;
				vcurr->a -= c[j].a;
			}
		}
		else{
			Backtrack(c, n, vcurr, vbest, usati, n, psopra); // dato che possono essere valide soluzione anche senza i==n allora ogni passo verifico se va bene la soluzione trovata fino ad ora mettendo i ==n
		}
		
	}





}
void TorreCartoni(cartone* c, int n) {
	torre vcurr = { .a = 0,.index = malloc(n * sizeof(int)),.size = 0 };
	torre vbest = { .a = 0,.index = malloc(n * sizeof(int)),.size = 0 };
	bool *usati = calloc(n, sizeof(int));
	int  b = 0;
	Backtrack(c, n, &vcurr, &vbest, usati, 0, &b);
	for (int i = 0; i < vbest.size; i++) {
		printf("%i\n", vbest.index[i]);
	}
	printf("Altezza %i cm", vbest.a);
	free(vcurr.index);
	free(vbest.index);
	free(usati);
}