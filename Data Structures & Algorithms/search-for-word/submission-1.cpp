class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(board,word,i,j,0,vis)) return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, string word,int x,int y,int k,
    vector<vector<bool>>&vis){
        int n = board.size();
        int m = board[0].size();
        if(board[x][y]!=word[k]) return false;
        if(k==word.size()-1) return true;
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + dirs[i];
            int ny = y + dirs[i+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m &&!vis[nx][ny]){
                if(check(board, word,nx,ny,k+1,vis)) return true;
            }

        }
        vis[x][y] = false;
        return false;
    }
};
