class Solution {
public:
    int factors(int num){
        int sum=0,cnt=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){   
                if(num/i==i){ 
                    sum+=num/i;
                    cnt+=1;
                }else{
                    sum+=num/i + i;
                    cnt+=2;
                }
                
            }
        }
        if(cnt==4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(auto it : nums){
            res+=factors(it);
        }
        return res;
    }
};