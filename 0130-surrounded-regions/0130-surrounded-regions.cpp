class Solution {
public:
    void dfs(vector<vector<char>>& board,int n,int m,int r,int c,vector<vector<bool>> &vis){
        vis[r][c]=true;
        board[r][c]='S';
        vector<int> delRow={1,-1,0,0};
        vector<int> delCol={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+delRow[i];
            int nc=c+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                vis[nr][nc]=true;
                board[nr][nc]='S';
                dfs(board,n,m,nr,nc,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //check borders
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(board,n,m,0,j,vis);
            if(board[n-1][j]=='O') dfs(board,n,m,n-1,j,vis);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(board,n,m,i,0,vis);
            if(board[i][m-1]=='O') dfs(board,n,m,i,m-1,vis);
        }

        //cleanup
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='S') board[i][j]='O';
                else continue;
            }
        }
    }
};