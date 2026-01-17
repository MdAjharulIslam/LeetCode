class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long area=0, n=bottomLeft.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long minX=max(bottomLeft[i][0], bottomLeft[j][0]);
                long long maxX=min(topRight[i][0], topRight[j][0]);
                long long minY=max(bottomLeft[i][1], bottomLeft[j][1]);
                long long maxY=min(topRight[i][1], topRight[j][1]);

                if(minX<maxX && minY<maxY){
                    long long side=min((maxX-minX), maxY-minY);
                    area=max(area, side*side);
                }
            }
        }
        return area;
    }
};