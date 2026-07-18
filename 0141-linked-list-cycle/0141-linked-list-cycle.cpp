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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> address;
        while (head != nullptr){
            if(address.count(head->next))   return true;
            address.insert(head->next);
            head = head->next;
        }
        return false;
    }
};