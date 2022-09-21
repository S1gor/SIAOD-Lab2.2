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
	Element* next = NULL;
};

struct Queue1
{
	Element* head = NULL;
	Element* tail = NULL;
};

struct Queue2
{
	Element* head = NULL;
	Element* tail = NULL;
};

struct Queue3
{
	Element* head = NULL;
	Element* tail = NULL;
};

struct Queue4
{
	Element* head = NULL;
	Element* tail = NULL;
};

struct Queue5
{
	Element* head = NULL;
	Element* tail = NULL;
};

void push(Queue1& q1, Queue2& q2, Queue3& q3, Queue4& q4, Queue5& q5, int d, int priority)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = NULL;

	switch (priority)
	{
	case 1:
		if (q1.head == NULL)
		{
			q1.head = e;
			q1.tail = e;
			return;
		}
		q1.tail->next = e;
		q1.tail = e;
		break;
	case 2:
		if (q2.head == NULL)
		{
			q2.head = e;
			q2.tail = e;
			return;
		}
		q2.tail->next = e;
		q2.tail = e;
		break;
	case 3:
		if (q3.head == NULL)
		{
			q3.head = e;
			q3.tail = e;
			return;
		}
		q3.tail->next = e;
		q3.tail = e;
		break;
	case 4:
		if (q4.head == NULL)
		{
			q4.head = e;
			q4.tail = e;
			return;
		}
		q4.tail->next = e;
		q4.tail = e;
		break;
	case 5:
		if (q5.head == NULL)
		{
			q5.head = e;
			q5.tail = e;
			return;
		}
		q5.tail->next = e;
		q5.tail = e;
		break;
	}
}

void printQueuePrioirity(Queue1 q1, Queue2 q2, Queue3 q3, Queue4 q4, Queue5 q5)
{
	printf("1: ");
	if (q1.head == NULL)
		printf("������ �������\n");
	else
	{
		for (Element* cur = q1.head; cur != NULL; cur = cur->next)
			printf("%d - ", cur->data);
		printf("\b\b \n");
	}

	printf("2: ");
	if (q2.head == NULL)
		printf("������ �������\n");
	else
	{
		for (Element* cur = q2.head; cur != NULL; cur = cur->next)
			printf("%d - ", cur->data);
		printf("\b\b \n");
	}

	printf("3: ");
	if (q3.head == NULL)
		printf("������ �������\n");
	else
	{
		for (Element* cur = q3.head; cur != NULL; cur = cur->next)
			printf("%d - ", cur->data);
		printf("\b\b \n");
	}

	printf("4: ");
	if (q4.head == NULL)
		printf("������ �������\n");
	else
	{
		for (Element* cur = q4.head; cur != NULL; cur = cur->next)
			printf("%d - ", cur->data);
		printf("\b\b \n");
	}

	printf("5: ");
	if (q5.head == NULL)
		printf("������ �������\n");
	else
	{
		for (Element* cur = q5.head; cur != NULL; cur = cur->next)
			printf("%d - ", cur->data);
		printf("\b\b \n");
	}
	printf("\n");
}

void printCommonQueue(Queue1 q1, Queue2 q2, Queue3 q3, Queue4 q4, Queue5 q5)
{
	if (q5.head != NULL)
		q5.tail->next = q4.head;

	if (q4.head != NULL)
		q4.tail->next = q3.head;
	else
		q5.tail->next = q3.head;

	if (q3.head != NULL)
		q3.tail->next = q2.head;
	else if (q4.head != NULL)
		q4.tail->next = q2.head;
	else
		q5.tail->next = q2.head;

	if (q2.head != NULL)
		q2.tail->next = q1.head;
	else if (q3.head != NULL)
		q3.tail->next = q1.head;
	else if (q4.head != NULL)
		q4.tail->next = q1.head;
	else
		q5.tail->next = q1.head;

	Element* cur;

	if (q5.head != NULL)
		cur = q5.head;
	else if (q4.head != NULL)
		cur = q4.head;
	else if (q3.head != NULL)
		cur = q3.head;
	else if (q2.head != NULL)
		cur = q2.head;
	else
		cur = q1.head;

	for (cur; cur != NULL; cur = cur->next)
		printf("%d - ", cur->data);
	printf("\b\b \n");
}

int selectFunc()
{
	int choice;
	printf("1 - �������� ������� � �������; 2 - ����������� �������; 3 - ����������� ����� �������; 4 - ������� �������; 5 - �����\n�����:");
	do {
		scanf_s("%d", &choice);
	} while (choice > 5 || choice < 1);
	printf("\n");
	return choice;
}

int selectPriority()
{
	int choice;
	printf("������� ���������: ");
	do {
		scanf_s("%d", &choice);
	} while (choice > 5 || choice < 1);
	printf("\n");
	return choice;
}

void loopQueue()
{
	Queue1 q1; Queue2 q2; Queue3 q3; Queue4 q4; Queue5 q5;

	while (true)
	{
		int tmp, priority;
		switch (selectFunc())
		{
		case 1:
			printf("������� ����������� ������ ��������: ");
			scanf_s("%d", &tmp);
			priority = selectPriority();
			push(q1, q2, q3, q4, q5, tmp, priority);
			break;
		case 2:
			//priority = selectPriority();
			printQueuePrioirity(q1, q2, q3, q4, q5);
			break;
		case 3:
			printCommonQueue(q1, q2, q3, q4, q5);
			break;
		case 4:
			break;
		case 5:
			return;
		}
	}
}

int main()
{
	system("chcp 1251"); system("cls");

	loopQueue();



	return 0;
}