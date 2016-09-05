#include"Configer.h"
/*将一个链表中的奇数放在偶数前面,然后将奇数序列分别偶数序列逆序*/

struct node
{
	int data;
	Node* next;
}; 
typedef node Node;

void Inverse(Node*& Head, Node*& Tail)
{
	if (Head != NULL && Tail != NULL)
	{
		Node *newHead = NULL, *newTail = NULL,*tmp = NULL;
		while (Head != Tail)
		{
			tmp = Head;
			Head = Head->next;
			if (newHead == NULL)
			{
				newHead = tmp;
				newTail = tmp;
				newTail->next = NULL;
			}
			else
			{
				tmp->next = newHead;
				newHead = tmp;
			}
		}
		Head->next = newHead;
		Tail = newTail;
	}
}

void Answer(Node*& list)
{
	Node *headLeft = NULL, *tailLeft = NULL, 
		*headRight = NULL, *tailRight = NULL,*tmp = list;
	while (tmp)
	{
		if (tmp->data % 2 == 1)
		{
			if (headLeft == NULL)
			{
				headLeft = tmp;
				tailLeft = headLeft;
			}
			else
			{
				tailLeft->next = tmp;
				tailLeft = tailLeft->next;
			}
		}
		else
		{
			if (headRight == NULL)
			{
				headRight = tmp;
				tailRight = headRight;
			}
			else
			{
				tailRight->next = tmp;
				tailRight = tailRight->next;
			}
		}
		tmp = tmp->next;
	}
	Inverse(headLeft, tailLeft);
	Inverse(headRight, tailRight);
	if (tailLeft)
	{
		tailLeft->next = headRight;
		list = headLeft;
	}
	else
		list = headRight;
}

