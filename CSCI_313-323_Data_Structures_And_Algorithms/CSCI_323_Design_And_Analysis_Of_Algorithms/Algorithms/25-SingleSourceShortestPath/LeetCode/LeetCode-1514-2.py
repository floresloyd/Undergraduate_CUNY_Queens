class Solution:
    # Bellman-Ford algorithm. Gets TLE
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        cost = [0]*n
        cost[start] = 1.0

        for iter in range(0, n-1):
            for i in range(len(edges)):
                u = edges[i][0]
                v = edges[i][1]
                p = succProb[i]
                cost[v] = max(cost[v], cost[u]*p)  # Relax(u, v)
                cost[u] = max(cost[u], cost[v]*p)  # Relax(v, u)
        return cost[end]
