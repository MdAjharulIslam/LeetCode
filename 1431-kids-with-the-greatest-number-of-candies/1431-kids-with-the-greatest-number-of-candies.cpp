class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxC=0;
        vector<bool> result(candies.size());
        for(int i=0;i<candies.size();i++)
        {
        if(candies[i]>maxC)
        {
            maxC=candies[i];
        }
        }
        for(int j=0;j<candies.size();j++)
        {
            if(candies[j]+extraCandies >= maxC)
            {
                result[j] = true;
            }
            else
            {
                result[j]= false;
            }
        }
        return result;
    }
};