class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        if(s1.length()>s2.length())
        {
            return false;
        }
        for(int i=0;i<s2.length()-s1.length()+1;i++)
        {
            string p=s2.substr(i,s1.length());
            
            sort(p.begin(),p.end());
            if(p==s1)
            {
                
                return true;
            }
        }
        return false;
    }
};