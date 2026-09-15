class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> rev[n];
        vector<int> inDeg(n, 0);
        vector<int> safe;
        queue<int> q;
        for(int i = 0; i < n; i++)
            for(auto it: graph[i]) {
                rev[it].push_back(i);
                inDeg[i]++;
            }
        for(int i = 0; i < n; i++)
            if(inDeg[i] == 0)
                q.push(i);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: rev[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0)
                    q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};