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
    TreeNode* searchBST(TreeNode* root, int val) {
     // if(root==NULL) return NULL;
     //    if(root->val == val) return root;
     //    if( val > root->val) return searchBST(root->right,val);
     //    else return searchBST(root->left, val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(val== temp->val) return temp;
            else if(val<temp->val && temp->left){
                q.push(temp->left);
            }else if(val>temp->val && temp->right){
                q.push(temp->right);
            }
        }
        return NULL;
    }
};