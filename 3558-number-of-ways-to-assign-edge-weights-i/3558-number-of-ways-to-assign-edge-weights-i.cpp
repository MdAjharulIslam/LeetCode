struct Solution {
    static constexpr unsigned assignEdgeWeights(const vector<vector<int>>& edges) {
        static constexpr unsigned mod = 1000000007;

        unsigned size = edges.size() + 1u;
        auto arr = make_unique<unsigned[]>(size * 3u);

        unsigned* const cnt = arr.get();
        unsigned* const sum = cnt + size;
        unsigned* right = sum + size;
        const unsigned* left = right;

        for (span<const int> e : edges) {
            unsigned u = e[0] - 1u;
            unsigned v = e[1] - 1u;

            ++cnt[u];
            ++cnt[v];

            sum[u] ^= v;
            sum[v] ^= u;
        }

        for (unsigned i = 1; i != size; ++i)
            if (cnt[i] == 1u)
                *right++ = i;

        unsigned res = 1;

        while (left != right) {
            span<const unsigned> curr(left, right);
            left = right;

            for (unsigned v : curr) {
                unsigned p = sum[v];

                if (p) {
                    sum[p] ^= v;

                    if (--cnt[p] == 1u)
                        *right++ = p;
                }
            }

            res %= mod;
            res *= 2u;
        }

        return res / 2u;
    }
};