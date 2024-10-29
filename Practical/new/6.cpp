/*6. Write a program to implement Binary Search Tree as an ADT which supports the following operations: 
    1. Insert an element x 
    2. Delete an element x 
    3. Search for an element x in the BST  
    4. Display the elements of the BST in preorder, inorder, and postorder traversal  
*/
#include <iostream>
using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

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

Node* findmin(Node* root){
    while(root->left!=nullptr)
        root=root->left;
    return root;
}

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

Node* Search(Node* &root,int value){
    if (root == nullptr || root->data==value){
        return root;
    }
    if (value < root->data)
        return Search(root->left, value);
    return Search(root->right, value);
}


void preorder(Node* root){ //preorder: Root->Left->Right
    if (root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){  //inorder: Left->Root->Right
    if (root != nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(Node* root){  //postorder: Left->Right->Root
    if (root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


Node* root=nullptr;

int main(){
    int choice,value;
    while (true){
        std::cout<<"1.Insert an element.\n2.Remove an element\n3.Search for an element\n4.Display an element in Preorder.\n5.Display an element in Inorder\n6.Display an element in Postorder\n7.Exit\nEnter Your choice:: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                root = Insert(root,value);
                std::cout<<value<<" Inserted in the BST.\n"<<std::endl;
                break;
            case 2:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                if (Search(root, value) != nullptr)
                    std::cout<<value<<" Deleted from the BST.\n"<<std::endl;
                else
                    std::cout << "Element " << value << " not found in the BST.\n" << std::endl;
                root = Delete(root,value);
                break;
            case 3:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                if (Search(root, value) != nullptr)
                    std::cout << "Element " << value << " found in the BST.\n" << std::endl;
                else
                    std::cout << "Element " << value << " not found in the BST.\n" << std::endl;
                break;
            case 4:
                if (root!=nullptr){
                    std::cout << "Preorder traversal: ";
                    preorder(root);
                    std::cout<<std::endl;
                }
                else
                    std::cout<<"BST is Empty.\n"<<std::endl;
                break;
            case 5:
                if (root!=nullptr){
                    std::cout << "Inorder traversal: ";
                    inorder(root);
                    std::cout<<std::endl;
                }
                else
                    std::cout<<"BST is Empty.\n"<<std::endl;
                break;
            case 6:
                if (root!=nullptr){
                    std::cout << "Postorder traversal: ";
                    postorder(root);
                    std::cout<<std::endl;
                }
                else
                    std::cout<<"BST is Empty.\n"<<std::endl;
                break;
            case 7:
                return 0;
        }
    }
}