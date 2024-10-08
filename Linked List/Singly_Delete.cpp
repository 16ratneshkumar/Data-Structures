//=================================================
// Delete An Element At Starting Of The Linked List
//=================================================
void deleteNode(Node* &head){
    Node* temp=head;
    head=head->next;
    delete temp;
}

//===============================================
// Delete An Element At Middle Of The Linked List
//===============================================
void deleteNode(Node* &head,int value){
    Node* prev= nullptr;
    Node* curr=head;
    while (curr->next->data!=value){
        curr=curr->next;
    }
    prev=curr->next;
    curr->next=curr->next->next;
    delete prev;
}


//==============================================
// Delete An Element At End Of The Linked List
//==============================================
//==============================================
// Using 2 Pointer
//==============================================
void deleteNode(Node* &head){
    Node* prev= nullptr;
    Node* curr=head;
    while (curr->next!=nullptr){
        prev=curr;
        curr=curr->next;
    }
    prev->next=nullptr;
    delete curr;
}

//==============================================
// Using 1 Pointer
//==============================================
void deleteNode(Node* &head){
    Node* curr=head;
    while (curr->next->next!=nullptr){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=nullptr;
}