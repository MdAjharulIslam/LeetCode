class Solution {
    int maxLen(vector<int>& bars) {
        int count = 2; 
        int length = 2;
        int n = bars.size();
        
        for(int i = 1; i < n; ++i) {
            if(bars[i] - bars[i-1] == 1) count++;
            else count = 2;
            length = max(length, count);
        }
        return length;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int hGap = maxLen(hBars);
        int vGap = maxLen(vBars);
    
        int side = min(hGap, vGap);
        
        return side*side; 
    }
};