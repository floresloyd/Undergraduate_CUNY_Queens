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
    /// O(nk) algorithm with O(k) extra space
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *resultHead = NULL;
        ListNode **indirect = &resultHead;
        while (true){
            int minIndex = -1;
            for (int i=0; i<lists.size(); i++){
                if (lists[i] == NULL) continue;
                if (minIndex < 0 || lists[i]->val < lists[minIndex]->val)
                    minIndex = i;
            } // end-for
            if (minIndex < 0) break;
            
            *indirect = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            indirect = &(*indirect)->next;
        } // end-while
        return resultHead;
    } // end-mergeKLists
};