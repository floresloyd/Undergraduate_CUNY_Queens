#include <iostream>

int main(){
	// Two dimensional arrays
	// Multi-dimensional arrays: Laid out in row-major order
#define NO_ROWS		3
#define NO_COLUMNS	4
	char D[NO_ROWS][NO_COLUMNS];

	for (int i = 0; i < NO_ROWS; i++) {
		for (int j = 0; j < NO_COLUMNS; j++) {
			printf("&D[%d][%d]: %p\n", i, j, &D[i][j]);
		} // end-for
		printf("----------------------------\n");
	} //end-for

    return 0;
}