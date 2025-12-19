class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < meetings.size(); i++) {
            int x = meetings[i][0], y = meetings[i][1], time = meetings[i][2];
            graph[x].push_back({y, time});
            graph[y].push_back({x, time});
        }

        vector<int> visited(n, INT_MAX); visited[0] = visited[firstPerson] = 0;
        queue<pair<int, int>> q; q.push({0, 0}); q.push({firstPerson, 0});
        while(!q.empty()) {
            auto [node, startTime] = q.front(); q.pop();
            if(visited[node] < startTime) continue;

            for(auto& nei : graph[node]) {
                int child = nei.first, time = nei.second;
                if(time >= startTime && time < visited[child]) {
                    q.push({child, time});
                    visited[child] = time;
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++) if(visited[i] != INT_MAX) res.push_back(i);
        return res;
    }
};