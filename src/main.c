#include<stdio.h>
#include<strings.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
const int InitialCount=100;
int Count,Num,Player;
bool Correct;
int main()
{
    srand(time(0));
    system("cls");
    Player=1;
    Count=InitialCount;
  do{
 
    if (Player==1){
    do{
        printf("Your turn. On table %d spichek.\n", Count);
        printf("How much spichek you take?\n");
        scanf("%d", &Num);
        if((Num>=1) && (Num<=10) && (Num<=Count)){
                Correct=true;}
        else
        {
            //rewind(stdin);
            //printf("%d \n", Num);
            printf("Lie! Try again!\n");
 
            Correct=false;
        }
      } while (!Correct);}
    else
    {
    do{
      Num=rand()%10+1;
      if (Num>Count){
        Num=Count;}
      printf("My Turn. I take  %d spichek\n", Num);
    }while (!Correct);
    }
    Count-=Num;
    if (Player==1){
        Player=2;}
    else{
        Player=1;}
  }
  while (Count>0);
  if (Player==1){
    printf("You won!\n");}
  else {printf("You lose! GOOD DAY SIR!\n");}
 
return 0;
}
