#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/* Computes the super digit of “n” */
int SuperDigit(int n){
  /* Base case */
  if (n < 10) return n;

  int digitSum = 0;
  while (n > 0){
     digitSum += n % 10;
     n = n/10;
  } //end-while
 	
  return SuperDigit(digitSum);
} /* end-SuperDigit */

int main(){
	printf("Superdigit of 9875: %d\n", SuperDigit(9875));

	return 0;
} // end-main
