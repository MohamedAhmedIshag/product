#include <stdio.h> 

	typedef unsigned short int u16; 
	typedef struct{

	char name[30];
	u16 price; 
	u16 quantity;
	
	} product_t;
	
	int main(){
	
	u16 items_count; 
	u16 total_bill=0; 
	u16 total_items_quantity=0; 
	printf("enter number of different product"); 
	scanf ("%hu" , &items_count);
	product_t cart[items_count];
	for(int i=0 ; i<items_count; i++){
	
	printf("\n====product%d====\n" , i+1 );
	
	printf("name:");
	scanf(" %29[^\n]", cart[i].name);
	
	printf("price per unit:");	
	scanf(" %hu" , &cart[i].price);
	
	printf("quantity:");
	scanf(" %hu" , &cart[i].quantity);
	
	total_bill += (cart[i].price * cart[i].quantity);
    total_items_quantity += cart[i].quantity;
	}
	printf("\n====INVOICE====\n"); 
	printf("items\t\tprice\tqty\tsub total\n"); 
	for(int i=0; i<items_count; i++){
	u16 sub_total= cart[i].price*cart[i].quantity;
	
	printf("%s\t\t%d\t%d\t%d\n", cart[i].name,cart[i].price,cart[i].quantity, sub_total);
	}
	printf("------------------------\n");
	printf("total units sold=%d items\n", total_items_quantity);
	printf ("total Amount Due:%d\n ", total_bill);
	
FILE *file = fopen("invoices_history.txt", "a");

if (file != NULL) {
    fprintf(file, "\n==== INVOICE ====\n");
    fprintf(file, "items\t\tprice\tqty\tsub total\n");

    for (int i = 0; i < items_count; i++) {
        u16 sub_total = cart[i].price * cart[i].quantity;
        fprintf(file, "%s\t\t%d\t%d\t%d\n", cart[i].name, cart[i].price, cart[i].quantity, sub_total);
    }

    fprintf(file, "-----------------------------------\n");
    fprintf(file, "total units sold = %d items\n", total_items_quantity);
    fprintf(file, "total Amount Due: %d\n", total_bill);
    fprintf(file, "===================================\n");

    fclose(file); 
}
	return 0;
	}