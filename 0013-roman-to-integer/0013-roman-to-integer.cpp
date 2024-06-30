class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>A;
        int n=s.length();
        int answer=0;
        A['I']=1;
        A['V']=5;
        A['X']=10;
        A['L']=50;
        A['C']=100;
        A['D']=500;
        A['M']=1000;
        
        for(int i=0;i<n;i++){
            if(A[s[i]]<A[s[i+1]]){
                answer-=A[s[i]];
                
            }
            
            else{
                answer+=A[s[i]];
            }
        }
        return answer;
    }
};