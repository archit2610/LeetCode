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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())  return nullptr;

        ListNode* head = lists[0];
        ListNode* curr = head;

        for(int i = 1;i < lists.size();++i){
            ListNode dummy;
            ListNode* merged = &dummy;
            ListNode* second = lists[i];
            curr = head;
            while (curr != nullptr && second != nullptr){
                if(curr->val <= second->val){
                    merged->next = curr;
                    curr = curr->next;
                }else{
                    merged->next = second;
                   second = second->next;
                }
            merged = merged->next;
            }
            if (curr != nullptr)    merged->next = curr;
            else    merged->next = second;
            head = dummy.next;
        }
        return head;
    }
};