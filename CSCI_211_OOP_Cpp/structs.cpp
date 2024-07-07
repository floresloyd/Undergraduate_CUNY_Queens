#include <iostream>
using namespace std;

// DEFAULT OF STRUCT IS PUBLIC 
// classes don't exist in C, and classes is what makes "++" in C++

struct Car{                 
    string make;
    string model;
    int year;
}car2;                                      // WE CAN CREATE AN OBJECT BY DECLARING AT THE END OF THE STRUCT
                                            // WE NEED TO CLOSE WITH A SEMI COLON
int main(){
    Car car1;
    car1.make = "Honda";
    car1.model = "Del-Sol";
    car1.year = 1995;

    car2.make = "Honda";
    car2.model = "Fit";
    car2.year = 2012;

    cout << car1.make << " " << car1.model << " "  << car1.year << endl;
    cout << car2.make << " " << car2.model << " "  << car2.year << endl;
}