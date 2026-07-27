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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* prev = nullptr;

        while (curr1 != nullptr){
            ListNode* next = curr1->next;
            curr1->next = prev;
            prev = curr1;
            curr1 = next;
        }

        l1 = prev;
        ListNode* curr2 = l2;
        prev = nullptr;

        while (curr2 != nullptr){
            ListNode* next = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = next;
        }

        l2 = prev;
        ListNode dummy;
        ListNode* curr = &dummy;
        curr1 = l1;
        curr2 = l2;
        int carry = 0;
        
        while (curr1 != nullptr || curr2 != nullptr){
            int val1 = (curr1 != nullptr) ? curr1->val : 0;
            int val2 = (curr2 != nullptr) ? curr2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum); 
            if (curr1 != nullptr) curr1 = curr1->next;
            if (curr2 != nullptr) curr2 = curr2->next; 
            curr = curr->next;
        }

        if (carry > 0){
            curr->next = new ListNode(carry);
        }

        prev = nullptr;
        curr = dummy.next;
         while (curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};