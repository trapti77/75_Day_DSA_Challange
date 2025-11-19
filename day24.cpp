
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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head1 = reverseList(slow->next);
        slow->next = NULL;
        ListNode *head2 = head;
        ListNode *temp1 = new ListNode(0);
        ListNode *temp2 = temp1;
        while (head1 && head2)
        {
            if (head2)
            {
                temp1->next = head2;
                temp1 = temp1->next;
                head2 = head2->next;
            }
            if (head1)
            {
                temp1->next = head1;
                temp1 = temp1->next;
                head1 = head1->next;
            }
        }
        if (head2)
        {
            while (head2)
            {
                temp1->next = head2;
                temp1 = temp1->next;
                head2 = head2->next;
            }
        }
        if (head1)
        {
            while (head1)
            {
                temp1->next = head1;
                temp1 = temp1->next;
                head1 = head1->next;
            }
        }
        head = temp2->next;
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
    list->reorderList(list->head);
    list->PrintList(list->head);
    return 0;
}