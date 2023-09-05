// Problem Link : https://leetcode.com/problems/copy-list-with-random-pointer/


// Solution //
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head ) return NULL;
        Node *node = head, *copiedListHead = NULL;
        // Creating Copy Nodes between the original nodes //
        while( node ){
            Node *copiedNode = new Node(node->val);
            copiedNode->next = node->next;
            node->next = copiedNode;
            node = copiedNode->next;
        }
        
        // Attaching Random Pointers //
        node = head;
        while( node ){
            Node *copiedNode = node->next;
            copiedNode->random = node->random? node->random->next : NULL;
            node = node->next->next;
        }

        // Deattaching the Copied list from the original list //
        Node *copiedLastNode = NULL;
        node = head;
        while( node ){
            Node *copiedNode = node->next;
            if( copiedLastNode ){
                copiedLastNode->next = copiedNode;
                copiedLastNode = copiedNode;
            } else{
                copiedListHead = copiedLastNode = copiedNode;
            }
            node->next = node->next->next;
            node = node->next;
        } 
        copiedLastNode->next = NULL;

        return copiedListHead;
    }
};