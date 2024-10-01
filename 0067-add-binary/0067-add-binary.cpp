class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }

        return result;
    }
};
