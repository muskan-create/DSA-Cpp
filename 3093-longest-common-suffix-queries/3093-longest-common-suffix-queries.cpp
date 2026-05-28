class Solution {
public:
    struct TrieNode {
        int idx;
        TrieNode* child[26];

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                if (child[i] != nullptr) {
                    delete child[i];
                    child[i] = nullptr;
                }
            }
        }
    };

    TrieNode* getNode(int i) {
        TrieNode* newNode = new TrieNode();
        newNode->idx = i;

        for (int k = 0; k < 26; k++) {
            newNode->child[k] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode* root, vector<string>& s, int id) {
        int n = s[id].size();
        TrieNode* crawl = root;
        for (int i = n - 1; i >= 0; i--) {
            int index = s[id][i] - 'a';

            if (crawl->child[index] == NULL) {
                crawl->child[index] = getNode(id);
            }

            crawl = crawl->child[index];
            if (s[crawl->idx].size() > n) {
                crawl->idx = id;
            }
        }
    }
    int search(string& s, TrieNode* root) {
        int res = root->idx;
        int n = s.size();
        TrieNode* crawl = root;
        for (int i = n - 1; i >= 0; i--) {
            int char_idx = s[i] - 'a';

            crawl = crawl->child[char_idx];
            if (crawl == NULL) {
                return res;
            }
            res = crawl->idx;
        }
        return res;
    }
    vector<int> stringIndices(vector<string>& s, vector<string>& q) {

        TrieNode* root = getNode(0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i].size() < s[root->idx].size()) {
                root->idx = i;
            }

            insert(root, s, i);
        }

        vector<int> ans;

        for (auto& it : q) {
            ans.push_back(search(it, root));
        }
        delete root;
        return ans;
    }
};