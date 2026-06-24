class Solution {
public:
    int countlessEqual(vector<vector<int>>& matrix, int k,int mid,int m,int n){
        int count=0;
        int row=m-1;
        int col=0;

        while(row>=0 && col<n){
            if(matrix[row][col]<=mid){
                count+=(row+1);
                col++;
            }
            else row--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=matrix[0][0];
        int r=matrix[m-1][n-1];
        int ans=l;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(countlessEqual(matrix,k,mid,m,n)>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};