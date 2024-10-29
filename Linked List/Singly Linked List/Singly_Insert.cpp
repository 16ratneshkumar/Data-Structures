//=================================================
// Insert An Element At Starting Of The Linked List
//=================================================
void insert(Node* &head,int value){
    Node* newnode= new Node();
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}

//===============================================
// Insert An Element At Middle Of The Linked List
//===============================================
void insert(Node* &head,int value,int loc){
    Node* newnode= new Node();
    newnode->data=value;
    Node* curr=head;
    while (curr->next->data != loc){
        curr=curr->next;
    }
    newnode->next=curr->next->next;
    curr->next->next=newnode;
}


//==============================================
// Insert An Element At end Of The Linked List
//==============================================
void insert(Node* &head,int value){
    Node* newnode= new Node();
    newnode->data=value;
    Node* temp=head;
    if (head==nullptr){
        head=newnode;
        head->next=nullptr;
        return;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}