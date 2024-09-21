class Solution {
public:
    vector<int>ans;
    void dfs(int i,int n)
    {
        if(i>n)return;

        ans.push_back(i);
        for(int append=0;append<=9;append++)
        {
            int newNum = i*10 + append;
            if(newNum > n)return;
            dfs(newNum ,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;i++)
        {
            dfs(i,n);
        }
        return ans;
    }
};