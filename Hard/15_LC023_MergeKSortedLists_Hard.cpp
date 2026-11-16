class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
