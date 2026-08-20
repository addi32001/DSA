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
        vector<int> ls;
        while (head) {
            ls.push_back(head->val);
            head = head->next;
        }
        
        int left = 0, right = ls.size() - 1;
        while (left < right && ls[left] == ls[right]) {
            left++;
            right--;
        }
        return left >= right;

    }
};