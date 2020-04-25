void StazioniServizio(double m, int n, double *d, double *p);
int main(void) {
	double distanze[5] = { 260,284,308,332,356 };   // distanze fra partenza e prima stazione prima e seconda .... ultima e arrivo
	double p[5] = { 35,35,33,29,23 };
	StazioniServizio(1540, 5, distanze, p);
	return 0;



}