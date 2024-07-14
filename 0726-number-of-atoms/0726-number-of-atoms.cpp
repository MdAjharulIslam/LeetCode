class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string,int> mp;
        stack<pair<bool,int>> stk;
        stk.push({false,1});
        int i=formula.size()-1;
        while(i>=0){
            if(isdigit(formula[i])){
                string digits = "";
                while(i>=0 && isdigit(formula[i])){
                    digits = formula[i] + digits;
                    i--;
                }
                stk.push({true,stoi(digits)*stk.top().second});
            }else if(formula[i]==')'){
                i--;
                stk.top().first = false;
                continue;
            }else if(formula[i]=='('){
                if(stk.size() > 1)
                    stk.pop();
                i--;
            }else{
                string str = "";
                while(i>=0 && formula[i] >= 'a' && formula[i] <= 'z'){
                    str = formula[i]+str;
                    i--;
                }
                str = formula[i] + str;
                mp[str]+=stk.top().second;
                if(stk.top().first){
                    stk.pop();
                }
                i--;
            }
        }
        vector<pair<string,int>> vec;
        for(auto it : mp){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end());
        string str = "";
        for(auto i : vec){
            str += i.first;
            if(i.second > 1)
                str += to_string(i.second);
        }
        return str;
    }
};