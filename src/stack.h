#ifndef STACK_H
#define STACK_H

// Структура элемента стека
struct stack_node {
    int data;               // Целое число
    struct stack_node* next; // Указатель на следующий элемент
};

// Инициализация стека (создание пустого стека)
struct stack_node* init(int data);

// Добавление элемента в стек (push)
struct stack_node* push(struct stack_node* root, int data);

// Удаление элемента из стека (pop)
struct stack_node* pop(struct stack_node* root);

// Уничтожение стека (освобождение памяти)
void destroy(struct stack_node* root);

#endif