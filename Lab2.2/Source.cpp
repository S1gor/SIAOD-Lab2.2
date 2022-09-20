#include <iostream>

/*Задания для выполнения на ЭВМ имеют различные приоритеты, задаваемые цифрами от 1 до 5 (5 - высший приоритет).
Для каждого приоритета образуется отдельная очередь.Приоритет задания может меняться.
При повышении приоритета задание помещается в конец другой очереди, а при понижении - в начало.Составить программу, обеспечивающую:
1) выдачу общей очереди;
2) выдачу очереди заданного приоритета;
3) перестройку очередей при изменении приоритета.*/

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