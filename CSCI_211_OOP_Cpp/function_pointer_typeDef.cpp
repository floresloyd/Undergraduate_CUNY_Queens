#include <iostream>
using namespace std;

// CREATES A FUNCTION POINTER USING TPYE DEF
// Allows us to create the function pointer as a variable type that we can create multiple ones

typedef int (*PFoperation_integer)(int, int);
typedef float(*PFoperation_float)(int, int);

int add(int x, int y){
    return x+y;
}
int subtract (int x, int y){
    return x-y;
}
int mult(int x, int y){
    return x*y;
}
float divide(int x, int y){
    return x%y;
}

int main(){
    PFoperation_integer a,s,m;
    PFoperation_float d;
    a = add;
    s = subtract;
    m = mult;
    d = divide;

    int x = 10;
    int y = 5;

    cout<< a(x,y) << endl
        << s(x,y) << endl
        << m(x,y) << endl
        << d(x,y) << endl;


    return 0;    
}