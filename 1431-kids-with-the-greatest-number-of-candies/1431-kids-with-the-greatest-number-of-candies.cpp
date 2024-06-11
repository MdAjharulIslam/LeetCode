class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
     int maxCan = 0;
        for(auto i : candies)
        maxCan = max(maxCan,i);

        vector<bool> result;

        for(int i =0;i<n;i++)
        {
            if(candies[i] + extraCandies >= maxCan)
            result.push_back(true);
            else
            {
            result.push_back(false);
            }
        }

        return result;   
    }
};