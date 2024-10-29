//==============================================
// Search an element in Binary Search Tree.
//==============================================

Node* Search(Node* &root,int value){
    if (root == nullptr || root->data==value){
        return root;
    }
    if (value < root->data)
        return Search(root->left, value);
    return Search(root->right, value);
}