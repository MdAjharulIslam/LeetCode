class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.size();
        
        for(int i=0;i<n;i++){
            
            if(path[i]=='/'){
                continue;
                
            }
            string s;
            while(i<n&& path[i]!='/'){
                s+=path[i];
                i++;
            }
            if(s=="."){
                continue;
            }
            else if(s==".."){
                
                if(!st.empty()){
                    st.pop();
                }
                
            }else{
                    st.push(s);
                }
            }
                string result;
                while(!st.empty()){
                    result="/"+st.top()+result;
                    st.pop();
                }
                if(result.size()==0){
                    return "/";
                }
                return result;
            }
        
    
};