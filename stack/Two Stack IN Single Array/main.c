#include <stdio.h>
#include <stdlib.h>

struct stack {
  int a[10];
  int top1;
  int top2;
}s;

void push1(int x) {

     if(s.top1+1==s.top2)
     {
      printf("Stack is full");return;
     }

     s.a[++s.top1]=x;
     printf("top1=%d\n",s.a[s.top1]);
}

void push2(int x) {
     if(s.top2-1==s.top1)
     {
      printf("Stack is full");return;
     }

     s.a[--s.top2]=x;
}
void pop1() {
    if(s.top1<=-1)
    {printf("stack is empty\n");return;}

    printf("popped ==%d\n",s.a[s.top1]);
    s.top1--;
}

void pop2() {
    if(s.top2>=10)
    {printf("stack is empty\n");return;}

    printf("popped ==%d\n",s.a[s.top2]);
    s.top2++;
}

int main()
{
    s.top1=-1;
    s.top2=10;

    int x;
    while(1) {
        printf("enter option 1.Push1 2.Pop1 3.Push2 4.Pop2\n");
        scanf("%d",&x);

        if(x==1) {
        scanf("%d",&x);
        push1(x);
        }

        if(x==3) {
        scanf("%d",&x);
        push2(x);
        }

        if(x==2) {pop1();}
        if(x==4) {pop2();}
    }
    return 0;
}
