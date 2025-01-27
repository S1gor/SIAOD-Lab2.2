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
	printf("1 - �������� ������� � �������; 2 - ����������� �������; 3 - ����������� ����� �������; 4 - �������� ��������� �������; 5 - �����\n�����:");
	do {
		scanf_s("%d", &choice);
	} while (choice > 5 || choice < 1);
	printf("\n");
	return choice;
}

int selectPriority(const char* str)
{
	int choice;
	printf("%s", str);
	do {
		scanf_s("%d", &choice);
	} while (choice > 5 || choice < 1);
	return choice;
}

void changePriority(Queue1& q1, Queue2& q2, Queue3& q3, Queue4& q4, Queue5& q5)
{
	int priority = selectPriority("������� ���������: ");
	int newPriority = selectPriority("������� ����� ���������: ");
	printf("\n");

	switch (priority)
	{
	case 1:
		if (q1.head == NULL)	return;
		switch (newPriority)
		{
		case 1:
			return;
		case 2:
			if (q2.head == NULL)
			{
				q2.head = q1.head;
				q2.tail = q1.tail;
				q1.head = NULL;
			}
			else
			{
				q2.tail->next = q1.head;
				q2.tail = q1.tail;
				q1.head = NULL;
			}
			break;
		case 3:
			if (q3.head == NULL)
			{
				q3.head = q1.head;
				q3.tail = q1.tail;
				q1.head = NULL;
			}
			else
			{
				q3.tail->next = q1.head;
				q3.tail = q1.tail;
				q1.head = NULL;
			}
			break;
		case 4:
			if (q4.head == NULL)
			{
				q4.head = q1.head;
				q4.tail = q1.tail;
				q1.head = NULL;
			}
			else
			{
				q4.tail->next = q1.head;
				q4.tail = q1.tail;
				q1.head = NULL;
			}
			break;
		case 5:
			if (q5.head == NULL)
			{
				q5.head = q1.head;
				q5.tail = q1.tail;
				q1.head = NULL;
			}
			else
			{
				q5.tail->next = q1.head;
				q5.tail = q1.tail;
				q1.head = NULL;
			}
			break;
		}
		break;
	case 2:
		if (q2.head == NULL)	return;
		switch (newPriority)
		{
		case 1:
			if (q1.head == NULL)
			{
				q1.head = q2.head;
				q1.tail = q2.tail;
				q2.head = NULL;
			}
			else
			{
				q2.tail->next = q1.head;
				q2.tail = q1.tail;
				q1.head = q2.head;
				q2.head = NULL;
			}
			break;
		case 2:
			return;
		case 3:
			if (q3.head == NULL)
			{
				q3.head = q2.head;
				q3.tail = q2.tail;
				q2.head = NULL;
			}
			else
			{
				q3.tail->next = q2.head;
				q3.tail = q2.tail;
				q2.head = NULL;
			}
			break;
		case 4:
			if (q4.head == NULL)
			{
				q4.head = q2.head;
				q4.tail = q2.tail;
				q2.head = NULL;
			}
			else
			{
				q4.tail->next = q2.head;
				q4.tail = q2.tail;
				q2.head = NULL;
			}
			break;
		case 5:
			if (q5.head == NULL)
			{
				q5.head = q2.head;
				q5.tail = q2.tail;
				q2.head = NULL;
			}
			else
			{
				q5.tail->next = q2.head;
				q5.tail = q2.tail;
				q2.head = NULL;
			}
			break;
		}
		break;
	case 3:
		if (q3.head == NULL)	return;
		switch (newPriority)
		{
		case 1:
			if (q1.head == NULL)
			{
				q1.head = q3.head;
				q1.tail = q3.tail;
				q3.head = NULL;
			}
			else
			{
				q3.tail->next = q1.head;
				q3.tail = q1.tail;
				q1.head = q3.head;
				q3.head = NULL;
			}
			break;
		case 2:
			if (q2.head == NULL)
			{
				q2.head = q3.head;
				q2.tail = q3.tail;
				q3.head = NULL;
			}
			else
			{
				q3.tail->next = q2.head;
				q3.tail = q2.tail;
				q2.head = q3.head;
				q3.head = NULL;
			}
			break;
		case 3:
			return;
		case 4:
			if (q4.head == NULL)
			{
				q4.head = q3.head;
				q4.tail = q3.tail;
				q3.head = NULL;
			}
			else
			{
				q4.tail->next = q3.head;
				q4.tail = q3.tail;
				q3.head = NULL;
			}
			break;
		case 5:
			if (q5.head == NULL)
			{
				q5.head = q3.head;
				q5.tail = q3.tail;
				q3.head = NULL;
			}
			else
			{
				q5.tail->next = q3.head;
				q5.tail = q3.tail;
				q3.head = NULL;
			}
			break;
		}
		break;
	case 4:
		if (q4.head == NULL)	return;
		switch (newPriority)
		{
		case 1:
			if (q1.head == NULL)
			{
				q1.head = q4.head;
				q1.tail = q4.tail;
				q4.head = NULL;
			}
			else
			{
				q4.tail->next = q1.head;
				q4.tail = q1.tail;
				q1.head = q4.head;
				q4.head = NULL;
			}
			break;
		case 2:
			if (q2.head == NULL)
			{
				q2.head = q4.head;
				q2.tail = q4.tail;
				q4.head = NULL;
			}
			else
			{
				q4.tail->next = q2.head;
				q4.tail = q2.tail;
				q2.head = q4.head;
				q4.head = NULL;
			}
			break;
		case 3:
			if (q3.head == NULL)
			{
				q3.head = q4.head;
				q3.tail = q4.tail;
				q4.head = NULL;
			}
			else
			{
				q4.tail->next = q3.head;
				q4.tail = q3.tail;
				q3.head = q4.head;
				q4.head = NULL;
			}
			break;
		case 4:
			return;
		case 5:
			if (q5.head == NULL)
			{
				q5.head = q4.head;
				q5.tail = q4.tail;
				q4.head = NULL;
			}
			else
			{
				q5.tail->next = q4.head;
				q5.tail = q4.tail;
				q4.head = NULL;
			}
			break;
		}
		break;
	case 5:
		if (q5.head == NULL)	return;
		switch (newPriority)
		{
		case 1:
			if (q1.head == NULL)
			{
				q1.head = q5.head;
				q1.tail = q5.tail;
				q5.head = NULL;
			}
			else
			{
				q5.tail->next = q1.head;
				q5.tail = q1.tail;
				q1.head = q5.head;
				q5.head = NULL;
			}
			break;
		case 2:
			if (q2.head == NULL)
			{
				q2.head = q5.head;
				q2.tail = q5.tail;
				q5.head = NULL;
			}
			else
			{
				q5.tail->next = q2.head;
				q5.tail = q2.tail;
				q2.head = q5.head;
				q5.head = NULL;
			}
			break;
		case 3:
			if (q3.head == NULL)
			{
				q3.head = q5.head;
				q3.tail = q5.tail;
				q5.head = NULL;
			}
			else
			{
				q5.tail->next = q3.head;
				q5.tail = q3.tail;
				q3.head = q5.head;
				q5.head = NULL;
			}
			break;
		case 4:
			if (q4.head == NULL)
			{
				q4.head = q5.head;
				q4.tail = q5.tail;
				q5.head = NULL;
			}
			else
			{
				q5.tail->next = q4.head;
				q5.tail = q4.tail;
				q4.head = q5.head;
				q5.head = NULL;
			}
			break;
		case 5:
			return;
		}
		break;
	}
}

void loopQueue()
{
	Queue1 q1; Queue2 q2; Queue3 q3; Queue4 q4; Queue5 q5;

	push(q1, q2, q3, q4, q5, 1, 1);
	push(q1, q2, q3, q4, q5, 2, 1);
	push(q1, q2, q3, q4, q5, 3, 1);
	push(q1, q2, q3, q4, q5, 4, 2);
	push(q1, q2, q3, q4, q5, 5, 2);
	push(q1, q2, q3, q4, q5, 7, 4);
	push(q1, q2, q3, q4, q5, 9, 5);
	push(q1, q2, q3, q4, q5, 10, 5);
	push(q1, q2, q3, q4, q5, 20, 5);
	push(q1, q2, q3, q4, q5, 17, 4);

	while (true)
	{
		int tmp, priority;
		switch (selectFunc())
		{
		case 1:
			printf("������� ����������� ������ ��������: ");
			scanf_s("%d", &tmp);
			priority = selectPriority("������� ���������: ");
			printf("\n");
			push(q1, q2, q3, q4, q5, tmp, priority);
			break;
		case 2:
			printQueuePrioirity(q1, q2, q3, q4, q5);
			break;
		case 3:
			printCommonQueue(q1, q2, q3, q4, q5);
			return;
		case 4:
			changePriority(q1, q2, q3, q4, q5);
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