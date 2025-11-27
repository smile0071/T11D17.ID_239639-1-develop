#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

struct node {
    struct door* door;
    struct node* next;
};

// Инициализация структуры односвязного списка
struct node* init(struct door* door);

// Вставка нового элемента после переданного узла
struct node* add_door(struct node* elem, struct door* door);

// Поиск двери в списке по id
struct node* find_door(int door_id, struct node* root);

// Удаление элемента списка
struct node* remove_door(struct node* elem, struct node* root);

// Освобождение памяти всего списка
void destroy(struct node* root);

#endif