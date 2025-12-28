#include <iostream>
using namespace std;

class LinkList
{
private:
    struct Node
    {
        int data;
        Node* link;
    } *START;

public:
    LinkList();
    void Print();       // Prints the contents
    void Append(int num); // Adds a new node at the end
    void Count();       // Counts number of nodes
};

// Constructor
LinkList::LinkList()
{
    START = nullptr;
}

// Prints the contents of linked list
void LinkList::Print()
{
    if (START == nullptr)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    cout << "Linked list contains: ";
    Node* tmp = START;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << endl;
}

// Adds a new node at the end of the linked list
void LinkList::Append(int num)
{
    Node* newNode = new Node;
    newNode->data = num;
    newNode->link = nullptr;

    if (START == nullptr)
    {
        // Create first node
        START = newNode;
        cout << num << " is inserted as the first node" << endl;
    }
    else
    {
        // Traverse to the end
        Node* tmp = START;
        while (tmp->link != nullptr)
            tmp = tmp->link;

        tmp->link = newNode;
        cout << num << " is inserted" << endl;
    }
}

// Counts number of nodes in the linked list
void LinkList::Count()
{
    Node* tmp;
    int c = 0;

    // Traverse the entire linked list
    for (tmp = START; tmp != nullptr; tmp = tmp->link)
        c++;

    cout << "No. of nodes in the linked list = " << c << endl;
}

int main()
{
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

    delete obj; // Free memory
    return 0;
}
