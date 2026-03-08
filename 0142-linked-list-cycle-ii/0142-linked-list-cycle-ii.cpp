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
    ListNode *detectCycle(ListNode *head){
        //initialising fast and slow pointers
        ListNode *slow = head;
        ListNode *fast = head;
        
        
        //traversing the pointers
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next;
            if(fast == slow){
                //find start of cycle 
                ListNode* start = head;
                while(start != slow){
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
            

        }
        return NULL;
        
    }
};