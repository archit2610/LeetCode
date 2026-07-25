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
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr){
            curr = curr->next;
            count++;
        }

        curr = head;
       ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        
       while (count >= k){
        ListNode* groupStart = curr;
        ListNode* prev = nullptr;

        for(int i = 0;i < k;++i){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        groupPrev->next = prev;
        groupStart->next = curr;
        groupPrev = groupStart;
        count -= k;
       
       }
       return dummy.next;
};
};