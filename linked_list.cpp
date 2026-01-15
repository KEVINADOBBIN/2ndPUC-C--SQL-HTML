#include <iostream>
using namespace std;

class LinkList {
private:
    struct Node {
        int data;
        Node* link;
    };

    Node* start;

public:
    // Constructor
    LinkList() {
        start = nullptr;
    }

    // Print the linked list
    void Print() {
        if (start == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        cout << "Linked list contains: ";
        Node* temp = start;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    // Append a new node at the end
    void Append(int num) {
        Node* newNode = new Node;
        newNode->data = num;
        newNode->link = nullptr;

        if (start == nullptr) {
            start = newNode;
            cout << num << " is inserted as the first node" << endl;
            return;
        }

        Node* temp = start;
        while (temp->link != nullptr) {
            temp = temp->link;
        }

        temp->link = newNode;
        cout << num << " is inserted" << endl;
    }

    // Count number of nodes
    void Count() {
        int count = 0;
        Node* temp = start;

        while (temp != nullptr) {
            count++;
            temp = temp->link;
        }

        cout << "Number of nodes in the linked list: " << count << endl;
    }
};

int main() {
    LinkList* obj = new LinkList();

    obj->Print();

    obj->Append(100);
    obj->Print();
    obj->Count();

    obj->Append(200);
    obj->Print();
    obj->Count();

    obj->Append(300);
    obj->Print();
    obj->Count();

    delete obj;
    return 0;
}
