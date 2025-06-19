#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;

    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* curr = &dummyHead;
    int carry = 0;

    while (p != NULL || q != NULL)
    {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        
        curr->next = createNode(sum % 10);
        curr = curr->next;

        if(p != NULL)
            p = p->next;
        if(q != NULL)
            q = q->next;
    }

    if(carry > 0)
        curr->next = createNode(carry);
    
    return dummyHead.next;
}

int main(int argc, char const *argv[])
{
    
    struct ListNode *resulLists;

    struct ListNode l11last = {
        3, NULL

    };

    struct ListNode l11second = {
        4,
        &l11last
    };

    struct ListNode l11first = {
        2,
        &l11second
    };

     struct ListNode l12last = {
        4, NULL

    };

    struct ListNode l12second = {
        6,
        &l12last
    };

    struct ListNode l12first = {
        5,
        &l12second
    };


    resulLists = addTwoNumbers(&l11first, &l12first);

    printf("[%i, %i, %i]\n", resulLists->val, resulLists->next->val, resulLists->next->next->val);

    struct ListNode l21last = {
        0, NULL

    };

    struct ListNode l22last = {
        0, NULL

    };

    resulLists = addTwoNumbers(&l21last, &l22last);
    
    printf("[%i]\n", resulLists->val);

    return 0;
}

