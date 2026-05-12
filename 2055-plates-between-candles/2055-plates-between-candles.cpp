class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> candlePrefix(n,0);
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        for(int i=0;i<n;i++){ //candles to the left of index
            if(s[i]=='|') left[i]=i;
            else if(i>0) left[i]=left[i-1];
        }
        for(int i=n-1;i>=0;i--){ //candles to the right of index
            if(s[i]=='|') right[i]=i;
            else if(i<n-1) right[i]=right[i+1];
        }
        int candles=0;
        for(int i=0;i<n;i++){
            if(s[i]=='|') candles++;
            candlePrefix[i]=candles;
        }

        vector<int> res;
        for(auto &it:queries){ //the actual queries can have floating plates
            int dl=right[it[0]]; //the left wall
            int dr=left[it[1]]; //the right wall

            if(dl==-1 || dr==-1 || dl>=dr) res.emplace_back(0); //validity check
            else{
                int elements=dr-dl+1; //element count between the walls
                int candleCnt=candlePrefix[dr]-candlePrefix[dl]+1;
                res.emplace_back(elements-candleCnt);
            }
        }

        return res;
    }
};