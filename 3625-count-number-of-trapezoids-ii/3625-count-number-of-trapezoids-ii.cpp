class Solution {
public:
    pair<int, int> getSlope(int x1, int x2, int y1, int y2) {

        int dx = (x1 - x2);
        int dy = (y1 - y2);

        bool flag = true;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }

        if (dx == 0) {
            return {1, 0};
        }

        if (dy == 0) {
            return {0, 1};
        }

        int gcd = __gcd(abs(dx), abs(dy));

        return {dy / gcd, dx / gcd};
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        map<pair<int, int>, map<int, int>> mp;
        map<pair<int, int>, int> mids;
        map<pair<int, int>, map<pair<int, int>, int>> mids_diff;
        int pg = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                pair<int, int> slope = getSlope(x1, x2, y1, y2);

                int intercept = y1 * slope.second - x1 * slope.first;

                mp[slope][intercept]++;

                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                pg += (mids[{mx, my}] - mids_diff[{mx, my}][slope]);
                mids[{mx, my}]++;
                mids_diff[{mx, my}][slope]++;
            }
        }

        int ans = 0;
        for (auto i : mp) {
            int edges = 0;

            for (auto j : i.second) {
                int count = j.second;
                ans += (edges * count);
                edges += count;
            }
        }

        return ans - pg;
    }
};