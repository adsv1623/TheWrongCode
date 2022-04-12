class Solution {
    int getSumSquare(vector<vector<int>> board, int x, int y){
        int n = board.size(), m = board[0].size();
        int ans=0;
        for(int i=x-1; i<x+2 ;i++){
            for(int j =y-1 ;j<y+2;j++){
                int xi=i, yj= j;
                if(i==x && j==y) continue;
                if(xi>=0 && yj>=0 && xi<n && yj<m ){
                    // safe
                    if(board[xi][yj]!=2)
                        ans+= board[xi][yj]==3?1: board[xi][yj];
                }
            }
        }
        return ans;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
       // 3: dead , 2:live 
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==1){
                    // Jinda huin mai ;)
                    int myNeigh = getSumSquare(board,i,j);
                    if(myNeigh < 2){
                        board[i][j] =3;
                    }else if(myNeigh ==2 || myNeigh ==3){
                        continue;
                        // not clear
                    }else{
                        board[i][j] =3;
                    }
                    
                }else{
                    // I'm dead ;)
                    int myNeigh = getSumSquare(board,i,j);
                    if(myNeigh==3){
                        board[i][j]=2;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==3) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
        
    }
};