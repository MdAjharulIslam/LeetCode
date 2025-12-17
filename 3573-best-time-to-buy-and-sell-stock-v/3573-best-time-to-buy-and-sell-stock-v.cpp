#define NORMAL 0
#define BUYING 1
#define SHORTING 2
class Solution {
    const long long inf=-(1ll<<60);
    void print(vector<long long>& v){
        for(long long x:v){
            if(x==inf) cout << "NONE" << ' ';
            else cout << x << ' ';
        }
        cout << endl;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<long long>> dp(3, vector<long long>(k+1, inf));
        dp[NORMAL][0]=0;
        int N=prices.size();
        for(int x:prices){
            for(int i=k-1;i>=0;--i){
                if(dp[BUYING][i]!=inf) dp[NORMAL][i+1]=max(dp[NORMAL][i+1], dp[BUYING][i]+x);
                if(dp[SHORTING][i]!=inf) dp[NORMAL][i+1]=max(dp[NORMAL][i+1], dp[SHORTING][i]-x);
                if(dp[NORMAL][i]!=inf){
                    dp[BUYING][i]=max(dp[BUYING][i], dp[NORMAL][i]-x);
                    dp[SHORTING][i]=max(dp[SHORTING][i], dp[NORMAL][i]+x);
                }
            }
        }
        return *max_element(dp[NORMAL].begin(), dp[NORMAL].end());
    }
};