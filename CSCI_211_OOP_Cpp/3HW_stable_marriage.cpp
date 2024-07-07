/**
 * @Author - Loyd Flores
 * CS211 - HW #6 Stable Marriage
 * Prof. Waxman
 * Prof. Abraham
 */

#include <iostream>
using namespace std;

bool ok (int q[], int c){
    static int mp[3][3] = { {0,2,1},
                            {0,2,1},
                            {1,2,0} };
                            
    static int wp[3][3] = { {2,1,0},
                            {0,1,2},
                            {2,0,1} };
                            
    for (int i = 0; i < c; i++){
     if(q[i] == q[c]) return false;     // Row test to see if selected woman was already chosen


//         CMtoNW      CMtoCW      &&    NWtoCM        NWtoNM 
     if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])  return false; 
      
//           NMtoCW           NMotNW    &&    NWtoNM         NWtoCM
     else if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
    
    }     
    return true;    // if all passes we break out of the loop 
}

/**
 * Simple print function
 * @param q - array to be taken in
 * @var solution - solution counter 
 */
void print(int q[]){                      
    static int solution = 1;
    cout << "Solution #" << solution++ <<":" <<endl << "Man  " << " Woman" << endl;
    for(int i = 0; i<3; i++){
        cout << i << "\t" << q[i];
        cout << endl;
    }
}

int main(){
    int q[3];               // Declares initial array of 3 boxes
    int c = 0;              // Column variable = Man
    q[c] = 0;               // Value within the box = Woman
    
    while (c >= 0){         // While column is greater or equal to zero codeblock will run
        c++;                // Move to next box or man
        if(c == 3){         
            print(q);       // Print solution out and move column back to find another solution 
            c--;            // backtrack
        }
        else q[c] = -1;     // resets value of q[c] or woman
        while(c >= 0){
            q[c]++;         
            
            if(q[c] == 3){  
                c--;        // Backtrack if wechave not found a solution       
            }
            else if(ok(q,c))    // Test if solution is valid
            break;
        } 
    }
    return 0;  
}