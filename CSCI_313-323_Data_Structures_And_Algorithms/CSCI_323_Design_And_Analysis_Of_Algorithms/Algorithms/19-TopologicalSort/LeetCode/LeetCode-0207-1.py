class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Create DAG from prerequisites
        G = []
        for i in range(numCourses): G.append([])
        inDegree = [0]*numCourses
        
        # Edge: prerequisites[i][1]-->prerequisites[i][0]
        for i in range(len(prerequisites)):
            G[prerequisites[i][1]].append(prerequisites[i][0])
            inDegree[prerequisites[i][0]] += 1

        Q = []  # Queue of nodes with in-degree == 0
        for i in range(numCourses):
            if inDegree[i] == 0:
                Q.append(i)
    
        numNodesTaken = 0
        while len(Q) > 0:
            u = Q.pop(0)
            numNodesTaken += 1
            
            # Reduce In-Degree of all vertices adjacent to u by 1
            for v in G[u]:
                inDegree[v] -= 1
                if inDegree[v] == 0:
                    Q.append(v)        
        return numNodesTaken == numCourses
        