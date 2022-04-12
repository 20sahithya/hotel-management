#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define MAX 15

void begin();              //function declarations//
void additionalprograms();
void complaints_suggestions();
void bookings();
void finalbill();
void menu();
int search();
int modify_details();


//STORING THE PERSONAL DETAILS OF THE CUSTOMER


struct personal
{

     char name[500];
     long int phone;
     char email[500];
     int roomno;
     char *roomtype;
     int bill;
     char *additionalprogram;

   };

//AN INTERACTIVE WAY TO RECIEVE INFORMATION
  

    int main()
   {
    struct personal a;
    personal.roomno=0;
      personal.bill=0;
      personal.additionalprogram="not chosen";



      printf(".............WELCOME TO SK HOTELS .............\n");
      printf("Please enter your details before moving to the main page!\n");
      printf("please enter your name:");
      scanf("%s",a.name);
      printf("enter your phone no:");
      scanf("%ld",&a.phone);
      printf("enter your email_id:");
      scanf("%s",a.email);

           begin();
           return 0;
}

//home page for selecting our choice

void begin(void)
 {
   int decide;
   printf("\n-----------------------HOME PAGE--------------------------\n");
   printf("\n HOW CAN WE HELP YOU?\n\n");

   printf("\n1.Book a room\n2to check out our fun additional programs for our customers.\n3.feel free to give your suggestions and complaints about on our services\n4.$
   scanf("%d",&decide);


     switch(decide)
       {
         case 1:
         bookings();
         break;

           case 2:
           additionalprograms();
           break;

  case 3:
             complaints_suggestions();
              printf("Thank you for your valuable suggestions!\n");
             begin();
             break;


               case 4:
               finalbill();
               break;


                    case 5:
                    printf("Visit again!");
                    printf("Thank you for trusting our service.\n");
                    break;

                       default:
                       printf("please choose  a number for continuing to the next page");

            }
 }

 //when no 1 is chosen-bookings


 
void bookings(void)
{

  struct personal a;

  if(personal.roomno == 0)
 {
    int i;
    int rooms;
    char ch,c;
    printf("\nWhat type of room do u want to book?\n");
  printf("\n1.Basic Room(1 bed)-Rs 1000\n2.Medium room(2 beds+balcony) -Rs 2500\n3.DELUXE ROOM(4 beds+balcony)- Rs 4000\n4.SUPER DELUXE ROOM-(4 beds+views +balcony)-$
    scanf("%d ",&rooms);

     fflush(stdin);


      if(rooms==1)

       {
          printf("\nDo you accept this room?(y/n)\n");
          fflush(stdin);
          scanf("%c",&c);
          if (c=='y')
            {
              printf("\nYou choose basic room. Enjoy your stay\n");
              for(int i=1;i<25;i++)
              printf("your room number is %d",i);

              personal.roomno = i;
              personal.roomtype = "basic";
  personal.bill += 1000;
              begin();
            }
         else

         begin();


       }

         if(rooms==2)
          {
              printf("\nDo you accept this room?(y/n)\n");
              scanf("%c",&c);
               if(c=='y')
             {

                printf("\nYou choose medium room. Enjoy your stay\n");
                for(int i=25;i<60;i++)
                printf("yoyr room no is %d",i);

                 personal.bill += 2500;
                 for(int i=25;i<60;i++)
                 personal.roomno =i;
                 personal.roomtype = "medium";
                 begin();
            }

          else

             begin();


       }


                      if(rooms==3)
                       {
                         printf("\nDo u accept this room?(y/n)\n");
  scanf("%c",&c);
                         if(c=='y')
                       {

                          printf("\nYou choose deluxe room. Enjoy your stay\n");
                          for(int i=60;i<100;i++)

                          printf("your room no is %d",i);
                          personal.bill += 4000;
                          personal.roomtype = "deluxe";
                          personal.roomno = i;
                           begin();
                        }

                        else


                        begin();

                       }

                            if(rooms==4)


                             {
                                 printf("\nDo you accept this room?(y/n)\n");
                                 scanf("%c",&c);
                                 if(c=='y')
                                  {

                                      printf("\nYou choose super deluxe room. Enjoy your stay\n");
                                       for(int i=100;i<130;i++)
                                       printf("your room no is %d",i);


                                       personal.bill += 5500;
  personal.roomno = i;
                                       personal.roomtype = "super deluxe";
                                        begin();
                                    }

                            else


                           begin();


                  }
}
}

//APART FROM THE ROOMS SOME  AMENITIES ARE PROVIDED TO MAKE THE CUSTOMERS'S STAY MORE ENJOYABLE

void additionalprograms(void)

 {

     int p;
      struct personal a;

      printf("\nWhich program do you want to choose?\n");
      printf("\n 1.Jungle Walk \n 2.Jungle Jeep Drive\n 3.Canoe ride \n 4. Cultural show ");
      scanf("%d",&p);

      switch(p)
       {
            case 1:

            printf("\nYou choose jungle walk\n");
            personal.additionalprogram = "Jungle walk";
            personal.bill += 1000;
            begin();
            break;


            case 2:
            printf("\nYou choose jungle jeep drive\n");
            personal.additionalprogram = "Jeep Drive";
            personal.bill += 2000;
            begin();

             break;


              case 3:
              printf("\nYou choose canoe ride\n");
              personal.bill+= 800;
              personal.additionalprogram = "Canoe Ride";
              begin();
              break;



              case 4:
              printf("\nYou choose cultural show\n");
              personal.bill+= 1000;
              personal.additionalprogram = "Cultural show";
              begin();
              break;


              default:
               begin();


            }


 }

//FOR IMPROVEMENT IN OUR SERVICES WE  RECIEVE

  void complaints_suggestions(void)
 {

    char complain[500];

     FILE *b;


    if(b == NULL)
    {
          printf("file cant be opened\n");
     }


       printf("please enter your complaints or suggestions");
       fflush(stdin);
       scanf("%s",complain);
  b= fopen("complain.txt","w+");
       fputs(complain,b);
       fclose(b);

  }



 //THE FINAL BILL TO BE PRINTED


void finalbill(void)
{

 struct personal a;
 FILE *b;
 b= fopen("personal","w+");

 if(b== NULL)
{
 printf("file cant be opened\n");
}

  else
{
      fprintf(b,"........DETAILS......\n");
      fprintf(b,"Name : %s\n",personal.name);
      fprintf(b,"Email id : %s\n",personal.email);
      fprintf(b,"Phone no: %ld\n",personal.phone);

      fprintf(b,"Roomno : %d\n",personal.roomno);
      fprintf(b,"Roomtype : %s\n",personal.roomtype);


       if(strcmp(personal.additionalprogram,"notchosen") != 0)
     {
       fprintf(b,"Program : %s\n",personal.additionalprogram);
     }

       fprintf(b,"your bill price is %d\n",personal.bill);
 fprintf(b,"press p to print your details");

       fflush(b);
       fclose(b);
       begin();


     }
}


 //BEFORE  FINALISING A MENU IS PRESENTED TO THE CUSTOMERS TO MAKE CHANGES(IF ANY)

void menu()
{
    int choice = 0;
    do
    {

        printf("\n\n\n\t\t\t1.search for customers details");
 printf("\n\t\t\t2.delete any entry");
        printf("\n\t\t\t3.exit ");


        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            search();
            break;
        case 2:
            modify_details;
            break;

        case 3:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
 printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    }
    while(choice!=0);
}



 //TO SEARCH FOR  A PARTICULAR RECORD

int search_customer()

{
    struct personal a;
    FILE *b;
    int found=0;
    int status = 0;
    char search[50];

    b = fopen("personal","rb");
 if(b == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }

         printf("\n\n\t\t\tEnter customer Name to search:");
         fflush(stdin);
        scanf("%s",search);

           rewind(b);

           while(fread(&a,sizeof(search),1,b)==1)
            {
              if(!strcmp(a.name,search)==0)
               {
                 found=1;
                 printf("\nName:%s",a.name);
                 printf("\nphone number:%ld",a.phone);
                 printf("\nemail id :%s",a.email);

               }
        }

    if(found==0)
      printf("\n there is no such record");

      fclose(b);
       return 0;


}

//TO UPDATE OR MODIFY PERSONAL DETAILS


int modify_details()

{

   struct personal a;
   FILE *b;
   char search[50];

     int found;

      int record_count=0;

     b=fopen("personal","rb+");

      if(b=NULL)
      {
       printf("cannot open file");
       exit(1);

      }

       printf("\tEnter customer name to modify their records:\t");

       scanf("%s",search);

       while(fread(&a,sizeof(a),1,b)==1)

       {
              if(!strcmp(a.name,search)==0)
               {
                 found=1;
                 printf("\n enter new record(name,phone,email):");
                 scanf("%s%ld%s",a.name,&a.phone,a.email);

                fseek(b,sizeof(a)*record_count,0);
                 if(fwrite(&a,sizeof(a),1,b)==1)

                      printf("\n record modified");
                }

                  record_count++;
       }

  if(found==0)
     printf("there is no such record");

      fclose(b);
      return 0;

    }
printf("thank you ! hope you Enjoy your stay");
}

