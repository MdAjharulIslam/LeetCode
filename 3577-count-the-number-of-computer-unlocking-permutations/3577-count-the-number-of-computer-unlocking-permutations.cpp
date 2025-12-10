class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        int n = complexity.size();
        int first = complexity[0];

        for(int i=1 ; i<n ; i++){
            if(complexity[i] <= first) return 0;
        }

        long long fact = 1;
        while(n>2){
            fact = (long long)(fact*(n-1)) % mod;
            n--;
        }
        return (int)fact;
    }
};