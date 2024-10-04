class Solution{
    
    public:
    
    long long dividePlayers(vector<int> &skill)
    {
        
        sort(skill.begin(),skill.end());
        
        int i=0;
        int j=skill.size()-1;
        long long ans=0;
        long long cheaker=skill[i] + skill[j];
        while(i<j){
            
            if(cheaker!=skill[i]+skill[j])
                return -1;
            else{
                ans+=skill[i++]*skill[j--];
            }
        }
        return ans;
    }
    
    
};