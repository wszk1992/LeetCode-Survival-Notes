class Solution {
private:
    struct BSTNode {
        long val;
        int leftNum;
        int count;
        BSTNode* left;
        BSTNode* right;
        BSTNode(long _val) : val(_val), leftNum(0), count(1), left(NULL), right(NULL) {}
    };
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int pairs = 0;
        int n = nums.size();
        BSTNode* root = new BSTNode((long)nums[n-1] * 2);
        for(int i = n-2; i >= 0; i--) {
            //find the number of nodes whose value less than current num
            BSTNode* p = root; 
            while(p) {
                if((long)nums[i] > p->val) {
                    pairs += p->leftNum + p->count;
                    p = p->right;
                } else {
                    p = p->left;
                }
            }
            //insert node
            p = root;
            while(1) {
                if((long)nums[i] * 2 > p->val) {
                    if(p->right) {
                        p = p->right;
                    } else {
                        p->right = new BSTNode((long)nums[i] * 2);
                        break;
                    }
                } else if((long)nums[i] * 2 < p->val) {
                    p->leftNum++;
                    if(p->left) {
                        p = p->left;
                    } else {
                        p->left = new BSTNode((long)nums[i] * 2);
                        break;
                    }
                } else {
                    p->count++;
                    break;
                }
            }
        }
        return pairs;
    }
};