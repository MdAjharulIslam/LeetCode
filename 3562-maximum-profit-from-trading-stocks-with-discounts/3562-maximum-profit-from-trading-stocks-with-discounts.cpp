class Solution {
    vector<vector<int>> adj;
    int n_val;
    int budget_val;
    vector<int> present_val;
    vector<int> future_val;
    
    // Constant for negative infinity to represent unreachable states
    const int INF = -1e9;

    // Returns a pair of vectors:
    // first: DP table if u's parent bought (u is eligible for discount)
    // second: DP table if u's parent didn't buy (u pays full price)
    pair<vector<int>, vector<int>> dfs(int u) {
        // dp_u_buys: Aggregate of children assuming u BUYS (children get discount)
        // dp_u_skips: Aggregate of children assuming u SKIPS (children pay full)
        vector<int> dp_u_buys(budget_val + 1, INF);
        vector<int> dp_u_skips(budget_val + 1, INF);
        
        // Base case initialization: 0 cost yields 0 profit
        dp_u_buys[0] = 0;
        dp_u_skips[0] = 0;
        
        // Merge children's results into the two scenarios
        for (int v : adj[u]) {
            pair<vector<int>, vector<int>> child_res = dfs(v);
            const vector<int>& v_discount = child_res.first; 
            const vector<int>& v_full = child_res.second;    
            
            // Merge for scenario where u buys (use v_discount)
            vector<int> next_dp_u_buys(budget_val + 1, INF);
            for (int b = 0; b <= budget_val; ++b) {
                if (dp_u_buys[b] == INF) continue;
                for (int cb = 0; cb <= budget_val - b; ++cb) {
                    if (v_discount[cb] != INF) {
                        next_dp_u_buys[b + cb] = max(next_dp_u_buys[b + cb], dp_u_buys[b] + v_discount[cb]);
                    }
                }
            }
            dp_u_buys = next_dp_u_buys;
            
            // Merge for scenario where u skips (use v_full)
            vector<int> next_dp_u_skips(budget_val + 1, INF);
            for (int b = 0; b <= budget_val; ++b) {
                if (dp_u_skips[b] == INF) continue;
                for (int cb = 0; cb <= budget_val - b; ++cb) {
                    if (v_full[cb] != INF) {
                        next_dp_u_skips[b + cb] = max(next_dp_u_skips[b + cb], dp_u_skips[b] + v_full[cb]);
                    }
                }
            }
            dp_u_skips = next_dp_u_skips;
        }
        
        // Prepare the result vectors for u
        vector<int> res_if_parent_bought(budget_val + 1, INF);
        vector<int> res_if_parent_skipped(budget_val + 1, INF);
        
        int cost_full = present_val[u-1];
        int profit_full = future_val[u-1] - cost_full;
        
        int cost_disc = present_val[u-1] / 2;
        int profit_disc = future_val[u-1] - cost_disc;
        
        // --- Calculate res_if_parent_bought ---
        // Option 1: u buys (at discount). Valid because parent bought.
        // We use dp_u_buys chain because u buying enables children discounts.
        for (int b = 0; b <= budget_val; ++b) {
            if (dp_u_buys[b] != INF && b + cost_disc <= budget_val) {
                res_if_parent_bought[b + cost_disc] = max(res_if_parent_bought[b + cost_disc], dp_u_buys[b] + profit_disc);
            }
        }
        // Option 2: u skips.
        // We use dp_u_skips chain because u skipping disables children discounts.
        for (int b = 0; b <= budget_val; ++b) {
            if (dp_u_skips[b] != INF) {
                res_if_parent_bought[b] = max(res_if_parent_bought[b], dp_u_skips[b]);
            }
        }
        
        // --- Calculate res_if_parent_skipped ---
        // Option 1: u buys (at full price).
        // We use dp_u_buys chain.
        for (int b = 0; b <= budget_val; ++b) {
            if (dp_u_buys[b] != INF && b + cost_full <= budget_val) {
                res_if_parent_skipped[b + cost_full] = max(res_if_parent_skipped[b + cost_full], dp_u_buys[b] + profit_full);
            }
        }
        // Option 2: u skips.
        // We use dp_u_skips chain.
        for (int b = 0; b <= budget_val; ++b) {
            if (dp_u_skips[b] != INF) {
                res_if_parent_skipped[b] = max(res_if_parent_skipped[b], dp_u_skips[b]);
            }
        }
        
        return {res_if_parent_bought, res_if_parent_skipped};
    }

public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        n_val = n;
        budget_val = budget;
        present_val = present;
        future_val = future;
        
        // Build adjacency list
        adj.assign(n + 1, vector<int>());
        for (auto& edge : hierarchy) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // DFS starting from root (employee 1)
        pair<vector<int>, vector<int>> result = dfs(1);
        
        // The root (CEO) has no boss, so they never get a discount.
        // We look at result.second (parent didn't buy / full price).
        int ans = 0;
        for (int p : result.second) {
            ans = max(ans, p);
        }
        
        return ans;
    }
};