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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 || l2){
            ListNode* add = new ListNode(carry);
            
            if(l1){
                add->val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                add->val += l2->val;
                l2 = l2->next;
            }
            carry = add->val / 10;
            add->val %= 10;
            curr->next = add;
            curr = curr->next;
        }
        if(carry){
            ListNode* add = new ListNode(carry);
            curr->next = add;
        }

        return dummy->next;
    }
};
