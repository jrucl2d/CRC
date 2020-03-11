#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int n, k, alt;
	char *nk_bit;
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &alt);
	nk_bit = (char*)malloc(n+k);
	scanf("%s", nk_bit);

	// argument error 
	if (argc != 2) {
		printf("argument number error!!\n");
		return 1;
	}
	// alter specific bit
	alt = atoi(argv[1]);
	if (nk_bit[alt-1] == '1')
		nk_bit[alt-1] = '0'; // indexing starts from 0
	else if (nk_bit[alt-1] == '0')
		nk_bit[alt-1] = '1';
	printf("%d\n", n);
	printf("%d\n", k);
	printf("%d\n", alt);
	printf("%s\n", nk_bit);
	free(nk_bit);
	return 0;
}