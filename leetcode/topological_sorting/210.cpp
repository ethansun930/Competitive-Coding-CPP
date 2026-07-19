class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> req(numCourses);
        vector<int> edges(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            req[prerequisites[i][1]].push_back(prerequisites[i][0]);
            edges[prerequisites[i][0]]++;
        }
        queue<int> process;
        for (int i = 0; i < numCourses; i++) {
            if (edges[i] == 0) {
                process.push(i);
            }
        }
        int count = 0;
        vector<int> path;
        while (!process.empty()) {
            int node = process.front();
            process.pop();
            path.push_back(node);
            count++;
            for (int i : req[node]) {
                edges[i]--;
                if (edges[i] == 0) {
                    process.push(i);
                }
            }
        }
        if (count != numCourses) {
            return {};
        } else {
            return path;
        }
        return {};
    }
};