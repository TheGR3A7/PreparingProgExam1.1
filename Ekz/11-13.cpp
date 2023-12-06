#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Структура узла списка
struct Node {
	int data; // Данные элемента списка
	Node* next; // Указатель на следующий узел
};


// #11 Функция добавления элемента в список
void AddNode(Node** head, int data) {
	// Создание нового узла
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL) {
		// Список пустой, новый узел будет головой списка
		*head = newNode;
		newNode->next = newNode; // Ссылка на себя, образуется кольцо
	}
	else {
		// Находим последний узел и устанавливаем ссылку на новый узел
		Node* last = *head;
		while (last->next != *head)
			last = last->next;
		last->next = newNode;

		// Устанавливаем ссылку нового узла на голову списка
		newNode->next = *head;
	}
}

// #12 Функция извлечения элемента из списка
int RemoveNode(Node** head, int num) {
	if (*head == NULL) {
		// Список пустой
		return 0;
	}

	Node* current = *head;
	Node* prev = NULL;

	// Поиск элемента по ключу
	while (current->data != num) {
		if (current->next == *head) {
			// Элемент не найден
			return 0;
		}
		prev = current;
		current = current->next;
	}

	// Удаление элемента
	if (current == *head && current->next == *head) {
		// Удаляемый элемент является единственным элементом в списке
		*head = NULL;
	}
	else if (current == *head) {
		// Удаляемый элемент является головой списка
		Node* last = *head;
		while (last->next != *head)
			last = last->next;
		*head = (*head)->next;
		last->next = *head;
	}
	else {
		// Удаляемый элемент находится в середине списка
		prev->next = current->next;
	}

	free(current); // Освобождение памяти

	return 1;
}

// #13 Печать
void PrintRing(Node* head) {
	if (head == NULL) {
		printf("Список пустой.\n");
		return;
	}

	Node* current = head;
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head);

	printf("\n");
}

// #13 Функция удаления всех элементов списка
void ClearRing(Node** head) {
	if (*head == NULL) {
		printf("Список пустой.\n");
		return;
	}

	Node* current = *head;
	Node* next = NULL;

	// Проходим по списку и освобождаем память для каждого узла
	do {
		next = current->next;
		free(current);
		current = next;
	} while (current != *head);

	*head = NULL;
	printf("Все элементы списка успешно удалены.\n");
}


int main() {
	system("chcp 1251");
	int value;
	Node* head = NULL; // Инициализация головы списка

	// Добавление элементов в список
	do {
		printf("Введите число(-1, чтобы закончить ввод):\n");
		scanf_s("%d", &value);
		if (value != -1)
			AddNode(&head, value);
	} while (value != -1);

	PrintRing(head);

	// Извлечение элемента из списка
	do {
		printf("Введите число, которое хотите извлечь (кроме -1):\n");
		scanf_s("%d", &value);
	} while (value == -1);

	int result = RemoveNode(&head, value);

	if (result)
		printf("Элемент %d успешно удален из списка.\n", value);
	else
		printf("Элемент %d не найден в списке или список пустой.\n", value);

	PrintRing(head);

	ClearRing(&head);
	PrintRing(head);

	return 0;
}

