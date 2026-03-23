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
public:

    bool findPath(TreeNode* LCA,int target,string& path){
        if(!LCA)
            return false;
        if(LCA->val==target)
            return true;
        path.push_back('L');
        if(findPath(LCA->left,target,path))
            return true;
        path.pop_back();
        path.push_back('R');
        if(findPath(LCA->right,target,path))
            return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string root_to_src="";
        string root_to_dest="";
        findPath(root,startValue,root_to_src);
        findPath(root,destValue,root_to_dest);
        int l=0;
        while(l<root_to_src.length()&&l<root_to_dest.length()&&root_to_src[l]==root_to_dest[l])
            l++;
        string res="";
        //add Upper
        for(int i=0;i<root_to_src.length()-l;i++){
            res+='U';
        }
        for(int i=l;i<root_to_dest.length();i++){
            res+=root_to_dest[i];
        }
        return res;
    }
};