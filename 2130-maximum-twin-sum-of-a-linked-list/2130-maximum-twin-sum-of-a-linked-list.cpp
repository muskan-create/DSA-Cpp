/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
       int res = 0;
        ListNode* left = head;

        auto dfs = [&](this auto&& dfs, ListNode* right) -> void {
            if (right->next)
                dfs(right->next);

            res = max(res, left->val + right->val);
            left = left->next;
        };

        dfs(head);
        return res;  
    }
};