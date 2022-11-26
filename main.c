//Andrea Tinsley 6165934 and Jose Cosio 5646580
/*Final Project: Quicket Airlines
Department of Electrical and Computer Engineering
Florida International University 
EEL 2880-C Programming for Embedded systems
Spring 2021

The program will prompt the user to select one of the 3 airlines (economy, American, and International). The user’s input will open and display the file for that company so that the user can select a city to travel to. 

The fees will be calculated as follows:
Price of flight depending on airline
Florida Tax, seat fee, our booking site’s fee, and bags/extras
Add-ons (hotel fees, attraction fees, transportation fees)
Multiple bookings will be added at the end by multiplying total by the amount of people. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15



float calFinalPrice(int cost, float extras);
float companySelect(char input);
float extraPrice(int cost);
void randomTrip(int *pointsptr);//functions
int pointsCalc;
int main(void) 
{
 char input;
 int bags,cost,extrasTotal,passengers,points,*pointsptr;
 float finalPrice,passengerPrice;
 pointsptr=&points;
 printf("Welcome to Quicket, the easy airline booking service.\nAll our flights are roundtrips starting from Miami International Airport and returning there as well\n**All flights and passes are intended for trips lasting one week**\n\nPlease select the airline you would like to fly with: ");
 printf("\nEnter \"E\" for Easyjet (economy), \"A\" for American (business), and \"B\" for International flights: ");
 scanf("%c", &input);
 cost = companySelect(input);
 extrasTotal = extraPrice(cost);
 points=calFinalPrice(cost,extrasTotal);
 randomTrip(&points);
 printf("\n\nThank you for booking with Quicket! \nIf you have any questions please do not hesitate to contact one of our agents at 123-456-7899 \nor by email at thesemesterisfinallyover@quicket.com\nWe hope to see you soon! Happy Travels and enjoy your trip!");
 return 0;
}//end main

float companySelect(char input)
{
	char city[SIZE][30], state[SIZE][20], destination[30];
	int i;
	if(input == 'E')//printing flight info for economy 
 {
	 FILE *fpe;
		fpe=fopen("Easyjet.txt","r");
		if(fpe==NULL)
		{
			printf("File cannot be found\n");
		}
		else
		{
			printf("City \t\t  State\n");
			for(i=0; i<SIZE; i++)
			{
				fscanf(fpe,"%s %s", city[i], state[i]);
				printf("%-13s %-13s\n",city[i], state[i]);
			}
			printf("\nEnter the city you wish to travel to: ");
      scanf("%s",destination);
			printf("\n----------------------------------------------------------------");
			printf("\nFlying to %s costs $100\n",destination);	
		  return 100;
    }
		fclose(fpe);
 }
 else if(input=='B')
 {
	 FILE *fpb;
	 
	 fpb = fopen("BA.txt","r");
	 if(fpb==NULL)
	 {
		 printf("File cannot be found\n");
	 }
	 else
	 {
		 printf("City \t\t  State\n");
		 for(i=0; i<SIZE; i++)
		 {
			 fscanf(fpb,"%s %s", city[i], state[i]);
			 printf("%-13s %-13s\n", city[i],state[i]);
		 }
		printf("\nEnter the city you wish to travel to: ");
    scanf("%s",destination); 
		printf("\n----------------------------------------------------------------");
		printf("\nFlying to %s costs $500\n",destination);
		return 500;
	 }
	 fclose(fpb);
 }
	else if(input=='A')
 {
	 FILE *fpa;
	 
	 fpa = fopen("AA.txt","r");
	 if(fpa==NULL)
	 {
		 printf("File cannot be found\n");
	 }
	 else
	 {
		 printf("City \t\t  State\n");
		 for(i=0; i<SIZE; i++)
		 {
			 fscanf(fpa,"%s %s", city[i], state[i]);
			 printf("%-13s %-13s\n", city[i],state[i]);
		 }
      printf("\nEnter the city you wish to travel to:  ");
      scanf("%s",destination);
			printf("\n----------------------------------------------------------------");
      printf("\nFlying to %s costs $300\n",destination);	
		  return 300;
   }
	 fclose(fpa);
 }
 return 0; 
}//end of companySelect 

float extraPrice(int cost)
{
	int i;
	char extras[9][30] = {"Bus Pass","Metrorail Pass", "Train Pass", "Taxi Service","Science museum Pass","Observatory","Zoo Entries", "City specific adventure", "Out of city excursions"};          
  float bags;
  float totalExtra=0;
	
	int numBags,freeBags;
	printf("\n----------------------------------------------------------------");
	printf("\nHow many bags will you be taking? ");
	scanf("%d", &numBags);
	if(cost==100)//easyjet
	{	
			freeBags=0;
			bags = numBags*20;
			//if(bags >2)
			//*points+=bags/2;	//it is intended that the whole number be taken and not the extra decimals
	}
	else if(cost == 300)//AA
	{
		freeBags = 1;
		bags = (numBags - freeBags)*20;//it is intended that if flying without bags user gets discount
	}	
	else if(cost == 500)//BA
	{
		freeBags = 2;
		bags = (numBags-freeBags)*20;//it is intended that if flying without bags user gets discount
	}
	
		printf("\n\n----------------------------------------------------------------");
  	printf("\nThese are the possible extras that can be purchased.\n"
         "To select one, enter the number associated with the desired extra (enter 0 to exit loop)\n\n"
              "1. Bus Pass = $10\n" 
							"2. Metrorail Pass = $5\n"
							"3. Train Pass = $20\n"
              "4. Taxi Service = $30\n"
              "5. Science museum Pass = $10\n"
              "6. Observatory = $0\n"
              "7. Zoo Entries = $15\n"
              "8. City specific adventure = $40\n"
              "9. Out of city excursions = $40\n"
  					);

  while(i != 0)
  {
    scanf("%d",&i);
		printf("Enter the number of any additional extra (0 to exit): ");
		switch(i)
		{
			case 1: totalExtra+= 10;	
			break;
			case 2: totalExtra+= 5;
      break;
			case 3: totalExtra+= 20;
      break;
			case 4: totalExtra+= 30;
      break;
      case 5: totalExtra+= 10;
      break;
      case 6: totalExtra+= 0;
      break;
      case 7: totalExtra+= 15;
      break;
      case 8: totalExtra+= 40;
			break;
      case 9: totalExtra+= 40;
			break;
			}//end switch
  	}//end while
	

	printf("\n----------------------------------------------------------------");
	printf("\nWe are now offering hotel rooms as an extra that can be added into your vacation package!");
  printf("\nEnter the number associated with the quality of the room to be included with your Quicket vacation package: (all rooms are individual)\n"
              "1. * Star Stay = $0 \n" 
							"2. ** Star Stay = $50\n"
							"3. *** Star Stay = $100\n"
              "4. **** Star Stay = $150\n"
              "5. ***** Star Stay = $200\n"
  
  );
    scanf("%d",&i);
		switch(i)
		{
			case 1: totalExtra+= 0;
			break;
			case 2: totalExtra+= 50;
      break;
			case 3: totalExtra+= 100;
      break;
			case 4: totalExtra+= 150;
      break;
      case 5: totalExtra+= 200;
      break;

  	} //end switch

totalExtra = bags + totalExtra;
printf("\nThe total cost of bags and extras in your vacation package is $%.2f\n", totalExtra);
return totalExtra;

}//end of extraPrice

float calFinalPrice(int cost, float extras)
{
	float finalPrice, passengerPrice;
	int passengers,points;
	
  finalPrice = ((extras+cost)+(0.07*(extras+cost))+(0.02*(extras+cost)));
	printf("\nBefore the final price is calculated we would like to remind you that the Florida Tax is 7 percent\nand a fee of 2 percent is applied to cover Quicket's electronic booking fees.");
	printf("\n----------------------------------------------------------------");
 	printf("\nThe total cost of your vacation package is $%.2f\n", finalPrice);
	 printf("----------------------------------------------------------------");
 	printf("\n\nEnter the number of people who will be traveling (including yourself): ");
 	scanf("%d",&passengers);
 	passengerPrice = finalPrice*passengers;
	points = 0.09 * passengerPrice;
	printf("\n----------------------------------------------------------------");
	printf("\nThe total cost of %d vacation packages is $%.2f ",passengers,passengerPrice);
	printf("\n----------------------------------------------------------------");
	return points;
}//end of calFinalPrice

void randomTrip(int *points)
{
	int r,lineNum=0, i;
	char line[30], country[20];				
	
	if(*points <50)
	printf("\nUnfortunately you did not earn enough points for a reward this time");
	
	if (*points >= 50 && *points <75)
	{
		srand(time(NULL));
		r=rand()%10;
		printf("\nYou have %d points! You are eligible for a random free extra!", *points);
		printf("\nYour free extra is ");
		switch(r)
		{
			case0: puts("Bus Pass");
			break;
			case 1: puts("Bus Pass");
			break;
			case 2: puts("Metrorail Pass");
			break;
			case 3: puts("Train Pass");
      break;
			case 4: puts("Taxi Service");
      break;
      case 5: puts("Science museum Pass");
      break;
      case 6: puts("Observatory");
      break;
      case 7: puts("Zoo Entries");
      break;
      case 8: puts("City specific adventure");
			break;
      case 9: puts("Out of city excursions");
			break;
		}//end switch
		
	}
	else if(*points >= 75 && *points <100)
	{
		srand(time(NULL));
		r=rand()%16;
		printf("\nYou have %d points! You are elibible for a free flight to a random city with our Economy airline, Easyjet! (with a 2 star hotel stay included)", *points);
		FILE *fpe;
		fpe = fopen("Easyjet.txt" ,"r");
		if(fpe == NULL)
		{
			printf("\nFile cannot be found");
		}
		else
		{
			for(i=0; i<SIZE; i++)
			{
				if(i==r)
				{
					fscanf(fpe,"%s %s", line, country);
					printf("\nYour random free city is %s %s", line, country);
				}	
				else
				{
					fscanf(fpe,"%s %s", line, country);
				}
			}//end for
		}//end else
	}//end outer else
	else if(*points >=100 && *points <= 145)
	{
		FILE *fpa;
		fpa = fopen("AA.txt","r");
		srand(time(NULL));
		r=rand()%16;
		printf("\nYou have %d points! You are eligible for a free flight to a random city with our American airline! (with a 2 star hotel stay included)", *points);
		if(fpa == NULL)
		{
			printf("\nFile cannot be found");
		}
		else
		{
			for(i=0; i<SIZE; i++)
			{
				if(i==r)
				{
					fscanf(fpa,"%s %s", line, country);
					printf("\nYour random free city is %s %s", line,country);
				}	
				else 
				{
					fscanf(fpa, "%s %s", line, country);
				}
			}
		}//end while
	}//end outer if-else
	
	else if(*points >145)
	{
		printf("\nYou have %d points! You are eligible for a free flight to a random international city! (with a 5 star hotel stay included",*points);
		FILE *fpb;
		fpb = fopen("BA.txt","r");
		srand(time(NULL));
		r=rand()%16;

		if(fpb == NULL)
		{
			printf("\nFile cannot be found");
		}
		else
		{
				for(i=0; i<SIZE; i++)
			{
				if(i==r)
				{
					fscanf(fpb,"%s %s", line, country);
					printf("\nYour random free city is %s %s", line, country);
				}	
				else 
				{
					fscanf(fpb, "%s %s", line,country);
				}
    }
			}//end while
		}//end outer if-else*/
	}
