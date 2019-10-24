#include <stdio.h>
#include <malloc.h>
#include<string.h>


struct Node
{
	int coeff;
	int pow;
	struct Node *link;
};
struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
void create(struct Node * node)
{
	char c;
	do
	{
		printf("\n enter coeff:");
		scanf("%d", &node->coeff);
		printf("\n enter power:");
		scanf("%d", &node->pow);
		node->link = (struct Node *)malloc(sizeof(struct Node));
		node = node->link;
		node->link = NULL;
		printf("\n continue(y/n):");
		scanf("%c",&c);
	} while (c == 'y' || c == 'Y');
}
void display(struct Node *node)
{
	while (node->link != NULL)
	{
		printf("%dx^%d", node->coeff, node->pow);
		node = node->link;
		if (node->link != NULL)
			printf("+");
	}
}
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
	while (poly1->link && poly2->link)
	{
		if (poly1->pow > poly2->pow)
		{
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->link;
		}
		else if (poly1->pow < poly2->pow)
		{
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->link;
		}
		else
		{
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->link;
			poly2 = poly2->link;
		}
		poly->link = (struct Node *)malloc(sizeof(struct Node));
		poly = poly->link;
		poly->link = NULL;
	}
	while (poly1->link || poly2->link)
	{
		if (poly1->link)
		{
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->link;
		}
		if (poly2->link)
		{
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->link;
		}
		poly->link = (struct Node *)malloc(sizeof(struct Node));
		poly = poly->link;
		poly->link = NULL;
	}
}
void main()
{
	char ch;
	do
	{
		poly1 = (struct Node *)malloc(sizeof(struct Node));
		poly2 = (struct Node *)malloc(sizeof(struct Node));
		poly = (struct Node *)malloc(sizeof(struct Node));
		printf("\nenter 1st number:");
		create(poly1);
		printf("\nenter 2nd number:");
		create(poly2);
		printf("\n1st Number:");
		display(poly1);
		printf("\n2nd Number:");
		display(poly2);
		polyadd(poly1, poly2, poly);
		printf("\nAdded polynomial:");
		display(poly);
		printf("\n add two more numbers:");
		scanf("%c",&ch);
	} while (ch == 'y' || ch == 'Y');
}