class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v=rooms.size();
        vector<bool> vis(v,false);
        queue<int> q;
        vis[0]=true;
        q.push(0);

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(int i:rooms[curr]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }

        for(int i=0;i<v;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};