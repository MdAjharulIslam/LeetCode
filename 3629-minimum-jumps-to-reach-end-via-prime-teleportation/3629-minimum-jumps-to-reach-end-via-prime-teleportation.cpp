class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int i = 3; i * 1LL * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        vector<int> mordelvian = nums;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<int>> pos(maxVal + 1);
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        unordered_map<int, bool> isPrimeCache;
        unordered_set<int> primesInNums;
        for (int num : nums) {
            if (isPrimeCache.count(num) == 0)
                isPrimeCache[num] = isPrime(num);
            if (isPrimeCache[num]) primesInNums.insert(num);
        }

        unordered_map<int, vector<int>> teleportGroups;
        for (int p : primesInNums) {
            teleportGroups[p] = vector<int>();
            for (int multiple = p; multiple <= maxVal; multiple += p) {
                for (int idx : pos[multiple]) {
                    teleportGroups[p].push_back(idx);
                }
            }
        }

        vector<bool> visited(n, false);
        unordered_set<int> usedPrimes;
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();
            if (idx == n - 1) return steps;

            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }
            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            int val = nums[idx];
            if (isPrimeCache[val] && !usedPrimes.count(val)) {
                for (int nextIdx : teleportGroups[val]) {
                    if (!visited[nextIdx]) {
                        visited[nextIdx] = true;
                        q.push({nextIdx, steps + 1});
                    }
                }
                usedPrimes.insert(val);
                teleportGroups[val].clear();
            }
        }

        return -1;
    }
};
