
class Solution {
public:
    int ans=0;
    
    void helper(TreeNode*root, int sum) {
        if(root==NULL)
            return ;
        if(root->val == sum)
            ans++;
        
        sum -= root->val;
        
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return 0;
        
        helper(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return ans;
    }
};
