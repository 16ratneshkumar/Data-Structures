//==============================================
// Traverse a Binary Search Tree in Preorder.
//==============================================

void preorder(Node* root){ //preorder: Root->Left->Right
    if (root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}