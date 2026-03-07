class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int i = 0;
        int j = 0;
        
        int odd0 = 0;
        int odd1 = 0;
        int even0 = 0;
        int even1 = 0;

        //generate count of zeros and ones at odd, even position
        while(j < n){
            if(j % 2 == 0){
                if(s[j] == '1') even1++;
                else even0++;
            }
            else{
                if(s[j] == '1') odd1++;
                else odd0++;
            }
            j++;
        }
        //notice possible pattern is either 0101... or 1010....
        //0101 means odd = 1 and even = 0
        //1010 means odd = 0 and even = 1
        //so we check both pattern with the help of count and take the min value needed to reach that pattern
        int ans = min(odd1 + even0, odd0 + even1);

        //NOTE : If the string is even length then pop and appending to end yields the same result
        //everytime, therefore we can return the ans as itll be our best possible ans
        if(ans == 0 || n % 2 == 0) return ans;


        //simulate sliding window of n size and handle adding removing bits by place
        while(i < n){
            s[i] == '1' ? even1-- : even0--; //remove the first bit 
            
            swap(odd0, even0); //since everything move back by one posi we simply swap the counts
            swap(odd1, even1);
            
            s[i] == '1' ? even1++ : even0++; //append the first bit to end

            i++;
            ans = min(ans, min(odd1 + even0, odd0 + even1));
        }
        return ans;
    }
};