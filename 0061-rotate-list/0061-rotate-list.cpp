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
        if(head==nullptr) return head;
        if (k == 0)return head;
        vector<int>ls;
        ListNode* temp = head;
        while(temp != nullptr){
            ls.push_back(temp->val);
            temp = temp->next;
        }
        k = k % ls.size();
        reverse(ls.begin(),ls.end());
        reverse(ls.begin(),ls.begin()+k);
        reverse(ls.begin()+k,ls.end());

        
        cout<<endl;
        temp = head;
        int i = 0;
        while(temp){
            temp->val = ls[i];
            i++;
            temp = temp->next;
        }
        return head;

    }
};