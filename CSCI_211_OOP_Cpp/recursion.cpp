#include <iostream>
using namespace std;

static int memo[1000] = {0};

int factorial (int x){  
    if (x <= 1) return 1;                           
    return x * factorial(x-1);
}

int fibonacci (int x){
    if (x <= 1) return x;
    return fibonacci(x-1) + fibonacci (x-2);
}

int memofibonacci(int x){                                   // CODE WILL READ ALL IF STATEMENTS IF CONDITION PASSES SOMETHING HAPPENS IF NOT IT IS JUST LIKE THE REGULAR FIBONACCI
    if (memo[x] != 0){                                      // If we have a solution saved for x, 
        return memo[x];                                     // instead of solving we straight away just have the answer from the memo array
    }
    
    if (x <= 1){                                            // base case 
        memo[x] = x;                                        // if it is just return base case 
        return memo[x];
    }

    memo[x] = memofibonacci(x-1)+memofibonacci(x-2);        // fibonacci computation, instead of returning we save it in the memo array
    return memo[x];                                         // return final solution
}

void reversePrint(int x){
    if ( x == 0) return;
    cout << x % 10;
    reversePrint(x / 10);
}

int main(){
    int(*functionPointer)(int);
    functionPointer = fibonacci;
    cout << functionPointer(5);
    reversePrint(678);

}

