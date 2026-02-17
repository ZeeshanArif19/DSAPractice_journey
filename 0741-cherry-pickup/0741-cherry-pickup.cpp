class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int row1,int col1,int row2,int n){
        int col2=row1+col1-row2;
        
        if(row1>=n || row2>=n || col1>=n || col2>=n || grid[row1][col1]==-1 || 
                    grid[row2][col2]==-1) return -1e9; //out of bounds or steped on thorn
        if((row1==n-1 && col1==n-1) || (row2==n-1 && col2==n-1)) return grid[n-1][n-1]; //reached dest
        if(dp[row1][col1][row2]!=-1) return dp[row1][col1][row2];

        int current_cherries=0;
        if(row1==row2 && col1==col2){  //if equal share
            current_cherries=grid[row1][col1];  //since our base case handles -1 there is only 1 or 0 left
        }
        else{
            current_cherries=grid[row1][col1] + grid[row2][col2];
        }

        int op1=solve(grid,dp,row1+1,col1,row2+1,n);  //down,down
        int op2=solve(grid,dp,row1,col1+1,row2,n);     //right,right
        int op3=solve(grid,dp,row1+1,col1,row2,n);      //down,right
        int op4=solve(grid,dp,row1,col1+1,row2+1,n);    //right,down
        int max_future_cherries=max({op1,op2,op3,op4});
        
        return dp[row1][col1][row2]= current_cherries+max_future_cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1))); //row1,col1,row2
        
        int ans=solve(grid,dp,0,0,0,n); 
        return max(0,ans); //no path->Imagine a grid that is completely blocked off by thorns
    }
};