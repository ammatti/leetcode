//recursive version


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    int ans = 0;
    int rightDepth = 0, leftDepth = 0;

    if (root == NULL) return 0;

    TreeNode *leftChild = root->left;
    TreeNode *rightChild = root->right;

    if (leftChild != NULL) {
      leftDepth = minDepth(leftChild);
    }

    if (rightChild != NULL) {
      rightDepth = minDepth(rightChild);
    }

    if((leftDepth!=0) && (rightDepth!=0)) {ans = rightDepth < leftDepth ? rightDepth : leftDepth;}
    else{
      ans = rightDepth > 0 ? rightDepth : leftDepth;
    }
    ans = ans + 1;
    return ans;
  }
};

int main() {

  Solution s;
  TreeNode root = TreeNode(3);
  TreeNode a = TreeNode(9);
  TreeNode b = TreeNode(20);
  TreeNode c = TreeNode(15);
  TreeNode d = TreeNode(7);
  root.left = &a;
  root.right = &b;
  b.left = &c;
  b.right = &d;
  int ans = s.minDepth(&root);
  cout<<ans<<endl;
  return 0;
}
                               
