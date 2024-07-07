#include <iostream>
using namespace std;

class Rational{
    private:
    // instance variables/ members are characteristics of a rational numbers (numerator/denominator)
    int n;
    int d;

    // has access to members
    // member functions can be called outside of the class
    public: 
    //CONSTRUCTORS
    Rational(){
        n = 0;
        d = 1;
    }
    Rational(int x){
        n = x;
        d = 1;
    }
    Rational(int x, int y){
        n = x;
        d = y;
    }
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
    int getDenmoniator(){
        return d;
    }

    // OPERATOR OVERLOADING
    // return type: rational number
    Rational operator+(Rational y){
        Rational x;
        x.n = (n * y.d) + (d * y.n);
        x.d = (d * y.d);
        return x;
    }
    Rational operator*(Rational y){
        Rational x;
        x.n = n * y.n;
        x.d = d * y.d;
        return x;
    }

    Rational operator-(Rational y){
        Rational x;
            if (d == y.d){
                x.n = n - y.n;
                x.d = d;
                cout <<" same denominator ";
            }else{
                x.n = (n * y.d) - y.n * y.n;
                x.d = d * y.d;
                cout <<" different denominator ";
            }
        return x;
    }

    Rational operator/ (Rational y){
        Rational x; 
        x.n = n * y.d;
        x.d = d * y.n;
        return x;
    }

        // We want to declare as a friend so the ostream object has access to the rat class
        friend ostream& operator<<(ostream& os, Rational x);
};

// WITH FRIEND DECLARATION
ostream& operator<<(ostream& os, Rational x){
    os << x.n << "/" << x.d;
    return os;
}
// WITHOUT FRIEND DECLARATION
// ostream& operator<<(ostream& os, Rational x){
//     os << x.getNumerator() << "/" << x.getDenmoniator();
//     return os;
// }


int main(){
    Rational x = Rational(6,2);
    Rational y = Rational(3,5);

    cout <<  x / y;

}