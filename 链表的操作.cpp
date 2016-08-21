#include"Configer.h"
/*将一个链表中的奇数放在偶数前面,然后将奇数序列分别偶数序列逆序*/

struct Node
{
	Node(int num = 0)
		:data(num), next(NULL)
	{}
	int data;
	Node* next;
}; 
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
	bool sign[2] = { 1,1 };
	while (tmp)
	{
		if (tmp->data % 2 == 1)
		{
			if (sign[0])
			{
				headLeft = tmp;
				tailLeft = headLeft;
				sign[0] = false;
			}
			else
			{
				tailLeft->next = tmp;
				tailLeft = tailLeft->next;
			}
		}
		else
		{
			if (sign[1])
			{
				headRight = tmp;
				tailRight = headRight;
				sign[1] = false;
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

int main()
{
	Node List[10];
	for (int i = 0; i < 10; ++i)
	{
		List[i].data = i;
	}
	for (int i = 0; i < 9; ++i)
	{
		List[i].next = List + i + 1;
	}
	Node* p = &List[0];
	Answer(p);
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}