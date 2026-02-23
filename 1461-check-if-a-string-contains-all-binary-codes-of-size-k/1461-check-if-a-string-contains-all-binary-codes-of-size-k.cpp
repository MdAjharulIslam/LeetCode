class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mp;
        string a="";
        if(k>s.size())return false;
        for(int i=0;i<k;i++){
            a+=s[i];
        }
        mp[a]++;
        for(int i=k;i<s.size();i++){
            a.erase(0, 1); 
            a+=s[i];
            mp[a]++;
        }if(mp.size()>=pow(2,k))return true;
        return false;
    }
};