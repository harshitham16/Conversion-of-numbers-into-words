#include<stdio.h>
#include<conio.h>

#define SIZE 9

int top = -1;
int stack[SIZE];
int nested_flag = 1;

void push(int item)
{
	if(top==SIZE-1)
	{
		printf("Number too big.Stack overflow.");
		printf("Press any key to exit......");
		getch();
		exit(0);

	}
	else
		stack[++top] = item;
}

void print(int num)
{
	switch(num)
	{
	
		case 1:
			printf("One ");
			break;

		case 2:
			printf("Two ");
			break;

		case 3:
			printf("Three ");
			break;

		case 4:
			printf("Four ");
			break;

		case 5:
			printf("Five ");
			break;

		case 6:
			printf("Six ");
			break;

		case 7:
			printf("Seven ");
			break;

		case 8:
			printf("Eight ");
			break;

		case 9: printf("Nine ");
			break;
	}
}

void print_pair(int num)
{
	switch(num)
	{

		case 1:
			switch(stack[top])
			{

				case 1:
					printf("Eleven ");
					break;

				case 2:
					printf("Twelve ");
					break;

				case 3:
					printf("Thirteen ");
					break;

				case 4:
					printf("Fourteen ");
					break;

				case 5:
					printf("Fifteen ");
					break;

				case 6:
					printf("Sixteen ");
					break;

				case 7:
					printf("Seventeen ");
					break;

				case 8:
					printf("Eighteen ");
					break;

				case 9: printf("Nineteen ");
					break;

				case 0:
					printf("Ten ");
					nested_flag = 0;
			}
			break;

		case 2:
			printf("Twenty ");
			break;

		case 3:
			printf("Thirty ");
			break;

		case 4:
			printf("Forty ");
			break;

		case 5:
			printf("Fifty ");
			break;

		case 6:
			printf("Sixty ");
			break;

		case 7:
			printf("Seventy ");
			break;

		case 8:
			printf("Eighty ");
			break;

		case 9: printf("Ninety ");
			break;
	}
}

void translate(int length)
{
	if(length==9)
	{
		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
			print(stack[top--]);
		else
			top--;

		printf("Crores ");

	}

	if(length>=7)
	{
		if(length==8)
		{
			print(stack[top--]);
			printf("Crores ");
		}

		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
			print(stack[top--]);

		else
			top--;

		if(stack[6]!=0||stack[5]!=0)
			printf("Lakhs ");

		if(nested_flag==0)
		      nested_flag = 1;

	}

	if(length>=5)
	{
		if(length==6)
		{
			print(stack[top--]);
			printf("Lakhs ");
		}

		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
			print(stack[top--]);
		else
			top--;

		if(stack[4]!=0||stack[3]!=0)
			printf("Thousand ");

		if(nested_flag==0)
			nested_flag = 1;

	}

	if(length>=3)
	{
		if(length==4)
		{
			print(stack[top--]);
			printf("Thousand ");
		}

		print(stack[top--]);

		if(stack[2]!=0)
			printf("Hundered ");

		if(stack[1]==0&&stack[0]!=0)
		{
			printf("AND ");
			print(stack[0]);
		}

		else if(stack[1]!=0)
		{
			printf("AND ");
			print_pair(stack[top--]);

			if(stack[top+1]!=1 && nested_flag)
				print(stack[top--]);
		}
	}

	if(length==2)
	{
		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
			print(stack[top--]);

		if(nested_flag==0)
			nested_flag = 1;
	}

	if(length==1)
		print(stack[top--]);
}

void main()
{
	long number;
	clrscr();

	printf("Enter the number to be translated: ");
	scanf("%ld",&number);

	while(number>0)
	{
		push(number%10);
		number = number/10;
	}
	translate(top+1);
	getch();
}
