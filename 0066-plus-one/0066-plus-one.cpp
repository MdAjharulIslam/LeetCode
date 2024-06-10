class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i = 1;

        while (digits[n-i] == 9)
        {
            if ( i == n)
            {
                break;
            }
            digits[n-i] = 0;
            
            i++;
        }
        
        digits[n-i] ++;

        if (digits[0] == 10)
        {
            digits.insert(digits.begin(), 1);
            digits[1] = 0;
        }

        return digits;
        
    }
};