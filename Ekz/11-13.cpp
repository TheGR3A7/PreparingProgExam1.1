#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ��������� ���� ������
struct Node {
	int data; // ������ �������� ������
	Node* next; // ��������� �� ��������� ����
};


// #11 ������� ���������� �������� � ������
void AddNode(Node** head, int data) {
	// �������� ������ ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		// ������ ������, ����� ���� ����� ������� ������
		*head = newNode;
		newNode->next = newNode; // ������ �� ����, ���������� ������
	}
	else {
		// ������� ��������� ���� � ������������� ������ �� ����� ����
		Node* last = *head;
		while (last->next != *head)
			last = last->next;
		last->next = newNode;

		// ������������� ������ ������ ���� �� ������ ������
		newNode->next = *head;
	}
}

// #12 ������� ���������� �������� �� ������
int RemoveNode(Node** head, int num) {
	if (*head == NULL) {
		// ������ ������
		return 0;
	}

	Node* current = *head;
	Node* prev = NULL;

	// ����� �������� �� �����
	while (current->data != num) {
		if (current->next == *head) {
			// ������� �� ������
			return 0;
		}
		prev = current;
		current = current->next;
	}

	// �������� ��������
	if (current == *head && current->next == *head) {
		// ��������� ������� �������� ������������ ��������� � ������
		*head = NULL;
	}
	else if (current == *head) {
		// ��������� ������� �������� ������� ������
		Node* last = *head;
		while (last->next != *head)
			last = last->next;
		*head = (*head)->next;
		last->next = *head;
	}
	else {
		// ��������� ������� ��������� � �������� ������
		prev->next = current->next;
	}

	free(current); // ������������ ������

	return 1;
}

// #13 ������
void PrintRing(Node* head) {
	if (head == NULL) {
		printf("������ ������.\n");
		return;
	}

	Node* current = head;
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head);

	printf("\n");
}

// #13 ������� �������� ���� ��������� ������
void ClearRing(Node** head) {
	if (*head == NULL) {
		printf("������ ������.\n");
		return;
	}

	Node* current = *head;
	Node* next = NULL;

	// �������� �� ������ � ����������� ������ ��� ������� ����
	do {
		next = current->next;
		free(current);
		current = next;
	} while (current != *head);

	*head = NULL;
	printf("��� �������� ������ ������� �������.\n");
}


int main() {
	system("chcp 1251");
	int value;
	Node* head = NULL; // ������������� ������ ������

	// ���������� ��������� � ������
	do {
		printf("������� �����(-1, ����� ��������� ����):\n");
		scanf_s("%d", &value);
		if (value != -1)
			AddNode(&head, value);
	} while (value != -1);

	PrintRing(head);

	// ���������� �������� �� ������
	do {
		printf("������� �����, ������� ������ ������� (����� -1):\n");
		scanf_s("%d", &value);
	} while (value == -1);

	int result = RemoveNode(&head, value);

	if (result)
		printf("������� %d ������� ������ �� ������.\n", value);
	else
		printf("������� %d �� ������ � ������ ��� ������ ������.\n", value);

	PrintRing(head);

	ClearRing(&head);
	PrintRing(head);

	return 0;
}

