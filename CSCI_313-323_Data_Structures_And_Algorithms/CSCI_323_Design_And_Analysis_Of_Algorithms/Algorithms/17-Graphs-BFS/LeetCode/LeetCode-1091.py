class Solution:
    # Do BFS starting from (0, 0)
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if (grid[0][0] != 0): return -1
        if (grid[n-1][n-1] != 0): return -1
        if (n == 1): return 1

        # <r, c, len>
        Q = []
        Q.append((0, 0, 1))
        grid[0][0] = 1     # Mark visited
        
        while (len(Q) > 0):
            r, c, length = Q[0]
            Q.pop(0)
            
            # Look at 8 neighbors
            neigh = ((r-1, c-1), (r-1, c), (r-1, c+1),
                     (r, c-1),             (r, c+1),
                     (r+1, c-1), (r+1, c), (r+1, c+1))
            
            for (nr, nc) in neigh:
                if (nr == n-1 and nc == n-1): return length+1
                if (nr<0 or nr>=n or nc<0 or nc>=n): continue
                if (grid[nr][nc] == 0):
                    grid[nr][nc] = 1
                    Q.append((nr, nc, length+1))
        
        return -1
