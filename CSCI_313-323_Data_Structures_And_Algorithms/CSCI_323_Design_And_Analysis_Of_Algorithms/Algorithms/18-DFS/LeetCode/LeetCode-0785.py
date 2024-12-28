class Solution:
    BLACK = 0
    WHITE = 1
    SETA = 0
    SETB = 1
    
    def dfs(self, u, G, color, set):
        color[u] = Solution.BLACK
        
        for v in G[u]:
            if color[v] == Solution.BLACK:
                if set[u] == set[v]: 
                    return False
            else:
                color[v] = Solution.BLACK
                set[v] = Solution.SETB if set[u] == Solution.SETA else Solution.SETA
                if self.dfs(v, G, color, set) == False: 
                    return False
        return True
    
    def isBipartite(self, graph: List[List[int]]) -> bool:    
        n = len(graph)
        color = [Solution.WHITE]*n
        set = [0]*n

        # Since the graph may be disconnected, we may have to start a new BFS
        # for each connected component. This is why we have this for loop
        for i in range(n):
            if color[i] == Solution.WHITE:
                # Start a DFS at node "i"
                set[i] = Solution.SETA
                if self.dfs(i, graph, color, set) == False:
                    return False
        return True
