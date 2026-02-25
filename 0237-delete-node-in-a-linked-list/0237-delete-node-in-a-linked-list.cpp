/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node){
       // copy next node value into current node
        node->val = node->next->val;
        
        // store next node
        ListNode* temp = node->next;
        
        // skip next node
        node->next = temp->next;
        
        // delete next node
        delete temp;
    }
};
    
