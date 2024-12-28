class Solution:
    #-----------------------------------------------------
    # Simply do BFS & find connected components
    #
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)

        BLACK = 0
        WHITE = 1
        color = [WHITE]*n
        
        noProvinces = 0
        for i in range(n):
            if (color[i] == BLACK): continue

            noProvinces += 1
            color[i] = BLACK
            Q = []
            Q.append(i);
            while (len(Q) > 0):
                u = Q.pop(0)
                
                for v in range(len(isConnected[i])):
                    if (isConnected[u][v] and color[v] == WHITE):
                        color[v] = BLACK
                        Q.append(v)
        
        return noProvinces
