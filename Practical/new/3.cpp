/*3. Write a program to implement circular linked list as an ADT which supports the following operations:
    1. Insert an element x in the list 
    2. Remove an element from the list 
    3. Search for an element x in the list and return its pointer  
*/

//==============================================
// Using Double Linked List.
//==============================================

#include <iostream>

struct Node{
    Node* prev;
    int data;
    Node* next;
};

void insert(Node* &head,int value){
    Node* newnode = new Node();
    newnode->data = value;
    if (head == nullptr){
        head=newnode;
        newnode->prev = head;
        newnode->next = head;
        std::cout<<"Element "<<value<<" inserted from the list!"<<std::endl;
    } else{
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next = head;
        head->prev = newnode;
        std::cout<<"Element "<<value<<" inserted from the list!"<<std::endl;
    }
}

void del(Node* &head,int value){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp=head;
    Node* pre=nullptr;
    do{
        if (temp->data==value){
            pre=temp;
            break;
        }
        temp=temp->next;
    }while(temp!=head);

    if (pre==nullptr){
        std::cout<<"Element "<<value<<" not found in the list!"<<std::endl;
        return;
    }
    if (pre==head){
        if (head->next==head){
            delete head;
            std::cout<<"Element "<<value<<" deleted from the list!"<<std::endl;
            head= nullptr;
            return;
        }
        head=head->next;
        head->prev=pre->prev;
        pre->prev->next=head;
    } else{
    pre->prev->next=pre->next;
    pre->next->prev=pre->prev;
    }
    delete pre;
    std::cout<<"Element "<<value<<" deleted from the list!"<<std::endl;
}

Node* search(Node* &head,int value){
    Node* temp=head;
    while(temp->next!=head){
        if (temp->next->data==value || head->data==value){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

void display(Node *head){
    Node* temp = head;
    if (head==nullptr){
        std::cout<<"List is empty"<<std::endl;
        return;
    }
    do{
        std::cout<<temp->data<<"<->";
        temp = temp->next;

    }while (temp!=head);
    temp = temp->next;
    std::cout<<"<head>"<<std::endl;
}


Node* head=nullptr;
int main(){
    int choice,value,position;
    while (true){
        std::cout<<"1.Insert an element at end\n2.Remove an element using data\n3.Search for an element\n4.View the elements of list\n5.Exit\nEnter Your choice:: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                insert(head,value);
                break;
            case 2:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                del(head,value);
                break;
            case 3:
                Node* ptr;
                std::cout<<"Enter value:: ";
                std::cin>>value;
                ptr=search(head,value);
                if (ptr!= nullptr){
                    std::cout<<"Element "<<value<<" found at memory address: "<<ptr<<std::endl;
                }else{
                    std::cout<<"Element "<<value<<" not found in the list."<<std::endl;
                }
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
        }
    }
}

//==============================================
// Using Singly Linked List.
//==============================================

#include <iostream>

struct Node{
    int data;
    Node* next;
};

void insert(Node* &head,Node* &tail,int value){
    Node* newnode=new Node();
    newnode->data=value;
    tail=newnode;
    
    Node* temp=head;
    if (head==nullptr){
        head=newnode;
        head->next=newnode;
        std::cout<<"Element "<<value<<" inserted from the list!"<<std::endl;
        return;
    } else{
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    std::cout<<"Element "<<value<<" inserted from the list!"<<std::endl;
    }
}

void del(Node* &head, Node* &tail, int value) {
    if (head == nullptr) {
        std::cout << "List is empty!" <<std::endl;
        return;
    }
    if (head->data == value) {
        if (head == tail) {
            delete head;
            std::cout<<"Element "<<value<<" deleted from the list!"<<std::endl;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            std::cout<<"Element "<<value<<" deleted from the list!"<<std::endl;
        }
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == value) {
            prev->next = temp->next;
            if (temp == tail) {
                tail = prev;
            }
            delete temp;
            std::cout<<"Element "<<value<<" deleted from the list!"<<std::endl;
            return;
        }
    } while (temp != head);

    std::cout<<"Element"<<value<<" not found in the list."<<std::endl;
}

Node* search(Node* &head,int value){
    Node* temp = head;
    do {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return nullptr;
}

void display(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty!" <<std::endl;
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    std::cout << "(head)" <<std::endl;
}

Node* head=nullptr;
Node* tail= nullptr;

int main(){
    int choice,value,position;
    while (true){
        std::cout<<"1.Insert an element at end\n2.Remove an element using data\n3.Search for an element\n4.View the elements of list\n5.Exit\nEnter Your choice:: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                insert(head,tail,value);
                break;
            case 2:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                del(head,tail,value);
                break;
            case 3:
                Node* ptr;
                std::cout<<"Enter value:: ";
                std::cin>>value;
                ptr=search(head,value);
                if (ptr!= nullptr){
                    std::cout<<"Element "<<value<<" found at memory address: "<<ptr<<std::endl;
                }else{
                    std::cout<<"Element "<<value<<" not found in the list."<<std::endl;
                }
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
        }
    }
}
