class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int best = 0;
        int l = 0;

        for(int i=0; i<(int)s.size(); i++){
            unsigned char ch = s[i];

            if (last[ch] >= l) {
                l = last[ch] + 1;
            }

            last[ch] = i;
            best = max(best, i - l + 1);
        }
        return best;
    }
};