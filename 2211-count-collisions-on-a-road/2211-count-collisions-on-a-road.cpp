class Solution {
public:
    int countCollisions(string directions) {
       
        int ans=0;
        int n=directions.size();
        int left=0;
        int right=n-1;

        while((left<n) && (directions[left]=='L'))
            left++;
   
        while((right>=0) && (directions[right]=='R'))
            right--;

        
        for(int idx=left;idx<=right;idx++)
        {
           
            if(directions[idx] != 'S')
                ans++;
        }
        return ans; 
    }
};