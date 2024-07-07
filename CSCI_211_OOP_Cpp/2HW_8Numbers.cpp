/*
Loyd Flores
CSCI 111 22A
Homework 5 - 8 Numbers on a Cross
Prof. Waxman & Prof. Abraham
*/

#include <iostream>
#include <cmath>
using namespace std;

bool ok (int q[], int c){

    static int adjacent[8][5] = {           // Initializes helper array that checks adjacent boxes and sets flags 
    {-1},                                   // Box 0            // These are the boxes that are adjacent to the specific box 
    {0, -1},                                // Box 1
    {0, -1},                                // Box 2
    {0, 1, 2, -1},                          // Box 3
    {0, 1, 3, -1},                          // Box 4 
    {1, 4, -1},                             // Box 5
    {2, 3, 4, -1},                          // Box 6 
    {3, 4, 5, 6 ,-1}                        // Box 7
    };
    
    for (int i = 0; i < c; i++){    // goes through all previous boxes to see if the number was used. It only checks up to c, we only look backwards
        if (q[i] == q[c]){          // if it is returns false 
            return false;           // If it finds a number that is used it returns us to the main function [line 67]
        }
    }
                            
    for (int i = 0; adjacent[c][i] != -1; i++){     // only checking adjacent boxes must not be consecutive 
         if (abs(q[c]-q[adjacent[c][i]]) == 1)      // checks adjacent boxes to see th conditions (q[c] and q[adjacent[c][i] holds a value)
        return false;                               // if it fails we return false and get out of the if statement and program jumps back to main [line 67]
    }                                               // c = current boxes' list of other boxes that are adjacent to it
                                                    // i = specific value in the adjacent box
    return true;
}


void print_solution (int q[]){
    static int solution_counter = 1;                    // declare static variable so it it can be called globally 
    cout << "Solution # " << solution_counter << endl;
    cout << "   " <<q[0] << " " << q[1] << endl;
    cout << " " <<q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << "   " << q[6] << " " << q[7] << " " << endl << endl;
    solution_counter++;
}
    

int main(){
    int q[8];           // Initializing the 8 boxes for the problem                   
    int c = 0;          // Initializes the column variable so we start at box 0
    q[c] = 0;           // we place the first number = 1, on box 0 to start the problem
    
    while (c >= 0 ){    // Program will run as long as column != -1
        c++;            // Next box
   
        if (c == 8){
            print_solution(q);         // If we c=8 it means we've found a solution, hence we call print function
            c--;                       // backtrack to box 7
        }
        else{
            q[c] = 0;                  //reinstates value to zero 
        }
            while(c >= 0){
                q[c]++;                 // increments value within the box 
                    if(q[c] == 8){   
                        c--;
                    }
                    else if (ok(q,c))  // calls okay function    
                    break;
            }
    }
    return 0;
}  
    
    

