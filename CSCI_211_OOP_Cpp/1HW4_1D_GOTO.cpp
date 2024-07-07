/**
 * HW 4 - one line for all testing  
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int q[8] = {};                          // Initializes board
    int c = 0;                              // initializing column variable to zero 
    int counter = 0;                        // counter for each result 
    
    q[c] = 0;                               // places first queen  (QUESTION WHY 0? = because we place the queen's location 0 index of the array or the first box, since its 1d)
                                            // uses index instead 

nc:
    c++;                                    // moves pointer to next column
    if ( c == 8 ) goto print;               // when c == 8 it means we found a solution, then we print
    q[c] = -1;                              // restarts our row position or index because we only visualize
    
nr: 
    q[c]++;                                 // increases value of box so in visualization it looks like were moving down 
    if ( q[c] == 8 ) goto backtrack;        // if we cant find a spot we backtrack

// =================== TESTS ====================
    for ( int i = 0; i < c; i++){
        if ((q[i] == q[c] || ((c - i) == abs(q[c] - q[i])))) goto nr;
        // row test           // diagonal test with absolute value 
 }
    
    goto nc;
    
backtrack:
    c--;                            // moves column back
    if ( c == -1) return 0;         // nr is q[c]++;
    goto nr;

print:
    cout << endl;
    counter++;
    cout << " Soulution #" << counter << endl;
    
        for (int i = 0; i < 8; i++){                // Prints out 1D array filled with solutions 
            cout << q[i] << " ";
        }
       
        cout << endl << endl;
                                                   // Prints out chess board
        for (int i = 0; i < 8; i++){               // Outer for loop is row
            for (int j = 0; j < 8; j++){           // inner loop is for the columns 
                if ( q[j] == i){
                    cout <<"1 ";                    // if there was a queen placed we print 1
                }                                   // ASK HOW WE PLACE QUEENS
                else{
                    cout <<"0 ";                    // if none then we don't print
                }
            }
        cout << endl;
        }
        goto backtrack;
}

/**
 * QUESTIONS
 * 1. How do we visualize the board if we only declare a 1Dimensional array
 * 2. I understand that q[c] is the row but how do we visualize it? How do we move along the board? (2D 8QUEENS u can know where q[r][c] is )
 * 3. how is a queen placed on the board? (1d was q[r][c] = 1;)
*/

/**
 * HOW IT DIFFERS FROM 1D 8QUEENS
 * 1. harder to read and visualize since we don't move through the board rather we reference through the indeces 
*/