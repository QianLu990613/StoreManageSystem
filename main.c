#include <stdio.h>
#include "info.h"
int main()
{
	struct addition *m = NULL;
	int n;
	do{
		n = main_interface();
		if (n == 1){
			m = Create();
		}
		else{
			printf("文件中没有内容\n");
			continue;
		}
	}while (n != 1);
	do{
		n = main_interface();
		if (n == 2){
			addition_continue(m);
		}
		else if (n == 3){
			change_link(m);
		}
		else if(n == 4){
			deleteByName(m);
		}
		else if(n == 5){
			search_print(m);
		}
		else if(n == 6){
			m = select_sort(m);
			print(m);
			print_fruits(m);
		}
		else if (n == 7){
			search_print_card(m);
		}
		else if (n == 8){
			big_payment(m);
		}
		else if (n == 9) {
			time_payment(m);
		}
		else if (n == 10) {
			outlink(m);
		}
		else if(n == 11){
			print(m);
		}
		else if (n == 12){
			card_outlink();
		}
	}while (n != 13);
	return 0;
}
