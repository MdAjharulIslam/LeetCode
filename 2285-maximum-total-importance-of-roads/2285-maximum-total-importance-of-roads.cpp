class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<int> connections(n,0); 
        for (const auto& road : roads){ 
            int j = road[0]; 
            int k = road[1];
            connections[j]++;
            connections[k]++;
        }
        sort(connections.begin(), connections.end()); 
        
        long long sum = 0;
        for (long long i = 0; i < n; i++){ 
    
            sum += static_cast<long long>(connections[i] * (i+1));
        }
        return sum;
    }
};