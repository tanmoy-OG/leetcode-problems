class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);
        for(int i = 0; i < numCourses; i++)
            if(!vis[i])
                if(dfs(i, adj, vis, pathVis))
                    return false;
        return true;
    }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
};