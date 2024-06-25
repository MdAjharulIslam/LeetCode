class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n=words.size();
        string ax="";
        for(int i=0;i<n;i++)
        {
            char ay=words[i][0];
            ax=ax+ay;
        }
        if(s==ax)
        return true;
        else{
        return false;
        }
    }
};