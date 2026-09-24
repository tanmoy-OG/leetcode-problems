class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safe(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
            if (!vis[i])
                dfs(i, vis, pathVis, safe, graph);
        for (int i = 0; i < V; i++)
            if (safe[i] == 1)
                ans.push_back(i);
        return ans;
    }
    bool dfs(int i, vector<int>& vis, vector<int>& pathVis, vector<int>& safe,
             vector<vector<int>> &graph) {
        vis[i] = 1;
        pathVis[i] = 1;
        for (int j : graph[i]) {
            if (!vis[j]) {
                if (dfs(j, vis, pathVis, safe, graph))
                    return true;
            } else if (pathVis[j])
                return true;
        }
        safe[i] = 1;
        pathVis[i] = 0;
        return false;
    }
};