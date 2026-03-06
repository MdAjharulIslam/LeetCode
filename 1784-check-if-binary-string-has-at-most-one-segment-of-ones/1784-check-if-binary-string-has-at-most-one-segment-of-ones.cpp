class Solution {
public:
    bool checkOnesSegment(string s) {
        int index=0;
        int ans=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){ 
            index=i;
            break;
            }
        }
        for(int j=index;j<s.size();j++){
            if(s[j]=='1'){
            ans=false;
            break;
            }
        }
        if(index==0) ans=true;
        
        if(ans){
            return true;
        }else{
            return false;
        }
    }
};