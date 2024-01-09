#include <iostream>

using namespace std;

struct Node
{
    int val;
    struct Node *left, *right;

    Node(int v)
    {
        this->val = v;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }
    Node *insertIntoBST(Node *root, int val)
    {
        if (root == nullptr)
            return root = new Node(val);

        if (root->val < val)
            root->right = insertIntoBST(root->right, val);

        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }

    Node *MinNode(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        return MinNode(root->left);
    }

    Node *deleteFromBST(Node *root, int val)
    {
        if (root == NULL)
            return NULL;

        if (root->val == val)
        {
            // if root contains 0 child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // if root contains left subtree
            if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // if root contains right subtree
            if (root->left == NULL & root->right != NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // if root contains both left & right subtree
            if (root->left != NULL & root->right != NULL)
            {
                int min = MinNode(root->right)->val;
                root->val = min;
                root->right = deleteFromBST(root->right, min);
                delete root;
            }
        }

        else if (root->val < val)
        {
            root->right = deleteFromBST(root->right, val);
            return root;
        }
        else
        {
            root->left = deleteFromBST(root->left, val);

            return root;
        }
    }
    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);

        cout << root->val << " ";

        inOrder(root->right);
    }
};

int main()
{

    BST b1;
    b1.root = b1.insertIntoBST(b1.root, 60);
    b1.root = b1.insertIntoBST(b1.root, 20);
    b1.root = b1.insertIntoBST(b1.root, 50);
    b1.root = b1.insertIntoBST(b1.root, 10);
    b1.root = b1.insertIntoBST(b1.root, 30);

    b1.inOrder(b1.root);

    return 0;
}