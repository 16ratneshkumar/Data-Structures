//==============================================
// Traverse Linked List
//==============================================
void traverse(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
        temp=temp->next;
    }
}



//==============================================
// Print or Display A Linked List
//==============================================
void display(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
        std::cout<<temp->data<<std::endl;
        temp=temp->next;
    }
}