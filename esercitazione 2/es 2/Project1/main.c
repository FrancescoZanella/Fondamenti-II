int main(void) {
	int c = 8;
	int ris = Fibonacci(c);
}
int Fibonacci(int n) {
	if (n < 0) { return -1; }
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	else { return Fibonacci(n - 1) + Fibonacci(n - 2); }
}

