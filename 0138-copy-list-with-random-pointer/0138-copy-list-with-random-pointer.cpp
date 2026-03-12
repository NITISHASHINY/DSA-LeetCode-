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
        //handle special cases
        if(head == NULL){
            return NULL;
        }
        //create an unordered map for pointing the keys original and new 
        unordered_map<Node*, Node*> m;
        //initialise new head and temporary variables 
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;
        
        //copying next pointers in new list
        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;newTemp = newHead;

        //copying random pointers in the new List
        while(oldTemp != NULL){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;


        }
        return newHead;


         
          
       
        
    }
};