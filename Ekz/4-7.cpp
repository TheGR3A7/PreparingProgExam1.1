#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Структура узла списка
struct ListNode {
	int data; // Данные элемента списка
	struct ListNode* next; // Указатель на следующий узел
};

//#4 Функция добавления элемента в список
void Add_To_List(ListNode** head, int data) {
	// Создание нового узла
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		// Список пустой, новый узел будет первым
		*head = newNode;
	}
	else {
		// Находим последний узел и добавляем новый узел после него
		ListNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

	printf("Элемент %d добавлен в список.\n", data);
}

// #7 Функция печати списка
void Print_List(ListNode* head) {
	ListNode* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// #5 Функция сортировки списка по возрастанию (сортировка вставками)
void Sort_List_In_Ascending(ListNode** head) {
	if (*head == NULL || (*head)->next == NULL) {
		// Список пустой или содержит только один элемент, уже отсортирован
		return;
	}

	ListNode* sortedList = NULL; // Отсортированный список
	ListNode* current = *head; // Текущий элемент списка

	while (current != NULL) {
		ListNode* nextNode = current->next; // Сохраняем ссылку на следующий элемент
		ListNode** sortedPtr = &sortedList; // Указатель на указатель на отсортированный список

		// Находим место для вставки текущего элемента в отсортированный список
		while (*sortedPtr != NULL && (*sortedPtr)->data < current->data) {
			sortedPtr = &((*sortedPtr)->next);
		}

		// Вставляем текущий элемент в отсортированный список
		current->next = *sortedPtr;
		*sortedPtr = current;

		// Переходим к следующему элементу для сортировки
		current = nextNode;
	}

	*head = sortedList; // Обновляем голову списка
}

// #6 Функция сортировки списка по убыванию
void Sort_List_In_Descending(ListNode** head) {
	if (*head == NULL || (*head)->next == NULL) {
		// Список пустой или содержит только один элемент, уже отсортирован
		return;
	}

	// Используем сортировку вставками
	ListNode* sortedList = NULL;
	ListNode* current = *head;

	while (current != NULL) {
		ListNode* nextNode = current->next;

		// Вставляем текущий узел в отсортированный список
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
	// Инициализация головы списка
	ListNode* head = NULL;

	// Добавление элементов в список
	do {
		printf("Введите число(-1, чтобы завершить ввод)\n");
		scanf_s("%d", &value);
		if(value != -1)
			Add_To_List(&head, value);
	} while (value != -1);

	printf("Исходный список: \n");
	//Печать
	Print_List(head);

	//Сортировка по возрастанию
	Sort_List_In_Ascending(&head);
	printf("Cписок, отсортированный по возрастанию: \n");
	Print_List(head);

	//Сортировка по убыванию
	Sort_List_In_Descending(&head);
	printf("Cписок, отсортированный по убыванию: \n");
	Print_List(head);

	return 0;
}
