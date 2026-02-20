class Solution {
public:
    string makeLargestSpecial(string s) {
      
      // This is the array where we store strings for concating sub-call
      vector<string>res;

      int sum =0;
      int start=0;
      
     // When size is zero this loop certainly won't work and call will automatically will be returned

      for(int i=0;i<s.length();i++){
         sum+=s[i]=='1'?1:-1;

         if(sum==0){
            string r =s.substr(start+1,i-start-1);
            res.push_back("1"+makeLargestSpecial(r)+"0");
            start=i+1;
         }
      }

      // whenever a call comes back

      sort(res.begin(),res.end(),greater<string>());

      string ans="";

      for(auto s:res){
          ans+=s;
      }

      return ans;
    }
};