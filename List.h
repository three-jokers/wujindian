#pragma once

// Define the data structures
typedef struct Item {
    int num;          // 五金件编号
    char name[100];   // 五金件名称
    int price;        // 单价
    int stock;           // 库存
    struct Item* next;
}Item;

typedef struct People {
    int score;        // 员工工号
    char name_peo[100]; // 员工名称
    struct People* next;
}People;

typedef struct Sell {
    int num;          // 五金件编号
    char name[100];   // 五金件名称
    int score;        // 员工工号
    char date[9];     //销售日期
    int sell_num;     //销售数量
    struct Sell* next;

}Sell;



/**
 * @brief 创建一个空链表
 * @return struct Node* 返回一个链表头
 */
struct Item* create_item_node();
/**
 * @brief 创建一个空链表
 * @return struct Node* 返回一个链表头
 */
struct People* create_people_node();
/**
 * @brief 创建一个空链表
 * @return struct Node* 返回一个链表头
 */
struct Sell* create_sell_node();
/**
 * @brief 删除item节点
 * @param head 链表头
 * @param num1 编号或工号
 * @return int 返回 1 表示成功，返回 0 表示找不到
 */
int del_item(struct Item* head, int num1);
/**
 * @brief 删除People节点
 * @param head 链表头
 * @param num1 编号或工号
 * @return int 返回 1 表示成功，返回 0 表示找不到
 */

int del_peo(struct People* head, int num1);
/**
 * @brief 删除Sell节点
 * @param head 链表头
 * @param num1 编号或工号
 * @return int 返回 1 表示成功，返回 0 表示找不到
 */
int del_sell(struct Sell* head, int num1);
/**
 * @brief 插入Item节点
 * @param head 链表头
 * @param new_target 新数据
 * @return int 返回 1 表示成功，返回 0 表示找不到
 */
int insert_item(struct Item* head, struct Item new_target);
/**
 * @brief 插入People节点
 * @param head 链表头
 * @param new_target 新数据
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int insert_peo(struct People* head, struct People new_target);
/** 
 * @brief 插入Sell节点
 * @param head 链表头
 * @param new_target 新数据
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int insert_Sell(struct Sell* head, struct Sell new_target);

// int save(struct Item item, struct People people, struct Sell sell);
/**
 * @brief 读取数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int read_Item(struct Item* list, char *file_name);
/**
 * @brief 读取数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int read_People(struct People* list, char *file_name);
/**
 * @brief 读取数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int read_Sell(struct Sell* list, char *file_name);
/**
 * @brief 写入数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int write_item(struct Item* list, char *file_name);
/**
 * @brief 写入数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int write_sell(struct Sell* list, char* file_name);
/**
 * @brief 写入数据
 * @param list 链表
 * @param file_name 文件名
 * @return int 返回 1 表示成功，返回 0 表示失败
 */
int write_people(struct People* list, char* file_name);

/**
 * @brief 查找Item节点
 * @param head 链表头
 * @param target 目标编号或工号
 * @return Data* 返回节点数据，如果找不到返回 NULL
 */
struct Item* find_item(struct Item *head, int target);
/**
 * @brief 查找People节点
 * @param head 链表头
 * @param target 目标编号或工号
 * @return Data* 返回节点数据，如果找不到返回 NULL
 */
struct People* find_peo(struct People *head, int target);
typedef struct Node* List;
