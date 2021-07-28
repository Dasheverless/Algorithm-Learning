
class Solution {
    /*
思路：
    1. 
下次：
    1.简化问题，一句话描述题目要干什么。
    2.分解问题，此题分为1.搜索target2.子树的距离3.其余部分的距离
    3.找到问题的核心：距离的定义，延申，推导等。
    2.找相同模式
    */
public:
    int flag = 0;
    int d = 0;
    vector<int> ans;
    void dfs(TreeNode* node, int k)
    {
        if(k < 0 || d > k)
            return;
        if(d==k)
        {
            ans.push_back(node->val);
            return;
        }
        if(node->left != NULL)
        {
            d++;
            dfs(node->left, k);
            d--;
        }
        if(node->right != NULL)
        {
            d++;
            dfs(node->right, k);
            d--;
        }
    }
    void search(TreeNode* node, int tar, int k)
    {
        if(node->val == tar)
        {
            flag = 1;
            dfs(node, k);
            return;
        }
        if(node->left != NULL)
        {
            search(node->left, tar, k);
            if(flag)
            {
                if(flag == k)
                    ans.push_back(node->val);
                flag++;
                if(node->right != NULL)
                {
                    dfs(node->right, k - flag);
                }
                return;
            }
        }
        if(node->right != NULL)
        {
            search(node->right, tar, k);
            if(flag)
            {
                if(flag == k)
                    ans.push_back(node->val);
                flag++;
                if(node->left != NULL)
                {
                    dfs(node->left, k - flag);
                }
                return;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        d = 0;
        search(root, target->val, k);
        return ans;
    }
};
