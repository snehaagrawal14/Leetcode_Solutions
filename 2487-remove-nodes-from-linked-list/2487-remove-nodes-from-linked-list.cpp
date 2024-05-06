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
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
public:
    ListNode* removeNodes(ListNode* head) {
        
        head = reverse(head);
        ListNode* ans = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            if(!ans || ans->val <= curr->val){
                curr->next = ans;
                ans = curr;
            }
            else{
                curr->next = NULL;
                delete curr;
            }
            curr = next;
        }
        return ans;
        
    }
};