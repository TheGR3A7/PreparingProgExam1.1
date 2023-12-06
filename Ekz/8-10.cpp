#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>

// Структура узла стека
struct StackNode
{
	int data; // Данные элемента стека
	StackNode* next; // Указатель на следующий узел
};

typedef struct StackL
{
	StackNode* top;
} StackL;

void InitStack(StackL* s)
{
	s->top = NULL;
}

// #8 Функция добавления элемента в стек

int Push(StackL* stack, int data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (!newNode)
		return 0;
	newNode->next = stack->top;
	newNode->data = data;
	stack->top = newNode;
	return 1;
}

// #9 Функция извлечения из стека

int Pop(StackL* stack) {

	struct StackNode* newNode;
	int x = INT_MAX;

	if (stack->top)
	{
		newNode = stack->top;
		stack->top = stack->top->next;
		x = newNode->data;
		free(newNode);
	}
	return x;
}

// #10 Печать

void PrintStack(StackL const* stack)
{
	struct StackNode* newNode;
	for (newNode = stack->top; newNode; newNode = newNode->next)
		printf("%d ", newNode->data);
}

// #10 Удаление всех элементов
void Clear(StackL* stack)
{
	for (StackNode* data = stack->top; data != NULL;)
	{
		StackNode* next = data->next;
		free(data);
		data = next;
	}
	stack->top = NULL;
}

int main3() {
	system("chcp 1251");
	StackL stack;
	int value;

	InitStack(&stack);

	// Добавление элементов в стек
	do {
		printf("Введите число(-1, чтобы закончить ввод):\n");
		scanf_s("%d", &value);
		if (value != -1)
			Push(&stack, value);
	} while (value != -1);
	
	printf("Получившийся стек:\n");
	PrintStack(&stack);
	printf("\n");

	// Извлечение элементов из стека
	while (stack.top)
	{
		int value = Pop(&stack);
		printf("Извлеченное число: %d\n", value);
	}
	
	Clear(&stack);

	printf("Получившийся стек:\n");
	PrintStack(&stack);

	return 0;
}