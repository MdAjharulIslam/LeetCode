class Solution {
public:
unordered_set<int> ed(vector<int> &v,int n)
{
    unordered_set<int> e;
    v.push_back(1);
    v.push_back(n);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
    for(int j=i+1;j<v.size();j++)
    {
    e.insert(v[j]-v[i]);
    }
    }return e;
}
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> h=ed(hFences,m);
        unordered_set<int> v=ed(vFences,n);
        int ans=0;
        for(auto p:h)
        {
        if(v.contains(p))
        {
            ans=max(ans,p);
        }
    }
    if(ans==0)
    ans=-1;
    else
    ans=1LL*ans*ans%1000000007;
    return ans;
    }
};