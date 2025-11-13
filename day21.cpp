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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        ListNode *temp = new ListNode(0);
        ListNode *ptr = temp;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data <= list2->data)
            {
                ptr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        if (list1 != NULL)
        {
            while (list1 != NULL)
            {
                ptr->next = list1;
                list1 = list1->next;
                ptr = ptr->next;
            }
        }
        if (list2 != NULL)
        {
            while (list2 != NULL)
            {
                ptr->next = list2;
                list2 = list2->next;
                ptr = ptr->next;
            }
        }
        return temp->next;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    LinkedList *list1 = new LinkedList();
    list->insertNode(1);
    list->insertNode(2);
    list->insertNode(5);
    list1->insertNode(4);
    list1->insertNode(7);
    list1->insertNode(8);
    

    ListNode *ans = list->mergeTwoLists(list->head, list1->head);
    list->PrintList(ans);
    return 0;
}