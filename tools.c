#include "tools.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

void welcome() {
    printf("欢迎使用五金店库存信息管理系统!\n");
    printf("1. 添加产品     2. 删除产品\n");
    printf("3. 修改产品     4. 查询产品\n");
    printf("5. 添加员工     6. 删除员工\n");
    printf("7. 修改员工     8. 查询员工\n");
    printf("9. 销售商品     10. 退货管理\n");
    printf("11. 进货提示    12. 缺货统计\n");
    printf("13. 销量统计    14. 员工销售业绩统计\n");
    printf("0. 保存并退出\n");
    printf("请输入您的选择: ");
}
void add_item(Item* item_head)
{
    Item new_item;
    printf("请按顺序输入编号、名称、单价、库存：");
    int ret=scanf("%d%s%d%d", &new_item.num, new_item.name, &new_item.price, &new_item.stock);
    if(ret!=4)
    {
        printf("输入错误！\n");
        printf("重新输入请输入1，返回主菜单请输入0：");
        int choice;
        scanf("%d", &choice);
        if(choice==1)
        {
            add_item(item_head);
            return;
        }
        return;
    }
    insert_item(item_head, new_item);
    printf("添加成功！\n");
}
void delete_item(Item* item_head)
{
    printf("请输入要删除的五金件编号：");
    int num1;
    scanf("%d", &num1);
    int ret = del_item(item_head, num1);
    if (ret == 1)
    {
        printf("删除成功！\n");
    }
    else
    {
        printf("五金件不存在，删除失败！\n");
    }
}
void change_item(Item* item_head)
{
    printf("请输入要修改的五金件编号：");
    int num1;
    scanf("%d", &num1);
    Item* item=find_item(item_head,num1);
    Item new_item;
    if (item==NULL)
    {
        printf("找不到该五金件！\n");
        return;
    }
    printf("请按顺序输入编号、名称、单价、库存：");
    int ret=scanf("%d%s%d%d", &new_item.num, new_item.name, &new_item.price, &new_item.stock);
    if(ret!=4)
    {
        printf("输入错误！\n");
        printf("重新输入请输入1，返回主菜单请输入0：");
        int choice;
        scanf("%d", &choice);
        if(choice==1)
        {
            change_item(item_head);
            return;
        }
        return;
    }
    memcpy(item, &new_item, sizeof(Item));
    printf("修改成功！\n");   
}
void search_item(Item* item_head)
{
    printf("请输入要查询的五金件编号：");
    int num1;
    scanf("%d", &num1);
    Item* item=find_item(item_head,num1);
    if (item==NULL)
    {
        printf("找不到该五金件！\n");
        return;
    }
    printf("编号：%d\n", item->num);
    printf("名称：%s\n", item->name);
    printf("单价：%d\n", item->price);
    printf("库存：%d\n", item->stock);
}
void add_peo(People* peo_head)
{
    People new_peo;
    printf("请按顺序输入员工编号、姓名：");
    int ret=scanf("%d%s", &new_peo.score, new_peo.name_peo);
    if(ret!=4)
    {
        printf("输入错误！\n");
        printf("重新输入请输入1，返回主菜单请输入0：");
        int choice;
        scanf("%d", &choice);
        if(choice==1)
        {
            add_peo(peo_head);
            return;
        }
        return;
    }
    insert_peo(peo_head, new_peo);
    printf("添加成功！\n");
}
void delete_peo(People* peo_head)
{
    printf("请输入要删除的员工编号：");
    int num1;
    scanf("%d", &num1);
    int ret = del_peo(peo_head, num1);
    if (ret == 1)
    {
        printf("删除成功！\n");
    }
    else
    {
        printf("员工不存在，删除失败！\n");
    }
}
void change_peo(People* peo_head)
{
    printf("请输入要修改的员工编号：");
    int num1;
    scanf("%d", &num1);
    People* peo=find_peo(peo_head,num1);
    People new_peo;
    if (peo==NULL)
    {
        printf("找不到该员工！\n");
        return;
    }
    printf("请按顺序输入员工编号、姓名：");
    int ret=scanf("%d%s", &new_peo.score, new_peo.name_peo);
    if(ret!=4)
    {
        printf("输入错误！\n");
        printf("重新输入请输入1，返回主菜单请输入0：");
        int choice;
        scanf("%d", &choice);
        if(choice==1)
        {
            change_peo(peo_head);
            return;
        }
        return;
    }
    memcpy(peo, &new_peo, sizeof(People));
    printf("修改成功！\n");
}
void search_peo(People* peo_head)
{
    printf("请输入要查询的员工编号：");
    int num1;
    scanf("%d", &num1);
    People* peo=find_peo(peo_head,num1);
    if (peo==NULL)
    {
        printf("找不到该员工！\n");
        return;
    }
    printf("员工编号：%d\n", peo->score);
    printf("员工姓名：%s\n", peo->name_peo);
}
void add_sell(Sell* sell_head, People* peo_head, Item* item_head)
{
    Sell new_sell;
    printf("请输入员工工号：");
    int ret=scanf("%d", &new_sell.score);
    if(ret!=1)
    {
        return;
    }
    People* peo = find_peo(peo_head,new_sell.score);
    if (peo==NULL)
    {
        printf("找不到该员工！\n");
        return;
    }
    printf("欢迎使用五金件销售系统, %s\n", peo->name_peo);
    printf("请输入要销售的五金件编号：");
    ret=scanf("%d", &new_sell.num);
    if(ret!=1)
    {
        return;
    }
    Item* item = find_item(item_head,new_sell.num);
    if (item==NULL)
    {
        printf("找不到该五金件！\n");
        return;
    }
    printf("要销售的五金件信息：\n");
    printf("名称：%s\n", item->name);
    printf("单价：%d\n", item->price);
    printf("库存：%d\n", item->stock);
    printf("请输入销售数量：");
    ret=scanf("%d", &new_sell.sell_num);
    if(ret!=1)
    {
        return;
    }
    if (new_sell.sell_num>item->stock)
    {
        printf("库存不足！\n");
        return;
    }
    strcpy(new_sell.name,item->name);
    //取当前时间转换为20240101的格式存储到date中
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    sprintf(new_sell.date, "%04d%02d%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    insert_sell(sell_head, new_sell);
    item->stock -= new_sell.sell_num;
    printf("销售成功！\n");
}
void delete_sell(Sell* sell_head)
{
    printf("请输入要删除的销售记录编号：");
    int num1;
    scanf("%d", &num1);
    int ret = del_sell(sell_head, num1);
    if (ret == 1)
    {
        printf("删除成功！\n");
    }
    else
    {
        printf("销售记录不存在，删除失败！\n");
    }
}
int check_sell_month(Sell* sell_head, int month)
{
    int count = 0;
    Sell* sell = sell_head->next;
    int mon;
    while (sell!= NULL)
    {
        sscanf(sell->date, "%*4d%2d", &mon);
        if (mon == month)
        {
            count+=sell->sell_num;
        }
        sell = sell->next;
    }
    return count;
}
void stock_warning(Sell* sell_head, Item* item_head)
{
    printf("请输入要统计的月份：");
    int month;
    scanf("%d", &month);
    if (month<1 || month>12)
    {
        printf("月份输入错误！\n");
        return;
    }
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        if (item->stock<2)
        {
            if(check_sell_month(item_head,item->num,month)>10)
            {
                printf("五金件%d(%s)库存不足！\n",item->num, item->name);
            }
        }
    }
}
void stock_statistics(Item* item_head)
{
    //统计已经卖完的五金件
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        if (item->stock==0)
        {
            printf("五金件%d(%s)已经卖完！\n",item->num, item->name);
        }
    }
}
void sales_statistics(Sell* sell_head, Item* item_head)
{
    //输入日期，统计该日各五金件销售情况，并排序输出
    printf("请输入要统计的日期，格式为年月日，如20240102：");
    char date[9];
    scanf("%s", date);
    //统计有多少个五金件
    int item_count = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_count++;
    }
    Item* item_all=malloc(sizeof(Item)*item_count);
    //将所有五金件的信息复制到item_all中
    int i = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_all[i] = *item;
        item_all[i].stock=0;
        i++;
    }
    for(Sell* sell=sell_head->next; sell!=NULL; sell=sell->next)
    {
        if (strcmp(sell->date, date)==0)
        {
            for(int j=0; j<item_count; j++)
            {
                if (strcmp(sell->name, item_all[j].name)==0)
                {
                    item_all[j].stock += sell->sell_num;
                }
            }
        }
    }
    //排序
    for(int j=0; j<item_count-1; j++)
    {
        for(int k=j+1; k<item_count; k++)
        {
            if (item_all[j].stock<item_all[k].stock)
            {
                Item temp = item_all[j];
                item_all[j] = item_all[k];
                item_all[k] = temp;
            }
        }
    }
    //输出
    printf("%s销售统计结果：\n",date);
    printf("五金件编号\t五金件名\t销售数量\n");
    for(int j=0; j<item_count; j++)
    {
        printf("%d\t%s\t%d\n",item_all[j].num, item_all[j].name, item_all[j].stock);
    }

}
void peo_sales_statistics(Sell* sell_head, People* peo_head, Item* item_head)
{
    //输入员工编号，统计该员工在该系统中销售的所有五金件的销售情况，并排序输出
    printf("请输入要统计的员工编号：");
    int num;
    scanf("%d", &num);
    People* peo = find_peo(peo_head, num);
    if (peo==NULL)
    {
        printf("找不到该员工！\n");
        return;
    }
    printf("欢迎使用五金件销售系统, %s\n", peo->name_peo);
    //统计有多少个五金件
    int item_count = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_count++;
    }
    Item* item_all=malloc(sizeof(Item)*item_count);
    //将所有五金件的信息复制到item_all中
    int i = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_all[i] = *item;
        item_all[i].stock=0;
        i++;
    }
    for(Sell* sell=sell_head->next; sell!=NULL; sell=sell->next)
    {
        if (sell->num==num)
        {
            for(int j=0; j<item_count; j++)
            {
                if (strcmp(sell->name, item_all[j].name)==0)
                {
                    item_all[j].stock += sell->sell_num;
                }
            }
        }
    }
    //排序
    for(int j=0; j<item_count-1; j++)
    {
        for(int k=j+1; k<item_count; k++)
        {
            if (item_all[j].stock<item_all[k].stock)
            {
                Item temp = item_all[j];
                item_all[j] = item_all[k];
                item_all[k] = temp;
            }
        }
    }
    //输出
    printf("%s销售统计结果：\n",peo->name_peo);
    printf("五金件编号\t五金件名\t销售金额\n");
    for(int j=0; j<item_count; j++)
    {
        printf("%d\t%s\t%d\n",item_all[j].num, item_all[j].name, item_all[j].stock*item_all[j].price);

    }
}
void save(Item* item_head, People* peo_head, Sell* sell_head)
{
    //将所有数据保存到文件中
    int ret=write_item(item_head, "Item.txt");
    ret+=write_people(peo_head, "People.txt");
    ret+=write_sell(sell_head, "Sell.txt");
    if (ret!=3)
    {
        printf("保存失败！\n");
        return;
    }
    printf("保存成功！\n");
}

