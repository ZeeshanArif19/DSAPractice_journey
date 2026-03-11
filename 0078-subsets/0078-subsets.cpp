class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> &nums,vector<int> &temp,int index){
        if(index>=nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[index]); //included i
        backtrack(nums,temp,index+1);//explore this path
        temp.pop_back(); //excluded i
        backtrack(nums,temp,index+1);//explore this path
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        backtrack(nums,temp,0);
        return result;
    }
};