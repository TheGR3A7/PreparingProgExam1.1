#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Структура узла списка
struct QueueNode {
	int data; // Данные элемента очереди
	QueueNode* next; // Указатель на следующий узел
};

// Структура очереди
struct Queue {
	QueueNode* head; // Указатель на первый элемент очереди
	QueueNode* tail; // Указатель на последний элемент очереди
};

// #1 Функция добавления элемента в очередь
void Add_Item_To_Queue(Queue* queue, int data) {
	// Создание нового узла
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->tail == NULL) {
		// Очередь пустая, новый узел будет первым и последним
		queue->head = queue->tail = newNode;
	}
	else {
		// Установка связи с последним узлом
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	printf("Элемент %d добавлен в очередь.\n", data);
}

//#2 Функция извлечения элемента из очереди
int Extract_Item_Of_The_Queue(Queue* queue) {
	if (queue->head == NULL) {
		// Очередь пустая
		printf("Очередь пустая.\n");
		return -1; // Или другое значение, которое указывает на ошибку
	}

	// Получение значения первого элемента
	int data = queue->head->data;

	// Сохранение указателя на первый узел
	QueueNode* temp = queue->head;

	// Перемещение указателя на следующий узел
	queue->head = queue->head->next;

	// Если очередь стала пустой, обновляем указатель на последний узел
	if (queue->head == NULL) {
		queue->tail = NULL;
	}

	// Освобождение памяти первого узла
	free(temp);

	return data;
}

//#3 Функция распечатки всех элементов очереди
void Print_Queue(Queue * queue) {
	if (queue->head == NULL) {
		// Очередь пустая
		printf("Очередь пустая.\n");
		return;
	}

	printf("Элементы в очереди: ");
	QueueNode* current = queue->head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//#3 Функция удаления всех элементов из очереди
void Clear_Queue(Queue* queue) {
	QueueNode* current = queue->head;
	while (current != NULL) {
		QueueNode* temp = current;
		current = current->next;
		free(temp);
	}
	queue->head = queue->tail = NULL;

	printf("Очередь очищена.\n");
}


int main1() {
	system("chcp 1251");
	int value;
	// Создание пустой очереди
	Queue queue;
	queue.head = queue.tail = NULL;

	// Добавление элементов в очередь
	do {
		printf("Введите число(0, чтобы закончить ввод)\n");
		scanf_s("%d", &value);
		if(value != 0)
			Add_Item_To_Queue(&queue,value);
	} while (value != 0);

	// Извлечение элементов из очереди
	int item1 = Extract_Item_Of_The_Queue(&queue);
	printf("Извлечен элемент из очереди: %d\n", item1);

	//Распечатка
	Print_Queue(&queue);

	//Удаление
	Clear_Queue(&queue);

	//Распечатка после очищения
	Print_Queue(&queue);

	return 0;
}