class Solution:
    # The idea is to do a DFS and look for back-edges, which indicate loops
    # When we find a back-edge, look at the length of the loop
    # If the loop has at least 4 cells, then return true
    BLACK = 0
    WHITE = 1
    
    def dfs(self, r, c, grid, color, dist):
        color[r][c] = Solution.BLACK

        m = len(grid)
        n = len(grid[0])
        
        neigh = ((r, c-1), (r, c+1), (r-1, c), (r+1, c))
        for nr, nc in neigh:
            if (nr < 0 or nr >= m or nc < 0 or nc >= n): continue
            if (grid[nr][nc] != grid[r][c]): continue  
            if (color[nr][nc] == Solution.BLACK):
                if (dist[nr][nc] - dist[r][c] >= 3): 
                    return True
                else: 
                    continue
            
            dist[nr][nc] = dist[r][c]+1
            if (self.dfs(nr, nc, grid, color, dist)): return True        
        return False
    
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        color = []
        for i in range(m): color.append([Solution.WHITE]*n)
            
        dist = []
        for i in range(m): dist.append([1]*n)
            
        for i in range(m):
            for j in range(n):
                if (color[i][j] == Solution.BLACK):
                    continue
                
                if (self.dfs(i, j, grid, color, dist)):
                    return True
        
        return False
