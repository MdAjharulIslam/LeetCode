class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        sort(capacity.begin(),capacity.end());
        int apple_sum = 0;
        int box_sum = 0;

        for(int i : apple){
            apple_sum += i;
        }

        int ans = 0;
        for(int i = capacity.size() - 1; i >= 0; i--){
            box_sum += capacity[i];
            ans++;
            if(apple_sum <= box_sum){  
                break;
            }
        }
        return ans;

        
    }
};