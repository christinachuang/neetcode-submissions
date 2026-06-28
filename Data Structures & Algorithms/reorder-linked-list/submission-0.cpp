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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* l2 = slow->next, *prev = nullptr, *next;
        slow->next = nullptr;
        while(l2){
            next = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = next;
        }
        ListNode dummy = ListNode(0);
        ListNode* curr = &dummy;
        ListNode* h1 = head, *h2 = prev;
        while(h1){
            curr->next = h1;
            curr = curr->next;
            h1 = h1->next;
            if(h2){
                curr->next = h2;
                curr = curr->next;
                h2 = h2->next;
            }
        }
    }
};
