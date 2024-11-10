#include <iostream>
using namespace std;

// creating struct for node
struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    // constructor to initialize head as null
    LinkedList() : head(NULL) {}

    // insertion
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        // new node inserted will point to previous head
        newNode->next = head;
        // update new node as head
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        // if list was empty, set as first node
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPos(int value, int position) {
        if (position < 1) {
            cout << "position should be valid (>=1)" << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;

        // traversing to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        // if position is out of range
        if (!temp) {
            cout << "position out of range" << endl;
            delete newNode;
            return;
        }
        // insert at desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // deletion
   void deleteFromBeginning() {
        if (!head) {
            cout << "list is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    // function to delete the last node of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "list is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        // traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        // delete the last node
        delete temp->next; 
        // set the second-to-last node's next to null
        temp->next = NULL; 
    }

    // function to delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "position out of range." << endl;
            return;
        }
        // save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // update the next pointer
        temp->next = temp->next->next;   
         // delete the node
        delete nodeToDelete;            
    }

    
    // display
    void display(){
        if(!head){
            cout<<"list is empty";
            return;
        }
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    
    // search
    bool search(int value){
        Node* temp=head;
        int position=1;
        while(temp){
            if(temp->data==value){
                cout<<"value "<<value<<" found at position "<<position<<endl;
                return true;
            }
            temp = temp->next; // move to the next node
            position++; // increment position

        }
        cout<<"value "<<value<<" not found\n";
        return false;
    }
};

int main() {
    LinkedList list;

    // insertion examples with changed values
    list.insertAtBeginning(30);
    list.insertAtEnd(50);
    list.insertAtPos(40, 2);
    list.insertAtPos(60, 5);
    list.insertAtPos(70, 3);

    cout << "linked list after insertions: ";
    list.display();

    // deletion examples with changed values
    list.deleteFromBeginning();
    cout << "linked list after deleting at beginning: ";
    list.display();

    list.deleteFromEnd();
    cout << "linked list after deleting at end: ";
    list.display();

    list.deleteFromPosition(3);
    cout << "linked list after deleting from position 3: ";
    list.display();

    // search examples with changed values
    list.search(40);  // searching for a value that exists
    list.search(100);  // searching for a value that does not exist

    return 0;
}
