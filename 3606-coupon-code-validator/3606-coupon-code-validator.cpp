class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> v;

        for(int i = 0; i < code.size(); ++i){
            if(code[i] == "") continue;
            if(!isActive[i]) continue;

            string st = businessLine[i];
            bool b = false;
            if(st == "electronics" || st == "grocery" || st == "pharmacy" || st == "restaurant")
                b = true;
            if(!b) continue;

            string s = code[i];
            bool t = false;

            for(int j = 0; j < s.size(); j++){
                if((s[j] >= 'a' && s[j] <= 'z') ||
                   (s[j] >= 'A' && s[j] <= 'Z') ||
                   (s[j] >= '0' && s[j] <= '9') ||
                   s[j] == '_')
                    continue;
                else {
                    t = true;
                    break;
                }
            }

            if(!t) v.push_back({businessLine[i], code[i]});
        }

        sort(begin(v), end(v));

        vector<string> ans;
        for(auto p : v){
            ans.push_back(p.second);
        }
        return ans;
    }
};