class Solution {
public:
    TreeNode *CreateTree(int low ,int high,vector<int> &nums)
    {
        if(low>high)
        {
            return NULL;
        }
        int mid = low + (high-low)/2;
        TreeNode* n = new TreeNode(nums[mid]);
        n->left = CreateTree(low,mid-1,nums);
        n->right = CreateTree(mid+1,high,nums);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreateTree(0,nums.size()-1,nums);
    }
};
