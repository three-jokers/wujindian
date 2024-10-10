#include<stdio.h>
#include"tools.h"
#include"List.h"
int main()
{
	printf("读取已有数据中，请稍等。。。");
	Item* item_head = create_item_node();
	People* peo_head = create_people_node();
	Sell* sell_head = create_sell_node();
	int ret = read_Item(item_head, "Item.txt");
	ret += read_People(peo_head, "People.txt");
	ret += read_Sell(sell_head, "Sell.txt");
	if (ret == 3)
	{
		printf("读取成功！\n");
	}
	else 
    {
		printf("读取失败！\n");
		printf("是否清空数据重新开始？\n");
		printf("1.是\n");
		printf("2.否\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			item_head = create_item_node();
            peo_head = create_people_node();
            sell_head = create_sell_node();
		}
		else
		{
			exit(0);
		}

	}
	welcome();
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		add_item(item_head);
		break;
	case 2:
		delete_item(item_head);
		break;
	case 3:
		change_item(item_head);
		break;
	case 4:
		search_item(item_head);
		break;
	case 5:
		add_peo(peo_head);
		break;
	case 6:
		delete_peo(peo_head);
		break;
	case 7:
		change_peo(peo_head);
		break;
	case 8:
		search_peo(peo_head);
		break;
	case 9:
		add_sell(sell_head, peo_head, item_head);
		break;
	case 10:
		delete_sell(sell_head);
		break;
	case 11:
		stock_warning(sell_head, item_head);
		break;
	case 12:
		stock_statistics(item_head);
		break;
	case 13:
		sales_statistics(sell_head, item_head);
		break;
	case 14:
		peo_sales_statistics(sell_head, peo_head);
		break;
	case 0:
		save(item_head, peo_head, sell_head);
        exit(0);
		break;
	default:
		printf("输入错误，请重新输入\n");
		break;
    system("cls");
	}
    save(item_head, peo_head, sell_head);


}