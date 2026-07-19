class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] != 0) {
                continue;
            }
            color[i] = 1;
            queue<int> process;
            vector<bool> visited(graph.size(), false);
            process.push(i);
            while (!process.empty()) {
                int node = process.front();
                process.pop();
                if (visited[node]) {
                    continue;
                }
                visited[node] = true;
                for (const int& i : graph[node]) {
                    if (color[i] == color[node]) {
                        return false;
                    }
                    color[i] = 3 - color[node];
                    process.push(i);
                }
            }
        }
        return true;
    }
};