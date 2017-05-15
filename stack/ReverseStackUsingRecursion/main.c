/*********************
The only thing is recursion so pop the element let the whole recusion calling gets empty
Once the recursion is over the first popped will be last to come back
Hence just by recursive calling it will become upside down
********************/


#include<stdio.h>
#include<stdlib.h>

#define size 5
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

void reverse() {
 if(chaubey.top<=-1)
 return;

 int x=pop();
 reverse();
 push(x);
}

int main() {
    chaubey.top = -1;
    push(25);
    push(26);
    push(27);
    push(28);
    display();
    reverse();
    printf("\n\n\n\n");
    display();

return 0;
}
