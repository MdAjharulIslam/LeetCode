class Solution {
public:
    long long getAns(long long n){
        if(n<=1) return 0;
        return (n*(n-1))/2;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cnt = 1;
        long long ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]+1==prices[i-1]) cnt++;
            else{
                ans+=getAns(cnt);
                cnt = 1;
            }
        }
        ans+=getAns(cnt);
        ans+=n;
        return ans;
    }
};