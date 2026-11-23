class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 || numRows>=n) return s;
        string res="";
        res.reserve(n);
        int cyclen=2*numRows-2;

        for(int row=0;row<numRows;row++){
            for(int idx=row;idx<n;idx+=cyclen){
                res.push_back(s[idx]);
                
                int diagIdx=idx+ cyclen-(2*row);
                if(row>0 && row<numRows-1 && diagIdx<n){
                    res.push_back(s[diagIdx]);
                }
            }
        }
        return res;

        // vector<vector<char>> matrix(numRows,vector<char>(n,' '));
        // int i=0;
        // int j=0;
        // bool goingdown=true;
        
        // for(int k=0;k<n;k++){
        //     matrix[i][j]=s[k];

        //     if(goingdown){
        //         if(i==numRows-1){
        //             goingdown=false;
        //             i--;
        //             j++;
        //         }
        //         else{
        //             i++;
        //         }
        //     }
        //     else{
        //         if(i==0){
        //             goingdown=true;
        //             i++;
        //         }
        //         else{
        //             i--;
        //             j++;
        //         }
        //     }
        // }
        // string res="";
        // for(int i=0;i<numRows;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]!=' ') res+=matrix[i][j];
        //     }
        // }
        // return res;
    }
};