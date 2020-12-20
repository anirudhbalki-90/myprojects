#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

void main()
{

    FILE *fp1,*fp2,*fp3;
    char finish;
    int adm;
        printf("If you are a customer type 1,If you are an Admin type 2 : ");
        scanf("%d",&adm);
        if(adm==2)
    {
            char password[10];
            printf("Enter the password :");
            scanf("%s",password);
            if(!(strcmp(password,"1234")))

        {

        // CITIES.TXT:
        char city[100];
        fp1=fopen("CITIES.txt","w");
        printf("enter the cities\n");
        fputs("CITIES:\n",fp1);
        int i;
        int j;
        for(i=0;i<5;i++)
        {
            gets(city);

            fputs(city,fp1);
            fputs("\n",fp1);
        }
        fputs("\n",fp1);
        fclose(fp1);


// ourcars.txt

        char car_type[100];
        char car_name[100];
        char no_of_bags[3];
        char no_of_seats[3];
        char ac_non_ac[10];
        char mileage[10];
    printf("Enter :CAR MODEL,CAR NAME,No:of bags,No of seats,AC/NON-AC,and mileage\n");
    fp2=fopen("ourcars.txt","w");
    fputs("CAR MODEL\t\tCAR NAME\t\tNo:of bags\tNo of seats\t    AC/NON-AC\tMileage\n",fp2);
    for(i=0;i<3;i++)



        {

                printf("Car Model :");
                scanf("%s",car_type);
                fputs(car_type,fp2);
                fputs("\t\t\t",fp2);
                printf("Car Name :");
                scanf("%s",car_name);
                fputs(car_name,fp2);
                fputs("\t\t\t",fp2);
                printf("No: of Bags :");
                scanf("%s",no_of_bags);

                fputs(no_of_bags,fp2);
                fputs("\t\t\t",fp2);
                printf("No:of seats :");
                scanf("%s",no_of_seats);
                fputs(no_of_seats,fp2);
                fputs("\t\t",fp2);
                printf("AC OR NON-AC :");
                scanf("%s",ac_non_ac);
                fputs(ac_non_ac,fp2);
                fputs("\t\t",fp2);
                printf("Mileage :");
                scanf("%s",mileage);
                fputs(mileage,fp2);
                fputs("\n",fp2);
                printf("\n\n");

        }


    fclose(fp2);

    }
     else
                {
                    printf("Wrong password");
                    exit(0);
                }
        }
// Customer:
else
    {
int triptype;
char pickupcity[25];
char dropcity[25];
char pickchk[25];
char dropchk[25];
char cctype[25];
int np;
char details[100];
char x;
char tocont;
float costoftravel=0;
// CONSOLE PAGE:

    do
    {
        printf("***************************Welcome!!!!!***********************************************\n");
        printf("TRIP TYPE:\n 1)Outstation One way\n 2) Outstation Round trip\n 3)Cab from Airport\n 4)Cab to airport\n");
        printf("Please enter your trip type(1,2,3 or 4) : ");
        scanf("%d",&triptype);
        printf("\n PLease enter the city in which you are residing :");
        scanf("%s",pickupcity);

        fp1=fopen("CITIES.txt","r");

        for(int i=0;i<5;i++)
        {
            int j=0;
     do
        {

            x=fgetc(fp1);


            pickchk[j]=x;
            j++;

        }while(x!='\n'&&x!=EOF);
        j--;
        pickchk[j--]='\0';
        int k =strcmpi(pickupcity,pickchk);
       if(k==0)
        {
            goto l;
        }
        else if(x==EOF)
           {
                printf("our service is not available in your location");
                fclose(fp1);
                exit(0);
           }
        }

     l:  printf("\n PLease enter the city in which your destination lies :");
         scanf("%s",dropcity);
         fseek(fp1,0,SEEK_SET);
         for(int r=0;r<5;r++)
        {
            int m=0;
     do
        {

            x=fgetc(fp1);
            dropchk[m]=x;
            m++;

        }while(x!='\n'&&x!=EOF);
        m--;
        dropchk[m--]='\0';
        int n=strcmpi(pickupcity,dropcity);
        if(n==0)
        {
            printf("We do provide cab services within your city\n");
            goto l1;
        }
       int b =strcmpi(dropchk,dropcity);
        if(b==0)
        {
            printf("\nOur service is available from %s to %s\n",pickupcity,dropcity);
            goto l1;
        }
        else if(x==EOF)
           {
                printf("our service is not available from %s to %s",pickupcity,dropcity);
                exit(0);
           }
        }
        fclose(fp1);


   l1:fp2=fopen("ourcars.txt","r");
    printf("The list of cars we have are now shown below!!!!!!!!!!\n");

    while(!feof(fp2))
    {
        x=getc(fp2);
        if(x=='\n')
        {
            printf("\n");
        }
        else
        {
            printf("%c",x);
        }
    }
    lc:printf("Enter the type of car you would like to travel in:  ");
    scanf("%s",cctype);
    lm:printf("\n enter the number of people who are traveling : ");
    scanf("%d",&np);
    printf("\n\n");
if(strcmpi(cctype,"sedan")!=0 &&strcmpi(cctype,"H-BACK")!=0&&strcmpi(cctype,"SUV")!=0)
{
    printf("You have entered an invalid car type!\n");
    goto lc;
}
if(strcmpi(cctype,"sedan")==0 && np>4)
{
    printf("Only a maximum of 4 passengers can travel in Sedan");
    goto lm;
}
else if(strcmpi(cctype,"H-BACK")==0 && np>4)
{
    printf("Only a maximum of 4 passengers can travel in H-Back");
    goto lm;
}
else if(strcmpi(cctype,"suv")==0 && np>6)
{
    printf("Only a maximum of 6 passengers can travel in SUV");
    goto lm;

}



// cost of travel: being displayed

if((strcmpi(pickupcity,"chennai")==0&&strcmpi(dropcity,"trichy")==0)||(strcmpi(pickupcity,"trichy")==0&&strcmpi(dropcity,"chennai")==0||strcmpi(pickupcity,dropcity)==0))
    {

        if(strcmpi(cctype,"sedan")==0)
        {
            costoftravel=3450;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=500;
            printf("Cost of travel: %.3f",costoftravel);
        }
        else if(strcmpi(cctype,"H-BACK")==0)
        {
            costoftravel=3900;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=500;
            printf("Cost of travel: %.3f",costoftravel);
        }
       else if(strcmpi(cctype,"suv")==0)
           {
            costoftravel=4441;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=500;
            printf("Cost of travel: %.3f",costoftravel);
           }



    }
else if((strcmpi(pickupcity,"chennai")==0&&strcmpi(dropcity,"coimbatore")==0)||(strcmpi(pickupcity,"coimbatore")==0&&strcmpi(dropcity,"chennai")==0)||strcmpi(pickupcity,dropcity)==0)
    {

        if(strcmpi(cctype,"sedan")==0)
        {


            costoftravel=3900;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=530;
            printf("Cost of travel: %.3f",costoftravel);

        }
        else if(strcmpi(cctype,"H-Back")==0)
            {costoftravel=4587;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=530;
            printf("Cost of travel: %.3f",costoftravel);

            }
       else  if(strcmpi(cctype,"suv")==0)
           {

            costoftravel=5608;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=530;
            printf("Cost of travel: %.3f",costoftravel);

           }





    }
else if((strcmpi(pickupcity,"chennai")==0&&strcmpi(dropcity,"madurai")==0)||(strcmpi(pickupcity,"madurai")==0&&strcmpi(dropcity,"chennai")==0))
    {
        if(strcmpi(cctype,"sedan")==0)
        {


            costoftravel=3324;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=470;
            printf("Cost of travel: %.3f",costoftravel);

        }
       else if(strcmpi(cctype,"H-Back")==0)
        {


            costoftravel=4181;
             if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=470;
            printf("Cost of travel: %.3f",costoftravel);

        }
      else  if(strcmpi(cctype,"suv")==0)
        {


            costoftravel=4991;
             if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=470;
            printf("Cost of travel: %.3f",costoftravel);

        }



    }
else if((strcmpi(pickupcity,"coimbatore")==0&&strcmpi(dropcity,"madurai")==0)||(strcmpi(pickupcity,"madurai")==0&&strcmpi(dropcity,"coimbatore")==0)||strcmpi(pickupcity,dropcity)==0)

    {
        if(strcmpi(cctype,"sedan")==0)
            {
                costoftravel=4524;
                 if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
       else if(strcmpi(cctype,"H-back")==0)
           {

           costoftravel=5181;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
           printf("Cost of travel: %.3f",costoftravel);
           }
        else if(strcmpi(cctype,"suv")==0)
        {


            costoftravel=5981;
             if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
                printf("Cost of travel: %.3f",costoftravel);
        }





    }
else if((strcmpi(pickupcity,"coimbatore")==0&&strcmpi(dropcity,"trichy")==0)||(strcmpi(pickupcity,"trichy")==0&&strcmpi(dropcity,"coimbatore")==0)||strcmpi(pickupcity,dropcity)==0)

    {
        if(strcmpi(cctype,"sedan")==0)
            {costoftravel=3594;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
       else if(strcmpi(cctype,"H-Back")==0)
            {costoftravel=4171;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
        else if(strcmpi(cctype,"suv")==0)
            {costoftravel=5281;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }

    }
else if((strcmpi(pickupcity,"madurai")==0&&strcmpi(dropcity,"trichy")==0)||(strcmpi(pickupcity,"trichy")==0&&strcmpi(dropcity,"madurai")==0)||strcmpi(pickupcity,dropcity)==0)

    {
        if(strcmpi(cctype,"sedan")==0)
            {costoftravel=4564;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
       else if(strcmpi(cctype,"H-BACK")==0)
            {costoftravel=5791;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
       else if(strcmpi(cctype,"suv")==0)
            {costoftravel=7281;
            if(triptype==2)
                costoftravel*=2;
            else if(triptype==3||triptype==4)
                costoftravel+=450;
            printf("Cost of travel: %.3f",costoftravel);
            }
    }

    do
    {
    printf("\nWould you like to confirm your booking??? If yes please enter y/Y if not Please enter n/N:");
    scanf("%c",&tocont);
    scanf("%c",&tocont);
    if(tocont=='y'||tocont=='Y')
    {
        //goto ld;
        break;
    }
    if(tocont=='n'||tocont=='N')
    {
        exit(0);
    }
    }while(tocont=='y'||tocont=='Y');

// customer details:

ld: fp3=fopen("CUSTOMER.txt","w");
    char details[100];

    printf("\nEnter your name : ");
    gets(details);
    gets(details);
    fputs("NAME : ",fp3);
    for (int i = 0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }

    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter the phone number : ");
    gets(details);
    fputs("PHONE NUMBER : ",fp3);
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter the email id : ");
    gets(details);
    fputs("EMAIL ID : ",fp3);
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter your permanent address  : ");
    gets(details);
    fputs("PERMANENT ADDRESS : ",fp3);
     for (int i=0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter your pickup location : ");
    gets(details);
    fputs("PICKUP LOCATION : ",fp3);
     for (int i=0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter the drop location : ");
    gets(details);
    fputs("DROP LOCATION : ",fp3);
     for (int i=0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter the date of travel: ");
    gets(details);
    fputs("DATE : ",fp3);
     for (int i=0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Enter the time of travel : ");
    gets(details);
    fputs("TIME : ",fp3);
     for (int i=0; details[i]!='\0'; i++)
        {
            if(details[i] >= 'a' && details[i] <= 'z')
            details[i] = details[i] -32;
        }
    fputs(details,fp3);
    fputs("\n",fp3);
    printf("Are you sure you want to confirm the booking\n(if yes type y/ if no type n/ To re-enter the details type r) : ");
    char p;
    scanf("%c",&p);
    if(p>='a'&&p<='z')
        p=p-32;
    if(p=='Y')
    {

        printf("Enter the payment method (c for cash or o for  net banking):");
        char q;
        scanf("%c",&q);
        scanf("%c",&q);
        //printf("%c",q);
        if(q>='a'&&q<='z')
        q=q-32;
        fputs("METHOD OF PAYMENT : ",fp3);
        if(q=='C')
        {
            fputs("CASH",fp3);
            fputs("\n",fp3);
        }
        else if (q=='O')
        {
            fputs("NET BANKING",fp3);
            fputs("\n",fp3);
        }
        fputs("BOOKING STATUS : SUCCESS\n",fp3);
        fputs("TIME OF BOOKING : ",fp3);
        fputs(__TIME__,fp3);
        fputs("\nDATE OF BOOKING : ",fp3);
        fputs(__DATE__,fp3);
    }
    else if(p=='n'||p=='N')
    {


        fputs("BOOKING STATUS : FAILED\n",fp3);
         fputs("TIME : ",fp3);
        fputs(__TIME__,fp3);
        fputs("\nDATE : ",fp3);
        fputs(__DATE__,fp3);
        exit(0);
    }
    else if (p=='r'||p=='R')
        {
            fputs("BOOKING STATUS : FAILED\n",fp3);
             fputs("TIME : ",fp3);
        fputs(__TIME__,fp3);
        fputs("\nDATE : ",fp3);
        fputs(__DATE__,fp3);
            fputs("\n*************************************************************************************************************\n",fp3);
            goto ld;
        }
    fputs("\n*************************************************************************************************************\n",fp3);
    fclose(fp3);

    printf("\n\n**************************************Customer Details************************************\n");
    fp3=fopen("CUSTOMER.txt","r");

        char u;
        while(!feof(fp3))
        {
            u=getc(fp3);
            printf("%c",u);
        }
        fclose(fp3);

        printf("\nTrip type:  ");
        switch(triptype)
        {
            case 1:printf("Outstation One Way\n");break;
            case 2:printf("Outstation Round Trip\n");break;
            case 3:printf("Cab From Airport\n");break;
            case 4:printf("Cab To Airport\n");break;
        }
        printf("Number of persons travelling: ");
        printf("%d",np);
        printf("\nFinal Amount(inclusive of GST): ");
        printf("%.3f\n",costoftravel);

    printf("\n***************The details of the driver will be displayed 2 hours prior to departure***********\n");

    printf("Would you like to continue checking for cab availability??(if yes please enter y/Y else please enter n/N)  ");
    scanf("%c",&finish);
    scanf("%c",&finish);
    if(finish=='n'||finish=='N')
        printf("\n*******************Thank you!!!!!!!!!!!************************************");
}while(finish=='y'||finish=='Y');


    }

}


