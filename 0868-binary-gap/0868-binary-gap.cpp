class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;      // position of last seen 1
        int pos = 0;        // current bit position
        int maxGap = 0;     // answer

        while (n > 0) {
            // Check if current bit is 1
            if (n & 1) {
                // If this is not the first 1
                if (prev != -1) {
                    // Calculate distance
                    maxGap = max(maxGap, pos - prev);
                }
                // Update previous position
                prev = pos;
            }

            // Move to next bit
            n >>= 1;
            pos++;
        }

        return maxGap;
    }
};