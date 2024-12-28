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
#include <queue>

class Solution {
public:
    // This is the efficient O(nlogk) algorithm
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        auto cmp = [](pair<int, int> &left, pair<int, int> &right) {
            return (left.first >= right.first);
        };
	    priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(cmp)> H(cmp);

        // Create the initial heap
        for (size_t i=0; i<lists.size(); i++){
            if (lists[i] != NULL){
                H.push(make_pair(lists[i]->val, i));
            } //end-if
        } //end-for

        ListNode *head = NULL, **tail = &head;

        while (!H.empty()){
            auto [_, index] = H.top();
            H.pop();

            *tail = lists[index];
            tail = &(*tail)->next;
            lists[index] = lists[index]->next;

            if (lists[index]){
                H.push({lists[index]->val, index});
            } //end-if
        } //end-while

        return head;
    } //end-mergeKLists
};