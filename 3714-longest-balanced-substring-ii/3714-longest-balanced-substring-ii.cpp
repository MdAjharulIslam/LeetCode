class Solution {
public:
    int solve(int c, string &s) {
        int cnt=0, ans=0;
        for (auto it:s) {
            if (it-'a' == c) cnt++;
            else cnt=0;
            ans=max(ans, cnt);
        }
        return ans;
    }
    int solve(int x, int y, string &s) {
        map<int, int> mp;
        mp[0]=-1;
        int cx=0, cy=0, ans=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]-'a' == x) cx++;
            else if (s[i]-'a' == y) cy++;
            else {
                cx=cy=0;
                mp.clear();
                mp[0]=i;
            }

            int dif=cx-cy;
            if (mp.count(dif)) ans=max(ans, i-mp[dif]);
            else mp[dif]=i;
        }
        return ans;
    }
    int solve(string &s) {
        int ans=0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}]=-1;
        int frq[3]={0, 0, 0};
        for (int i=0; i<s.size(); i++) {
            frq[s[i]-'a']++;
            int x=frq[0]-frq[1], y=frq[1]-frq[2];
            if (mp.count({x, y})) ans=max(ans, i-mp[{x, y}]);
            else mp[{x, y}]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans=solve(s);
        cout<<"#1 "<<ans<<'\n';
        for (int i=0; i<3; i++) {
            ans=max(ans, solve(i, s));
            cout<<"#2 "<<ans<<'\n';
            for (int j=i+1; j<3; j++) {
                ans=max(ans, solve(i, j, s));
                cout<<"#3 "<<ans<<'\n';
            }
        }
        return ans;
    }
};