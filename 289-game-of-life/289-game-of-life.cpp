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
                    ans+= board[xi][yj];
                }
            }
        }
        return ans;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) arr[i][j]= board[i][j];
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==1){
                    // Jinda huin mai ;)
                    int myNeigh = getSumSquare(arr,i,j);
                    if(myNeigh < 2){
                        board[i][j] =0;
                    }else if(myNeigh ==2 || myNeigh ==3){
                        continue;
                        // not clear
                    }else{
                        board[i][j] =0;
                    }
                    
                }else{
                    // I'm dead ;)
                    int myNeigh = getSumSquare(arr,i,j);
                    if(myNeigh==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};