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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ptr=head;
        while(ptr!=nullptr){
            st.push(ptr);
            ptr=ptr->next;
        }
        int k=st.size();
        k/=2;
        ptr=head;
        while(k--){
            ListNode* nxt=ptr->next;
            ptr->next=st.top();
            st.pop();
            ptr->next->next=nxt;
            ptr=nxt;
        }
        ptr->next=nullptr;
    }
};