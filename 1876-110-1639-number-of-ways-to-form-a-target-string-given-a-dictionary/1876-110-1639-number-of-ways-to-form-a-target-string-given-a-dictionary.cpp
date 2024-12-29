class Solution {
    vector<vector<long>> dp;
    vector<vector<int>> charCount;
    const int MOD = 1e9 + 7;

    long getWords(vector<string>& words, string& target, int i, int j) {
        if (j == target.size()) return 1;
        if (i == words[0].size() || words[0].size() - i < target.size() - j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long count = 0;
        if (charCount[target[j] - 'a'][i] > 0) {
            count += (charCount[target[j] - 'a'][i] * getWords(words, target, i + 1, j + 1)) % MOD;
        }
        count += getWords(words, target, i + 1, j) % MOD;

        return dp[i][j] = count % MOD;
    }

public:
    int numWays(vector<string>& words, string target) {
        int m = words[0].size(), n = target.size();
        dp = vector<vector<long>>(m, vector<long>(n, -1));
        charCount = vector<vector<int>>(26, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (string& word : words) {
                charCount[word[i] - 'a'][i]++;
            }
        }

        return getWords(words, target, 0, 0);
    }
};
