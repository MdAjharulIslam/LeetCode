class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> criticalPoints;
        for (const auto& building : buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            criticalPoints.emplace_back(left, -height);  
            criticalPoints.emplace_back(right, height);  
        }
        
        
        sort(criticalPoints.begin(), criticalPoints.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        
        multiset<int> activeHeights{0};
        vector<vector<int>> skyline;
        int previousMaxHeight = 0;
        
        
        for (const auto& point : criticalPoints) {
            int position = point.first;
            int heightChange = point.second;
            
            
            if (heightChange < 0) {
                activeHeights.insert(-heightChange);
            } 
            
            else {
                activeHeights.erase(activeHeights.find(heightChange));
            }
            
            
            int currentMaxHeight = *activeHeights.rbegin();
            
            
            if (currentMaxHeight != previousMaxHeight) {
                skyline.push_back({position, currentMaxHeight});
                previousMaxHeight = currentMaxHeight;
            }
        }
        
        return skyline; 
    }
};