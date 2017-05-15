#include <stdio.h>
#include <stdlib.h>

/****************************
Array Implementation of Stack
******************************/
int a[100]={0};
int top=-1;

void pop() {

   if(top<=-1)
   { printf("Stack is empty\n");
     return;
   }

    printf("popped ==%d\n",a[top]);
    top--;
}

void push(int x) {
    a[++top]=x;
    printf("pushed ==%d\n",a[top]);
}


int main()
{
 int i;

  while(1) {
  printf("\nenter choice 1.push 2. pop\n");

  scanf("%d",&i);

  if(i==1) {
   scanf("%d",&i);
   push(i);
  }

  if(i==2)
  pop();

 }
    return 0;
}
