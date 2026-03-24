class Solution {
public:
    bool isWin(vector<string> &board,char c){
        for(int i=0;i<3;i++){
            if(board[0][i]==c && board[1][i]==c && board[2][i]==c) return true;  //vertical
            if(board[i][0]==c && board[i][1]==c && board[i][2]==c) return true;  //horizontal
        }
        if(board[0][0]==c && board[1][1]==c && board[2][2]==c) return true; //diagonal
        if(board[2][0]==c && board[1][1]==c && board[0][2]==c) return true; //antidiagonal
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int Ocount=0;
        int Xcount=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X') Xcount++;
                if(board[i][j]=='O') Ocount++;
            }
        }

        bool Owon=isWin(board,'O');
        bool Xwon=isWin(board,'X');

        if(Ocount>Xcount || Xcount-Ocount>1) return false;  //count off balance
        if(Xwon && Owon) return false;          //both canot win at same time
        if(Xwon && Xcount!=Ocount+1) return false; //if x wins it should have +1 chance than O
        if(Owon && Xcount!=Ocount) return false;  //if o wins it should have played equal chances as x as it begins last

        return true;
    }
};