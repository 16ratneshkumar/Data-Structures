//==============================================
// Traverse a Binary Search Tree in Inorder.
//==============================================

void inorder(Node* root){  //inorder: Left->Root->Right
    if (root != nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}