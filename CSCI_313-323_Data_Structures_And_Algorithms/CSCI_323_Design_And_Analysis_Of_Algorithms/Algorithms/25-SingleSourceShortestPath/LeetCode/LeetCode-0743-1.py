import heapq
class Solution:
    # Simply run Dijkra's shortest path algorithm & take the distance
    # to the farthest node as the solution
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Convert times to an adjacency list
        G = []
        for i in range(n+1): G.append([])
            
        for i in range(len(times)):
            G[times[i][0]].append([times[i][1], times[i][2]])

        # Run Dijktra's algorithm
        BLACK = 0
        WHITE = 2
        color = [WHITE]*(n+1)
        cost = [20000]*(n+1)

        cost[0] = 0      # There is no node with id=0. So, make its distance 0
        cost[k] = 0
        Q = [(0, k)]
        
        while (len(Q) > 0):
            # Get the node with the smallest distance
            currCost, u = heapq.heappop(Q)
            
            if color[u] == BLACK: continue  # Already processed
            
            color[u] = BLACK # Mark as processed

            for v, w in G[u]:            
                if (color[v] == BLACK): continue
                    
                newCost = currCost + w
                if (newCost < cost[v]):                    
                    cost[v] = newCost
                    heapq.heappush(Q, [newCost, v])

        for u in range(1, n+1):                    
            if (color[u] == WHITE):
                return -1
        
        return max(cost)        
        
        