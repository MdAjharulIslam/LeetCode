class Solution {
public:
    int countPalindromicSubsequence(string s) {
    int ans=0;
    vector<int>v(26,-1);
    for(int i=s.length()-1;i>=0;i--) 
    {
        if(v[s[i]-'a']==-1) v[s[i]-'a']=i;
    }
    for(int i=0;i<s.length();i++)
    {
        if(v[s[i]-'a']-i>1)
        {
            unordered_set<char>st;
            for(int j=i+1;j<v[s[i]-'a'];j++) st.insert(s[j]);
            ans+=st.size();
            v[s[i]-'a']=-1;
        }
    }
    return ans;
}   
    
};