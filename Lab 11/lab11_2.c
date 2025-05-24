#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int leftover(int money, int *prices) {
    int min_leftover = money;
    int n = 4;  
    
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int cost = prices[i] + prices[j];
            if (cost <= money && (money - cost) < min_leftover) {
                printf("\n -%d",prices[i]);
                printf("\n -%d \n",prices[j]);
                min_leftover = money - cost;
            }
        }
    }
    return min_leftover;
}

int main () {
    int t = 0;
    printf("Enter how many chocolate: ");
    scanf("%d" ,&t);
    int *prices = (int *)malloc(t * sizeof(int));
    int money = 0;
    int count = 0;

    printf("\n Enter prices of goods: ");
    while (count < t) {
        if (scanf("%d", &prices[count]) != 1) {
            break;
        }
        count++;
    }
    
    printf("\n Enter your money: ");
    scanf("%d", &money);

    printf("Your leftover is : %d", leftover(money, prices));
    free(prices);

    return 0;
}
