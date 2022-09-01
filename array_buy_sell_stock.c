#include <stdio.h>

typedef struct order {
    int buy;
    int sell;
} order;

//function finds the buy sell 
// schedule for maximum profit 
void findProfit(int price[], int n) 
{ 
    order orders[n] ;
    int num_orders = 0;
    memset(orders, 0, sizeof(orders));
    for (int i = 0; i < n; i++) {
        while ((i < n-1) && price[i+1] <= price[i]) {
            i++;
        }
               
        if (i == n-1)
            break;
        orders[num_orders].buy = price[i];
        while ((i < n-1) && price[i+1] >= price[i]) {
            i++;
        }
        orders[num_orders].sell = price[i];
        num_orders++;
    }
    for (int i = 0; i < num_orders; i++)
        printf("\nbuy %d sell %d\n", orders[i].buy, orders[i].sell);
} 
  
int main() 
{ 
   // int array1[] = { 98, 178, 250, 300, 40, 540, 690 }; 
    int array1[] = { 7,1,5,3,6,4 };
    int n = sizeof(array1) / sizeof(array1[0]); 
    findProfit(array1, n); 
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = findProfit([7,1,5,3,6,4],6)
expected = 2

Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3

case2: 
 actual = findProfit([1,2,3,4,5],5)
 expected = 4
 Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4
 
case3: 
actual = findProfit([7,6,4,3,1],5)
expected = 0
In this case, no transaction is done, i.e., max profit = 0
*/