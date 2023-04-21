#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#define MAX 20  
#define TURE 1  
#define FALSE 0 
// typedef  struct listnode node; 
struct listnode{
    int date; 
    struct listnode *link; 
 };
 struct listnode *seq[MAX];
 int put[MAX],n;
 struct listnode *Malloc(void)
 {
    struct listnode *temp; 
    if(!(temp=(struct listnode*)malloc(sizeof(struct listnode)))){
    fprintf(stderr,"error:memory location failed!");
    exit(2); 
 }
return temp; 
} 
int initial(struct listnode **seq,int *put) 
{
int i; 
for(i=0;i<MAX;i++){ 
    seq[i]=NULL;
    put[i]=TURE;
} 
printf("enter the types(<=%d):",MAX); 
scanf("%d",&n);
printf("\n"); 
if(n>0&&n<=MAX){ 
for(i=0;i<n;i++){
seq[i]=Malloc(); 
seq[i]->date=i; 
seq[i]->link=NULL;
put[i]=TURE;
}
}
else{
fprintf (stderr,"waring:Wrong puting of types!"); 
exit(1);
 }
return 0; 
 }
int inputpairs(struct listnode **seq) 
{
int i,j; 
struct listnode *temp; 
printf("enter your pairs of equivalence with the form\"i j\"[<-1 -1>means quit]:\n"); 
scanf("%d %d",&i,&j);
while(TURE){
if(i==-1&&j==-1) 
break; 
 
else if(i>=0&&j>=0&&i<n&&j<n){
    temp=Malloc(); 
    temp->date=i;temp->link=seq[j]->link;seq[j]->link=temp;
    temp= Malloc();
    temp->date =j;temp->link=seq[i]->link;seq[i]->link=temp;
    } 
else{
fprintf(stderr,"wrong pairs!"); 
exit(3);
} 
scanf("%d %d",&i,&j); 
}
return 0; 
}
int output_predeal(struct listnode **seq)
{
int i;
struct listnode *temp;
for(i=0;i<n;i++){
printf("%d:",i); 
temp=seq[i];
while(temp){ 
printf("%5d",temp->date); 
temp=temp->link;
} 
printf("\n");
} 

return 0; 
} 
int output_deal(struct listnode *Node,int *put, struct listnode **seq)
{
while(Node){
    if(put[Node->date]){ 
    printf("%2d",Node->date); 
    put[Node->date]=FALSE;
    output_deal(seq[Node->date],put,seq);
     }
    Node=Node->link; 
}
return 0; 
}
int main(void) 
{
int k; 
initial(seq,put);
inputpairs(seq); 
output_predeal(seq);
printf("\n \n"); 
printf("after deal,there are types:\n");
for(k=0;k<n;k++)
{ output_deal(seq[k],put,seq);
 printf("\n"); 
 }

return 0;
}
