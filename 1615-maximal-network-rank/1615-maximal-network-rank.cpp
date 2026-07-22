class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> isConnected(n,vector<bool>(n,false));
        vector<int> roadCnt(n,0);

        for(vector<int> &edge:roads){
            int u=edge[0];
            int v=edge[1];
            isConnected[u][v]=1;
            isConnected[v][u]=1;

            roadCnt[u]++;
            roadCnt[v]++;
        }

        int maxNet=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currentMax=roadCnt[i]+roadCnt[j];
                if(isConnected[i][j] || isConnected[j][i]){
                    currentMax--;
                }

                maxNet=max(maxNet,currentMax);
            }
        }

        return maxNet;
    }
};