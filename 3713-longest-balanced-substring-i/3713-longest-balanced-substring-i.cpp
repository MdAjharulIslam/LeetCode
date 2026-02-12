class Solution {
public:
    int longestBalanced(string s) {

        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++){
            int freq[26]={0};
            int distinct_count=0;
            int max_freq=INT_MIN;
            

            for(int j=i;j<n;j++){
                char c=s[j];
                if(freq[c-'a']==0){
                    distinct_count++;
                }
                freq[c-'a']++;
                max_freq=max(max_freq,freq[c-'a']);

                int window_length=j-i+1;

                if(window_length==max_freq*distinct_count){
                    ans=max(ans,window_length);
                }
              
            }
            
            
        }
        return ans;
        
    }
};