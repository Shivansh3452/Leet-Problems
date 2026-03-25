/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(int n,string& s,int depth,int& i){
        if(i>=n)
            return nullptr;
        //step1 pointer adjust karo
        int j=i;
        while(j<n&&s[j]=='-')
            j++;
        int dash=j-i;
        if(dash!=depth)
            return nullptr;
        //step 2 update pointer on string
        i+=dash;
        //step3 maal banao
        int digit=0;
        while(i<n&&isdigit(s[i])){
            digit=(digit*10)+(s[i]-'0');
            i++;
        }
        //step 4 ped banao
        TreeNode* root=new TreeNode(digit);
        root->left=helper(n,s,depth+1,i);
        root->right=helper(n,s,depth+1,i);
    
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string s) {
        int n=s.size();
        int i=0;
        int depth=0;
        return helper(n,s,depth,i);
    }
};