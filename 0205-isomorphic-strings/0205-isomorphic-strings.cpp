class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false; 
    
    
    
    unordered_map<char,char>mapS, mapT;
    
    for(int i=0;i<s.size();i++){
        
        if(mapS.find(s[i]) != mapS.end()){
            if(mapS[s[i]] != t[i]) return false;
        }else{
            mapS[s[i]]=t[i];
        }
        
        if(mapT.find(t[i]) != mapT.end()){
            if(mapT[t[i]]!=s[i]) return false;
        }else{
            mapT[t[i]]=s[i];
        }
        
        
    }
        return true;
    }
};