class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        int del=len-n-1;
        if(del<0){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
        }
        temp=head;
        while(del--){
            temp=temp->next;
        }
        ListNode* nxt=temp->next;
        temp->next=temp->next->next;
        delete(nxt);
        return head;
    }
};