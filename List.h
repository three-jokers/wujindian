#pragma once

// Define the data structures
typedef struct Item {
    int num;          // �������
    char name[100];   // ��������
    int price;        // ����
    int stock;           // ���
    struct Item* next;
}Item;

typedef struct People {
    int score;        // Ա������
    char name_peo[100]; // Ա������
    struct People* next;
}People;

typedef struct Sell {
    int num;          // �������
    char name[100];   // ��������
    int score;        // Ա������
    char date[9];     //��������
    int sell_num;     //��������
    struct Sell* next;

}Sell;



/**
 * @brief ����һ��������
 * @return struct Node* ����һ������ͷ
 */
struct Item* create_item_node();
/**
 * @brief ����һ��������
 * @return struct Node* ����һ������ͷ
 */
struct People* create_people_node();
/**
 * @brief ����һ��������
 * @return struct Node* ����һ������ͷ
 */
struct Sell* create_sell_node();
/**
 * @brief ɾ��item�ڵ�
 * @param head ����ͷ
 * @param num1 ��Ż򹤺�
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾ�Ҳ���
 */
int del_item(struct Item* head, int num1);
/**
 * @brief ɾ��People�ڵ�
 * @param head ����ͷ
 * @param num1 ��Ż򹤺�
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾ�Ҳ���
 */

int del_peo(struct People* head, int num1);
/**
 * @brief ɾ��Sell�ڵ�
 * @param head ����ͷ
 * @param num1 ��Ż򹤺�
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾ�Ҳ���
 */
int del_sell(struct Sell* head, int num1);
/**
 * @brief ����Item�ڵ�
 * @param head ����ͷ
 * @param new_target ������
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾ�Ҳ���
 */
int insert_item(struct Item* head, struct Item new_target);
/**
 * @brief ����People�ڵ�
 * @param head ����ͷ
 * @param new_target ������
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int insert_peo(struct People* head, struct People new_target);
/** 
 * @brief ����Sell�ڵ�
 * @param head ����ͷ
 * @param new_target ������
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int insert_Sell(struct Sell* head, struct Sell new_target);

// int save(struct Item item, struct People people, struct Sell sell);
/**
 * @brief ��ȡ����
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int read_Item(struct Item* list, char *file_name);
/**
 * @brief ��ȡ����
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int read_People(struct People* list, char *file_name);
/**
 * @brief ��ȡ����
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int read_Sell(struct Sell* list, char *file_name);
/**
 * @brief д������
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int write_item(struct Item* list, char *file_name);
/**
 * @brief д������
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int write_sell(struct Sell* list, char* file_name);
/**
 * @brief д������
 * @param list ����
 * @param file_name �ļ���
 * @return int ���� 1 ��ʾ�ɹ������� 0 ��ʾʧ��
 */
int write_people(struct People* list, char* file_name);

/**
 * @brief ����Item�ڵ�
 * @param head ����ͷ
 * @param target Ŀ���Ż򹤺�
 * @return Data* ���ؽڵ����ݣ�����Ҳ������� NULL
 */
struct Item* find_item(struct Item *head, int target);
/**
 * @brief ����People�ڵ�
 * @param head ����ͷ
 * @param target Ŀ���Ż򹤺�
 * @return Data* ���ؽڵ����ݣ�����Ҳ������� NULL
 */
struct People* find_peo(struct People *head, int target);
typedef struct Node* List;
