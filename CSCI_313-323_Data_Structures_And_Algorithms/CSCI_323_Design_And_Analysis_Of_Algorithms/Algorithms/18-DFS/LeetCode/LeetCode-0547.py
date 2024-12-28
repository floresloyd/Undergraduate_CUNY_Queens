class Solution:
    """
    Each time dfs finishes, we have traversed all nodes of a connected component
    """    
    BLACK = 0
    WHITE = 1
    
    def dfs(self, u, isConnected, color):
        color[u] = Solution.BLACK
        for v in range(len(isConnected[u])):
            if isConnected[u][v] and color[v] == Solution.WHITE:
                self.dfs(v, isConnected, color)    
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        color = [Solution.WHITE]*n
        
        noProvinces = 0
        for i in range(n):
            if color[i] == Solution.WHITE:
                noProvinces += 1
                self.dfs(i, isConnected, color)        
        return noProvinces
        