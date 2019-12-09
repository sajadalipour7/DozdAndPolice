#include <stdio.h>
#include <time.h>
#include <windows.h>
int a[100][100];
//if a[i][j]=0-->a[i][j]=empty
//if a[i][j]=1-->a[i][j]=Dozd
//if a[i][j]=2-->a[i][j]=Police
//if a[i][j]=3-->a[i][j]=Kalantary
int p[1000];
int n,m,k,t;
void Initialize();
void Display();
void update();
void Ddecision();
void Pdecision();
int rg(int,int);
int main()
{
    srand(time(NULL));
    Initialize();
    Display();
    return 0;
}
void Initialize(){
    printf("Enter Size of Environment :\n");
    scanf("%d%d",&n,&m);
    printf("Enter the number of Kalantaris :\n");
    scanf("%d",&k);
    int i,r;
    for(i=0;i<k;i++){
        printf("How Many Police Kalantari #%d has?\n",i+1);
        scanf("%d",&r);
        p[i]=r;
    }
}
int rg(int st,int en){
    return (rand()%(en-st+1))+st;
}
void Display(){
    int i,j;
    for(j=0;j<m;j++){
            printf("------");
    }
    printf("-\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("|  %d  ",a[i][j]);
        }
        printf("|\n");
        if(i==n-1){
            for(j=0;j<m;j++){
            printf("------");
            }
            printf("-\n");
        }else{
        for(j=0;j<m;j++){
            printf("|-----");
        }
        printf("|\n");
        }
    }
    t++;
    //Sleep(500);
    //system("cls");
}
void Ddecision(){
    int x=rg(1,9);
    x--;
    int i=x/3;
    int j=x%3;
    if(a[i][j]==0);
}
void update(){

}
