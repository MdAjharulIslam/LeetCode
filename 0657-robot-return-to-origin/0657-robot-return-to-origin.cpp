class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() & 1) return false;
        unordered_map<char, int> f;
        for (char c : moves) f[c]++;

        return f['U'] == f['D'] && f['L'] == f['R'];
    }
};