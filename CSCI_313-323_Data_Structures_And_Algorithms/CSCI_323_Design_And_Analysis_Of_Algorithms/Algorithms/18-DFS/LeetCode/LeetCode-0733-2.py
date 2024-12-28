class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        color = []
        for i in range(m): color.append([0]*n)
            
        # <row, column>
        S = []
        S.append([sr, sc])
        initialColor = image[sr][sc]
        image[sr][sc] = newColor
        color[sr][sc] = 1

        # Expand by DFS
        while len(S) > 0:
            r, c = S.pop()

            neighs = ((r, c-1), (r, c+1), (r-1, c), (r+1, c))
            for nr, nc in neighs:
                if nr<0 or nr==m or nc<0 or nc == n: continue
                if color[nr][nc] == 0 and image[nr][nc] == initialColor:
                    image[nr][nc] = newColor
                    color[nr][nc] = 1
                    S.append([nr, nc])
        return image
