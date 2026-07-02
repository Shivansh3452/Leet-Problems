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

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        ListNode* ptr=head;
        int count=0;
        while(count!=n/2){
            ptr=ptr->next;
            count++;
        }
        ListNode* head1=reverse(ptr);
        int maxm=INT_MIN;
        ptr=head;
        while(head1){
            maxm=max(maxm,head1->val+ptr->val);
            head1=head1->next;
            ptr=ptr->next;
        }
        return maxm;
    }
};