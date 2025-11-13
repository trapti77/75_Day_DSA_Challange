#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{

public:
    ListNode *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertNode(int data)
    {
        ListNode *newNode = new ListNode(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    void PrintList(ListNode *head)
    {
        if (head != NULL)
        {
            ListNode *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
        else
        {
            cout << "there is no data in list" << endl;
        }
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *temp;

        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

int main()
{
    LinkedList *list = new LinkedList();

    list->insertNode(1);
    list->insertNode(2);
    list->insertNode(3);
    list->insertNode(4);
    list->insertNode(5);

    list->PrintList(list->head);
    cout << endl;
    ListNode *ans = list->reverseList(list->head);
    list->PrintList(ans);
    return 0;
}