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
        int length = 0;
        ListNode* curr = head;
        while(curr){
            length++;
            curr= curr->next;
        }
        n = length-n;
        if(n == 0) return head->next;
        curr = head;
        ListNode* prev = nullptr;
        while(n--){
            prev = curr;
            curr = curr->next;
        }
        prev ->next = curr->next;
        curr->next = nullptr;
        return head;
    }
};