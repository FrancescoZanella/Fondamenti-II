#include<stdbool.h>
extern void Ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned *nsol);

int main (void){
	bool vcurr[4] = { 0,0,0,0 };
	int nsol = 0;
	Ombrelloni(2, 4, 0, vcurr, 0, &nsol);




}
/*k: il numero di ragazzi da posizionare;
• n: il numero di posti disponibili in prima fila;
• i: la posizione attuale. Si noti che questo valore corrisponde al livello dell'albero di
backtrack che la funzione corrente sta esplorando;
• vcurr: un array che indica lo stato degli ombrelloni in prima fila (ad esempio 1 =
occupato, 0 = libero). All'inizio dovranno essere tutti liberi:
• cnt: un contatore che memorizza il numero di ragazzi posizionati nella soluzione
corrente;
• nsol: il numero totale di soluzioni trovate ;*/