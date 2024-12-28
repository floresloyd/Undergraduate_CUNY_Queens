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
        if (self.sets[u] < self.sets[v]):
            self.sets[u] += self.sets[v]
            self.sets[v] = u
        else:
            self.sets[v] += self.sets[u]
            self.sets[u] = v

    # Assumes that "u" is a valid set head
    def size(self, u):
        return -self.sets[u]

    
class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        """
        For a path to exist between start & end, they have to be
        on the same connected component, i.e., same set
        """
        ds = DS(n)
        
        for u, v in edges:
            set1 = ds.find(u)
            set2 = ds.find(v)
            if set1 != set2:
                ds.join(set1, set2)
        return ds.find(start) == ds.find(end)
        