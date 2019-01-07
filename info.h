//
// Created by 钱辂 on 2017/12/19.
//

#ifndef LIANXI_1_INFO_H
#define LIANXI_1_INFO_H




#ifndef FUNCTION
int main_interface();
struct addition *Create();
void outlink(struct addition *head);
void deleteByName(struct addition * head);
void print_fruits(struct addition *head);
void print(struct addition *head);
void search_print(struct addition *head);
struct addition *select_sort(struct addition *head);
void addition_continue(struct addition *head);
void big_payment(struct addition *head);
void change_link(struct addition *head);
void time_payment(struct addition *head);
void search_print_card(struct addition *head);
void card_outlink();
#endif


#ifndef STRUCT
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
#endif
#endif //LIANXI_1_INFO_H
