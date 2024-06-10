class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n=gain.size();
        
        int current_altitude = 0;
        
        int highest_altitude = 0;

        for (int i = 0; i < n; i++) {
            current_altitude += gain[i];
            
            highest_altitude = max(highest_altitude, current_altitude);
        }

        return highest_altitude;
    }
};