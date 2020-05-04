#define _CRT_SECURE_NO_WARNINGS
#include"gioielli.h"
Gioiello *Gioielli(const char *filename,float b, int *ret_size) {
	/*1 12 100   peso valore     devo massimizzare il peso rimanendo sotto valore   8.33    2,1     4.8
      2 10 21
      3 25 120*/
	FILE* f = fopen(filename, "rt");
	if (!f) {
		return NULL;
	}
	int numGioielli = 0, a ;
	float d;
	float c ;
	while (fscanf(f,"%d %f %f\n",&a,&d,&c ) == 3) {
			numGioielli++;
	}
	rewind(f);
	Gioiello *res = malloc(numGioielli * sizeof(Gioiello));
	for (int i = 0; i < numGioielli; i++) {
		fscanf(f, "%d %f %f\n", &res[i].codice, &res[i].peso, &res[i].prezzo);
	}
	int min;
	Gioiello *temp=malloc(numGioielli *sizeof(Gioiello));
	//li ordino in base al peso in ordine decrescente
	for (int i = 0; i < numGioielli - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < numGioielli; j++)
			if (res[j].peso/res[j].prezzo > res[min].peso/ res[min].prezzo)
				min = j;

		temp[i] = res[min]; res[min] = res[i]; 		res[i] = temp[i];		
	}
	int r = 0,h=0,numfin=numGioielli;
	Gioiello *resfin = malloc(numfin * sizeof(Gioiello));
	//fine ordinamento
	//inizia il greedy 
	for (int i = 0; i < numGioielli; i++) {
		if (r + res[i].prezzo <= b) {
			r += res[i].prezzo;
			resfin[h] = res[i];
			h++;
		}
		else {
			numfin--;
			resfin = realloc(resfin, numfin * sizeof(Gioiello));
		}
	}
	*ret_size = numfin;
	free(res);
	free(temp);
	fclose(f);
	return resfin;

}



