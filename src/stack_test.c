#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SUCCESS 1
#define FAIL 0

// Тест для функции push
int test_push() {
    struct stack_node* stack = NULL;
    
    // Тестируем добавление в пустой стек
    stack = push(stack, 10);
    if (stack == NULL || stack->data != 10) {
        destroy(stack);
        return FAIL;
    }
    
    // Тестируем добавление еще одного элемента
    stack = push(stack, 20);
    if (stack == NULL || stack->data != 20 || stack->next->data != 10) {
        destroy(stack);
        return FAIL;
    }
    
    // Тестируем добавление третьего элемента
    stack = push(stack, 30);
    if (stack == NULL || stack->data != 30 || stack->next->data != 20) {
        destroy(stack);
        return FAIL;
    }
    
    destroy(stack);
    return SUCCESS;
}

// Тест для функции pop
int test_pop() {
    struct stack_node* stack = NULL;
    
    // Создаем стек с тремя элементами
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    
    // Проверяем начальное состояние
    if (stack == NULL || stack->data != 30) {
        destroy(stack);
        return FAIL;
    }
    
    // Удаляем первый элемент
    stack = pop(stack);
    if (stack == NULL || stack->data != 20) {
        destroy(stack);
        return FAIL;
    }
    
    // Удаляем второй элемент
    stack = pop(stack);
    if (stack == NULL || stack->data != 10) {
        destroy(stack);
        return FAIL;
    }
    
    // Удаляем последний элемент
    stack = pop(stack);
    if (stack != NULL) {
        destroy(stack);
        return FAIL;
    }
    
    // Пробуем удалить из пустого стека
    stack = pop(stack);
    if (stack != NULL) {
        destroy(stack);
        return FAIL;
    }
    
    destroy(stack);
    return SUCCESS;
}

// Тест для последовательности push/pop
int test_push_pop_sequence() {
    struct stack_node* stack = NULL;
    
    // Добавляем несколько элементов
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    
    // Проверяем порядок извлечения (LIFO)
    if (stack->data != 3) {
        destroy(stack);
        return FAIL;
    }
    stack = pop(stack);
    
    if (stack->data != 2) {
        destroy(stack);
        return FAIL;
    }
    stack = pop(stack);
    
    if (stack->data != 1) {
        destroy(stack);
        return FAIL;
    }
    stack = pop(stack);
    
    if (stack != NULL) {
        destroy(stack);
        return FAIL;
    }
    
    destroy(stack);
    return SUCCESS;
}

// Тест для функции init
int test_init() {
    struct stack_node* stack = init(42);
    
    if (stack == NULL || stack->data != 42 || stack->next != NULL) {
        destroy(stack);
        return FAIL;
    }
    
    destroy(stack);
    return SUCCESS;
}

int main() {
    printf("Running stack tests...\n");
    
    int init_test = test_init();
    printf("test_init: %s\n", init_test ? "SUCCESS" : "FAIL");
    
    int push_test = test_push();
    printf("test_push: %s\n", push_test ? "SUCCESS" : "FAIL");
    
    int pop_test = test_pop();
    printf("test_pop: %s\n", pop_test ? "SUCCESS" : "FAIL");
    
    int sequence_test = test_push_pop_sequence();
    printf("test_push_pop_sequence: %s\n", sequence_test ? "SUCCESS" : "FAIL");
    
    // Общий результат (основные тесты - push и pop)
    if (push_test && pop_test) {
        printf("\nAll main tests (push/pop): SUCCESS\n");
        return SUCCESS;
    } else {
        printf("\nSome main tests (push/pop): FAIL\n");
        return FAIL;
    }
}