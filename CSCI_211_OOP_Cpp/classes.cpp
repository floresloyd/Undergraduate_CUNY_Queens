#include <iostream>
using namespace std;

class Rat{
    // Private are the instance variables so we only have access within the class 
    private:
    int n;
    int d;

    public: 
    // CONSTRUCTORS 

    // 1. Blank Constructor
    Rat(){
        n = 0;
        d = 1;
    }
    // 2. One parameter constructor | Pass an integer and we make 1 it's denominator to make it a fraction
    Rat(int x){
        n = x;
        d = 1;
    }
    // 3. Two parameter constructor 
    Rat (int x, int y){
        n = x;
        d = y;
    }

    // FUNCTIONS 

    // GETTERS AND SETTERS
    void setNumerator(int x){
        n = x;
    }
    void setDenominator(int x){
        d = x;
    }
    int getNumerator(){
        return n;
    }
    int getDenominator(){
        return d;
    }
    
    // Operator overloading 
// Class_name operator(operator) (parameter)
    Rat operator+ (Rat y){
        Rat x;
        x.n = (n * y.d) + (d * y.n); 
        x.d = d * y.d;
        return x;
    }

    Rat operator*(Rat y){
        Rat x;
        x.n = n * y.n;
        x.d = d * y.d;
        return x;
    }

    Rat operator-(Rat y){
        Rat x;
        x.n = n * y.d - d * y.n;
        x.d = d*y.d;
        return x;
    }

    Rat operator/(Rat y){
        Rat x;
        x.n = n*y.d;
        x.d = d*y.d;
        return x;
    }


    // Has private access when you declare as a friend 
    //      return_type operator (parameters)
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);

};  // rat class close


ostream& operator<<(ostream& os, Rat r){
    os << r.n << "this is a fraction" << r.d;
    return os;
}

istream& operator>>(istream& is, Rat& r){
    is >> r.n >> r.d;
    return is; 
}

int main(){
    Rat x = Rat(1,2);
    Rat y = Rat(3,4);
    Rat z = x * y;
    
    cout << x;


    return 0;
}