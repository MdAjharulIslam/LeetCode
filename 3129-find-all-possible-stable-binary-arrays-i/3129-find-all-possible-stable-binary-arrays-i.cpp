constexpr int mod=1e9+7;
long long dp[201][201][2];// ( cnt 0, cnt 1, last is 0/1)
class Solution {
public:
    static int numberOfStableArrays(int zero, int one, int limit) {
        for(int i=0; i<=zero; i++)
            memset(dp[i], 0, (one+1)*2*sizeof(long long));
        const int lim0=min(zero, limit), lim1=min(one, limit);
        for(int i=0; i<=lim0; i++) dp[i][0][0]=1;
        for(int i=0; i<=lim1; i++) dp[0][i][1]=1;
        for(int i=1; i<=zero; i++){
            for(int j=1; j<=one; j++){
                long long& dp0=dp[i][j][0];
                dp0=dp[i-1][j][0]+dp[i-1][j][1];
                if (i>limit) dp0+=mod-dp[i-limit-1][j][1];
                if (dp0>=mod) dp0%=mod;

                long long& dp1=dp[i][j][1];
                dp1=dp[i][j-1][1]+dp[i][j-1][0];
                if (j>limit) dp1+=mod-dp[i][j-limit-1][0];
                if (dp1>=mod) dp1%=mod;
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};