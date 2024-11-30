class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        // Step 1: Build the graph and calculate in-degree and out-degree
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Step 2: Find the starting node
        int startNode = pairs[0][0]; // Default starting node
        for (auto& [node, _] : graph) {
            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        // Step 3: Perform Hierholzer's Algorithm to find Eulerian path
        vector<int> path;
        stack<int> st;
        st.push(startNode);

        while (!st.empty()) {
            int u = st.top();
            if (!graph[u].empty()) {
                int v = graph[u].back();
                graph[u].pop_back(); // Remove edge u -> v
                st.push(v);
            } else {
                path.push_back(u);
                st.pop();
            }
        }

        // Step 4: Construct the result
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i + 1]});
        }
        return result;
    }
};
