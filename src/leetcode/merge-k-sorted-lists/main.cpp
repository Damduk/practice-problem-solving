/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* merged, ListNode* node) {
    if (merged == NULL) {
        return node;
    } else if (node == NULL) {
        return merged;
    }
    
    ListNode *i, *j, *res;
    if (merged->val < node->val) {
        i = merged;
        j = node;
        res = i;
    } else {
        i = node;
        j = merged;
        res = i;
    }
    
    while (j != NULL) {
        if (i->next == NULL) {
            i->next = j;
            break;
        } else if (j->val <= i->next->val) {
            ListNode *tmp = i->next;
            i->next = j;
            j = j->next;
            i->next->next = tmp;
        } else {
            i = i->next;
        }
    }
    
    return res;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) {
            return NULL;
        }
        
        ListNode* merged = lists[0];
        for (int i = 1; i < lists.size(); i++)
            merged = merge(merged, lists[i]);
        
        return merged;
    }
};