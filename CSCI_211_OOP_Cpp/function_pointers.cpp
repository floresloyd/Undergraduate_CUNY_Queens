#include <iostream>
#include <string>
using namespace std;

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int main(){
// FUNCTION POINTER 
// return type (*pointer_name)(parameters);
// with pointers we then have to point it towards something 
// We can re-instantiate the one we declare 
    int (*func)(int, int);
    
    int x,y,userInput;
    string operation;

    cout<< "Enter a number: ";
    cin>> x;
    cout<< "Enter another number: ";
    cin>> y;
    cout<< "Enter 1 for addition" << endl
        << "Enter 2 for subtraction: ";
       
        cin>> userInput;
        if (userInput == 1){
            // Pointers points to add function
            func = add;
            operation = "+";
        }
        else if (userInput == 2){
            // Pointer points to subtract function
            func = subtract; 
            operation = "-";
        } 
    cout<< x << " " << operation << " " << y << " = " << func(x,y);

}