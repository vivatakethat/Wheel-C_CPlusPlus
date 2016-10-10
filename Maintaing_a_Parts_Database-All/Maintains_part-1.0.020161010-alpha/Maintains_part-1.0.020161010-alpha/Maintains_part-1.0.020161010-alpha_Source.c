#include<stdio.h>
#include <ctype.h>
#define MAX_NUMBER 100
#define LEN 20

int mark = 0;

void insert(void);
void show(void);
void read_part_name(char str[], int n);
int find_part_number(int);
void print(void);
void update(void);


struct part {
	int number;
	char name[LEN + 1];
	int on_hand;
}inventory[MAX_NUMBER];


int main(void)
{
	char choice, take;
	for (;;) {
		printf("Please input button :\n");
		scanf(" %c", &choice);			//空格的scanf(" %c")表示要从输入流缓冲区读两个字符，一个给空格，一个给%c。为什么加空格呢
										//，是因为回车符(\n)也在输入流缓冲区中，所以将\n赋值给空格，以让%c被正确赋值。否则，不加空格，回车符\n会被赋值给%c。
		while ((take = getchar()) != '\n');  //	去掉'\n'???????
		switch (choice)
		{
		case 'i':insert(); break;
		case 's':show(); break;
		case 'p':print(); break;
		case 'u':update(); break;
		case 'q':return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
}


void insert(void)
{
	int part_number, take;

	if (mark == 100)					//检测零件数量是否超100，超100则无法输入
	{
		printf("overtload!!\n");
		return;              //返回什么呢？
	}
	printf("Please input part_number\n");
	scanf("%d", &part_number);

	int temp;
	if (mark > 0)
	{
		if ((temp = find_part_number(part_number)) == -1)
		{
			inventory[mark].number = part_number;
		}
		else
		{
			printf("The part is exist!\n");
			return;
		}
	}
	else
		inventory[mark].number = part_number;

	printf("Please input part's name\n");
	read_part_name(inventory[mark].name, LEN + 1);

	printf("how much on_hand?\n");
	scanf("%d", &inventory[mark].on_hand);
	mark++;
	take = getchar();			//如果没有这个getchar 会产生多一个'\n',这是为什么？？？？？？？？
}


void show()
{
	int part_number, temp2;
	printf("Please input part's number\n");
	scanf(" %d", &part_number);
	if (((temp2 = find_part_number(part_number)) == -1) || mark == 0)
	{
		printf("No that part exist!\n");
		return 0;
	}
	else
	{
		int i = 0;
		i = find_part_number(part_number);
		printf("Number:    name        on hand       \n");
		printf("%4d      %8s %8d\n ", inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}


}


void read_part_name(char str[], int n)
{
	int ch, i = 0;						//为什么是int ?因为getchar()是获取ASCⅡ码
	ch = getchar();
	while (isspace(ch = getchar()));

	while (ch != '\n'&&ch != EOF)
	{
		if (i < n)
		{
			str[i++] = ch;
			ch = getchar();
		}
	}
}



/**********************************Print parts************************************************/
void print()
{
	int temp;
	if (mark == 0)
	{
		printf("NO part is exist!\n");
		getchar();     //如果没有这个getchar 会产生多一个'\n',这是为什么？？？？？？？？          
		return 0;			//返回0????????????????????????????????????????
	}
	else
		for (int i = 0; i < mark; i++)
		{
			printf("Number:    name        on hand       \n");
			printf("%4d      %8s %8d\n ", inventory[i].number, inventory[i].name, inventory[i].on_hand);
		}

}


int find_part_number(int part_number_insert)
{
	for (int i = 0; i <= mark; i++)				//检测是否重复存在零件编号
	{
		if (part_number_insert == inventory[i].number)
		{
			return i;							//如果存在相同的编号就返回i
		}
		else
		{
			return -1;							//如果不存在相同的编号就返回-1
		}
	}
}



/************************************Upadte****************************************************/
void update(void)
{
	int temp3, update_number, part_number;
	printf("Please input part_number for update:\n");
	scanf("%d", &part_number);

	if ((temp3 = find_part_number(part_number)) == -1)
	{
		printf("Error ,no that part_number!\n");
		return;
	}
	else
		printf("Please input numbe of on_hand for upadte:\n");

	scanf("%d", &update_number);
	inventory[temp3].on_hand += update_number;

}
