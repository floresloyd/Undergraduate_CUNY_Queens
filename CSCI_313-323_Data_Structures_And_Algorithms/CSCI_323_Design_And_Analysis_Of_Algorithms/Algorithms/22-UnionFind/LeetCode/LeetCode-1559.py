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
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        ds = DS(m*n)
        
        for i in range(m):
            for j in range(n):
                # Look at two neighbors: Left, Up
                neigh = ((i, j-1), (i-1, j))
                
                for nr, nc in neigh:
                    if (nr >= 0 and nc >= 0 and grid[nr][nc] == grid[i][j]):
                        u = i*n+j
                        v = nr*n+nc
                        set1 = ds.find(u)
                        set2 = ds.find(v)
                        if (set1 == set2):
                            if (ds.size(set1) >= 4): return True
                        else:
                            ds.join(set1, set2)
        return False
