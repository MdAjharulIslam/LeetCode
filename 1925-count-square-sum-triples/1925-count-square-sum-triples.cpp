class Solution {
public:
    int countTriples(int n) {
        int count=0;

        for(int i=1;i<=n;i++)
        {
            int left=1;
            int right=i-1;
            int target=i*i;

            while(left<right)
            {
                int sum=left*left + right*right;

                if(sum==target)
                {
                    count+=2;
                    left++;
                    right--;
                }
                else if(sum<target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return count;
    }
};