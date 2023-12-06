#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>

// ��������� ���� �����
struct StackNode
{
	int data; // ������ �������� �����
	StackNode* next; // ��������� �� ��������� ����
};

typedef struct StackL
{
	StackNode* top;
} StackL;

void InitStack(StackL* s)
{
	s->top = NULL;
}

// #8 ������� ���������� �������� � ����

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

// #9 ������� ���������� �� �����

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

// #10 ������

void PrintStack(StackL const* stack)
{
	struct StackNode* newNode;
	for (newNode = stack->top; newNode; newNode = newNode->next)
		printf("%d ", newNode->data);
}

// #10 �������� ���� ���������
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

	// ���������� ��������� � ����
	do {
		printf("������� �����(-1, ����� ��������� ����):\n");
		scanf_s("%d", &value);
		if (value != -1)
			Push(&stack, value);
	} while (value != -1);
	
	printf("������������ ����:\n");
	PrintStack(&stack);
	printf("\n");

	// ���������� ��������� �� �����
	while (stack.top)
	{
		int value = Pop(&stack);
		printf("����������� �����: %d\n", value);
	}
	
	Clear(&stack);

	printf("������������ ����:\n");
	PrintStack(&stack);

	return 0;
}