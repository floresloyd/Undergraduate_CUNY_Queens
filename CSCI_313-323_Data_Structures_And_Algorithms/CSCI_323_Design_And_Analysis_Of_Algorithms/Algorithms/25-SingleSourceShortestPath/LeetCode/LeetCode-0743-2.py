class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        """
        This time we run the Bellmann-Ford algorithm
        """        
        maxDist = 100*100
        cost = [maxDist]*(n+1)
        cost[0] = 0      # There is no node with id=0. So, make its distance 0
        cost[k] = 0
        
        for ite in range(n-1):
            for u, v, w in times:
                cost[v] = min(cost[v], cost[u]+w) # Relax(u, v)
        
        maxVal = max(cost)
        return -1 if maxVal == maxDist else maxVal
