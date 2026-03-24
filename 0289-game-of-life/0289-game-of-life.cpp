class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> toChange;  //i,j
        int m=board.size();
        int n=board[0].size();
        
        int dr[8]={1,-1,0,0,-1,-1,1,1};
        int dc[8]={0,0,1,-1,-1,1,-1,1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveCount=0;
                int deadCount=0;
                
                for(int k=0;k<8;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(board[nr][nc]==1) liveCount++;
                        else deadCount++;
                    }
                }

                if(board[i][j]==1 && liveCount<2) toChange.push_back({i,j});
                if(board[i][j]==1 && liveCount>3) toChange.push_back({i,j});
                if(board[i][j]==0 && liveCount==3) toChange.push_back({i,j});
            }
        }

        for(auto &it:toChange){
            int row=it.first;
            int col=it.second;
            if(board[row][col]==1) board[row][col]=0;
            else board[row][col]=1;
        }
    }
};