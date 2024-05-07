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
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
        
        head = reverse(head);
        ListNode* ans = NULL;
        int carry = 0;
        ListNode* temp = head;
        while(temp){
            int data = temp->val * 2 + carry;
            ListNode* newnode = new ListNode(data%10);
            carry = data/10;
            newnode->next = ans;
            ans = newnode;
            temp = temp->next;
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            newnode->next = ans;
            ans = newnode;
        }
        return ans;
        
    }
};