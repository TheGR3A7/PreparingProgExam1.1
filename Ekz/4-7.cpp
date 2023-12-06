#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ��������� ���� ������
struct ListNode {
	int data; // ������ �������� ������
	struct ListNode* next; // ��������� �� ��������� ����
};

//#4 ������� ���������� �������� � ������
void Add_To_List(ListNode** head, int data) {
	// �������� ������ ����
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		// ������ ������, ����� ���� ����� ������
		*head = newNode;
	}
	else {
		// ������� ��������� ���� � ��������� ����� ���� ����� ����
		ListNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

	printf("������� %d �������� � ������.\n", data);
}

// #7 ������� ������ ������
void Print_List(ListNode* head) {
	ListNode* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// #5 ������� ���������� ������ �� ����������� (���������� ���������)
void Sort_List_In_Ascending(ListNode** head) {
	if (*head == NULL || (*head)->next == NULL) {
		// ������ ������ ��� �������� ������ ���� �������, ��� ������������
		return;
	}

	ListNode* sortedList = NULL; // ��������������� ������
	ListNode* current = *head; // ������� ������� ������

	while (current != NULL) {
		ListNode* nextNode = current->next; // ��������� ������ �� ��������� �������
		ListNode** sortedPtr = &sortedList; // ��������� �� ��������� �� ��������������� ������

		// ������� ����� ��� ������� �������� �������� � ��������������� ������
		while (*sortedPtr != NULL && (*sortedPtr)->data < current->data) {
			sortedPtr = &((*sortedPtr)->next);
		}

		// ��������� ������� ������� � ��������������� ������
		current->next = *sortedPtr;
		*sortedPtr = current;

		// ��������� � ���������� �������� ��� ����������
		current = nextNode;
	}

	*head = sortedList; // ��������� ������ ������
}

// #6 ������� ���������� ������ �� ��������
void Sort_List_In_Descending(ListNode** head) {
	if (*head == NULL || (*head)->next == NULL) {
		// ������ ������ ��� �������� ������ ���� �������, ��� ������������
		return;
	}

	// ���������� ���������� ���������
	ListNode* sortedList = NULL;
	ListNode* current = *head;

	while (current != NULL) {
		ListNode* nextNode = current->next;

		// ��������� ������� ���� � ��������������� ������
		if (sortedList == NULL || current->data > sortedList->data) {
			current->next = sortedList;
			sortedList = current;
		}
		else {
			ListNode* temp = sortedList;
			while (temp->next != NULL && current->data <= temp->next->data) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}

		current = nextNode;
	}

	*head = sortedList;
}


int main2() {
	system("chcp 1251");
	int value;
	// ������������� ������ ������
	ListNode* head = NULL;

	// ���������� ��������� � ������
	do {
		printf("������� �����(-1, ����� ��������� ����)\n");
		scanf_s("%d", &value);
		if(value != -1)
			Add_To_List(&head, value);
	} while (value != -1);

	printf("�������� ������: \n");
	//������
	Print_List(head);

	//���������� �� �����������
	Sort_List_In_Ascending(&head);
	printf("C�����, ��������������� �� �����������: \n");
	Print_List(head);

	//���������� �� ��������
	Sort_List_In_Descending(&head);
	printf("C�����, ��������������� �� ��������: \n");
	Print_List(head);

	return 0;
}
