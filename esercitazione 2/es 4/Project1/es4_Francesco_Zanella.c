int Prodotto(int a, int b) {
	if (a < 0 || b < 0) { return -1; }
	if (b == 1) { return a; }
	else {
		return a + Prodotto(a, b - 1);
	}

}
