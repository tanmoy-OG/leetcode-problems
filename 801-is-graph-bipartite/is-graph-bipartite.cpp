class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
            if(vis[i] == -1 && !dfs(i, 0, graph, vis))
                return false;
        return true;
    }
    bool dfs(int i, int col, vector<vector<int>>& graph, vector<int>& vis) {
        vis[i] = col;
        for(auto it: graph[i]) {
            if(vis[it] == -1 && !dfs(it, !col, graph, vis))
                return false;
            else if(vis[it] == vis[i])
                return false;
        }
        return true;
    }
};