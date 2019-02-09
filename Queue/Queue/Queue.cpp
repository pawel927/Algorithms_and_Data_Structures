#include "pch.h"
#include <iostream>

using namespace std;

struct Queue
{
	int data;
	Queue *next;
	Queue *prev;

public:
	void Enque(int);
	void Deque();
	void Print(Queue*);
}*head, *tail;

void Queue::Enque(int data)
{
	Queue *temp;

	temp = new Queue;

	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}

	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void Queue::Deque()
{
	if (head == NULL)
		return;

	else
	{
		Queue *temp;

		temp = head->next;
		head = NULL;
		head = temp;
	}
}

void Queue::Print(Queue *head)
{
	cout << "Your queue: " << endl;

	while (head)
	{
		cout << head->data << endl;
		head = head->next;
	}
}

int main()
{
	Queue *q = new Queue;

	q->Enque(4);
	q->Enque(5);
	q->Enque(4);
	q->Enque(2);
	q->Enque(9);

	q->Print(head);

	q->Deque();
	q->Deque();
	q->Deque();

	q->Print(head);

	system("PAUSE");

	return 0;
}