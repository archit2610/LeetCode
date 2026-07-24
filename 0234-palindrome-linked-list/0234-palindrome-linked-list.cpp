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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)   return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        if ( fast!= nullptr)    slow = slow->next;
        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while (curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow = head;

        while(prev!= nullptr){
            if (slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};