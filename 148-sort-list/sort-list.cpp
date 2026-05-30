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

    ListNode* mergeList(ListNode* l1,ListNode* l2){
    //     if(!l1||!l2)
    //         return l1||l2;
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }

    ListNode* getmid(ListNode* & head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* left=head;
        ListNode* mid=getmid(head);
        ListNode* right=mid->next;
        mid->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return mergeList(left,right);
    }
};