#include<stdio.h>
#include"List.h"
void welcome();
void add_item(Item* item_head);
void delete_item(Item* item_head);
void change_item(Item* item_head);
void search_item(Item* item_head);
void add_peo(People* peo_head);
void delete_peo(People* peo_head);
void change_peo(People* peo_head);
void search_peo(People* peo_head);
void add_sell(Sell* sell_head, People* peo_head, Item* item_head);
void delete_sell(Sell* sell_head);
void stock_warning(Sell* sell_head, Item* item_head);