class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<int>> &b, set<int> &st){
        int n = b.size(), m = b[0].size();
        st.insert(i);
        b[i][j] = 2;
        for(auto &[dx,dy]:dir){
            int nx = i+dx, ny = j+dy;
            if(nx>=0 && nx<n && ny>=0 && ny<m && b[nx][ny] == 0){
                dfs(nx, ny, b, st);
            }
        }
    }
    bool ok(int mid, vector<vector<int>> &a, int n, int m){
        vector<vector<int>> b(n, vector<int>(m, 0));
        for(int i=0;i<=mid;i++){
            b[a[i][0]-1][a[i][1]-1] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j] == 0){
                    set<int> st;
                    dfs(i, j, b, st);
                    if(st.count(0) && st.count(n-1)) return true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>& a) {
        int l = 0, r = n*m-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(ok(mid, a, n, m)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans+1;
    }
};