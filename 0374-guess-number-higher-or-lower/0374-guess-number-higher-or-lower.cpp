/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int first=1;
        int last=n;
        
        while(first<=last){
            int mid=first+(last-first)/2;
            int res=guess(mid);
            if(res==0){
                return mid;
            }
            if(res== -1){
                last=mid-1;
            }else{
                first=mid+1;
            }
        }
        return -1;
    }
};