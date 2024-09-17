class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        stringstream ss(s1 + " " + s2);
        unordered_map<string, int> mpp;

        string temp;

        while(ss >> temp){
            mpp[temp]++;
        }

        for(auto x: mpp){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};