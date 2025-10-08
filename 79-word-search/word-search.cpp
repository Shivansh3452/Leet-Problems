class Solution {
public:
    bool dfs(vector<vector<char>>& board,int r,int c,int i,string word){
        if(i==word.size()){
            return true;
        }
        if(r>=board.size() || c>=board[0].size() || r<0 || c<0 || word[i]!=board[r][c]){
            return false;
        }
        char temp=board[r][c];
        board[r][c]='#';
        bool res=dfs(board,r+1,c,i+1,word) || 
                 dfs(board,r,c+1,i+1,word) || 
                 dfs(board,r-1,c,i+1,word) || 
                 dfs(board,r,c-1,i+1,word);
        
        board[r][c]=temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};