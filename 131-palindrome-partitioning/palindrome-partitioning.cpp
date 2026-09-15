class Solution {
public:
    void backtrack(int start,string s,vector<string>& curr,vector<vector<bool>>& pal,vector<vector<string>>& ans){
        if(start==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(!pal[start][end])
                continue;
            curr.push_back(s.substr(start,end-start+1));
            backtrack(end+1,s,curr,pal,ans);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((s[i]==s[j])&&(j-i<=2||pal[i+1][j-1]))
                    pal[i][j]=true;
            }
        }
        vector<string> curr;
        vector<vector<string>> ans;
        backtrack(0,s,curr,pal,ans);
        return ans;
    }
};