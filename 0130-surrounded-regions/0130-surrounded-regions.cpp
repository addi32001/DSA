class Solution {
private:
    void dfs(int x,int y,vector<vector<char>>&board,vector<vector<int>>&vis){
        int n = board.size();
        int m = board[0].size();
        int drow[]={0,0,-1,1};
        int dcol[] = {-1,1,0,0};
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x + drow[i]; 
            int ny = y + dcol[i]; 
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && board[nx][ny]=='O'){
                dfs(nx,ny,board,vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            //last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }

            }
        }
    }
};