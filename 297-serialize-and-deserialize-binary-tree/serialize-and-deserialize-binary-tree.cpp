/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st;
        if(!root)
            return st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(!node)
                    st += "#,";
                else {
                    st += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        stringstream s(data);
        string st;
        queue<TreeNode*> q;
        getline(s, st, ',');
        TreeNode* root = new TreeNode(stoi(st));
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, st, ',');
            if(st == "#")
                node->left = NULL;
            else {
                node->left = new TreeNode(stoi(st));
                q.push(node->left);
            } 
            getline(s, st, ',');
            if(st == "#")
                node->right = NULL;
            else {
                node->right = new TreeNode(stoi(st));
                q.push(node->right);
            } 
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));