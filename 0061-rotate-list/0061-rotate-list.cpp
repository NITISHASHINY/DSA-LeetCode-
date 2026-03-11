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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        //find length
        ListNode *curr = head;
        int length = 1;

        while(curr->next != NULL){
            curr = curr->next;
            length++;
        }
        k = k % length;

        if(k == 0){
            return head;
        }
        
        //make circular 
        curr->next = head;

        //find new tail
        int steps = length - k;
        ListNode* newTail = head;

        for(int i=1;i<steps;i++){
            newTail = newTail->next;
        }
        //break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;

    }
};