#include "tools.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

void welcome() {
    printf("��ӭʹ����������Ϣ����ϵͳ!\n");
    printf("1. ��Ӳ�Ʒ     2. ɾ����Ʒ\n");
    printf("3. �޸Ĳ�Ʒ     4. ��ѯ��Ʒ\n");
    printf("5. ���Ա��     6. ɾ��Ա��\n");
    printf("7. �޸�Ա��     8. ��ѯԱ��\n");
    printf("9. ������Ʒ     10. �˻�����\n");
    printf("11. ������ʾ    12. ȱ��ͳ��\n");
    printf("13. ����ͳ��    14. Ա������ҵ��ͳ��\n");
    printf("0. ���沢�˳�\n");
    printf("����������ѡ��: ");
}
void add_item(Item* item_head)
{
    Item new_item;
    printf("�밴˳�������š����ơ����ۡ���棺");
    int ret=scanf("%d%s%d%d", &new_item.num, new_item.name, &new_item.price, &new_item.stock);
    if(ret!=4)
    {
        printf("�������\n");
        printf("��������������1���������˵�������0��");
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
    printf("��ӳɹ���\n");
}
void delete_item(Item* item_head)
{
    printf("������Ҫɾ����������ţ�");
    int num1;
    scanf("%d", &num1);
    int ret = del_item(item_head, num1);
    if (ret == 1)
    {
        printf("ɾ���ɹ���\n");
    }
    else
    {
        printf("���������ڣ�ɾ��ʧ�ܣ�\n");
    }
}
void change_item(Item* item_head)
{
    printf("������Ҫ�޸ĵ�������ţ�");
    int num1;
    scanf("%d", &num1);
    Item* item=find_item(item_head,num1);
    Item new_item;
    if (item==NULL)
    {
        printf("�Ҳ�����������\n");
        return;
    }
    printf("�밴˳�������š����ơ����ۡ���棺");
    int ret=scanf("%d%s%d%d", &new_item.num, new_item.name, &new_item.price, &new_item.stock);
    if(ret!=4)
    {
        printf("�������\n");
        printf("��������������1���������˵�������0��");
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
    printf("�޸ĳɹ���\n");   
}
void search_item(Item* item_head)
{
    printf("������Ҫ��ѯ��������ţ�");
    int num1;
    scanf("%d", &num1);
    Item* item=find_item(item_head,num1);
    if (item==NULL)
    {
        printf("�Ҳ�����������\n");
        return;
    }
    printf("��ţ�%d\n", item->num);
    printf("���ƣ�%s\n", item->name);
    printf("���ۣ�%d\n", item->price);
    printf("��棺%d\n", item->stock);
}
void add_peo(People* peo_head)
{
    People new_peo;
    printf("�밴˳������Ա����š�������");
    int ret=scanf("%d%s", &new_peo.score, new_peo.name_peo);
    if(ret!=4)
    {
        printf("�������\n");
        printf("��������������1���������˵�������0��");
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
    printf("��ӳɹ���\n");
}
void delete_peo(People* peo_head)
{
    printf("������Ҫɾ����Ա����ţ�");
    int num1;
    scanf("%d", &num1);
    int ret = del_peo(peo_head, num1);
    if (ret == 1)
    {
        printf("ɾ���ɹ���\n");
    }
    else
    {
        printf("Ա�������ڣ�ɾ��ʧ�ܣ�\n");
    }
}
void change_peo(People* peo_head)
{
    printf("������Ҫ�޸ĵ�Ա����ţ�");
    int num1;
    scanf("%d", &num1);
    People* peo=find_peo(peo_head,num1);
    People new_peo;
    if (peo==NULL)
    {
        printf("�Ҳ�����Ա����\n");
        return;
    }
    printf("�밴˳������Ա����š�������");
    int ret=scanf("%d%s", &new_peo.score, new_peo.name_peo);
    if(ret!=4)
    {
        printf("�������\n");
        printf("��������������1���������˵�������0��");
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
    printf("�޸ĳɹ���\n");
}
void search_peo(People* peo_head)
{
    printf("������Ҫ��ѯ��Ա����ţ�");
    int num1;
    scanf("%d", &num1);
    People* peo=find_peo(peo_head,num1);
    if (peo==NULL)
    {
        printf("�Ҳ�����Ա����\n");
        return;
    }
    printf("Ա����ţ�%d\n", peo->score);
    printf("Ա��������%s\n", peo->name_peo);
}
void add_sell(Sell* sell_head, People* peo_head, Item* item_head)
{
    Sell new_sell;
    printf("������Ա�����ţ�");
    int ret=scanf("%d", &new_sell.score);
    if(ret!=1)
    {
        return;
    }
    People* peo = find_peo(peo_head,new_sell.score);
    if (peo==NULL)
    {
        printf("�Ҳ�����Ա����\n");
        return;
    }
    printf("��ӭʹ����������ϵͳ, %s\n", peo->name_peo);
    printf("������Ҫ���۵�������ţ�");
    ret=scanf("%d", &new_sell.num);
    if(ret!=1)
    {
        return;
    }
    Item* item = find_item(item_head,new_sell.num);
    if (item==NULL)
    {
        printf("�Ҳ�����������\n");
        return;
    }
    printf("Ҫ���۵�������Ϣ��\n");
    printf("���ƣ�%s\n", item->name);
    printf("���ۣ�%d\n", item->price);
    printf("��棺%d\n", item->stock);
    printf("����������������");
    ret=scanf("%d", &new_sell.sell_num);
    if(ret!=1)
    {
        return;
    }
    if (new_sell.sell_num>item->stock)
    {
        printf("��治�㣡\n");
        return;
    }
    strcpy(new_sell.name,item->name);
    //ȡ��ǰʱ��ת��Ϊ20240101�ĸ�ʽ�洢��date��
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    sprintf(new_sell.date, "%04d%02d%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    insert_sell(sell_head, new_sell);
    item->stock -= new_sell.sell_num;
    printf("���۳ɹ���\n");
}
void delete_sell(Sell* sell_head)
{
    printf("������Ҫɾ�������ۼ�¼��ţ�");
    int num1;
    scanf("%d", &num1);
    int ret = del_sell(sell_head, num1);
    if (ret == 1)
    {
        printf("ɾ���ɹ���\n");
    }
    else
    {
        printf("���ۼ�¼�����ڣ�ɾ��ʧ�ܣ�\n");
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
    printf("������Ҫͳ�Ƶ��·ݣ�");
    int month;
    scanf("%d", &month);
    if (month<1 || month>12)
    {
        printf("�·��������\n");
        return;
    }
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        if (item->stock<2)
        {
            if(check_sell_month(item_head,item->num,month)>10)
            {
                printf("����%d(%s)��治�㣡\n",item->num, item->name);
            }
        }
    }
}
void stock_statistics(Item* item_head)
{
    //ͳ���Ѿ����������
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        if (item->stock==0)
        {
            printf("����%d(%s)�Ѿ����꣡\n",item->num, item->name);
        }
    }
}
void sales_statistics(Sell* sell_head, Item* item_head)
{
    //�������ڣ�ͳ�Ƹ��ո�����������������������
    printf("������Ҫͳ�Ƶ����ڣ���ʽΪ�����գ���20240102��");
    char date[9];
    scanf("%s", date);
    //ͳ���ж��ٸ�����
    int item_count = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_count++;
    }
    Item* item_all=malloc(sizeof(Item)*item_count);
    //��������������Ϣ���Ƶ�item_all��
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
    //����
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
    //���
    printf("%s����ͳ�ƽ����\n",date);
    printf("�������\t������\t��������\n");
    for(int j=0; j<item_count; j++)
    {
        printf("%d\t%s\t%d\n",item_all[j].num, item_all[j].name, item_all[j].stock);
    }

}
void peo_sales_statistics(Sell* sell_head, People* peo_head, Item* item_head)
{
    //����Ա����ţ�ͳ�Ƹ�Ա���ڸ�ϵͳ�����۵�����������������������������
    printf("������Ҫͳ�Ƶ�Ա����ţ�");
    int num;
    scanf("%d", &num);
    People* peo = find_peo(peo_head, num);
    if (peo==NULL)
    {
        printf("�Ҳ�����Ա����\n");
        return;
    }
    printf("��ӭʹ����������ϵͳ, %s\n", peo->name_peo);
    //ͳ���ж��ٸ�����
    int item_count = 0;
    for(Item* item=item_head->next; item!=NULL; item=item->next)
    {
        item_count++;
    }
    Item* item_all=malloc(sizeof(Item)*item_count);
    //��������������Ϣ���Ƶ�item_all��
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
    //����
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
    //���
    printf("%s����ͳ�ƽ����\n",peo->name_peo);
    printf("�������\t������\t���۽��\n");
    for(int j=0; j<item_count; j++)
    {
        printf("%d\t%s\t%d\n",item_all[j].num, item_all[j].name, item_all[j].stock*item_all[j].price);

    }
}
void save(Item* item_head, People* peo_head, Sell* sell_head)
{
    //���������ݱ��浽�ļ���
    int ret=write_item(item_head, "Item.txt");
    ret+=write_people(peo_head, "People.txt");
    ret+=write_sell(sell_head, "Sell.txt");
    if (ret!=3)
    {
        printf("����ʧ�ܣ�\n");
        return;
    }
    printf("����ɹ���\n");
}

