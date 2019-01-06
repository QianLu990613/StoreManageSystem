#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define LEN sizeof(struct addition)


struct cash_payment{          //现金支付信息
	float payment;            //支付金额
	float change;             //找零金额
};
typedef struct cash_payment cash;


struct card_payment{          //会员卡支付信息
	int number;               //会员卡号
	float money_before;       //购物前余额
	float money_after;       //购物后余额
};
typedef struct card_payment card;


struct addition{
	int num;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int kinds_of_fruit;       //水果种类
	float unit_price;         //单价
	float quantity;           //数量
	float total_price;        //总价
	int k;                    //开关，判断是现金支付还是会员卡支付
	cash m1;
	card m2;
	struct addition *next;     //指向下一节点的指针
};
typedef struct addition add;
int n;          //节点总数
struct addition *Create(){
	struct addition *head;
	struct addition *p1 = NULL;       //p1保存创建的新节点地址
	struct addition *p2 = NULL;       //p2保存原链表最后一个节点
	n = 0;
	p1 = (struct addition *) malloc (LEN);
	p2 = p1;


	time_t tmpcal_ptr;
	struct tm *tmp_ptr = NULL;
	time(&tmpcal_ptr);
	tmp_ptr = localtime(&tmpcal_ptr);



	if (p1 == NULL) {
		printf("程序出错，无法创建链表");            //程序出错时的输出
		return NULL;
	}
	else{
		head = NULL;
		printf("输入程序启动，请自行按照提示进行输入(购物时间默认为当前时间)\n");
		printf("请输入序号(四位整数）：  ");
		scanf("%d",&(p1->num));
		while (isalpha(p1->num) || (p1->num)<1000 || (p1->num) > 9999){
			if (p1->num == 0){
				break;
			}
			else {
				printf("输入内容不合法，请重新输入!\n");
				scanf("%d", &(p1->num));
			}
		}
		p1->year = (1900+tmp_ptr->tm_year);
		p1->month = (1+tmp_ptr->tm_mon);
		p1->day = (tmp_ptr->tm_mday);
		p1->hour = (tmp_ptr->tm_hour);
		p1->minute = (tmp_ptr->tm_min);
		p1->second = (tmp_ptr->tm_sec);
		printf("购买时间:%d.%d.%d %d:%d:%d\n",1900+tmp_ptr->tm_year,1+tmp_ptr->tm_mon,tmp_ptr->tm_mday,tmp_ptr->tm_hour,tmp_ptr->tm_min,tmp_ptr->tm_sec);
		printf("请输入水果种类所对应序号：1.苹果  2.香蕉  3.梨  4.西瓜  5.桃子\n");
		scanf("%d",&(p1->kinds_of_fruit));
		printf("请输入单价(元/kg):   \n");
		scanf("%f",&(p1->unit_price));
		printf("请输入卖出的公斤数(kg):   \n");
		scanf("%f",&(p1->quantity));
		printf("总价(元):   %.2f元\n",(p1->quantity)*(p1->unit_price));
		(p1->total_price) = (p1->quantity)*(p1->unit_price);
		printf("请输入支付信息对应编号:1.现金支付  2.会员卡支付\n");
		scanf("%d",&(p1->k));
		if (p1->k == 1) {
			printf("请输入支付金额:   ");
			scanf("%f",&(p1->m1.payment));
			printf("找零金额:   %.2f元\n",(p1->m1.payment)-(p1->total_price));
			(p1->m1.change) = (p1->m1.payment)-(p1->total_price);
		}
		else if(p1->k == 2){
			printf("请输入会员卡号:   ");
			scanf("%d",&(p1->m2.number));
			printf("请输入支付前会员卡余额:   ");
			scanf("%f",&(p1->m2.money_before));
			printf("请输入支付后会员卡余额:   %.2f\n",(p1->m2.money_before)-(p1->total_price));
			(p1->m2.money_after) = (p1->m2.money_before)-(p1->total_price);
		}
		else {
			printf("输入错误！");
		}
	}
	while (p1->num != 0){
		n += 1;
		if (n == 1) {
			head = p1;
			p2->next = NULL;
		} else {
			p2->next = p1;
		}

		time_t tmpcal_ptr;
		struct tm *tmp_ptr = NULL;
		time(&tmpcal_ptr);
		tmp_ptr = localtime(&tmpcal_ptr);

		p2 = p1;
		p1 = (struct addition *) malloc (LEN);
		printf("上一条购物信息已录入，请继续输入(输入序号为0时退出)\n");
		printf("请输入序号：");
		scanf("%d",&(p1->num));
		while (isalpha(p1->num) || (p1->num)<1000 || (p1->num) > 9999){
			if (p1->num == 0){
				break;
			}
			else {
				printf("输入内容不合法，请重新输入!\n");
				scanf("%d", &(p1->num));
			}
		}
		if (p1->num == 0) {
			break;
		}
		p1->year = (1900+tmp_ptr->tm_year);
		p1->month = (1+tmp_ptr->tm_mon);
		p1->day = (tmp_ptr->tm_mday);
		p1->hour = (tmp_ptr->tm_hour);
		p1->minute = (tmp_ptr->tm_min);
		p1->second = (tmp_ptr->tm_sec);
		printf("购买时间:%d.%d.%d %d:%d:%d\n",1900+tmp_ptr->tm_year,1+tmp_ptr->tm_mon,tmp_ptr->tm_mday,tmp_ptr->tm_hour,tmp_ptr->tm_min,tmp_ptr->tm_sec);
		printf("请输入水果种类所对应序号：1.苹果  2.香蕉  3.梨  4.西瓜  5.桃子\n");
		scanf("%d",&(p1->kinds_of_fruit));
		printf("请输入单价(元/kg):   \n");
		scanf("%f",&(p1->unit_price));
		printf("请输入卖出的公斤数(kg):   \n");
		scanf("%f",&(p1->quantity));
		printf("总价(元):   %.2f元\n",(p1->quantity)*(p1->unit_price));
		(p1->total_price) = (p1->quantity)*(p1->unit_price);
		printf("请输入支付信息对应编号:1.现金支付  2.会员卡支付\n");
		scanf("%d",&(p1->k));
		if (p1->k == 1) {
			printf("请输入支付金额:   ");
			scanf("%f",&(p1->m1.payment));
			printf("找零金额:   %.2f元\n",(p1->m1.payment)-(p1->total_price));
			(p1->m1.change) = (p1->m1.payment)-(p1->total_price);
		}
		else if(p1->k == 2){
			printf("请输入会员卡号:   ");
			scanf("%d",&(p1->m2.number));
			printf("请输入支付前会员卡余额:   ");
			scanf("%f",&(p1->m2.money_before));
			printf("请输入支付后会员卡余额:   %.2f\n",(p1->m2.money_before)-(p1->total_price));
			(p1->m2.money_after) = (p1->m2.money_before)-(p1->total_price);
		}
		else {
			printf("输入错误！");
		}
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;
	return head;
};







//
// Created by 钱辂 on 2017/12/19.
//

