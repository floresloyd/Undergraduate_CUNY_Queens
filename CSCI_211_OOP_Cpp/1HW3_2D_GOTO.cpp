 /**
 * 8 Queens first version with go to and multiple lines for testing 
 */

#include <iostream>
using namespace std;

int main(){
    
    // Initialization of Variables 
    int q[8][8] = {0};                          // Declares a 2 dimension array of all zeroes | 0 means no queen placed
    int r;                                      // row variable
    int c = 0;                                  // column variable 
    int counter = 0;
    
    q[0][0] = 1;                                    // Placing the first queen
    nc:                                             
        c++;                                          // Next column function
        if (c == 8) goto print;                      // we print a solution if we exit the board
        r = -1;                                      // reset row function when moving columns
        
    nr:                                             
        r++;                                        // New row function
        if ( r == 8) goto backtrack;                // if we go down the board without placing a queen we backtrack
        
        for (int i=0; i<c; i++){                                                // ROW TEST 
            if (q[r][i] == 1) goto nr;
        }
    
    for (int i = 1; (r-i)>=0 && (c-i)>=0; i++){                               // UP DIAGONAL TEST 
        if (q[r-i][c-i]==1) goto nr;
    }
    
    for (int i=1; (r+i) <8 && (c-i)>=0; i++){                                 // DOWN DIAGONAL
        if (q[r+i][c-i]==1)goto nr;
    }
    
        q[r][c]=1;
        goto nc;
        
    backtrack:                                                                  // BACK TRACK FUNCTION 
    c--;                                                                        // when called we move a column back
    if (c==-1) return 0;                                                        // terminate the program if we leave the board all the way to the left 
    r=0;                                                                        // if not we reset row 
    while (q[r][c] != 1){                                                       // looks for the last 1 we placed | once it equals 1 we found it      
        r++;                                                                    // iterates through row
    }               
    q[r][c] = 0;                                                                // removes previously placed queen
    goto nr;                                                                    // and moves a row down (if we're on the last row we backtrack again)
    
    
    print:                                                                      // print statement 
        counter++;
        cout <<"Solution #" << counter << endl;
        
            for (int i = 0; i < 8; i++){                                        // NESTED FOR LOOP TO COUT SINCE IT'S A 2D ARRAY
                for (int j = 0; j < 8; j++){
                    cout<< q[i][j] <<" ";
                }
                cout<< endl;
            }
            cout << endl;
            goto backtrack;                                                     // Everytime we print we just backtrack and try to modify previous solution
                                                                                // we never clear the board and start from scratch, we build off where we left off
} // main FUNCTION



/*
Loyd Flores
CSCI 111 22A
Prof. Waxman & Prof. Abraham
*/
