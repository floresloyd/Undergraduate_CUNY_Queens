#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> tower[3]; // Initializes the 3 vector towers
    int ringCount;
    int candidate = 1;
    int to = 1;
    int from = 0;
    int moveCounter = 0;

    cout << "Please enter an ODD number of rings to move: ";
    cin >> ringCount;
    cout << endl;

        // rings = 3
    /**
     * Initializes the tower's values and base value
    */
    for (int i = ringCount+1; i >= 1; i--){
        tower[0].push_back(i);              // Adds number of rings to Tower[0] / Tower A
    }

    tower[1].push_back(ringCount+1);
    tower[2].push_back(ringCount+1);

    while (tower[1].size() < ringCount+1){  // Program will complete if all rings are placed in tower[1] or Tower B        
            //cout << tower[0].back() << " " << tower[1].back() << " " << tower[2].back() << endl;
            cout << "Move #" << ++moveCounter 
             << " Transfer ring " << candidate 
             << " from tower " << char(from+65) 
             << " to tower " << char(to+65)<<endl;
            // tower[0].push_back(ring1)
            tower[to].push_back(tower[from].back());    // moves first disk from tower a to b
            tower[from].pop_back();                       // removes the last disk you moved

            // Determining next "from" tower
            if(tower[(to+1)%3].back() < tower[(to+2)%3].back()){  
                from = (to+1) % 3; 
            }
            else{ 
                from = (to+2) % 3; 
            }
    
            candidate = tower[from].back();

            // Determining next "to" tower
            if(ringCount % 2 == 1){              // Determinant if EVEN or ODD
                if(tower[(from+1)%3].back() > candidate){
                    to = (from+1)%3;
                }
                else{
                    to = (from+2)%3;
                } 
            }
            else{
                if(tower[(from+2)%3].back() > candidate){
                    to = (from+2)%3;
                }
                else{
                    to = (from+1)%3;
                }
            }
    }  
    //cout << tower[0].back() << " " << tower[1].back() << " " << tower[2].back() << endl; 
    return 0; 
}
