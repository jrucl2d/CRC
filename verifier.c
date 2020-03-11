#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* divide(char* arr, char* di, int n, int k);
int main() {
	int n, k, alt;
	char *nk_bit;
	char *divisor; // will divide something
	char *first_dividend; // will be divided first
	char *verify_dividend; // will be divided later
	char *remainder;
	int i, count = 0;

	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &alt);
	nk_bit = (char*)malloc(n+k);
	scanf("%s", nk_bit);
	divisor = (char*)malloc(k);
	first_dividend = (char*)malloc(n+k-1);
	verify_dividend = (char*)malloc(n+k-1);
	remainder = (char*)malloc(k-1);

	for (i = 0; i < k; i++) // to extract k_bit line
		divisor[i] = nk_bit[i + n];

	for (i = 0; i < n; i++) // make first dividend
		first_dividend[i] = nk_bit[i];
	for (i = 0; i < k-1; i++)
		first_dividend[i+n] = '0';
	if(alt > 0){ // re-alter to make original bit
		if (first_dividend[alt-1] == '1')
			first_dividend[alt-1] = '0'; // indexing starts from 0
		else if (first_dividend[alt-1] == '0')
			first_dividend[alt-1] = '1';
	}
	printf("first_dividend : %s", first_dividend);

	strcpy(remainder, divide(first_dividend, divisor, n, k)); // first divide to make remainder
	
	printf("remainder : %s\n", remainder);

	for (i = 0; i < n; i++) // make verify dividend
		verify_dividend[i] = nk_bit[i];
	for (i = 0; i < k; i++)
		verify_dividend[i+n] = remainder[i];
	printf("verify_dividend : %s", verify_dividend);

	strcpy(remainder, divide(verify_dividend, divisor, n, k)); // verifying
	
	printf("remainder : %s\n", remainder);	

	for(i=0; i<k-1; i++){
		if(remainder[i] == '1')
			count++;
	}
	if(count >0)
		printf("\nerror occurred!\n");
	else
		printf("\nno error!\n");
	free(nk_bit);
	free(divisor);
	free(first_dividend);
	free(verify_dividend);
	free(remainder);
	return 0;
}
char* divide(char* arr, char* di, int n, int k) {
	int i, j, count;
	int num_of_dividing = n;
	char *tmp_dividend = (char*)malloc(n+k-1);
	char *remainder = (char*)malloc(k-1);
	for (i = 0; i < num_of_dividing; i++) {
		for (j = 0; j < k; j++)
			tmp_dividend[j] = arr[i + j]; // take k bits

		if (tmp_dividend[0] == '0') { // if divisor is bigger than dividend -> divisor * 0
			count = 0;
			while (count < k) {
				arr[count + i] = ((arr[count + i]-'0') ^ 0) +'0';
				count++;
			}
		}
		else if (tmp_dividend[0] == '1'){ // if divisor is smaller than dividend -> divisor * 1
			count = 0;
			while (count < k) {
				arr[count + i] = ((arr[count + i]-'0') ^ (di[count]-'0'))+'0';
				count++;
			}
		}
		printf("\n%d번째", i);
		for (j = 0; j < n+k-1; j++) // set remainder
			printf("%c",arr[j]);
		
	}
	printf("\n");
	
	for (i = 0; i < k - 1; i++) // set remainder
		remainder[i] = arr[i + n];
	
	return remainder;
}