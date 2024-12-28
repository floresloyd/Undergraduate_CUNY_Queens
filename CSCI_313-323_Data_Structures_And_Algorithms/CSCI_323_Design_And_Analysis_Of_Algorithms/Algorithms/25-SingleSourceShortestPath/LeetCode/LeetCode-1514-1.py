import heapq
class Solution:
    #----------------------------------------------------------------
    # The version using priority_queue
    #
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        G = []
        for i in range(n): G.append([])

        for i in range(len(edges)):
            G[edges[i][0]].append((edges[i][1], succProb[i]))
            G[edges[i][1]].append((edges[i][0], succProb[i]))
        
        # Run Dijkstra's algo with relaxation: cost[u, v] = weight(u, w)*cost[w, v]
        BLACK = 0
        WHITE = 1
        color = [WHITE]*n
        cost = [0]*n
        cost[start] = 1.0
        
        # heapq only supports min-heap. 
        # To emulate a max-heap, invert the keys values by negation
        Q = [(-1.0, start)]   
        
        while (len(Q) > 0):
            # Get the vertex with the highest probability
            currCost, u = heapq.heappop(Q)
            currCost *= -1                          # Invert again for correct processing
            
            if (u == end): return currCost
            if (color[u] == BLACK): continue    # Already processed
            color[u] = BLACK                    # Mark as processed
            
            # Perform relaxation for "u"s neighbors
            for v, w in G[u]:
                newCost = currCost*w
                if (newCost > cost[v]):
                    cost[v] = newCost
                    heapq.heappush(Q, (-newCost, v))
        
        return 0.0
