/**
 * Author: Loyd Flores
 * N Queens - Dynamic Memory Allocation 
 * Submitted to: Prof. Waxman & Prof. Kevin
 */

#include <iostream>
#include <cmath>
using namespace std;

bool ok (int q[], int c){               
    for (int i = 0; i < c; i++){
         if ((q[i] == q[c] || ((c - i) == abs(q[c] - q[i])))){      // Row, up & down diagonal test
             return false;                                          // if any pass it means we have a queen, we return false
         }
    }
    return true;                                                    // if there is no queen ok function returns true
}

// This function should return the number of solutions for the given board size
// (you don't need to print the solutions).
int nqueens(int n) {
    int number_of_solutions = 0;
    
    int *q = new int[n];  // pass in user's input as number of queens 
    
    int c = 0;                  // column variable 
    q[c] = 0;                   // row variable 

   while (c >= 0){              
        c++;                    // always starts at an inbound column
        if(c == n){             // if we go out of bounds it means: 
            number_of_solutions++;        // 1) we have a solution, add to the counter 
            c--;                // 2) go backwards to find another one
        }
        else{
            q[c] = -1;          // resets row and re-finds another placement for a queen
        }
    while (c >= 0){             
        q[c]++;                 // pushes row down
        if (q[c] == n){         // if our row goes out of bounds
            c--;                // we move a column back to backtrack
        }
        
        else if (ok(q,c)){      // if we find a solution we call print function 
            break;
        }
    }
    
   }
    // have to delete the same way we declare it 
    delete []q;
    return number_of_solutions;
}


int main() {
    int userInput;
    cout << "How many queens do you want to use? : ";
    cin >> userInput;
   int n = 12;
   for (int i = 1; i <= userInput; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}