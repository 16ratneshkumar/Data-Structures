//==============================================
// Delete an element from Binary Search Tree.
//==============================================

Node* Delete(Node* root,int value){
    if (root == nullptr) return root;

    if (value < root->data) {
        root->left = Delete(root->left, value);
    }
    else if (value > root->data) {
        root->right = Delete(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findmin(root->right);
        root->data=temp->data;
        root->right = Delete(root->right,temp->data);
    }
    return root;
}