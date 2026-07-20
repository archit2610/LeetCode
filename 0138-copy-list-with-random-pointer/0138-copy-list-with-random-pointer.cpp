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
    unordered_map<Node*,Node*> copy;
    copy[NULL] = NULL;

   Node* cur = head;
    while (cur != NULL) {
        Node* copied = new Node(cur->val);
        copy[cur] = copied;
        cur = cur->next;
    }

    cur = head;
    while(cur != nullptr){
        Node* copied = copy[cur];
        copied->random = copy[cur->random];
        copied->next = copy[cur->next];
        cur = cur->next;
    }
    return copy[head];
    }
};