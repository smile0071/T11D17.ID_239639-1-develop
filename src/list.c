#include <stdlib.h>
#include "list.h"

struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->door = door;
        new_node->next = NULL;
    }
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    if (elem == NULL || door == NULL) {
        return NULL;
    }
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->door = door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->door != NULL && current->door->id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) {
        return root;
    }
    
    // Если удаляем первый элемент
    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }
    
    // Ищем предыдущий элемент
    struct node* prev = root;
    while (prev != NULL && prev->next != elem) {
        prev = prev->next;
    }
    
    // Если нашли предыдущий элемент
    if (prev != NULL) {
        prev->next = elem->next;
        free(elem);
    }
    
    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }
}