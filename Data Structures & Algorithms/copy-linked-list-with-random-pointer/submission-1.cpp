/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }
        curr = head;
        // random
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* copy_head = curr->next;
        Node* tmp = copy_head;
        // spilt
        while(curr){
            tmp = curr->next;
            curr->next = tmp->next;
            if(tmp->next)
                tmp->next = tmp->next->next;
            curr = curr->next;
        }
        return copy_head;
    }
};
