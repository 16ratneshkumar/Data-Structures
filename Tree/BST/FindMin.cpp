//==============================================
// Find a minimum number in Binary Search Tree.
//==============================================

Node* FindMin(Node* root){
    while(root->left!=nullptr)
        root=root->left;
    return root;
}