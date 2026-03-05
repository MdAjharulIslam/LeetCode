class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count = 0;
        for(int i =0; i< n; i++){
            count += (s[i]^i) & 1;
        }
        return min(count , n-count );
    }
};