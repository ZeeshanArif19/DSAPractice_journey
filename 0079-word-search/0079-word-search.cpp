class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int i,int j,int m,int n,int wordInd){
        if(wordInd==word.size()-1) return true;

        char temp=board[i][j];
        board[i][j]='#';
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]!='#' && board[nr][nc]==word[wordInd+1]){
                if(dfs(board,word,nr,nc,m,n,wordInd+1)){
                    return true;
                }
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j,m,n,0)) return true;
                }
            }
        }
        return false;
    }
};