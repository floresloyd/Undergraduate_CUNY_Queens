#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;                                                                           // number of rings that the user inputs
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // close is the number of spots to move to the right to find the "closest" tower.
   // If n is odd, close = 1 and far = 2.  If n is even, the reverse.
   int close = (n % 2 == 0 ? 2 : 1), far = (n % 2 == 0 ? 1 : 2);
   int from = 0, to = close, candidate = 1, move = 0;
   
   // Initialize the towers
   for(int i = n + 1; i >= 1; i--)
      t[0].push_back(i);
      
   t[1].push_back(n+1);
   t[2].push_back(n+1);
   
   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      
      t[to].push_back(t[from].back()); // Move the ring from the "from" tower to the "to" tower.
      t[from].pop_back();
      
      if (t[(to+1) % 3].back() < t[(to+2) % 3].back()) // Determine the "from" tower (the smallest available ring that has not just been moved).
         from = (to+1) % 3;
      else
         from = (to+2) % 3;
      candidate = t[from].back();                      // The candidate is the ring on top of the "from" tower.
         
      if (t[(from+close) % 3].back() > candidate) // Determine the "to" tower.
         to = (from+close) % 3;                   // (the closest tower on which the ring can be placed)
      else
         to = (from+far) % 3;
   }
   return 0;
}