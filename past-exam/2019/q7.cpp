#include <iostream>
#include <climits>
using namespace std;

typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

/* Preorder traversal */
void preorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/* Find the smallest data value in a leaf of the tree */
int find_min_leaf(TreeNode *root) {
    if (root == NULL) {
        return INT_MAX;   // no leaf exists in an empty tree
    }

    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }

    int leftMin = find_min_leaf(root->left);
    int rightMin = find_min_leaf(root->right);

    if (leftMin < rightMin) {
        return leftMin;
    } else {
        return rightMin;
    }
}

int main() {
    /*
        Build this tree:

               10
              /  \
             5    20
            / \     \
           2   7     15

        Leaf nodes are: 2, 7, 15
        Smallest leaf value should be 2
    */
    TreeNode n2 = {2, NULL, NULL};
    TreeNode n7 = {7, NULL, NULL};
    TreeNode n15 = {15, NULL, NULL};
    TreeNode n5 = {5, &n2, &n7};
    TreeNode n20 = {20, NULL, &n15};
    TreeNode root = {10, &n5, &n20};

    cout << "Preorder traversal: ";
    preorder(&root);
    cout << endl;

    int minLeaf = find_min_leaf(&root);
    cout << "Smallest leaf value: " << minLeaf << endl;

    // write a case for empty tree.
    TreeNode empty = {};
    cout << "Preorder traversal of empty tree: ";
    preorder(&empty);
    cout << endl;
    int minLeafEmpty = find_min_leaf(&empty);
    cout << "Smallest leaf value of empty tree: " << minLeafEmpty << endl;
    cout << INT_MAX << endl;

    return 0;
}