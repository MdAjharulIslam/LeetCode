class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         vector<int> result;
        
    
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            
            
            if (c == '+' || c == '-' || c == '*') {
                
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                
                
                vector<int> leftResult = diffWaysToCompute(left);
                vector<int> rightResult = diffWaysToCompute(right);
                
            
                for (int l : leftResult) {
                    for (int r : rightResult) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};