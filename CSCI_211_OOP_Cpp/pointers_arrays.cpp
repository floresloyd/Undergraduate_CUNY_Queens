#include <iostream>

using namespace std;

int main()
{
    int b[3][4] = {
        {2,3,5,6},
        {11,1,-1,7},
        {9,8,4,-2}
    };
    
    cout << "sizeof(b) = "<< sizeof(b) <<endl;
    cout << "sizeof(b[0]) = "<< sizeof(b[0]) <<  endl;
    cout << "sizeof(b+1) = " << sizeof(b+1)  << endl;
    cout << "sizeof (*(b+1)) = "<< sizeof (*(b+1))  << endl;
    cout << "sizeof(*b+1)  = " << sizeof(*b+1) <<  endl;
    
    cout << endl << endl;

    cout << "b = " << b << endl;
    cout << "b[0] = "<< b[0] << endl;
    cout << "b+1 = " << b+1 << endl;
    cout << "b[0]+1  = "<< b[0]+1 << endl;
    
    cout << endl << endl;
    
    cout << "b[0] + 1 = " << b[0] + 1 << endl;
    cout << "*b[0] = "<< *b[0] << endl;
    cout << "*(b+1) = "<< *(b+1) << endl;
    cout << "*(b+1) + 2 = " << *(b+1) + 2 << endl;
    cout << "*(*(b+1) + 2) = "<< *(*(b+1) + 2) << endl;
    
    cout << endl << endl;
    
    cout << "&b = "<< &b << endl;
    cout << "&b + 1 = "<< &b + 1 << endl;
    
    int x = 5;
    cout << sizeof(x);
    
}
