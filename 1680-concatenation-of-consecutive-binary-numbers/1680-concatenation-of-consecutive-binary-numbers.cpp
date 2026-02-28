class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long int ans = 0;
        
        
        const int MOD = 1e9 + 7;
        
        
        long long int bits = 0;
        
        
        for (int i = 1; i <= n; ++i) {
          
            if ((i & (i - 1)) == 0)
                ++bits; 
            ans = ((ans << bits) | i);
            
       
            ans %= MOD;
        }
        
        return ans;
    }
};