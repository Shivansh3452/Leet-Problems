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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        set<int> st;
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                st.insert(temp->val);
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};