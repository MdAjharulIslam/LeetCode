class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> m(n+1);
        vector<vector<int>> m1(n+1);
        vector<unordered_set<int>> hash(n+1);
        
        int ans = 0;
        if (n < 3)    return 0;
        for (auto& b : buildings) {
            int i = b[0];
            int j = b[1];
            if(m[i].size() == 0) m[i].push_back(j);
            else 
            {
                if (j>m[i][0]) swap(j,m[i][0]);
                if (m[i].size() == 1) m[i].push_back(j);
                else 
                {
                    if (j<m[i][1]) swap(j,m[i][1]);
                if(i!=1  && i!=n)
                    hash[i].insert(j);
                }
            }
        }
        for (auto& b : buildings) {
            int j = b[0];
            int i = b[1];
            if(m1[i].size() == 0) m1[i].push_back(j);  
            else 
            {
                if (j>m1[i][0]) swap(j,m1[i][0]);           
                if (m1[i].size() == 1) m1[i].push_back(j);  
                else 
                {
                    if (j<m1[i][1]) swap(j,m1[i][1]);       
                 if(i!=1  && i!=n)
                    if (hash[j].count(i)) ans++;
                }
            }
        }


        return ans;
    }
};