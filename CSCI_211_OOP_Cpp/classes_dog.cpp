#include <iostream>
#include <string>

using namespace std;

class Dog{
    private:
    string name;
    string breed;
    int age;
    
    public:
    // Constructor
    Dog(string n, string b, int a){
        name = n;
        breed = b;
        age = a;
    }
    // Getters and setters
    void setName(string n){
        name = n;
    }
    void setBreed(string b){
        breed = b;
    }
    void setAge(int a){
        age = a;
    }
    string getName(){
        return name;
    }
    string getBreed(){
        return breed;
    }
    int getAge(){
        return age;
    }
    //Bark function
    void bark(){
        cout << name << " barks!" << endl; 
    }
    
     friend bool operator== (Dog a, Dog b);
};
   
    

   bool operator==(Dog a, Dog b){
    if(
    a.getName() != b.getName() && 
    a.getBreed() != b.getBreed() &&
    a.getAge() != b.getAge()){
        return false;
    }
    return true;

}

int main(){
    Dog dog1 = Dog("Brownie","Askal",5);
    Dog dog2 = Dog("Choco", "Shitzu", 12);
    Dog dog3 = Dog("Choco", "Shitzu", 12);
    dog1.bark();
    dog2.bark();

    bool equal = dog3 == dog2; ;

    cout << equal;


}