//==============================================
// Find a maximum number in Binary Search Tree.
//==============================================

Node* FindMax(Node* root){
    while(root->right!=nullptr)
        root=root->right;
    return root;
}