class SegmentTree {
private:
    inline static array<int, 4> t[400001];
    int l;

    inline int get_new(int a, int b, int c) {
        return c + (((a >> 5) + (b >> 5)) << 5);
    }

    array<int, 4> combine(array<int, 4> &l, array<int, 4> &r) noexcept {
        int cl = l[2] & 31, cr = r[1] & 31, ini = max(l[0], r[0]), rl = l[1], rr = r[2];

        if (cl == cr) {
            ini = max(ini, (l[2] >> 5) + (r[1] >> 5));
            if (l[0] == l[3]) {
                rl = get_new(rl, r[1], cl);
            }

            if (r[0] == r[3]) {
                rr = get_new(rr, l[2], cr);
            }
        }

        return {ini, rl, rr, l[3] + r[3]};
    }

    void build(string_view s, int p, int le, int ri) {
        if (le == ri) {
            int tmp = 32 + (s[le] - 'a');
            t[p] = {1, tmp, tmp, 1};
        } else {
            int tmp = le + ((ri - le) >> 1);
            build(s, 2 * p, le, tmp);
            build(s, 2 * p + 1, tmp + 1, ri);

            t[p] = combine(t[2 * p], t[2 * p + 1]);
        }
    }

    void update(int p, int le, int ri, int idx, int val) {
        if (le == ri) {
            t[p] = {1, 32 + val, 32 + val, 1};
        } else {
            int tmp = le + ((ri - le) >> 1);
            if (idx <= tmp) {
                update(2 * p, le, tmp, idx, val);
            } else {
                update(2 * p + 1, tmp + 1, ri, idx, val);
            }

            t[p] = combine(t[2 * p], t[2 * p + 1]);
        }
    }
public:
    SegmentTree(string_view s): l(s.length()) {
        build(s, 1, 0, l - 1);
    }

    void update(int idx, int val) {
        update(1, 0, l - 1, idx, val);
    }

    int query() {
        return t[1][0];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string &s, string_view queryCharacters, vector<int>& queryIndices) {
        SegmentTree sTree(s);

        int l = queryIndices.size();
        vector<int> ans(l, 0);

        for (int i = 0; i < l; ++i) {
            int tmp = queryIndices[i];
            char cc = queryCharacters[i];
            if (s[tmp] != cc) {
                s[tmp] = cc;
                sTree.update(tmp, cc - 'a');
            }

            ans[i] = sTree.query();
        }

        return ans;
    }
};