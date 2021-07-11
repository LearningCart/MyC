/* Bank withdrawal helper.
Will divide amount to withdraw in terms of number of 
notes required from the legal tender denominators
*/

#include <stdio.h>

int denominators[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};

#define NUM_DENOM   (sizeof(denominators)/sizeof(denominators[0]))

int main(int argc,char **argv)
{
    int amount_cash_withdraw, index, numnotes;

    amount_cash_withdraw = 0;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount_cash_withdraw);


    for(index = NUM_DENOM - 1; 0 <= index && 0 != amount_cash_withdraw; index--) 
    {
        if(amount_cash_withdraw >= denominators[index])
        {
            numnotes = amount_cash_withdraw / denominators[index];
            printf("Total: %d notes of %d Rupeese\n", numnotes, denominators[index]);
            amount_cash_withdraw -= (numnotes * denominators[index]);
        }
    } 
    return 0;
}
