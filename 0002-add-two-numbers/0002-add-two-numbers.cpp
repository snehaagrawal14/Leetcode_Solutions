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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* tempans=ans;
        while(l1!=NULL || l2!=NULL){
            int a=(l1==NULL)?0:l1->val;
            int b=(l2==NULL)?0:l2->val;
            int sum=a+b+carry;
            ListNode* temp=new ListNode(sum%10);
            tempans->next=temp;
            tempans=tempans->next;
            carry=sum/10;
            l1=(l1==NULL)?l1:l1->next;
            l2=(l2==NULL)?l2:l2->next;
        }
        if(carry){
            ListNode* temp=new ListNode(carry);
            tempans->next=temp;
            tempans=tempans->next;
        }
        return ans->next;
    }
};