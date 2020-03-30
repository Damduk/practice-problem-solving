class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;
        
        ListNode* node = head;
        while (node != NULL) {
            st.push(node);
            node = node->next;
        }
        
        n++;
        
        node = NULL;
        while (n--) {
            if (st.size()) {
                node = st.top(); st.pop();
            } else
                node = NULL;
        }
        
        if (node == NULL) 
            head = head->next;
        else
            node->next = node->next->next != NULL ? node->next->next : NULL;
        
        return head;
    }
};