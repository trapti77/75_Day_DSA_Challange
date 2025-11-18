//DELETE NTH NODE FROM THE END OF THE LINKEDLIST

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 0;
        ListNode *ptr = head;
        ListNode *temp = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        int i = length - n;
        if (i == 0)
        {

            return head->next;
        }

        while (temp != NULL)
        {
            i--;
            if (i == 0)
            {
                break;
            }
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            return slow->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};