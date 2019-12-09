#include <stdio.h>
#include <time.h>
#include <windows.h>
char a[100][100]= {'\0'}; // Our Matrix
int tedad[10000]= {0}; //Number of polices of i-th Kalantary
int isfinished; //A simple Flag to recognize that is dozd dastgired ?
int px[100][100]= {0}; //This is cops's Position --> px[kalantary i-th][cop j]
int py[100][100]= {0}; //This is cops's Position --> py[kalantary i-th][cop j]
int n,m,k,t,xdozd,ydozd,harakatedozd,harakatepolice;
void Initialize(); // Initializes The Matrix
void Display(); // Shows our Matrix
void Update(); // This Function Work until Dozd become dastgired
void Ddecision(); // Cops Decisions
void Tdecision(); // Dozd Decisions
int rg(int,int); // Generates A random number in range [x,y]
int main()
{
    srand(time(NULL));
    Initialize();
    Update();
    return 0;
}
void Initialize()
{
    printf("Enter Size of Environment :\n");
    scanf("%d%d",&n,&m);
    xdozd=rg(0,n-1);
    ydozd=rg(0,m-1);
    a[xdozd][ydozd]='T';
    printf("Enter the number of Kalantaris :\n");
    scanf("%d",&k);
    int i,flag,tmpx,tmpy;
    for(i=0; i<k; i++)
    {
        printf("How Many Police Kalantari #%d has?\n",i+1);
        scanf("%d",&tedad[i]);
        flag=0;
        while(flag<tedad[i])
        {
            tmpx=rg(0,n-1);
            tmpy=rg(0,m-1);
            if(a[tmpx][tmpy]=='\0')
            {
                a[tmpx][tmpy]=i+48; // I used this for converting the number of kalantary to char
                px[i][flag]=tmpx;
                py[i][flag]=tmpy;
                flag++;
            }
        }
    }
}
int rg(int st,int en)
{
    return (rand()%(en-st+1))+st;
}
void Display()
{
    int i,j;
    for(j=0; j<m; j++)
    {
        printf("------");
    }
    printf("-\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i][j]>='0' && a[i][j]<='9')
                printf("| D%c  ",a[i][j]+1);
            else
                printf("|  %c  ",a[i][j]);
        }
        printf("|\n");
        if(i==n-1)
        {
            for(j=0; j<m; j++)
            {
                printf("------");
            }
            printf("-\n");
        }
        else
        {
            for(j=0; j<m; j++)
            {
                printf("|-----");
            }
            printf("|\n");
        }
    }
    t++;
    Sleep(500);
    if(!isfinished)
        system("cls");
}
void Tdecision()
{
    if(!isfinished)
    {
        int x=rg(-1,1);
        int y=rg(-1,1);
        int tmpx=x+xdozd;
        int tmpy=y+ydozd;
        if(tmpx>0 && tmpy>0 && tmpx<n && tmpy<m)
        {
            if(a[tmpx][tmpy]>='0' && a[tmpx][tmpy]<='9')
            {
                a[xdozd][ydozd]='\0';
                isfinished=1;
                a[tmpx][tmpy]='K';
                harakatedozd++;
            }
            else
            {
                a[xdozd][ydozd]='\0';
                a[tmpx][tmpy]='T';
                xdozd=tmpx;
                ydozd=tmpy;
                harakatedozd++;
            }
        }
    }
}
void Ddecision()
{
    if(!isfinished)
    {
        int kln,cops;
        for(kln=0; kln<k; kln++)
        {
            if(!isfinished)
            {
                int isthere=0;
                /*
                At first I check for every Kalantary this conditions :
                Is Dozd near to cop in [-2,2] range?
                    if yes --> every cops from that kalantary should move to dozd . How ? I will explain that in [III]
                    if no --> Move Randomly
                */
                for(cops=0; cops<tedad[kln]; cops++)
                {
                    int x=px[kln][cops];
                    int y=py[kln][cops];
                    int i,j;
                    for(i=-2; i<=2; i++)
                    {
                        for(j=-2; j<=2; j++)
                        {
                            if(a[x+i][y+j]=='T')
                            {
                                if(x+i || y+i)
                                {
                                    isthere=1;
                                }

                            }
                        }
                    }
                    if(isthere)
                    {
                        break;
                    }
                }
                if(isthere)
                {
                    /*
                    [III]
                        in here i check fasele oghlidosi for every cop and move him correctly
                    */
                    for(cops=0; cops<tedad[kln]; cops++)
                    {
                        if(!isfinished)
                        {
                            int x=px[kln][cops];
                            int y=py[kln][cops];
                            int ux=x-xdozd;
                            int uy=y-ydozd;
                            if(ux>0)
                                ux=-1;
                            else if(ux<0)
                                ux=+1;
                            if(uy>0)
                                uy=-1;
                            else if(uy<0)
                                uy=+1;
                            if(a[x+ux][y+uy]=='\0')
                            {
                                if(ux+x>0 && uy+y>0 && ux+x<n && uy+y<m)
                                {
                                    px[kln][cops]+=ux;
                                    py[kln][cops]+=uy;
                                    a[x][y]='\0';
                                    a[ux+x][uy+y]=kln+48; // I used this for converting the number of kalantary to char
                                    harakatepolice++;
                                }
                            }
                            else if(a[x+ux][y+uy]=='T')
                            {
                                a[x][y]='\0';
                                isfinished=1;
                                a[x+ux][y+uy]='K';
                                harakatepolice++;

                            }
                        }
                    }
                }
                else
                {
                    /*
                    in here I move Cops Randomly
                    */
                    for(cops=0; cops<tedad[kln]; cops++)
                    {
                        if(!isfinished)
                        {
                            int x2=rg(-1,1);
                            int y2=rg(-1,1);
                            int x=px[kln][cops];
                            int y=py[kln][cops];
                            int tmpx=x2+x;
                            int tmpy=y2+y;
                            if(a[tmpx][tmpy]=='T')
                            {
                                a[x][y]='\0';
                                isfinished=1;
                                a[tmpx][tmpy]='K';
                                harakatepolice++;
                            }
                            else if(a[tmpx][tmpy]=='\0')
                            {
                                if(tmpx>0 && tmpy>0 && tmpx<n && tmpy<m)
                                {
                                    a[x][y]='\0';
                                    px[kln][cops]=tmpx;
                                    py[kln][cops]=tmpy;
                                    a[tmpx][tmpy]=kln+48; // I used this for converting the number of kalantary to char
                                    harakatepolice++;
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}
void Update()
{
    for(;;) // This is an Infinity Loop until Dozd Become Dastgired
    {
        if(isfinished)
        {
            printf("Dozd Gerefte Shod Dar Lahzeie %d \n",t);
            printf("Tedad Harakate Dozd = %d \n",harakatedozd);
            printf("Tedad Harakate Police ha = %d \n",harakatepolice);
            break;
        }
        else
        {
            Tdecision();
            Ddecision();
            Display();
        }
    }
}


