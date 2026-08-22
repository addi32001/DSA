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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr || k == 0) return head;

        ListNode* tail = head;
        int length = 1;
        while(tail->next){
            length++;
            tail = tail->next;
        }
        tail->next = head;
        k =  k % length;
        int right = length-k;
        ListNode*newtail = head;
        for(int i=1;i<right;i++){
            newtail = newtail->next;
        }
        ListNode* newHead = newtail->next;
        newtail->next = nullptr;

        return newHead;
    }
};