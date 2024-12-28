#include <iostream>

int main(){
	/// 3D arrays
#define DIM1	5
#define DIM2	2
#define DIM3	3
	char E[DIM1][DIM2][DIM3];

	for (int i = 0; i < DIM1; i++) {
		for (int j = 0; j < DIM2; j++) {
			for (int k = 0; k < DIM3; k++) {
				printf("&E[%d][%d][%d]: %p\n", i, j, k, &E[i][j][k]);
			} //end-for
			printf("---------------------------------\n");
		} // end-for
		printf("================================\n");
	} //end-for

    return 0;
}