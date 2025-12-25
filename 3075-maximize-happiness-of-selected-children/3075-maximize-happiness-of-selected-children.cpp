class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();

        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int i=n-1;
        int k1 = 0;

        while(k1 < k){
            if(happiness[i]-k1 >= 0){
                ans += happiness[i]-k1;
            }
            i--;
            k1++;
        }
        return ans;
    }
};