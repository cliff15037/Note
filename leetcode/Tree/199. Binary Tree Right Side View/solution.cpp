/*
  This is my first thought and solution, maintain a layer to record.
*/
class Solution {
public:
    void helper(TreeNode* root, vector<int> &res, int &layerGlobal, int layerLocal) {
        if (!root) return;

        if(layerLocal>layerGlobal){
            res.push_back(root->val);
            layerGlobal++;
        }
        
        if (root->right) {
            helper(root->right, res, layerGlobal, layerLocal+1);
        } 
        if (root->left) {
            helper(root->left, res, layerGlobal, layerLocal+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int layer=0;
        helper(root, res, layer, 1);
        return res;
    }
};

/*
  But it can be optimized, and this problem can actually be solved by BFS(Level-Order traversal)
*/
class Solution {
public:
    void helper(TreeNode* root, vector<int> &res, int depth) {
        if (!root) return;

        if( depth == res.size()){
            res.push_back(root->val); // This step also increment depth
        }
        
        if (root->right) {
            helper(root->right, res, depth+1);
        } 
        if (root->left) {
            helper(root->left, res, depth+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int depth=0;
        helper(root, res, depth);
        return res;
    }
};
