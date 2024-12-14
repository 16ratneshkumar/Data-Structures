//=================================================
// Insert An Element At Starting Of The Linked List
//=================================================
void insert(Node* &head,int value){
    Node* newnode= new Node();
    newnode->prev=nullptr;
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}

//===============================================
// Insert An Element At Middle Of The Linked List
//===============================================
void insert(Node* &head,int value,int loc){
    Node* newnode= new Node();
    if (loc==1){
        newnode->prev=nullptr;
        newnode->data=value;
        newnode->next=head;
        head=newnode;
        return;
    }
    Node* temp=head;
    for(int i=0;i<loc-2;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->data=value;
}


//==============================================
// Insert An Element At end Of The Linked List
//==============================================
void insert(Node* &head,int value){
    Node* newnode= new Node();
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->data=value;
    newnode->next=nullptr;
}