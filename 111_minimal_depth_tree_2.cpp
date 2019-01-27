//BFS Version

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
    int current_depth = 0;
    vector< pair<int, TreeNode*> > tree;
    
    if (root == NULL) {return 0;}
    else{
          tree.push_back(make_pair(1, root));
          current_depth = current_depth+1;
    }
    while(!tree.empty()){
      pair<int, TreeNode*> current_node_pair = tree.front();
      tree.erase(tree.begin());
      current_depth = current_node_pair.first;      
      TreeNode* current_node = current_node_pair.second;
      TreeNode *leftChild = current_node->left;
      TreeNode *rightChild = current_node->right;
      if(leftChild != NULL){
        tree.push_back(make_pair(current_depth+1, leftChild));
      }
      if(rightChild != NULL){
        tree.push_back(make_pair(current_depth+1, rightChild));
      }
      if (leftChild == NULL && rightChild == NULL){
        return current_depth;
      }
    }
    ans  = current_depth;
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
                               
