int ProdottoNegativi(int a, int b) {
	if (b==-1) return -a;
	if (b == 1)return a;
	else {
		if (b < 0) {
			return -a + ProdottoNegativi(a, b + 1);

		}
		else
			return a + ProdottoNegativi(a, b - 1);

	}
}