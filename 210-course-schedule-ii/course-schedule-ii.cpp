class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> v;
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);
        for(int i = 0; i < numCourses; i++)
            if(!vis[i])
                if(dfs(i, adj, vis, pathVis, v))
                    return {};
        return v;
    }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& v) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis, v))
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        v.push_back(node);
        return false;
    }
};