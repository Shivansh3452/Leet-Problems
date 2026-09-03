class Solution {
public:
    bool isValid(int i,int j,int num,vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            if(k!=j&&(board[i][k]-'0')==num)
                return false;
            if(k!=i&&(board[k][j]-'0')==num)
                return false;
        }
        int strtrw=(i/3)*3;
        int strtclm=(j/3)*3;
        for(int p=strtrw;p<strtrw+3;p++){
            for(int q=strtclm;q<strtclm+3;q++){
                if((p != i || q != j) &&board[p][q]-'0'==num)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'0';
                if(!isValid(i,j,num,board))
                    return false;
            }
        }
        return true;
    }
};