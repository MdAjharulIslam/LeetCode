class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int mod = 1e9+7;
        int count =0;
        int currCount =0;
        int prevSeat =-1;
        int ans =1;
        for(int i=0; i<n;i++){
            char elm = corridor[i];
            if(elm == 'S'){
                count++;
                currCount++;
                if(currCount ==3){
                    
                    currCount=1;
                    int num = i-prevSeat;
                    ans= (1LL *ans *num) % mod;
                }
                prevSeat =i;

            }
        }

        if(count%2==1 || count==0){
            return 0;
        }
        return (ans % mod);

    }
};