stack
array
#include<iostream>
#include<stdlib.h>
using namespace std;

struct arrayq
{
    int front;
    int rear;
    int capacity;
    int *array;
};
arrayq* createq(int cap)
{
    arrayq *p;
    p=(arrayq*)malloc(sizeof(arrayq));
    p->capacity=cap;
    p->front=-1;
    p->rear=-1;
    p->array=(int*)malloc(cap*sizeof(int));
    return p;
}
int isempty(arrayq *p)
{
    return(p->front==-1);
}
bool isfull(arrayq *p)
{
    return((p->rear+1)%(p->capacity)==(p->front));
}
int sizeatanytime(arrayq *p)
{
    return((p->capacity)-(p->front)+(p->rear+1));
}
void push(arrayq *p,int item)
{
  if(isfull(p))
  {
      cout<<endl<<"queue is full"<<endl;
      return;
  }
  p->rear=(p->rear+1)%p->capacity;
  p->array[p->rear]=item;
  if(p->front=-1)
  p->front=p->rear;
}
int pop(arrayq *p)
{
    int item=-1000;
    if(isempty(p))
    return item;
    item=p->array[p->front];
    if(p->front==p->rear)
    {
       p->front=-1;
       p->rear=-1 ;
    }
    else
    {
        p->front=(p->front+1)%p->capacity;
    }

}
void deleteq(arrayq *p)
{
    if(p)
    {
       if(p->array)
       free(p->array);
       free(p);
    }


}

int main()
{
    arrayq *p;
    p=createq(5);
    int choice,x,y,z,item,l;
    while(1)
    {
        cout<<endl<<"1.push";
        cout<<endl<<"2.pop";
        cout<<endl<<"3.isfull";
        cout<<endl<<"4.isempty"<<endl;
        cout<<endl<<"5.sizeatanytime"<<endl;

        cin>>choice;
        switch(choice)
    {

        case 1: cout<<endl<<"enter item"<<endl;
                 cin>>item;
                push(p,item);
                break;
        case 2:  x=pop(p); break;
        case 3:  y=isfull(p);
                  cout<<endl<<y; break;
        case 4:  z=isempty(p);
                cout<<endl<<z; break;
                case 5:l=sizeatanytime(p);
                cout<<endl<<l;


    }
    }

}
