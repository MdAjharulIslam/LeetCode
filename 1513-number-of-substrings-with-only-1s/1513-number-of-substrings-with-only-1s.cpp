class Solution {
public:
    int numSub(string s) {
        int res  = 0;
      for(long i=0, j=0; i<=s.size(); ++i){
        if(i==s.size() || s[i]== '0'){
            res = (res+(i-j) * (i-j+1)/2)% 1000000007;
            j= i+1;
        }

      } 
      return res; 
    }
};