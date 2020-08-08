class Solution {
public:
    
    class Node {
        public: 
        TreeNode* node;
        int hl;
        int vl;
        Node(TreeNode* node, int hl, int vl) {
            this->node = node;
            this->hl = hl;
            this->vl = vl;
        }
    };
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root==NULL) return{};
        
        queue<Node> pending;
        map<int,map<int,vector<int>>> mapp;
        
        Node temp(root,0,0);
        
        pending.push(temp);
        
        while(!pending.empty()){
            auto front = pending.front();
            pending.pop();
            
            TreeNode* curNode = front.node;
            int hl = front.hl;
            int vl = front.vl;
            
            mapp[vl][hl].push_back(curNode->val);
            
            if(curNode->left){
                Node left(curNode->left, hl+1, vl-1);
                pending.push(left);
            }
            if(curNode->right){
                Node right(curNode->right, hl+1, vl+1);
                pending.push(right);
            }
        }
        
        vector<vector<int>> result;
        
        for(auto it=mapp.begin(); it!=mapp.end(); it++) {
            vector<int> temp;
            auto hmap = it->second;
            for(auto it1= hmap.begin(); it1!=hmap.end(); it1++){
                sort(it1->second.begin(), it1->second.end());
                for(int nodeVal : it1->second) {
                    temp.push_back(nodeVal);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
