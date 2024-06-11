class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ') cnt++;
            else break;
        }
        int ans = 0;
        for(int i=s.length()-cnt-1;i>=0;i--){
            if(s[i]==' ') break;
            else ans++;
        }
        return ans;
    }
};