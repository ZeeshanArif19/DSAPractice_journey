class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0; //longest prefix subarray
        int right=n-1; //longest suffix subarray
        
        while(left+1<n && arr[left]<=arr[left+1]) left++;
        if(left==n-1) return 0; //the array is already sorted

        while(right>0 && arr[right-1]<=arr[right]) right--;

        int remove=min(n-left-1,right); //worst case scenario-- keeponly suffix,keep only prefix
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){ //delete everything in between
                remove=min(remove,j-i-1);
                i++; //move 'i' forward to try and keep a LARGER prefix (which is better for us)
            }
            else j++; //we need larger element on the suffix
        }

        return remove;

    }
};