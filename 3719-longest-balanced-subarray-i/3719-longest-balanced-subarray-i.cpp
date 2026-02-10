class Solution {
public:
    int longestBalanced(const vector<int>& nums) {
        
        int balance = 0;
        unordered_map<int, int> freq;

        auto add = [&](int num) {
            if(++freq[num] == 1)
                num % 2? ++balance: --balance;
        };

        auto del = [&](int num) {
            if(--freq[num] == 0)
                num % 2? --balance: ++balance;
        };

        const int lenght = ssize(nums);
        
        for(int len = ssize(nums); len > 1; --len) {
            balance = 0;
            freq.clear();

            for(int i = 0; i < len; ++i)
                add(nums[i]);
            
            if(balance == 0) return len;

            for(int i = 0; i < lenght - len; ++i) {
                del(nums[i]);
                add(nums[i + len]);
                if(balance == 0) return len;
            }
        }

        return 0;
    }
};