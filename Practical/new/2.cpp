/* 2. Write a program to implement doubly linked list as an ADT that supports the following operations: 
    1. Insert an element x at the beginning of the doubly linked list 
    2. Insert an element x at the end of the doubly linked list 
    3. Remove an element from the beginning of the doubly linked list 
    4. Remove an element from the end of the doubly linked list
*/

#include <iostream>

struct Node{
    Node* prev;
    int data;
    Node* next;
};


void insert_at_begin(Node* &head,int value){
    Node* newnode= new Node();
    newnode->prev=nullptr;
    newnode->data=value;
    newnode->next=head;
    if (head!=nullptr){
        head->prev = newnode;
    }
    head=newnode;
    std::cout<<head->data<<"->"<<"Inserted"<<std::endl;
}

void insert_at_end(Node* &head,int value){
    if (head==nullptr){
        insert_at_begin(head,value);
        return;
    }
    Node* newnode= new Node();
    newnode->prev=nullptr;
    newnode->data=value;
    newnode->next=nullptr;
    Node* temp=head;
    while (temp->next!=nullptr){
        temp=temp->next;
    }
    if (temp!=nullptr){
        temp->next=newnode;
        newnode->prev=temp;
    }
    std::cout<<newnode->data<<"->"<<"Inserted"<<std::endl;
}

void remove_from_begin(Node* &head){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    std::cout<<temp->data<<"->"<<"Deleted"<<std::endl;
    delete temp;
}

void remove_from_end(Node* &head){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    if (head->next==nullptr){
        std::cout<<head->data<<"->"<<"Deleted"<<std::endl;
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    while (temp->next!=nullptr){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    std::cout<<temp->data<<"->"<<"Deleted"<<std::endl;
    delete temp;

}

void display_forward(Node* head){
    if (head ==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp =head;
    while(temp->next!=nullptr){
        std::cout<<temp->data<<"->";
        temp=temp->next;
    }
    std::cout<<temp->data<<"->";
    std::cout<<"Null"<<std::endl;
}

void display_backword(Node* &head){
    if (head ==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp =head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    while(temp!=nullptr){
        std::cout<<temp->data<<"->";
        temp=temp->prev;
    }
    std::cout<<"Null"<<std::endl;
}


Node* head = nullptr;
int main(){
    int choice,value;
    while (true){
        std::cout<<"1.Insert an element at begin\n2.Insert an element at end\n3.Remove an element from begin\n4.Remove an element from end\n5.View linked list Forword\n6.View linked list Backword\n7.Exit\nEnter Your choice:: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                insert_at_begin(head,value);
                break;
            case 2:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                insert_at_end(head,value);
                break;
            case 3:
                remove_from_begin(head);
                break;
            case 4:
                remove_from_end(head);
                break;
            case 5:
                display_forward(head);
                break;
            case 6:
                display_backword(head);
                break;
            case 7:
                return 0;
        }
    }
}
