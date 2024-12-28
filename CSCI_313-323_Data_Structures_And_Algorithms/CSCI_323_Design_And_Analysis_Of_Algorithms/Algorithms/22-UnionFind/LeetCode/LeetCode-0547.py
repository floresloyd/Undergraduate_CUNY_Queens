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
    
    def join(self, u, v):
        if u == v: return
        if (self.sets[u] < self.sets[v]):
            self.sets[u] += self.sets[v]
            self.sets[v] = u
        else:
            self.sets[v] += self.sets[u]
            self.sets[u] = v

    # Assumes that "u" is a valid set head
    def size(self, u):
        return -self.sets[u]

    def noSets(self):
        count = 0
        for i in range(len(self.sets)):
            if self.sets[i] < 0:
                count += 1        
        return count

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)

        ds = DS(n)
        for i in range(n):
            for j in range(i+1, n):
                if isConnected[i][j]:
                    set1 = ds.find(i)
                    set2 = ds.find(j)
                    ds.join(set1, set2)
        return ds.noSets()
