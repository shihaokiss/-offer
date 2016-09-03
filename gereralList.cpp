#include"Configer.h"

enum Type
{
	HEAD,
	VALUE,
	SUB
};

struct Node        
{
	Node(Type T = VALUE,char ch = '0')
	:type(T)
	, next(NULL)
	{
		switch (type)
		{
		case HEAD:
			break;
		case VALUE:
			value = ch;
			break;
		case SUB:
			nextHead = NULL;
			break;
		default:
			break;
		}
	}

	Type type;
	Node* next;
	union
	{
		char value;
		Node* nextHead;
	};
};


class GeneralList
{
public:
	GeneralList(const char* ptr)
		:head(NULL)
	{
		head = creatList(ptr);
	}
	Node* creatList(const char* &ptr);
	void showList(Node* head);
	int nodeCount(Node* head);
	int depth(Node* head);

public:
	Node* head;
};

Node* GeneralList::creatList(const char* &ptr)
{
	Node* head = new Node(HEAD);
	Node* cur = head;
	++ptr;
	while (*ptr != ')')
	{
		if (*ptr <= '9' && *ptr >= '0')
		{
			cur->next = new Node(VALUE, *ptr);
			cur = cur->next;
			++ptr;
		}
		else if (*ptr == '(')
		{
			cur->next = new Node(SUB);
			cur = cur->next;
			cur->nextHead = creatList(ptr);
		}
		else
			++ptr;
	}
	return head;
}

void GeneralList::showList(Node* head)
{
	if (head)
	{
		Node* cur = head;
		while (cur)
		{
			if (cur->type == HEAD)
			{
				cout << '(';
			}
			else if (cur->type == VALUE)
			{
				cout << cur->value;
				if (cur->next)
				{
					cout << ',';
				}
			}
			else
			{
				showList(cur->nextHead);
				if (cur->next)
					cout << ',';
			}
			cur = cur->next;
		}
		cout << ')';
	}
}
int GeneralList::nodeCount(Node* head)
{
	Node* cur = head;
	int count = 0;
	while (cur)
	{
		if (cur->type == VALUE)
		{
			count++;
		}
		else if (cur->type == SUB)
		{
			count += nodeCount(cur->nextHead);
		}
		cur = cur->next;
	}
	return count;
}
int GeneralList::depth(Node* head)
{
	Node* cur = head;
	int _depth = 1;
	if (head)
	{
		while (cur)
		{
			if (cur->type == SUB)
			{
				int preDepth = depth(cur->nextHead);
				_depth = preDepth + 1 > _depth ? preDepth + 1 : _depth;
			}
			cur = cur->next;
		}
	}
	return _depth;
}


void Test()
{
	char* p = "(0,0,(1,2,(4,5),3),10,(10,20))";
	GeneralList Object(p);
	Object.showList(Object.head);
	cout << endl << Object.nodeCount(Object.head) << endl;
	cout << Object.depth(Object.head) << endl;
}

