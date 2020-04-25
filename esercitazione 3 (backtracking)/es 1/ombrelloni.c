#include<stdbool.h>
#include<stdio.h>
void Ombrelloni(int k, int n, unsigned int  i, bool *vcurr, unsigned int cnt, unsigned int  *nsol) {
	if (cnt == k) {   // se il numero di ragazzi da posizionare é uguale al numero di ragazzi posizionati allora mi fermo
		printf("%d)",*nsol);
		(*nsol)++;
		for (int j = 0; j < i; j++) {
			printf("%d", vcurr[j]);
		}
		for (int j = i; j < n; j++) {
			printf("0");
		}
		printf("\n");
		return;

	}
	if (i == n)return;
	if (i==0 || ((n-i)/2>=(k-cnt))) {// non metto il ragazzo
		vcurr[i] = 0;
		Ombrelloni(k, n, i + 1, vcurr, cnt, nsol);
	}
	if (i==0 || vcurr[i-1]==0) {// metto il ragazzo 
		vcurr[i] = 1;
		Ombrelloni(k, n, i + 1, vcurr, cnt + 1, nsol);
	}
}
/*
k: il numero di ragazzi da posizionare;
• n: il numero di posti disponibili in prima fila;
• i: la posizione attuale. Si noti che questo valore corrisponde al livello dell'albero di
backtrack che la funzione corrente sta esplorando;
• vcurr: un array che indica lo stato degli ombrelloni in prima fila (ad esempio 1 =
occupato, 0 = libero). All'inizio dovranno essere tutti liberi:
• cnt: un contatore che memorizza il numero di ragazzi posizionati nella soluzione
corrente;
• nsol: il numero totale di soluzioni trovate ;*/