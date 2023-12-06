#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ��������� ���� ������
struct QueueNode {
	int data; // ������ �������� �������
	QueueNode* next; // ��������� �� ��������� ����
};

// ��������� �������
struct Queue {
	QueueNode* head; // ��������� �� ������ ������� �������
	QueueNode* tail; // ��������� �� ��������� ������� �������
};

// #1 ������� ���������� �������� � �������
void Add_Item_To_Queue(Queue* queue, int data) {
	// �������� ������ ����
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->tail == NULL) {
		// ������� ������, ����� ���� ����� ������ � ���������
		queue->head = queue->tail = newNode;
	}
	else {
		// ��������� ����� � ��������� �����
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	printf("������� %d �������� � �������.\n", data);
}

//#2 ������� ���������� �������� �� �������
int Extract_Item_Of_The_Queue(Queue* queue) {
	if (queue->head == NULL) {
		// ������� ������
		printf("������� ������.\n");
		return -1; // ��� ������ ��������, ������� ��������� �� ������
	}

	// ��������� �������� ������� ��������
	int data = queue->head->data;

	// ���������� ��������� �� ������ ����
	QueueNode* temp = queue->head;

	// ����������� ��������� �� ��������� ����
	queue->head = queue->head->next;

	// ���� ������� ����� ������, ��������� ��������� �� ��������� ����
	if (queue->head == NULL) {
		queue->tail = NULL;
	}

	// ������������ ������ ������� ����
	free(temp);

	return data;
}

//#3 ������� ���������� ���� ��������� �������
void Print_Queue(Queue * queue) {
	if (queue->head == NULL) {
		// ������� ������
		printf("������� ������.\n");
		return;
	}

	printf("�������� � �������: ");
	QueueNode* current = queue->head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//#3 ������� �������� ���� ��������� �� �������
void Clear_Queue(Queue* queue) {
	QueueNode* current = queue->head;
	while (current != NULL) {
		QueueNode* temp = current;
		current = current->next;
		free(temp);
	}
	queue->head = queue->tail = NULL;

	printf("������� �������.\n");
}


int main1() {
	system("chcp 1251");
	int value;
	// �������� ������ �������
	Queue queue;
	queue.head = queue.tail = NULL;

	// ���������� ��������� � �������
	do {
		printf("������� �����(0, ����� ��������� ����)\n");
		scanf_s("%d", &value);
		if(value != 0)
			Add_Item_To_Queue(&queue,value);
	} while (value != 0);

	// ���������� ��������� �� �������
	int item1 = Extract_Item_Of_The_Queue(&queue);
	printf("�������� ������� �� �������: %d\n", item1);

	//����������
	Print_Queue(&queue);

	//��������
	Clear_Queue(&queue);

	//���������� ����� ��������
	Print_Queue(&queue);

	return 0;
}