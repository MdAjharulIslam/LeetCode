class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        
        string A1="";
        string A2="";
        
        for(int i=0;i<n||i<m;i++){
            
            if(i<n){
                A1=A1+word1[i];
            }if(i<m){
                A2=A2+word2[i];
            }
        }
        if(A1==A2){
            return true;
            
        }else {
                return false;
        }
    }
};