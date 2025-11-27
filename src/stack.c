#include <stdlib.h>
#include "stack.h"

struct stack_node* init(int data) {
    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

struct stack_node* push(struct stack_node* root, int data) {
    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (new_node == NULL) {
        return root; // Возвращаем исходный стек при ошибке выделения памяти
    }
    
    new_node->data = data;
    new_node->next = root; // Новый элемент становится новым корнем
    return new_node;       // Возвращаем новый корень стека
}

struct stack_node* pop(struct stack_node* root) {
    if (root == NULL) {
        return NULL; // Нечего удалять
    }
    
    struct stack_node* new_root = root->next;
    free(root);
    return new_root;
}

void destroy(struct stack_node* root) {
    struct stack_node* current = root;
    while (current != NULL) {
        struct stack_node* next = current->next;
        free(current);
        current = next;
    }
}