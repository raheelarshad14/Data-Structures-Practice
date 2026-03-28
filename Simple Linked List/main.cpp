#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Push Operations
    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {                     // if List is empty
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;                     // sets the tai value
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;              // if we only use the push front method
        }                                       // the first time it is used it sets the tail value
        else {                                  // to the first element added using this function which stays there
            newNode -> next = head;
            head = newNode;
        }
    }

    void pop_front() {

        if (head == NULL) {
            cout<<"List is Empty"<<endl;
        }
        else {
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout<<"List is Empty"<<endl;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* temp = head;
            while (temp -> next != tail) {
                temp = temp -> next;
            }
            delete tail;
            tail = temp;
            tail -> next = NULL;            //  important tail se agla null declare krna
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }

    void insertAt(int value, int index) {

        if (index <= 0) {                       // Index is less than bound
            push_front(value);                  // pushfront CASE 1
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != NULL; i++) {     // aik pehle wale pr ruk jaega
            temp = temp -> next;                                   // ya agr index zyada bada hai aur loop zyada aage nikal gya hai
        }                                       // that means ke temp has become Null so dont run the loop anymore
        if (temp == NULL || temp -> next == NULL) {  // instead do this CASE 2 index is larger
            push_back(value);
        }
        else {                                      // CASE 3 all good index in range
            Node * newNode = new Node(value);
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }

    }
};

int main() {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);

    list.push_back(50);

    list.pop_back();
    list.pop_front();

    list.insertAt(25,1);

    list.display();
}

