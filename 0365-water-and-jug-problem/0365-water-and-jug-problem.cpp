class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false; //if the the two jugs is smaller than the target then not possible
        //jug operations generate combinations of x and y
        //smallest acheivable positive quantity gcd(x,y)
        //every achievable quantity is the multiple of gcd(x,y)
        return target % gcd(x,y)==0;
    }
};