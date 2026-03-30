class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty){
            if(size[rootx]<size[rooty]){
                parent[rootx]=rooty;
                size[rooty]+=size[rootx];
            }
            else{
                parent[rooty]=rootx;
                size[rootx]+=size[rooty];
            }
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int ma=*max_element(nums.begin(),nums.end());
        DSU ds(ma+1);
        //By only connecting numbers to their fundamental prime factors, we ensure we only plug into the central routers, 
        //and we never accidentally hotwire two different routers together.
        for(int val:nums){  //find all the unique prime factors of a number
            int temp=val;
            for(int i=2;i*i<=val;i++){
                if(val%i==0){
                    ds.unite(i,temp);

                    while(val%i==0){ //Since we already know 2 is a prime factor and we connected it to 20, we don't care how many times 2 goes into 20
                        val/=i;
                    }
                }
            }
            if(val>1) ds.unite(val,temp);
        }
        //Because we never explicitly ask the loop to check the numbers 2 or 5, they act strictly as invisible scaffolding
        //in the background. They hold the network together, but they never get counted as actual members of the group!
        unordered_map<int,int> count;
        int maxsize=0;
        for(int i=0;i<n;i++){
            int root=ds.find(nums[i]);
            count[root]++;
            maxsize=max(maxsize,count[root]);
        }
        return maxsize;
    }
};