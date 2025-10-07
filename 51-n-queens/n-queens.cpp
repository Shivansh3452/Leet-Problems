class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;

    bool checker(int i, int j, int n) {

        //Upper column
        for(int a=0;a<i;a++){
            if(temp[a][j]=='Q')
                return false;
        }

        //Upper left diagonal
        int x=i-1;
        int y=j-1;
        while(x>=0 && y>=0){
            if(temp[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        //Upper right diagonal
        x=i-1;
        y=j+1;
        while(x>=0 && y<n){
            if(temp[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        return true;
    }

    void backtrack(int i, int n) {
        if(i==n){
            result.push_back(temp);
            return;
        }
            
        for (int j = 0; j < n; j++) {
            if (checker(i, j, n)) {
                temp[i][j]='Q';
                backtrack(i+1,n);
                temp[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        temp = vector<string>(n, string(n, '.'));
        backtrack(0,n);
        return result;
    }
};