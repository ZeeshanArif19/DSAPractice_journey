class Solution {
public:
    void merge(vector<pair<int,int>> &v,int left,int mid,int right,vector<int> &res){
        vector<pair<int,int>> temp;
        int i=left;
        int j=mid+1;
        int right_count=0; //no of elements from the right half smaller than left[i]
        //If k elements from the Right half were smaller than left[i], those exact same k elements are automatically smaller than left[i+1]
        while(i<=mid && j<=right){
            //right element is smaller ->jums ahead
            if(v[j].first<v[i].first){
                temp.push_back(v[j]);
                right_count++;
                j++;
            }
            else{ //left element is smaller or equal ->count how many right elements jumped before it
                temp.push_back(v[i]);
                res[v[i].second]+=right_count;
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(v[i]);
            res[v[i].second]+=right_count;
            i++;
        }
        while(j<=right) temp.push_back(v[j++]);

        for(int k=0;k<temp.size();k++){
            v[left+k]=temp[k];
        }
    }
    void mergeSort(vector<pair<int,int>> &v,int left,int right,vector<int> &res){
        if(left>=right) return;
        
        int mid=left+(right-left)/2;
        mergeSort(v,left,mid,res);
        mergeSort(v,mid+1,right,res);
        merge(v,left,mid,right,res);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i]={nums[i],i};

        vector<int> res(n,0);
        mergeSort(v,0,n-1,res);
        return res;
    }
};