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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr = head;
        stack<int>st;
        while(temp != nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        while(curr != nullptr){
            curr->val = st.top();
            curr = curr->next;
            st.pop();
        }
        return head;
    }
};