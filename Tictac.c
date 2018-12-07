#include<stdio.h>
#include<string.h>
int main()
{
 char endchoice[10];
 do
 {
  char s1[100]={'\0'},s2[100]={'\0'},z1,z2,s3[100]={'\0'},a[3][3]={'.','.','.','.','.','.','.','.','.'},n,ch[5],ch2[5],firstuser[100]={'\0'},seconduser[100]={'\0'};
  int p1,p2,c=0,i,j,fl,flag,mychoice=0,cons,k=1,counter,awina,awinb,bwina,bwinb,cwina,cwinb,dwina,dwinb,ewina,ewinb,fwina,fwinb,gwina,gwinb,hwina,hwinb;
  system("cls");
  printf("\t\t*****TIC TAC TOE GAME*****\n");
  printf("Enter a name for X player:- ");
  gets(s1);
  printf("Enter a name for 0 player:- ");
  gets(s2);
  do
  {
   printf("Who is going to take first chance, %s or %s? - ",s1,s2);
   gets(s3);
   p1=strcmpi(s1,s3);
   p2=strcmpi(s2,s3);
   if(p1==0)
   {
    z1='X';
    z2='O';
    strcpy(firstuser,s1);
    strcpy(seconduser,s2);
   }
   if(p2==0)
   {
    z1='O';
    z2='X';
    strcpy(firstuser,s2);
    strcpy(seconduser,s1);
   }
   if(p1==0||p2==0)
   {
    c=1;
    break;
   }
   else
    printf("Invalid player name.....Please enter again\n");
  }while(c!=1);
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    printf("%c ",a[i][j]);
   printf("\n");
  }
  do
  {
   cons=0;
   if((p1==0&&k%2!=0)||(p2==0&&k%2==0))
   {
    printf("Player of Current turn is: %s",s1);
   }
   else if((p2==0&&k%2!=0)||(p1==0&&k%2==0))
   {
    printf("Player of Current turn is: %s",s2);
   }
   do
   {
    fl=0;
    printf("\nchoose a row number (0 to 2) : ");
    gets(ch);
    i=ch[0]-48;
    if(ch[0]!='\0'&&ch[1]=='\0')
    {
     if(ch[0]=='0'||ch[0]=='1'||ch[0]=='2')
      fl=1;
     else
      printf("Invalid row number");
    }
    else
     printf("Invalid row number");
   }while(fl!=1);
   do
   {
    flag=0;
    printf("choose a column number (0 to 2) : ");
    gets(ch2);
    j=ch2[0]-48;
    if(ch2[0]!='\0'&&ch2[1]=='\0')
    {
     if(ch2[0]=='0'||ch2[0]=='1'||ch2[0]=='2')
      flag=1;
     else
      printf("Invalid column number\n");
    }
    else
     printf("Invalid column number\n");
   }while(flag!=1);
   system("cls");
   if(a[i][j]=='.')
   {
    if(k%2!=0)
     a[i][j]=z1;
    else
     a[i][j]=z2;
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
      printf("%c ",a[i][j]);
     printf("\n");
    }
   }
   else
   {
    printf("Error...given space is already occupied\n");
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
      printf("%c ",a[i][j]);
     printf("\n");
    }
    cons=1;
   }
   if(cons!=1)
    k++;
   counter=awina=awinb=bwina=bwinb=cwina=cwinb=dwina=dwinb=ewina=ewinb=fwina=fwinb=gwina=gwinb=hwina=hwinb=0;
   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
     if((i==j)&&(a[i][j]==z1))
      awina=awina+1;
     if((i==j)&&(a[i][j]==z2))
      awinb=awinb+1;
     if((i+j==2)&&(a[i][j]==z1))
      bwina++;
     if((i+j==2)&&(a[i][j]==z2))
      bwinb++;
     if(i==0&&a[i][j]==z1)
      cwina++;
     if(i==0&&a[i][j]==z2)
      cwinb++;
     if(i==1&&a[i][j]==z1)
      dwina++;
     if(i==1&&a[i][j]==z2)
      dwinb++;
     if(i==2&&a[i][j]==z1)
      ewina++;
     if(i==2&&a[i][j]==z2)
      ewinb++;
     if(j==0&&a[i][j]==z1)
      fwina++;
     if(j==0&&a[i][j]==z2)
      fwinb++;
     if(j==1&&a[i][j]==z1)
      gwina++;
     if(j==1&&a[i][j]==z2)
      gwinb++;
     if(j==2&&a[i][j]==z1)
      hwina++;
     if(j==2&&a[i][j]==z2)
      hwinb++;
     if(a[i][j]!='.')
      counter++;
    }
   }
   if(awina==3||bwina==3||cwina==3||dwina==3||ewina==3||fwina==3||gwina==3||hwina==3)
   {
    printf("Game is over!!\n%s wins the game\n",firstuser);
    break;
   }
   if(awinb==3||bwinb==3||cwinb==3||dwinb==3||ewinb==3||fwinb==3||gwinb==3||hwinb==3)
   {
    printf("Game is over!!\n%s wins the game\n",seconduser);
    break;
   }
   if(counter==9)
   {
    printf("Game is over!!\nThere is a tie\n");
    break;
   }
  }while(k!=0);
  do
  {
   printf("Do you want to play again? (Y/N)\n");
   gets(endchoice);
   if((endchoice[0]=='Y'&&endchoice[1]=='\0')||(endchoice[0]=='N'&&endchoice[1]=='\0'))
   mychoice++;
   else
   printf("Invalid Choice\n");
  }while(mychoice!=1);
  if(endchoice[0]=='N'&&endchoice[1]=='\0')
   printf("Good bye!!\n");
 }while(endchoice[0]=='Y'&&endchoice[1]=='\0');
return 0;
}

