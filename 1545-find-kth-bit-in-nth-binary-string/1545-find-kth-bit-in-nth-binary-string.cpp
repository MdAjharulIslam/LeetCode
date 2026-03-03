class Solution {
public:
    char findKthBit(int _, int k) {
        int pow = 2;
        while(k > pow) {
            pow *= 2;
        }
        pow /= 2;
        bool flip = false;
        while (k > 1) {
            if (k == pow) {
                return flip ? '0' : '1';
            }
            flip ^= 1;
            k = 2*pow - k;
            while( k < pow) {
                pow /= 2;
            } 
        }
        return flip ? '1' : '0';
    }
};