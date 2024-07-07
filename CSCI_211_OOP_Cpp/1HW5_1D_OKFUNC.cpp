/*
Loyd Flores
CSCI 111 22A
Homework 4 - 1D 8 Queens without Go-To Statements
Prof. Waxman & Prof. Abraham
*/

/**
 * @brief no go to statements
 */

#include <iostream>
#include <cmath> 

using namespace std;

/*
*   ok function returns a boolean function to determine if we can place a queen or not
*   int q[] -> an array 
*   int c   -> another integer which stands for column 
*/
                
bool ok (int q[], int c){                                                      
    for (int i = 0; i < c; i++){
         if ((q[i] == q[c] || ((c - i) == abs(q[c] - q[i])))){      // Row, up & down diagonal test
             return false;                                          // if any pass it means we have a queen, we return false
         }
    }
    return true;                                                    // if there is no queen ok function returns true
}

/*
* Task function that prints solution counter, solution, chess board
* Only takes in q[] as an argument 
*/

void printsol (int q[]){                                              
    static int solution_counter = 1;                            // static so we can access it globally if we don't declare it static it will never change 
    cout <<"Soulution # " << solution_counter++ << endl;
    
    for (int i = 0; i < 8; i++){
        cout << q[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ( q[j] == i){
            cout <<"1 ";
            }
            else{
            cout <<"0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
        

int main(){
    
    int q[8] = {};              // initializes chess board
    int c = 0;                  // column variable 
    q[c] = 0;                   // row variable 

   while (c >= 0){              // I will run as long as "C" is greater than or equal to 0 (AS LONG AS ITS NOT NEGATIVE)   
        c++;                    // makes the first move since we placed first queen in 0,0 | otherwise it just moves us to the next column 
        if(c == 8){             // if we go out of bounds it means (board is 0-7, 8 means we exited the board)
            printsol(q);        // 1) we have a solution
            c--;                // 2) go backwards to find another one // BACKTRACKING
        }
        else{                   // WHEN WE PLACE A QUEEN AND C!=8 THIS RUNS AND BASICALLY JUST RESETS OUR ROW 
            q[c] = -1;          // every time we move to next column we set it to -1 to test the values 
        }
    while (c >= 0){             
        q[c]++;                 // pushes row down
        if (q[c] == 8){         // if our row goes out of bounds
            c--;                // we move a column back to backtrack 
        }
        
        else if (ok(q,c)){      // we call the okay function to check if we can place a queen here // if true we place one down and then next column
            break;
        }
    }
    
   }
    return 0;
}

/**
 * WHEN PLACING A QUEEN THIS IS WHAT HAPPENS 
 * C++       -> we move to next column
 * q[c]++    -> we check row 0-7 where we can place a queen 
 * ok(q,c)   -> every time we move down we call the ok(q,c) to check if we can place. If it returns false  
 * q[c]++    -> we just move down the row 
 * ok(q,c)   -> if it returns true we place a queen or we c++ and move to the next column 
 * 
 * 
 * WHEN BACKTRACKING 
 * C--      -> moves back a row 
 * q[c]++   -> move the last piece forward
 * ok(q,c);
 * 
 * 
*/

/**
 * QUESTIONS
 * 1. how does backtracking happen in 1D WITH OKAY FUNC? I understand you go c-- but where do you go and find the previous queen placed and remove it?
 * 2. 
*/