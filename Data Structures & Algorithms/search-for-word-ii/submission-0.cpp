class TrieNode{
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode(){
        for(int i=0;i<26;i++) children[i] = nullptr;
        isLeaf = false;
    }
};

class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};

    void insert(TrieNode* root, const string& key){
        TrieNode* curr = root;
        for(char c : key){
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node,
             vector<string>& res, string& curr, vector<vector<bool>>& vis){

        char c = board[x][y];
        if(node->children[c-'a'] == nullptr) return;

        node = node->children[c-'a'];
        curr.push_back(c);

        if(node->isLeaf){
            res.push_back(curr);
            node->isLeaf = false;
        }

        vis[x][y] = true;

        int n = board.size(), m = board[0].size();
        for(int i=0;i<4;i++){
            int nx = x + dirs[i];
            int ny = y + dirs[i+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                dfs(board, nx, ny, node, res, curr, vis);
            }
        }

        vis[x][y] = false;
        curr.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto &w: words) insert(root, w);

        int n = board.size(), m = board[0].size();
        vector<string> res;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        string curr = "";

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board, i, j, root, res, curr, vis);
            }
        }
        return res;
    }
};