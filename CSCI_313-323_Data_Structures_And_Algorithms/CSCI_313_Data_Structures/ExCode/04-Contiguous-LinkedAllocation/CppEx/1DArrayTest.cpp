#include <iostream>

int main(){
	// One dimensional arrays
#define ARRAY_SIZE  5
	char A[ARRAY_SIZE];
	int* B = new int[ARRAY_SIZE];
	double C[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++){
		printf("&A[%d]: %p\n", i, &A[i]);
	} //end-for
	printf("-------------------------------------\n");
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("&B[%d]: %p\n", i, &B[i]);
	} //end-for
	printf("-------------------------------------\n");

	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("&C[%d]: %p\n", i, &C[i]);
	} //end-for
	printf("-------------------------------------\n");

    return 0;
}