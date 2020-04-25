int Somma(int n) {
	if (n <= 0) {
		return-1;
	}
	else {
		if (n == 1) {
			return 1;
		}
		else {
			return n + Somma(n - 1);
		}
	}
}