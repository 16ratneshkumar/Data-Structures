//==============================================
// Insert an element in Binary Search Tree.
//==============================================

Node* Insert(Node* root,int value){
    if (root ==nullptr){
        root = createNode(value);
    }
    else if (value < root->data){
        root->left = Insert(root->left,value);
    }else if (value > root->data){
        root->right=Insert(root->right,value);
    }
    return root;
}