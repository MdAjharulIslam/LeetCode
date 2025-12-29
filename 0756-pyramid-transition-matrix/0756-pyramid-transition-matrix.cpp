class Solution {
public:
    bool find(string level,
              unordered_map<string, vector<char>>& allowed,
              unordered_map<string, int>& isValid) {

        // Base case: only one pair left
        if (level.size() == 2) {
            return isValid[level] != 0;
        }

        queue<string> q;

        // Build next level using BFS
        for (int i = 0; i < level.size() - 1; i++) {
            string pair = "";
            pair += level[i];
            pair += level[i + 1];

            // Invalid pair -> cannot form pyramid
            if (isValid[pair] == 0) return false;

            if (i == 0) {
                // Initialize queue for first pair
                for (char c : allowed[pair]) {
                    string next = "";
                    next += c;
                    q.push(next);
                }
            } else {
                // Extend existing partial strings
                while (!q.empty() && q.front().size() == i) {
                    string prev = q.front();
                    q.pop();

                    for (char c : allowed[pair]) {
                        string validate = "";
                        validate += prev[i - 1];
                        validate += c;

                        if (isValid[validate] != 0) {
                            q.push(prev + c);
                        }
                    }
                }
            }
        }

        // Recursively try all possible next levels
        while (!q.empty()) {
            string nextLevel = q.front();
            q.pop();

            if (find(nextLevel, allowed, isValid)) {
                return true;
            }
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        unordered_map<string, vector<char>> validFor;
        unordered_map<string, int> isValid;

        // Preprocess allowed transitions
        for (string& s : allowed) {
            string key = "";
            key += s[0];
            key += s[1];
            validFor[key].push_back(s[2]);
            isValid[key]++;
        }

        return find(bottom, validFor, isValid);
    }
};