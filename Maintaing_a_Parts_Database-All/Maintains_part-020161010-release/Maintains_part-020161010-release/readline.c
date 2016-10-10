#include<ctype.h>
#include<stdio.h>
#include"readline.h"

int read_line(char str[], int n)					//	n是NAME_LEN的形参,值：25 ; str[]是inventory[num_parts].name的形参
{
	int ch, i = 0;						//		为什么ch是int 类型？			

	while (isspace(ch = getchar()));			/* 该函数作用是消除上1个scanf遗留下的'\n',在它开始往字符串中存储字符前跳过空白符， */
												// getchar()一个一个字符读取,且能读取`\n`		/*	避免存储用户在零件名称的开始处录入空白       /
												/*描述：输入是空格或者回车则进入 死循环 */



	while (ch != '\n'&&ch != EOF) {		/*	输入的不是回车且	没有出错,则  执行循环体	*/
		if (i < n)
			str[i++] = ch;					/*str字符串数组储存输入的字符串*/
		ch = getchar();
	}

	str[i] = '\0';							/*	有没有这条好像都一样？？	str字符串数组最后以个元素为 空字符		*/
	return i;						/*这个有什么作用？	i数值 为输入：字符串数字*/
}
