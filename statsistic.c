#include <stdio.h>
#include "info.h"
void print_fruits(struct addition *head){
	struct addition *p1;
	p1 = head;
	float apple = 0;
	float banana = 0;
	float pear = 0;
	float watermelon = 0;
	float peach = 0;
	do {
		if (p1->kinds_of_fruit == 1) {
			apple += p1->quantity;
		} else if (p1->kinds_of_fruit == 2) {
			banana += p1->quantity;
		} else if (p1->kinds_of_fruit == 3) {
			pear += p1->quantity;
		} else if (p1->kinds_of_fruit == 4) {
			watermelon += p1->quantity;
		} else if (p1->kinds_of_fruit == 5) {
			peach += p1->quantity;
		}
		p1 = (struct addition *) p1->next;
	}while(p1 != NULL);
	printf("苹果共售出:%.2f kg\n",apple);
	printf("香蕉共售出:%.2f kg\n",banana);
	printf("梨共售出:%.2f kg\n",pear);
	printf("西瓜共售出:%.2f kg\n",watermelon);
	printf("桃子共售出:%.2f kg\n",peach);
}//
// Created by 钱辂 on 2017/12/19.
//

