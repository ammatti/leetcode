//DFS version


#include <iostream>
#include <vector>
#include <utility>

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
    int mini_depth = 65535;
    vector < pair<int, TreeNode*> > tree;
    if (root == NULL) {return 0;}
    else{
        tree.push_back(make_pair(1, root));
    }
    while(!tree.empty()){
        //find children
        pair<int, TreeNode*> currentnode_pair = tree.back();
        tree.pop_back();
        int current_depth = currentnode_pair.first;
        TreeNode* currentNode = currentnode_pair.second;
        TreeNode *leftChild = currentNode->left;
        int next_depth = current_depth+1;
        if (leftChild != NULL){
           tree.push_back(make_pair(next_depth, leftChild));
        }
        TreeNode *rightChild = currentNode->right;
        if (rightChild != NULL){
           tree.push_back(make_pair(next_depth, rightChild));
        }

        //if a leaf node
        if((leftChild == NULL) && (rightChild == NULL) && (current_depth < mini_depth)){
            mini_depth = current_depth;
        }
        

    }
    ans = mini_depth;
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
                               
