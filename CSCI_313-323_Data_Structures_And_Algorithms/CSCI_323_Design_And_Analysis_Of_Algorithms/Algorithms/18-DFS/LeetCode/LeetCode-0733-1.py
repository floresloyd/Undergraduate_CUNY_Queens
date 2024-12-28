class Solution:
    def dfs(self, r, c, initialColor, newColor, image, color):
        m = len(image)
        n = len(image[0])
        
        image[r][c] = newColor
        color[r][c] = 1

        neighs = ((r, c-1), (r, c+1), (r-1, c), (r+1, c))
        for nr, nc in neighs:
            if nr<0 or nr==m or nc<0 or nc == n: continue
            if color[nr][nc] == 0 and image[nr][nc] == initialColor:
                self.dfs(nr, nc, initialColor, newColor, image, color)
    
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        color = []
        for i in range(m): color.append([0]*n)
        
        self.dfs(sr, sc, image[sr][sc], newColor, image, color)

        return image
