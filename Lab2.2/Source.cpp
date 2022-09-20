#include <iostream>

/*������� ��� ���������� �� ��� ����� ��������� ����������, ���������� ������� �� 1 �� 5 (5 - ������ ���������).
��� ������� ���������� ���������� ��������� �������.��������� ������� ����� ��������.
��� ��������� ���������� ������� ���������� � ����� ������ �������, � ��� ��������� - � ������.��������� ���������, ��������������:
1) ������ ����� �������;
2) ������ ������� ��������� ����������;
3) ����������� �������� ��� ��������� ����������.*/

struct Element
{
	int data;
	int priority;
	Element* next = NULL;
};

struct Queue
{
	int priority;
	Element* head = NULL;
	Element* tail = NULL;
};

void push(Queue& q, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = NULL;

	if (q.head == NULL)
	{
		q.head = e;
		q.tail = e;
		return;
	}
	q.tail->next = e;
	q.tail = e;
}

void printQueue(Queue& q)
{
	for (Element* cur = q.head; cur != NULL; cur = cur->next)
		printf("%d - ", cur->data);
	printf("\b\b \n");
}

int main()
{
	Queue q;

	const int PRIORITY = 5;
	const int PLACE = 10;
	int data[PRIORITY][PLACE];


	return 0;
}