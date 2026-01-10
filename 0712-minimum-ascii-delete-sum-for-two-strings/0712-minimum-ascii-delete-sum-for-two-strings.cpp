class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size(), total = 0;
        vector<int> pre(m+1), cur(m+1);
        for(int i=1;i<=n;i++)
        {
            total += s1[i-1];
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    cur[j]=pre[j-1]+s1[i-1];
                }
                else
                {
                    cur[j] = pre[j]>cur[j-1] ? pre[j] : cur[j-1];
                }
            }
            pre=cur;
        }
        for(int i=0;i<m;i++)
        {
            total+=s2[i];
        }
        
        return total-2*pre[m];
    }
};