class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int counts = 0;

        for (int i = left; i <= right; ++i) {
            string word = words[i]; 
            int n = word.size();
            
            
            if (vowels.count(word[0]) && vowels.count(word[n - 1])) {
                counts++; 
            }
        }

        return counts;
    }
};
