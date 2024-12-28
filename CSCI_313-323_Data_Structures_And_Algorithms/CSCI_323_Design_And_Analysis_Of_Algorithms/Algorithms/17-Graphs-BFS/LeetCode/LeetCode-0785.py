class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        
        BLACK = 0
        WHITE = 1
        color = [WHITE]*n
        
        SETA = 0
        SETB = 1
        set = [SETA]*n
        
        # Since the graph may be disconnected, we may have to start a new BFS
        # for each connected component. This is why we have this for loop
        Q = []
        for i in range(n):
            if (color[i] == WHITE):
                # Start a BFS at node "i"
                color[i] = BLACK
                set[i] = SETA
                Q.append(i)
                
                while (len(Q) > 0):
                    u = Q.pop()
                    
                    for j in (range(len(graph[u]))):
                        v = graph[u][j]
                        
                        if (color[v] == BLACK):
                            if (set[u] == set[v]): return False
                        else:
                            color[v] = BLACK
                            set[v] = SETB if set[u] == SETA else SETB
                            Q.append(v)
        
        return True
