#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "door_struct.h"

#define SUCCESS 1
#define FAIL 0

// Тест для функции add_door
int test_add_door() {
    // Создаем тестовые данные
    struct door test_door1 = {1, 0};
    struct door test_door2 = {2, 1};
    
    // Создаем корневой элемент
    struct node* root = init(&test_door1);
    if (root == NULL) {
        return FAIL;
    }
    
    // Добавляем второй элемент
    struct node* second = add_door(root, &test_door2);
    if (second == NULL) {
        destroy(root);
        return FAIL;
    }
    
    // Проверяем, что элементы связаны правильно
    int result = FAIL;
    if (root->next == second && 
        second->door == &test_door2 && 
        root->door == &test_door1) {
        result = SUCCESS;
    }
    
    destroy(root);
    return result;
}

// Тест для функции remove_door
int test_remove_door() {
    // Создаем тестовые данные
    struct door test_door1 = {1, 0};
    struct door test_door2 = {2, 1};
    struct door test_door3 = {3, 0};
    
    // Создаем список из трех элементов
    struct node* root = init(&test_door1);
    struct node* second = add_door(root, &test_door2);
    struct node* third = add_door(second, &test_door3);
    
    if (root == NULL || second == NULL || third == NULL) {
        if (root) destroy(root);
        return FAIL;
    }
    
    // Удаляем средний элемент
    root = remove_door(second, root);
    
    // Проверяем, что список правильно перелинкован
    int result = FAIL;
    if (root != NULL && 
        root->next == third && 
        root->door == &test_door1 && 
        third->door == &test_door3) {
        result = SUCCESS;
    }
    
    destroy(root);
    return result;
}

// Тест для функции find_door
int test_find_door() {
    struct door test_door1 = {1, 0};
    struct door test_door2 = {2, 1};
    struct door test_door3 = {3, 0};
    
    struct node* root = init(&test_door1);
    add_door(root, &test_door2);
    add_door(root, &test_door3);
    
    // Ищем существующую дверь
    struct node* found = find_door(2, root);
    int result = (found != NULL && found->door->id == 2) ? SUCCESS : FAIL;
    
    // Ищем несуществующую дверь
    struct node* not_found = find_door(5, root);
    if (not_found != NULL) {
        result = FAIL;
    }
    
    destroy(root);
    return result;
}

int main() {
    printf("Running tests...\n");
    
    int add_test_result = test_add_door();
    printf("test_add_door: %s\n", add_test_result ? "SUCCESS" : "FAIL");
    
    int remove_test_result = test_remove_door();
    printf("test_remove_door: %s\n", remove_test_result ? "SUCCESS" : "FAIL");
    
    int find_test_result = test_find_door();
    printf("test_find_door: %s\n", find_test_result ? "SUCCESS" : "FAIL");
    
    // Общий результат
    if (add_test_result && remove_test_result && find_test_result) {
        printf("All tests: SUCCESS\n");
        return SUCCESS;
    } else {
        printf("Some tests: FAIL\n");
        return FAIL;
    }
}