//==============================================
// Check Linked List Is Pallindrone Or Not
//==============================================
//===================================================
// Approach 1:Create A Copy & Reverse It.
//          Traverse The List And Compare Each Value.
//===================================================
bool isPallindrone(Node* head){
    if (head==nullptr){
        return false;
    }
    Node* Rev_head=head;
    reverse(Rev_head);
    while (head){
        if(head->data != Rev_head->data) return false;
        head=head->next;
        Rev_head=Rev_head->next;
        return true;
    }
}
