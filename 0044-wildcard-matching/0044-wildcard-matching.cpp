class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        // vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        
        vector<bool> prev(m+1);
        //Initially prev is for n=0
        prev[0]=true;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            prev[i]=flag;
        }
        vector<bool> curr(m+1);
        
        
        for(int i=1;i<=n;i++)
        {
            curr[0]=false;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[j-1]=='*')
                    curr[j] = prev[j] || curr[j-1];
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};