class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> exist;
        int c=0;
        for(int i=0;i<allowed.length();i++){
            exist[allowed[i]]++;
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(exist[words[i][j]] == 0){
                    break;
                }
                if(j==words[i].length()-1){
                    c++;
                }
            }
        }
        return c;
    }
};