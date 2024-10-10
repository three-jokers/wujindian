#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

struct Item* create_item_node() {
    struct Item* node = (struct Item*)malloc(sizeof(struct Item));
    if (node == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    memset(node, 0, sizeof(struct Item));
    node->next = NULL;
    return node;
}

struct People* create_people_node() {
    struct People* node = (struct People*)malloc(sizeof(struct People));
    if (node == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    memset(node, 0, sizeof(struct People));
    node->next = NULL;
    return node;
}

struct Sell* create_sell_node() {
    struct Sell* node = (struct Sell*)malloc(sizeof(struct Sell));
    if (node == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    memset(node, 0, sizeof(struct Sell));
    node->next = NULL;
    return node;
}



int del_item(struct Item* head, int num1)
{
    // 删除功能（针对 Item）
    struct Item* current = head;
    while (current->next)
    {
        if (current->next->num == num1)
        {
            struct Item* p = current->next;
            current->next = current->next->next;
            free(p);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int del_peo(struct People* head, int num1)
{
    // 删除功能（针对 People）
    struct People* current = head;
    while (current->next)
    {
        if (current->next->score == num1)
        {
            struct People* p = current->next;
            current->next = current->next->next;
            free(p);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int insert_item(struct Item* head, struct Item new_target)
{
    // 插入功能（针对 Item）
    struct Item* new_node = (struct Item*)malloc(sizeof(struct Item));
    *new_node = new_target;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}

int insert_peo(struct People* head, struct People new_target)
{
    // 插入功能（针对 People）
    struct People* new_node = (struct People*)malloc(sizeof(struct People));
    *new_node = new_target;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}

int insert_end_item(struct Item* head, struct Item new_target)
{
    // 在末尾插入功能（针对 Item）
    struct Item* current = head;
    while (current->next)
    {
        current = current->next;
    }
    struct Item* new_node = (struct Item*)malloc(sizeof(struct Item));
    *new_node = new_target;
    current->next = new_node;
    return 1;
}

int insert_end_peo(struct People* head, struct People new_target)
{
    // 在末尾插入功能（针对 People）
    struct People* current = head;
    while (current->next)
    {
        current = current->next;
    }
    struct People* new_node = (struct People*)malloc(sizeof(struct People));
    *new_node = new_target;
    current->next = new_node;
    return 1;
}

// int save(struct Item item, struct People people, struct Sell sell)
// {
//     FILE *file = fopen("output.txt", "a"); // 打开文件以追加写入
//     if (file == NULL)
//     {
//         exit(1);
//     }
//     fprintf(file, "Item: %s, Price: %d, Stock: %d\n", item.name, item.price, item.stock);
//     fprintf(file, "People: %s, Score: %d\n", people.name_peo, people.score);
//     fclose(file);
// }

int insert_end_sell(struct Sell* head, struct Sell new_target)
{
    struct Sell* current = head;
    struct Sell* new_node = (struct Sell*)malloc(sizeof(struct Sell));
    // Assign the new Data to the new node
    *new_node = new_target;
    while (current)
    {
        if (current->next == NULL)
        {
            current->next = new_node;
        }
        current = current->next;
    }
}

int read_Item(struct Item* list, char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        exit(1);
    }
    while (1) {
        struct Item data;
        int num = fread(&data, sizeof(struct Item), 1, file);
        if (num == 1) {
            insert_end_item(list, data);
        }
        else {
            break;
        }
    }
    fclose(file);
    return 1;
}

// 读取 People 数据
int read_People(struct People* list, char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        return 0;
    }
    while (1) {
        struct People data;
        int num = fread(&data, sizeof(struct People), 1, file);
        if (num == 1) {
            // 插入到链表中
            insert_end_peo(list, data);
        }
        else {
            break;
        }
    }
    fclose(file);
    return 1;
}

// 读取 Sell 数据
int read_Sell(struct Sell* list, char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        return 0;
    }
    while (1) {
        struct Sell data;
        int num = fread(&data, sizeof(struct Sell), 1, file);
        if (num == 1) {
            // 插入到链表中
            insert_end_sell(list, data);
        }
        else {
            break;
        }
    }
    fclose(file);
    return 1;
}


int write_item(struct Item* list, char* file_name) {
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        return 0;
    }
    for (struct Item* p = list->next; p != NULL; p = p->next) {
        int num = fwrite(p, sizeof(struct Item), 1, file);
        if (num != 1) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

// 写入 People 数据
int write_people(struct People* list, char* file_name) {
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        return 0;
    }
    for (struct People* p = list->next; p != NULL; p = p->next) {
        int num = fwrite(p, sizeof(struct People), 1, file);
        if (num != 1) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

// 写入 Sell 数据
int write_sell(struct Sell* list, char* file_name) {
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        return 0;
    }
    for (struct Sell* p = list->next; p != NULL; p = p->next) {
        int num = fwrite(p, sizeof(struct Sell), 1, file);
        if (num != 1) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

struct Item* find_item(struct Item* head, int target)
{
    struct Item* current = head;
    while (current)
    {
        if (current->num == target)
        {
            return current;
        }
        current = current->next;
    }
}


struct People* find_peo(struct People* head, int target)
{
    struct People* current = head;
    while (current)
    {
        if (current->score == target)
        {
            return current;
        }
        current = current->next;
    }

}


// int change_peo(struct Node *head,int target,char name[100]){
//     struct Node*current=head;
//     struct Node*new;
//     new->data.people.score=target;
//     new->data.people.score=name;
//     while(current){
//         if((current->data.people.score == target)){
//             strcpy(current->data.people.name_peo, name);
//             return 1;
//         }current=current->next;
//     }return 0;
// }

// int change_item(struct Node *head,int target,char name[100]){
//     struct Node*current=head;
//     while(current){
//         if((current->data.item.num == target)){
//             strcpy(current->data.item.price, name);
//             return 1;
//         }current=current->next;
//     }return 0;
// }
// void print_list(struct Node *head)
// {
//     // 实现遍历功能
//     struct Node *current = head;
//     while (current)
//     {
//         if (current->item.num)
//         {
//             printf("Item: %s (Num: %d, Price: %d, Stock: %d)\n", current->item.name, current->item.num, current->item.price, current->item.stock);
//         }
//         else if (current->people.score)
//         {
//             printf("Employee: %s (Score: %d)\n", current->people.name_peo, current->people.score);
//         }
//         else if (current->sell.num)
//         {
//             printf("Sale record: Item %s (Num: %d) sold by %s (Score: %d)\n", current->sell.name, current->sell.num, current->sell.score);
//         }
//         current = current->next;
//     }
// }

