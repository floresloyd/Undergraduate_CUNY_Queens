#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/// Disjoint set class
class DS {
    vector<int> sets;
    int numSets;
public:
    DS(int n){sets.resize(n, -1); numSets = n;}
    
    // Find set with path compression
    int find(int u){
        if (sets[u] < 0) return u;
        
        int s = find(sets[u]);
        sets[u] = s;
        return s;
    } // end-findSet
    
    void join(int u, int v){
        if (sets[u] >= 0) u = find(u);
        if (sets[v] >= 0) v = find(v);
        if (u == v) return;

        numSets--;
        if (sets[u] < sets[v]){
            sets[u] += sets[v];
            sets[v] = u;
        } else {
            sets[v] += sets[u];
            sets[u] = v;
        } //end-else
    } // end-join
    
    // Assume that "u" is a valid set head
    int size(int u){return -sets[u];}    
    int numberOfSets(){return numSets;}
    int numberOfElements(){return sets.size();}
}; // end-DS


void print(DS &ds){
    printf("Disjoint Set data structure has %d set(s), %d element(s)\n", ds.numberOfSets(), ds.numberOfElements());
    for (int i=0; i<ds.numberOfElements(); i++){
        printf("%c->%c, ", 'a'+i, 'a'+ds.find(i));
    }
    printf("\b\b \n");
    printf("----------------------------------------------------------\n");
} // end-print


int main(){
    DS ds(9); // 'a'-'i'    

    printf("Created 9 sets\n");
    print(ds);

    printf("union('b', 'e')\n");
    ds.join(1, 4); 
    print(ds);

    printf("union('a', 'd')\n");
    ds.join(0, 3);  
    print(ds);

    printf("union('a', 'b')\n");
    ds.join(0, 1);  
    print(ds);

    printf("union('h', 'i')\n");
    ds.join(7, 8); 
    print(ds);

    printf("union('c', 'f')\n");
    ds.join(2, 5); 
    print(ds);

    printf("union('c', 'a')\n");
    ds.join(2, 0); 
    print(ds);

    printf("union('g', 'h')\n");
    ds.join(6, 7); 
    print(ds);

    printf("union('g', 'd')\n");
    ds.join(6, 3); 
    print(ds);

    return 0;
}
