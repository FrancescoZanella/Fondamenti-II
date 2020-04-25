#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
	char s[100];
	scanf("%s", s);
	int lungstr = strlen(s);

	FILE *f = fopen("F.txt", "rt");
	if (!f) {
		printf("C'é stato un errore nell'apertura del file");
	}
	char g;
	int lung=0;
	while ((g = fgetc(f)) != EOF) {
		lung++;
	}
	rewind(f); // conto la dimensione del file
	char c;
	int occorrenza = 0,i=0;
	for (int z = 0; z < lung; z++) {
		while ((c = fgetc(f)) == s[i]){
			z++;
		    i++;
        }
		if (i == lungstr) {
			occorrenza++;
			i = 0;
		}
		
	}
	printf("il numero di occorrenze e' %d", occorrenza);
	fclose(f);
	return EXIT_SUCCESS;
}
