int Minimo(int *vec, int len) {
	int min_vec;
	len--;
	if (len == 0) { return vec[0]; }
	min_vec = Minimo(vec, len);
	if (min_vec < vec[len]) {
			return min_vec;
	}
	return vec[len];
}