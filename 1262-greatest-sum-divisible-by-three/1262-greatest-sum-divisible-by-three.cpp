class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
    long long total = 0;
    vector<int> one;
    vector<int>two;
    for(int n:nums){
        total +=n;
        if(n%3 == 1){
            one.push_back(n);
        }
        else if(n%3 == 2){
            two.push_back(n);
        }

    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());

    long long original_total = total;
    if(total % 3 == 1){
        if(one.size()>=1){
            total = total - one[0];
        }
        if(two.size()>=2){
            if(total%3 == 0){
                total = max(total,original_total-two[0]-two[1]);
            }
            else{
                total = original_total-two[0]-two[1];
            }
            
        }
    }
    else if(total %3 == 2){
        if(two.size()>=1){
            total = total - two[0];
        }
        if(one.size()>=2){
            if(total % 3 == 0){
                total = max(total, original_total - one[0]- one[1]);
            }
            else{
                total = original_total - one[0]- one[1];
            }
            
        }

    }
     
     if(total %3 == 0) return total;
     return 0;
    }
};