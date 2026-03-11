class Solution {
public:

    int helper(int n,vector<int>& leftChild, vector<int>& rightChild){
        set<int> st;
        st.insert(leftChild.begin(),end(leftChild));
        st.insert(begin(rightChild),end(rightChild));
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end())
                return i;   //returned root
        }
        return -1;      //root is in leftchild or rightchild so no root
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=helper(n,leftChild,rightChild);
        if(root==-1)
            return false;
        unordered_set<int> seen;
        stack<int> st;
        st.push(root);
        seen.insert(root);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            vector<int> children={leftChild[node],rightChild[node]};
            for(auto& child:children){
                if(child!=-1){
                    if(seen.find(child)!=seen.end())
                        return false;       //repeated so not unique node number
                    st.push(child);
                    seen.insert(child);
                }
            }
        }
        return seen.size()==n;
    }
};