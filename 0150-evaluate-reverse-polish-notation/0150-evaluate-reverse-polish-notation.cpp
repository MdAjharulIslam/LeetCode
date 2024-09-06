class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int>st;   
        int n=tokens.size();
        for(int i=0;i<n;i++){
            string token=tokens[i];
            
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                int c=0;
                
                if(token=="+") {
                    c=a+b;
                }else if(token=="-"){
                    c=a-b;
                }else if(token=="*"){
                    c=a*b;
                }else {
                    c=a/b;
                }
                
                st.push(c);
            }
        else{
            st.push(stoi(token));
        }
        
        }
        
        return st.top();
    }
};