# Implement a Union/Find DS
# Find set with path compression
class DS:
    def __init__(self, n):
        self.sets = [-1]*n

    def find(self, u):
        if (self.sets[u] < 0): return u
        
        s = self.find(self.sets[u])
        self.sets[u] = s
        return s
    
    def union(self, u, v):
        if (self.sets[u] < self.sets[v]):
            self.sets[u] += self.sets[v]
            self.sets[v] = u
        else:
            self.sets[v] += self.sets[u]
            self.sets[u] = v
        
class Solution:
    #---------------------------------------------------------
    # Idea: Compute the number of connected components using 
    # a Union-Find DS. At the same time, count the number 
    # of extra connections, i.e., connections that create loops
    # Finally, simply compare the number of extra connections
    # and the number of connected components    
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        ds = DS(n)
        noExtraCables = 0
        noSets = n
        for i in range(len(connections)):
            s1 = ds.find(connections[i][0])
            s2 = ds.find(connections[i][1])
            if (s1 == s2): noExtraCables += 1 # loop
            else:
                ds.union(s1, s2)
                noSets -= 1
        
        noCablesNeeded = noSets-1
        if (noCablesNeeded > noExtraCables): return -1
        return noCablesNeeded
        