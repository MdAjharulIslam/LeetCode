class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int found, count, ans = 0;
       for(int i = 0; i < mat.size(); i++){
            count = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    count++;
                    found = j;
                }
            }
            if(count == 1){
                count = 0;
                for(int k = 0; k < mat.size(); k++){
                    if(mat[k][found] == 1) count++;
                }
                if(count == 1) ans++;
            }
       }
       return ans;
    }
};