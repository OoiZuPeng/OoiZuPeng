#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#pragma warning (disable: 4996)
#define COMBOA 10.00
#define COMBOB 15.00
#define COMBOC 18.00
#define COMBOD 24.00
#define SST 0.10

int quantityA = 0, quantityB = 0, quantityC = 0, quantityD = 0, quantity, allquantity, nocustomer = 0, takeaway = 0, eatinside = 0, group, groupm = 0, groupc = 0, groupi = 0, groupo = 0;
char selection, inorout;
double comboprice, allAprice = 0, allBprice = 0, allCprice = 0, allDprice = 0, totaltopay, priceSST = 0, allcomboprice = 0, allprice, finalamount, allsst;
float amounttopay = 0;
char nextcustomer;
void menu();
void foodselection();
void customer();
void checkquantity();
void dailysalesreport();
void billsystem();
void eat();
void race();

void main()
{
	system("color f0");
	do
	{
		++nocustomer;
		menu();
		foodselection();
		customer();
	} while (nextcustomer == 'Y');
	dailysalesreport();
	system("pause");
}

void menu()
{
	printf("_____________________________\n");
	printf(" [OZP FAST FOOD RESTAURANT] \n");
	printf("_____________________________\n");
	printf("//Welcome to my RESTAURANT\\\\\n");
	printf("\\\\Please Select your Combo//\n");
	printf("_____________________________\n\n");
	printf("Combo A:RM10.00\n");
	printf("[1 Burger,1 Soda drink,1 (S)French fries]\n");
	printf("Combo B:RM15.00\n");
	printf("[2 Piece of Chicken,1 Soda drink,1 (S)French fries]\n");
	printf("Combo C:RM18.00\n");
	printf("[1 Burger,2 Piece of Chicken,1 Soda drink,1 (M)French fries]\n");
	printf("Combo D:RM24.00\n");
	printf("[2 Burger,3 Piece of Chicken,2 Soda drink,1 (L)French fries]\n");
}

void checkquantity()
{
	printf("Quantity:");
	do
	{
		while (scanf("%d", &quantity) != 1)
		{
			printf("\nPlease Enter Again\n");
			scanf("%*s");
		}
		while (quantity ==0)
		{
			printf("\nPlease Enter Again\n");
			scanf("%d", &quantity);
		}
	} while (quantity <= 0);

}

void foodselection()
{  
	rewind(stdin);
	allcomboprice = 0;
	priceSST = 0;
	totaltopay = 0;
	printf("\nCustomer No:%d\n", nocustomer);
	do
	{
		rewind(stdin);
		printf("COMBO A,B,C,D (OTHER = EXIT):");
		scanf("%c", &selection);
		selection = toupper(selection);
		switch (selection)
		{
		case 'A':
			checkquantity();
			comboprice = COMBOA * quantity;
			printf("\tCombo A: %d @ RM10 = %.2f\n", quantity, comboprice);
			allAprice = comboprice + allAprice;
			allcomboprice = comboprice + allcomboprice;
			quantityA = quantityA + quantity;
			break;
		case'B':
			checkquantity();
			comboprice = COMBOB * quantity;
			printf("\tCombo B: %d @ RM15 = %.2f\n", quantity, comboprice);
			allBprice = comboprice + allBprice;
			allcomboprice = comboprice + allcomboprice;
			quantityB = quantityB + quantity;
		    break;
		case'C':
			checkquantity();
			comboprice = COMBOC * quantity;
			printf("\tCombo C: %d @ RM18 = %.2f\n", quantity, comboprice);
			allCprice = comboprice + allCprice;
			allcomboprice = comboprice + allcomboprice;
			quantityC = quantityC + quantity;
			break;
		case'D':
			checkquantity();
			comboprice = COMBOD * quantity;
			printf("\tCombo D: %d @ RM24 = %.2f\n", quantity, comboprice);
			allDprice = comboprice + allDprice;
			allcomboprice = comboprice + allcomboprice;
			quantityD = quantityD + quantity;
			break;
		default:
			if (allcomboprice == 0)
			{
				printf("Try Again!!!\n");
				foodselection();
			}
			else
			{
				race();
				eat();
				billsystem();
			}
		
		}
	} while (selection == 'A' || selection == 'B' || selection == 'C' || selection == 'D');
}

void customer()
{
	do
	{
		rewind(stdin);
		printf("\nNext Customer Y/N?:");		
		scanf("%c", &nextcustomer);
		nextcustomer = toupper(nextcustomer);
		if (nextcustomer != 'Y' && nextcustomer != 'N')
		    printf("\nPlease Enter Again!");
	} while (nextcustomer != 'Y' && nextcustomer != 'N');
}



void dailysalesreport()
{
	allquantity = quantityA + quantityB + quantityC + quantityD;
	allprice = allAprice + allBprice + allCprice + allDprice;
	allsst = allprice * SST;
	finalamount = allprice + allsst;
	printf("\nDAILY SALES REPORT\n");
	printf("Total Number of Customers: %d\n", nocustomer);
	printf("Combo Sales For Today\n");
	printf("Combo\t\tQuantity Sold\tSales Amount\n");
	printf("A\t\t%d\t\tRM%.2f\n", quantityA, allAprice);
	printf("B\t\t%d\t\tRM%.2f\n", quantityB, allBprice);
	printf("C\t\t%d\t\tRM%.2f\n", quantityC, allCprice);
	printf("D\t\t%d\t\tRM%.2f\n", quantityD, allDprice);
	printf("======\t\t====\t\t=========\n");
	printf("TOTALS\t\t%d\t\tRM%.2f\n", allquantity, allprice);
	printf("======\t\t====\t\t=========\n");
	printf("Total Number Takeaway: %d\n", takeaway);
	printf("Eat Inside: %d\n", eatinside);
	printf("Customer Race\n");
	printf("Malay: %d\n",groupm);
	printf("Cina: %d\n", groupc);
	printf("Indians: %d\n", groupi);
	printf("Other: %d\n", groupo);
	printf("TOTAL SST charges: RM%.2f\n", allsst);
	printf("TOTAL RM collected: RM%.2f\n", finalamount);
}

void billsystem()
{
	double changedue;
	priceSST = allcomboprice * SST;
	totaltopay = allcomboprice + priceSST;
	printf("\t\tCombo Charge\t= RM%.2f\n", allcomboprice);
	printf("\t\tAdd 10%%SST\t= RM%.2f\n", priceSST);
	printf("\t\tTOTAL TO PAY\t= RM%.2f\n", totaltopay);
	printf("\t\tAmount Paid\t= RM");
	scanf("%f", &amounttopay);
	changedue = amounttopay - totaltopay;
	while(changedue<0)
	{
			printf("Please enter again\n");
			printf("\t\tCombo Charge\t= RM%.2f\n", allcomboprice);
			printf("\t\tAdd 10%%SST\t= RM%.2f\n", priceSST);
			printf("\t\tTOTAL TO PAY\t= RM%.2f\n", totaltopay);
			printf("\t\tAmount Paid\t= RM");
			scanf("%f", &amounttopay);
			changedue = amounttopay - totaltopay;		
	} 
	printf("\t\tChangeDue\t= RM%.2f\n", changedue);
	printf("THANK YOU, HAVE A NICE DAY!!\n");
}

void eat()
{
	rewind(stdin);
	printf("Take Away Y/N: ");
	scanf("%c", &inorout);
	inorout = toupper(inorout);
	switch (inorout)
	{
	case 'Y':
	{
		printf("\t\tTake Away\n");
		takeaway++;
		break;
	}
	case 'N':
	{
		eatinside++;
		break;
	}
	default:
	{
		printf("Please Enter Again\n");
		eat();
	}
	}
}

void race()
{
		printf("1.Malay\n");
		printf("2.Chinese\n");
		printf("3.Indians\n");
		printf("4.Others\n");
	printf("Please select Customer race: ");
	scanf("%d", &group);
	switch (group)
	{
	case 1:
	{
		groupm++;
		break;
	}
	case 2:
	{
		groupc++;
		break;
	}
	case 3:
	{
		groupi++;
		break;
	}
	case 4:
	{
		groupo++;
		break;
	}
	default:
	{
		printf("\t\tPlease Enter Again\n");
		race();
	}
	}
}