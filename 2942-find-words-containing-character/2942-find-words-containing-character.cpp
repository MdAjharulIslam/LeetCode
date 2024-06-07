class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int size = words.size();
        vector<int> ans;
        for(int i=0; i<size; i++){
            for(int j=0; j<words[i].size(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};