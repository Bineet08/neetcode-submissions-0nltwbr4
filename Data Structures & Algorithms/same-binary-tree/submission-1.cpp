/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false; 
        return check(p,q);
    }
private:
    bool check(TreeNode* p, TreeNode* q){
        if(q->val != p->val) return false;
        if(p->left || q->left){
        if(p->left && q->left) return check(p->left, q->left);
        else return false;
        }
        if(p->right || q->right){
        if(p->right && q->right) return check(p->right, q->right);
        else return false;
        }
        return true;
    }
};
