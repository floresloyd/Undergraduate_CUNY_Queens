class Solution:
    BLACK = 0
    GRAY = 1
    WHITE = 2

    #--------------------------------------------------------------
    # Do DFS & look for back edges (loops)
    #
    def dfs(self, u, G, color):
        color[u] = Solution.GRAY
        
        for v in G[u]:
            if (color[v] == Solution.GRAY):
                return False         # Backedge
            if (color[v] == Solution.WHITE):
                if (not self.dfs(v, G, color)):
                    return False

        color[u] = Solution.BLACK        
        return True

    #-----------------------------------------------------------------
    # Convert the prerequisites to a graph. 
    # Then do a DFS & look for a backedge (llop) 
    #                
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Create DAG from prerequisites
        G = []
        for i in range(numCourses): G.append([])
            
        for i in range(len(prerequisites)):
            G[prerequisites[i][1]].append(prerequisites[i][0])
                
        # Do DFS & look for cycles (back edges)        
        color = [Solution.WHITE]*numCourses
        print(color)
        
        for u in range(numCourses):
            if (color[u] == Solution.WHITE):
                if (not self.dfs(u, G, color)):
                    return False
        
        return True
        