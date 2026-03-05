class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        int count=0;
        for(char &ch:s){
            freq[ch-'a']++;
            count=max(count,freq[ch-'a']);
        }

        if(count>(n+1)/2) return "";
        
        string res="";
        priority_queue<pair<int,char>> pq; //to store freq,char
        for(int i=0;i<26;i++){
            if(freq[i]>0){  //dont push dulpicate chars every time
                pq.push({freq[i],'a'+i});
            }
        }
        pair<int,char> waitingRoom={0,0};
        while(!pq.empty()){
            auto [count,ch]=pq.top();
            pq.pop();

            res+=ch;
            count--;
            
            if(waitingRoom.first>0){
                pq.push(waitingRoom);
            }
            waitingRoom={count,ch};
        }
        return res;
    }
};