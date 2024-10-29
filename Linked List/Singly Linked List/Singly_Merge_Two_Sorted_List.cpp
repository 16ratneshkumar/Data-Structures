//=================================================
// Merge Two Sorted Linked List
//=================================================
//==============================================
// Using Iterative Approach
//==============================================
Node* merge(Node* &head1,Node* &head2){
    if (!(head1)) return head2;
    if (!(head2)) return head1;
    Node* dummy=new Node();
    Node* head=dummy;
    dummy->data=1;
    dummy->next=nullptr;
    while(head1!=nullptr && head2!=nullptr){
        Node* newnode=new Node();
        if (head1->data > head2->data){
            newnode->data=head2->data;
            dummy->next=newnode;
            head2=head2->next;
        } else{
            newnode->data=head1->data;
            dummy->next=newnode;
            head1=head1->next;
        }
        dummy=dummy->next;
    }
    if (head1) dummy->next=head1;
    if (head2) dummy->next=head2;
    dummy=head;
    head=head->next;
    delete dummy;
    return head;
}

//==============================================
// Using Recursive Approach
//==============================================
Node* merge(Node* head1,Node* head2){
    if (!(head1)) return head2;
    if (!(head2)) return head1;

    if (head1->data <= head2->data){
        head1->next=merge(head1->next,head2);
        return head1;
    }else{
        head2->next=merge(head2->next,head1);
        return head2;
    }
}