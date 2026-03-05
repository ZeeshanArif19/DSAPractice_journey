class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        while(!pq.empty()){
            auto [count1,ch1]=pq.top();  //best option
            pq.pop();
            
            int n=res.size();
            if(n>=2 && res[n-1]==ch1 && res[n-2]==ch1){
                if(pq.empty()) break;
                
                auto [count2,ch2]=pq.top();  //second best option
                pq.pop();
                
                res+=ch2;
                count2--;

                if(count2>0) pq.push({count2,ch2}); //put the Second back after decrementing count
                pq.push({count1,ch1});   //put the first back
            }
            else{
                res+=ch1;
                count1--;
                if(count1>0) pq.push({count1,ch1}); //put the first back after decrementing count
            }
        }
        return res;
    }
};