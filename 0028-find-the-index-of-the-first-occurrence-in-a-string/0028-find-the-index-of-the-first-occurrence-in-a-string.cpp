class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        if (nLen == 0) {
            return 0;
        }

        for (int i = 0; i <= hLen - nLen; i++) {
            if (haystack.substr(i, nLen) == needle) {
                return i;
            }
        }

        return -1;
    }
};
