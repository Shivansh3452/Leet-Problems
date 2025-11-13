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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head2=list2;
        ListNode* ptr2=list2;
       
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }
        
        ListNode* head1=list1;
        ListNode* temp1=head1;
        while(a>1){
            temp1=temp1->next;
            a--;
        }
        ListNode* temp1_b=head1;
        while(b>0){
            temp1_b=temp1_b->next;
            b--;
        }
        temp1->next=head2;
        ptr2->next=temp1_b->next;

        return list1;
    }
};