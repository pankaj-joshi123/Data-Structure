#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;                            /** so that all the member functions can be attatched to this **/

node * push(node *root,int x) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=x;

/*********************
make the new node next as the previous node else you would not be able to come back to previous node after pop
***********************/
    newNode->next=root;
    root=newNode;

    return root;
}

node * pop(node *root) {
  if(root==NULL)
  {
    printf("Stack is Empty\n");
    return root;
  }

  printf("Popped =%d\n",root->data);
  node *temperory=root;
  root=temperory->next;

  free(temperory);
  return root;
}

int main()
{
    node* root=NULL;
    int x;
    while(1) {
        printf("enter your choice 1.push 2.pop\n");
        scanf("%d",&x);

        if(x==1)
        { scanf("%d",&x);
          root=push(root,x);
        }
        else
        root=pop(root);

    }

    return 0;
}
