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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int no = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            curr = curr->next;
            no++;
        }
        curr = head;
        int N = 0;
        int index = no - n;
        if (index == 0) return head->next;
        while (curr != nullptr){
            if (index - 1 == N){
                curr->next = curr->next->next;
                break;
            }else{
                curr = curr->next;
                N++;
            }
        }
        return head;
    }
};