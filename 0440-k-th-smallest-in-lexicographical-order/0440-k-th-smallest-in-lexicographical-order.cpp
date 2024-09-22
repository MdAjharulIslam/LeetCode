class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k > 0){
            long next = curr + 1;
            long count = 0;
            long first = curr, last = next;

            while(first <= n){
                count += min((long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }

            if(k >= count){
                k -= count;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }
        return curr;
    }
};