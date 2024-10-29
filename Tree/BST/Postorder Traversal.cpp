//==============================================
// Traverse a Binary Search Tree in Postorder.
//==============================================

void postorder(Node* root){  //postorder: Left->Right->Root
    if (root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}