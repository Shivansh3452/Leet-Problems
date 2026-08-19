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
    ListNode* addTwoNumbers(ListNode* temp1, ListNode* temp2) {
        int sum=temp1->val+temp2->val;
        int carry=sum/10;
        sum%=10;
        ListNode* ans=new ListNode(sum);
        ListNode* nw=ans;
        temp1=temp1->next;
        temp2=temp2->next;
        while(temp1||temp2||carry){
            sum=carry;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            carry=sum/10;
            sum%=10;
            ans->next=new ListNode(sum);
            ans=ans->next;
        }
        return nw;
    }
};