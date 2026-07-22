/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Map to store parent of each node
    unordered_map<TreeNode*, TreeNode*> parent;

    // Function to build parent mapping
    void markParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Step 1: Store parent of every node
        markParents(root);

        // Step 2: BFS starting from target node
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {

            // If current level is k, stop
            if (distance == k)
                break;

            int size = q.size();
            distance++;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                // Visit left child
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // Visit right child
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // Visit parent
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
        }

        // Step 3: All nodes left in queue are at distance k
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
}
;