#include <iostream>

using namespace std;

class ListOfNumber
{
    struct ListNode
    {
        int value;
        ListNode *next;
    };
    ListNode *head;
public:
    ListOfNumber()
    {
        head = 0;
    }
    ~ListOfNumber();
    void appendNode (int);
    void insertNode (int);
    void deleteNode (int);
    void displayList () const;
};

void ListOfNumber::appendNode(int num)
{
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = 0;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;

        while(nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

void ListOfNumber::displayList() const
{
    ListNode *nodePtr;

    nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << endl;

        nodePtr = nodePtr->next;
    }
}

void ListOfNumber::insertNode(int num)
{
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *perviousNode = 0;

    newNode = new ListNode;
    newNode->value = num;

    if (head == 0)
    {
        head = newNode;
        newNode->next = 0;
    }
    else
    {
        nodePtr = head;

        perviousNode = 0;

        while (nodePtr != 0 && nodePtr->value < num)
        {
            perviousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (perviousNode == 0)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            perviousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void ListOfNumber::deleteNode(int num)
{
    ListNode *nodePtr;
    ListNode *previousNode;

    if (!head)
    return;

    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

ListOfNumber::~ListOfNumber()
{
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
}
int main()
{
    ListOfNumber number;
    number.appendNode(1);
    number.appendNode(2);
    number.appendNode(4);
    number.appendNode(5);

    number.insertNode(3);

    number.displayList();

    cout << "delete 2" << endl;

    number.deleteNode(2);

    number.displayList();


    return 0;
}
