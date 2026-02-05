class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
         greater<pair<int,pair<int,int>>>> pq;
        
        int delRow[4]={1,-1,0,0};
        int delCol[4]={0,0,1,-1};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1) return effort;
            if(effort>dist[row][col]) continue;

            for(int k=0;k<4;k++){
                int nr=row+delRow[k];
                int nc=col+delCol[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int weight=abs(heights[row][col]-heights[nr][nc]);
                    int newEffort=max(weight,effort);

                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};