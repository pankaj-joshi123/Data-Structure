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

void putLeastInBottom(int x) {

    if(chaubey.top==-1 || x>=chaubey.s[chaubey.top])
    {   push(x);
        return;
    }

    if(x<chaubey.s[chaubey.top])
    {
        int tempo=pop();       ///** if you don't pop here the elemets wont decrese --> infinite loop
        putLeastInBottom(x);   ///by this recursice calling the stack again pop from top so that min elemt goes down
        push(tempo);
    }

}

void sort() {
    if(chaubey.top<=-1)
    return;

    int x=pop();
    sort();
    putLeastInBottom(x);
}

int main() {
    chaubey.top = -1;
    push(29);
    push(26);
    push(97);
    push(-5);
    push(50);
    display();

    sort();

    display();

return 0;
}
