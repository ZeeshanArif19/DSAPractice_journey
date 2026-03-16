class Solution {
public:
    vector<string> res;
    void solve(string &num,int &target,int idx,long currentVal,string path,long prevOperand){{
        if(idx==num.size()){
            if(currentVal==target){
                res.push_back(path);
            }
            return;
        }
        string numStr="";
        long n=0;

        for(int i=idx;i<num.size();i++){
            if(i>idx && num[idx]=='0') break;

            numStr+=num[i];
            n=n*10+(num[i]-'0');
            if(idx==0){
                solve(num,target,i+1,n,numStr,n);
            }
            else{
                solve(num,target,i+1,currentVal+n,path+"+"+numStr,n);

                solve(num,target,i+1,currentVal-n,path+"-"+numStr,-n);

                solve(num,target,i+1,currentVal-prevOperand+(prevOperand*n),path+"*"+numStr,prevOperand*n);
            }
        }
    }

    }
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,0,"",0);
        return res;
    }
};