class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);

        // Frequency of every value.
        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1);

        // Inclusion-Exclusion over divisors.
        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            // Count numbers divisible by g.
            for (int x = g; x <= mx; x += g)
                cnt += freq[x];

            // Total pairs divisible by g.
            exact[g] = cnt * (cnt - 1) / 2;

            // Remove pairs whose gcd is a larger multiple.
            for (int x = g + g; x <= mx; x += g)
                exact[g] -= exact[x];
        }

        // Prefix over gcd values.
        vector<long long> pref(mx + 1);

        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {

            // Queries are 0-indexed.
            q++;

            int g = lower_bound(pref.begin() + 1,
                                pref.end(),
                                q) - pref.begin();

            ans.push_back(g);
        }

        return ans;
    }
};