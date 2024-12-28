class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create DAG from prerequisites
        vector<vector<int>> G(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Edge: prerequisites[i][1]-->prerequisites[i][0]
        for (int i=0; i<prerequisites.size(); i++){
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        } // end-for
        
        queue<int> Q; // Queue of nodes with in-degree == 0
        for (int i=0; i<numCourses; i++)
            if (inDegree[i] == 0)
                Q.push(i);
    
        int numNodesTaken = 0;
        while (!Q.empty()){
            auto u = Q.front(); Q.pop();
            numNodesTaken++;
            
            // Reduce In-Degree of all vertices adjacent to u by 1
            for (auto v: G[u]){
                if (--inDegree[v] == 0)
                    Q.push(v);
            } // end-for
        } // end-while
        
        return numNodesTaken == numCourses;
    } // end-canFinish
};