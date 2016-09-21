#include <iostream>
using namespace::std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode *ptr = new ListNode(0);
		ListNode *head = ptr;
		int carry = (l1->val + l2->val)/10;
		ptr->val = (l1->val + l2->val)%10;	
		l1 = l1->next;
		l2 = l2->next;
		while(l1 && l2)
		{
			ptr->next = new ListNode(0);
			ptr = ptr->next;
			ptr->val = (l1->val + l2->val + carry)%10;	
			carry = (l1->val + l2->val + carry)/10;
			l1 = l1->next;
			l2 = l2->next;
		}

		if(l1==NULL)
		{
			while(l2)
			{
				ptr->next = new ListNode(0);
				ptr = ptr->next;
				ptr->val = (carry + l2->val)%10;
				carry = (carry + l2->val)/10;
				l2 = l2->next;
			}
		}
		if(l2==NULL)
		{
			while(l1)
			{
				ptr->next = new ListNode(0);
				ptr = ptr->next;
				ptr->val = (carry + l1->val)%10;
				carry = (carry + l1->val)/10;
				l1 = l1->next;
			}
		}
		if(carry)
		{
			ptr->next = new ListNode(0)
			ptr = ptr->next;
			ptr->val = carry;
		}
		return head;
	}

};
