
// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char from, char to,char third){
    if (n == 0) {       //BASE CASE 
        return;
    }

    towerOfHanoi(n - 1, from, third, to);
    cout << "Move disk " << n << " from rod " << from
         << " to rod " << to << endl;
    towerOfHanoi(n - 1, third, to, from);
}
 
// Driver code
int main(){
    int N;
    cout <<"Enter number of rings: ";
    cin >> N;
    
 
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}
 