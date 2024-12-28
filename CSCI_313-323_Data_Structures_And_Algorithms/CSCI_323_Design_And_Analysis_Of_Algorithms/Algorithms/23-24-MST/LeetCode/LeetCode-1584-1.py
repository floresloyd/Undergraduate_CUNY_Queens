class Solution:
    # Implement a Union/Find DS
    # Find set with path compression
    def find(self, sets, u):
        if (sets[u] < 0): return u
        
        s = self.find(sets, sets[u])
        sets[u] = s
        return s
    
    def union(self, sets, u, v):
        if u == v: return
        if (sets[u] < sets[v]):
            sets[u] += sets[v]
            sets[v] = u
        else:
            sets[v] += sets[u]
            sets[u] = v
            
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if (n <= 1): return 0

        dists = []
        
        for i in range(n-1):
            for j in range(i+1, n):
                dx = abs(points[i][0] - points[j][0])
                dy = abs(points[i][1] - points[j][1])                
                dists.append((dx+dy, i, j))
        
        # Sort the edges wrt their distance in increasing order
        dists.sort()
        
        # Walk over the edges & select the edges that do not create a cycle
        minCost = 0
        sets = [-1]*n
        for d, i, j in dists:
            s1 = self.find(sets, i)
            s2 = self.find(sets, j)
            if (s1 != s2):
                minCost += d
                self.union(sets, s1, s2)
        
        return minCost
        