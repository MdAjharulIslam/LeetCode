class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;

        string a = s1, b = s1;

        swap(a[0], a[2]);
        if(a == s2) return true;

        swap(a[1], a[3]);
        if(a == s2) return true;

        swap(b[1], b[3]);
        if(b == s2) return true;

        return false;
    }
};