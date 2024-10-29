//===============================================
// Add Two Number Using Linked List
//===============================================
Node* sum(Node* head1,Node* head2){
    if (!(head1)) return head2;
    if (!(head2)) return head1;
    reverse(head1);//reverse function use from Singly_Reverse.cpp file.
    reverse(head2);
    Node* dummy=new Node();
    Node* head=dummy;
    dummy->data=1;
    dummy->next=nullptr;
    int carry =0;
    while(head1 || head2){
        Node* newnode=new Node();
        int firstval=head1 ? head1->data:0;
        int secval=head2 ? head2->data:0;
        int total=firstval + secval + carry;
        carry= total/10;
        total= total%10;
        newnode->data=total;
        dummy->next=newnode;
        dummy=dummy->next;

        head1=head1 ? head1->next : head1;
        head2=head2 ? head2->next : head2;
    }
    if (carry){
        Node* newnode=new Node();
        newnode->data=carry;
        dummy->next=newnode;
    }
    dummy=head;
    head=head->next;
    delete dummy;
    reverse(head);
    return head;
}