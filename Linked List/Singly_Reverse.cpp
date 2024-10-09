//==============================================
// Reverse A Linked List
//==============================================
//==============================================
// Using Iterative Approach
//==============================================
void reverse(Node* &head){
    Node* prev=nullptr;
    Node* curr=nullptr;
    Node* next=head;
    while(next!=nullptr){
        prev=curr;
        curr=next;
        next=next->next;
        curr->next=prev;
    }
    head=curr;
}


//==============================================
// Using Recursive Approach
//==============================================
