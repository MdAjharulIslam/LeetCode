class Solution {
public:
    int minimumDeletions(string s) {

        int cnt = 0 ;

        string st ;

        for(char c : s) {

            if(!st.empty() && st.back() == 'b' && c == 'a') {
                st.pop_back() ;
                ++cnt ;
            }

            else {
                st += c ;
            }

        }

        return cnt ;

    }
};