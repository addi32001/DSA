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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int>ls;
        while(curr){
            ls.push_back(curr->val);
            curr = curr->next;
        }
        sort(ls.begin(),ls.end());
        curr = head;
        int i = 0;
        while(curr){
            curr->val = ls[i];
            i++;
            curr = curr->next;
        }
        return head;
        
    }
};