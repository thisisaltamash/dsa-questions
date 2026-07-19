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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // column -> row -> sorted values
        map<int, map<int, multiset<int>>> nodes;

        // Queue stores: Node, (Vertical, Level)
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int vertical = temp.second.first;
            int level = temp.second.second;

            nodes[vertical][level].insert(node->val);

            if (node->left)
                q.push({node->left, {vertical - 1, level + 1}});

            if (node->right)
                q.push({node->right, {vertical + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto p : nodes) {

            vector<int> col;

            for (auto q : p.second) {

                for (auto val : q.second) {
                    col.push_back(val);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};