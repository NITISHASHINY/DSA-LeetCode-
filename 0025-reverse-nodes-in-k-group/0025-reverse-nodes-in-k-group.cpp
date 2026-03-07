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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while(true){

            // check if k nodes exist
            ListNode* temp = curr;
            for(int i = 0; i < k; i++){
                if(temp == NULL) return dummy->next;
                temp = temp->next;
            }

            // reverse k nodes
            ListNode* groupStart = curr;
            ListNode* p = NULL;

            for(int i = 0; i < k; i++){
                ListNode* next = curr->next;
                curr->next = p;
                p = curr;
                curr = next;
            }

            // connect reversed group
            prev->next = p;
            groupStart->next = curr;

            prev = groupStart;
        }
    }
};