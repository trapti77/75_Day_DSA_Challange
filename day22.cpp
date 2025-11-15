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

void insertNode(int data, ListNode *head)
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

ListNode *convertToList(vector<int>ans){
    ListNode *head = new ListNode(0);
    ListNode *dummy = head;
    for (int i = 0; i < ans.size();i++){
        ListNode *temp = new ListNode(ans[i]);
        dummy->next = temp;
        dummy = dummy->next;
    }
    return head->next;
}
    // Brute Force Approach
    ListNode *mergeKthLists1(vector<ListNode *> lists)
{

   
    vector<int> ans;
    for (ListNode *list : lists)
    {
        while(list!=NULL){
            ans.push_back(list->data);
            list = list->next;
        }
    }
    sort(ans.begin(), ans.end());
    ListNode *temp = convertToList(ans);
    return temp;
}

//Optimized Approach
ListNode *mergeKthLists(vector<ListNode *> lists)
{

    ListNode *temp = lists[0];
    for (ListNode *lis : lists)
    {
        temp = mergeTwoLists(temp, lis);
    }
    return temp;
}



int main()
{
    ListNode *list = new ListNode(0);
    ListNode *list1 = new ListNode(1);
    ListNode *list2 = new ListNode(2);
    ListNode *list3 = new ListNode(3);
    insertNode(1, list);
    insertNode(2, list);
    insertNode(5, list);
    insertNode(4, list1);
    insertNode(7, list1);
    insertNode(8, list1);
    insertNode(11, list2);
    insertNode(12, list2);
    insertNode(15, list2);
    insertNode(17, list2);
    insertNode(13, list3);
    insertNode(14, list3);
    insertNode(18, list3);
    vector<ListNode *> lists(4);
    lists.push_back(list);
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode *ans = mergeKthLists(lists);
    PrintList(ans);
    return 0;
}