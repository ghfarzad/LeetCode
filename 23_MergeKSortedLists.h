#include <queue>
#include <vector>


using namespace std;

/*
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        auto cmp = [](ListNode* left, ListNode* right) {
            if (left == nullptr) {
                return false;
            }

            if (right == nullptr) {
                return true;
            }

            return (left->val) > (right->val);
        };

        priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);

        for (const auto& list : lists) {
            if (list != nullptr) {
                q.push(list);
            }
        }

        ListNode* ret = nullptr;
        ListNode* walker = nullptr;
        while (!q.empty()) {
            ListNode* tmp = new ListNode(q.top()->val);
            if (ret == nullptr) {
                ret = tmp;
                walker = ret;
            } else {
                walker->next = tmp;
                walker = walker->next;
            }

            if (q.top()->next != nullptr) {
                q.push(q.top()->next);
            }
            q.pop();
        }

        return ret;
    }
};
