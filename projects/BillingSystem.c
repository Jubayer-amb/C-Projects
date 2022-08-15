#include<stdio.h>
#include<time.h>

int main()
{
    struct Product
    {
        char name[20];
        int quantity;
        float unitPrice;
        float totalPrice;
    };
    char customerName[20];
    int numOfProd;
    float subTotal = 0.0;
    float taxAmount = 0.0;
    printf("\t \t \t \t \t \t Billing System \n");
    printf("\t \t \t \t \t \t ==============\n");
    printf("Customer Name: ");
    scanf("%s", &customerName);
    printf("\n");
    printf("Number of Product(s): ");
    scanf("%d", &numOfProd);
    printf("\n");
    struct Product products[numOfProd];
    int numbers[numOfProd];

    system("PAUSE");
	system("CLS");

    printf("\t \t \t \t \t Please Enter Product(s) Details. \n");
    printf("\t \t \t \t \t -------------------------------- \n");

    for(int i = 0; i < numOfProd; i++)
    {
        printf("\n %d. Product ", i+1);
        printf("Name: ");
        scanf("%s", &products[i].name);
        printf("\n Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("\n Unit Price: ");
        scanf("%f", &products[i].unitPrice);
        products[i].totalPrice = products[i].unitPrice * products[i].quantity;

    }

    printf("\n Press Any Key To Generate Bill");
	getch();

    printf("\n\n\n\t\t\t\t\tLOADING\t");
   	for( int a=1;a<5;a++)
	{
		Sleep(150);
		printf("..");
	}

	system("CLS");

    time_t t;
    time(&t);

    printf("\n");
    printf("\t\t\t===============================================================\n");
	printf("\t\t\t\t                  Sales Bill\n");
	printf("\t\t\t===============================================================\n\n");

    printf("\t\t\t Customer: %s", customerName);
    printf("\t\t Date: %s\n", ctime(&t));

	printf("\t\t\tQTY \t Name of Product      \t Unit Price$\t Total Price$\n");
	printf("\t\t\t--- \t ---------------      \t ---------- \t -----------\n\n");


    for(int i = 0; i < numOfProd; i++)
    {
        subTotal += products[i].totalPrice;
        printf("\t\t\t%02d \t %-20s \t %.2f \t \t %.2f \n", products[i].quantity, products[i].name, products[i].unitPrice, products[i].totalPrice);
    }
        taxAmount = (subTotal * 2)/100;
    printf("\t\t\t\t                                        -------------\n\n");
	printf("\t\t\t\t                           SUBTOTAL       %10.2f   \n", subTotal);
	printf("\t\t\t\t                           TAX            %10.2f    \n", taxAmount);
	printf("\t\t\t\t                           Total$         %10.2f     \n", subTotal + taxAmount);
	printf("\t\t\t=============================================================\n\n");
	printf("\t\t\t\t\t\tEnd of bill\n\n");

    printf("\n\n\n\t\t\t\t ©Digital Billing System by Jubayer Al Mamun.\n\n");
return 0;
}
