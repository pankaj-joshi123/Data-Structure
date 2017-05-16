#include <stdio.h>
#include <stdlib.h>
#define size 10

struct stack {
   int s[size];
   int top;
} chaubey;

void push(int item) {
   chaubey.top++;
   chaubey.s[chaubey.top] = item;
}

int pop() {
   int item;
   item = chaubey.s[chaubey.top];
   chaubey.top--;
   return (item);
}

int stempty() {
   if (chaubey.top == -1)
      return 1;
   else
      return 0;
}

void display() {
   int i;
   if (stempty())
      printf("\nChaubey Is Empty!");
   else {
      for (i = chaubey.top; i >= 0; i--)
         printf("\n%d", chaubey.s[i]);
   }
}
/*******************************************************************
First thing is input array will be given which contains the stock prices
You need to store the span in the output array
The important point is stock prices are given so storing them again will not be of any use
Instead of storing the stock prices you can store the indexes....... by indexes you are basically
checking the maximum last height from which the current stock was bigger'
And once you get a maximum height you stop there .........
The differenct between the index of current and the last will give you the last height which was greater than this
******************************************************************/

void calculate(int prices[],int answer[]) {

   int n = 7;
   int i;
   chaubey.top = -1;

   answer[0]=1;                    /*the first element will have only one as the height**/
   push(0);                        /**This is the index of the first element pushed we assume it is the highest height*/

   for(i=1;i<n;i++) {
     if(prices[i]<prices[chaubey.s[chaubey.top]]) {  /*which means if the coming is for smaller height then we just push it**/
        printf("\nin If loop");
        answer[i]=1;                        /*as it is just smaller so no one is smaller than him so least span of 1**/
        push(i);
     }
     else{
       while(!stempty() && prices[i]>prices[chaubey.s[chaubey.top]])     /**until you get a larger height keep on popping**/
       {
       printf("\npopping as %d > %d",prices[i],prices[chaubey.s[chaubey.top]]);
       pop();
       }

       if(chaubey.top==-1)
       {
        answer[i]=i+1;
       }
        else
       answer[i]=i-chaubey.s[chaubey.top];

       push(i);
     }
   }

printf("\n\n\n");
   for(i=0;i<n;i++) {
     printf("%d ",answer[i]);
   }

}

int main() {

    int price[] = {100, 80, 60, 70, 60, 75 ,85};

    int answer[10]={0};

    calculate(price,answer);

return 0;
}
