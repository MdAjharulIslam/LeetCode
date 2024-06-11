class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result;
        result=s;
        int n=indices.size();
        int m=s.size();
        for(int i=0;i<n;i++){
            result[indices[i]]=s[i];
            
        } return result;
    }
};