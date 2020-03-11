#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char n_bit[20];
	char k_bit[20];
	char *nk_bit;
	int n, k, alt = 0; // length, alter bit
	int i;

	// input n_bit, k_bit from file.txt
	scanf("%s", n_bit);
	scanf("%s", k_bit);
	n = strlen(n_bit);
	k = strlen(k_bit);
	nk_bit = (char*)malloc(n+k);

	// generate n+k bit, output of generator
	for (i = 0; i < n; i++)
		nk_bit[i] = n_bit[i];
	for (i = 0; i < k; i++)
		nk_bit[i+n] = k_bit[i];
	printf("%d\n", n);
	printf("%d\n", k);
	printf("%d\n", alt); // if no alter, alt will be 0
	printf("%s\n", nk_bit);
	free(nk_bit);
	return 0; // return n+k bit line
}
