# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<ctype.h>
# define MAXBUFFER 30
typedef struct Node_shuju//数据节点
{
	double val;
    //int val;
	struct Node_shuju *pNext;
}NODE,*PNODE;

typedef struct Node_yunsuan//运算符节点
{
	char val;
	struct Node_yunsuan *pNext;
}NODE1,*PNODE1;

typedef struct Stack_yunsuan
{
	PNODE1 ptop;
	PNODE1 pbase;
}STACK1,*PSTACK1;

typedef struct Stack
{
	PNODE ptop;
	PNODE pbase;
}STACK,*PSTACK;
void Init(PSTACK ps);//初始化数据栈
void Init(PSTACK1 ps);//初始化运算符栈
void Push(PSTACK1 ps,char val);
void Push(PSTACK ps,double val);
void traverse(PSTACK ps);//遍历
bool Pop(PSTACK ps,double *pdata);
bool Pop(PSTACK1 ps,char *pdata);
bool empty(PSTACK ps);
bool empty(PSTACK1 ps);
void clear(PSTACK ps);//清空
double Gettop(PSTACK ps);//若栈不空则返回值为栈顶元素
char Gettop(PSTACK1 ps);//若栈不空则返回值为栈顶元素
double Operate(double j,char a,double i);
void print_user(); //计算器欢迎界面
void libolan_calculator();//逆波兰计算器
//数据与运算符之间用空格隔开，以#作为结束标志
double calculator();//计算器，输入以#作为结束标志
char Precede(char stack_top,char ch);//判断优先级函数,返回值为'>','<','='
void main(void)
{
//	STACK S;
	double blend;
    blend =calculator();

	//libolan_calculator();
	//Push(&S,1);
	//Push(&S,2);
//	Push(&S,3);
//traverse(&S);
//clear(&S);
//traverse(&S);

}
void Init(PSTACK ps)//初始化数据栈
{
	ps->ptop=(PNODE)malloc(sizeof(NODE));
	if(NULL==ps->ptop)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		ps->pbase =ps->ptop ;
		ps->pbase ->pNext =NULL;
	}
}
void Init(PSTACK1 ps)//初始化运算符栈
{
	ps->ptop =(PNODE1)malloc(sizeof(NODE1));
	if(NULL==ps->ptop )
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		ps->pbase =ps->ptop ;
		ps->pbase ->pNext =NULL;
	}
}
void Push(PSTACK ps,double val)
{
	PNODE pnew=(PNODE)malloc(sizeof(NODE));
	pnew->val =val;
	pnew->pNext =ps->ptop ;
	ps->ptop =pnew;
}
void Push(PSTACK1 ps,char val)
{
	PNODE1 pnew=(PNODE1)malloc(sizeof(NODE1));
	pnew->val =val;
	pnew->pNext =ps->ptop ;
	ps->ptop =pnew;
}

bool empty(PSTACK ps)
{
	if(ps->ptop ==ps->pbase )
		return true;
	else
		return false;
}

bool empty(PSTACK1 ps)
{
	if(ps->ptop ==ps->pbase )
		return true;
	else
		return false;
}
void traverse(PSTACK ps)//遍历
{
	PNODE p=ps->ptop ;
	while(p!=ps->pbase )
	{
		printf("%d ",p->val );
		p=p->pNext;
	}
	printf("\n");
}
bool Pop(PSTACK ps,double *pdata)
{
	if(!empty(ps))
	{
		PNODE p=ps->ptop ;
		ps->ptop =p->pNext ;
		*pdata=p->val ;
		free(p);
		p=NULL;
		return true;
	}
	else
	return false;
}
bool Pop(PSTACK1 ps,char *pdata)
{
	if(!empty(ps))
	{
		PNODE1 p=ps->ptop ;
		ps->ptop =p->pNext ;
		*pdata=p->val ;
		free(p);
		p=NULL;
		return true;
	}
	else
		return false;
}
double Gettop(PSTACK ps)//若栈不空则返回值为栈顶元素
{
	if(ps->ptop==ps->pbase )
	{
		printf("栈空，无栈顶元素");
		exit(-1);
	}
	else
		return(ps->ptop ->val );
}
char Gettop(PSTACK1 ps)//若栈不空则返回值为栈顶元素
{
	if(ps->ptop==ps->pbase )
	{
		printf("栈空，无栈顶元素");
		exit(-1);
	}
	else
		return(ps->ptop ->val );
}

void clear(PSTACK ps)
{
	PNODE r=ps->ptop;
	if(ps->ptop ==ps->pbase )
		return;
	else
	{
		while(ps->ptop !=ps->pbase )
		{
			ps->ptop =ps->ptop ->pNext ;
			free(r);
			r=ps->ptop ;
		}
	}

}
char Precede(char stack_top,char ch)//判断优先级函数,返回值为'>','<','='
{
	char tab[7][7]={{'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},{'>','>','>','>','<','>','>'},{'<','<','<','<','<','=',' '},{'<','<','<','<',' ','>','>'},{'<','<','<','<','<',' ','='}};;

	switch(stack_top)
	{
	case'+':stack_top=0;break;
	case'-':stack_top=1;break;
	case'*':stack_top=2;break;
	case'/':stack_top=3;break;
	case'(':stack_top=4;break;
	case')':stack_top=5;break;
	case'#':stack_top=6;break;
	}
	switch(ch)
	{
	case'+':ch=0;break;
	case'-':ch=1;break;
	case'*':ch=2;break;
	case'/':ch=3;break;
	case'(':ch=4;break;
	case')':ch=5;break;
	case'#':ch=6;break;
	}
	
	return tab[stack_top][ch];
}
double Operate(double j,char a,double i)
{
	double val;
	switch(a)
	{
	case'+':val=i+j;break;
	case'-':val=j-i;break;
	case'/':val=j/i;break;
	case'*':val=i*j;break;
	}
		return val;
}
void libolan_calculator()//逆波兰计算器
{
	char ch;
	double i,j;
		STACK S1;
		char str[MAXBUFFER];
		int k=0;
	Init(&S1);
	//Init(&S2);
	printf("请按逆波兰表达式输入带计算数据，数据与运算符之间用空格隔开以#好作为结束标志:\n");
	scanf("%c",&ch);

	while(ch!='#')
	{
		while(isdigit(ch)||ch=='.')//过滤数字,函数isdigit()判断参数ch是否为阿拉伯数字0到9。若参数c为阿拉伯数字，则返回TRUE，否则返回NULL(0)。
		{
			str[k++]=ch;
			str[k]='\0';
			if(k>=MAXBUFFER)
			{
				printf("输入的单个数据过大\n");
				exit(-1);
			}
				scanf("%c",&ch);
				if(ch==' ')
				{
					i=atof(str);   //函数atof()功能：函数说明 atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分，如123.456或123e-2。
					Push(&S1,i);   //简单点说就是将数字字符串转换为double型数据
					k=0;
					break;//跳出这个循环
				}
		}
		switch(ch)
		{
		case'+':Pop(&S1,&i);Pop(&S1,&j);Push(&S1,i+j);break;
		case'-':Pop(&S1,&i);Pop(&S1,&j);Push(&S1,j-i);break;
		case'*':Pop(&S1,&i);Pop(&S1,&j);Push(&S1,j*i);break;
		case'/':Pop(&S1,&i);Pop(&S1,&j);
			if(i!=0)Push(&S1,j/i);
			else
			{printf("\n出错：除数为零！\n");exit(-1);}break;
		}
			
		scanf("%c",&ch);
	}
	Pop(&S1,&i);
	printf("最后的结果：%f\n",i);
   
}
void print_user()  //计算器欢迎界面
{
 printf("\n   欢迎使用C语言版模拟计算器  \n\n");
 printf("************************************************************************\n");
 printf(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
 printf(" |  模拟计算器使用说明   |\n\n");
 printf(" |       作者：李奥  |\n\n");
 printf(" | 本程序包括对'+'、'-'、'*'、'/'、'()'的运算 |\n");
 printf("  正确的表达式如：1+A(7-8)+S(9*8)#  \n");
 printf(" | 输入'#'表示表达式输入结束!!   |\n\n");
 printf(" |     欢迎使用!!!-->-->      |\n");
 printf(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
 printf("************************************************************************\n\n");
}
double calculator()        //计算器，输入以#作为结束标志
{
	print_user();
	printf("输入表达式(注意要在英文输入法下输入括号)  例如4+2*3-2*(10-3)#  下面请输入表达式：\n");
	char ch,a;
	long int k=0;double i,j;
	char str[MAXBUFFER];
	STACK S1;STACK1 S2;//S1为数据栈，S2为运算符栈
	Init(&S1);
	Init(&S2);
	Push(&S2,'#');
	scanf("%c",&ch);
	while(ch!='#'||Gettop(&S2)!='#')
	{
		while(isdigit(ch)||ch=='.')//过滤数字,函数isdigit()判断参数ch是否为阿拉伯数字0到9。若参数ch为阿拉伯数字，则返回TRUE，否则返回NULL(0)。
		{
			str[k]=ch;
			++k;
			str[k]='\0';
			if(k>=MAXBUFFER)
			{
				printf("输入的单个数据过大\n");
				exit(-1);
			}
				scanf("%c",&ch);
				if(isdigit(ch)==NULL)
				{
					i=atof(str);   //函数atof()功能：函数说明 atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分，如123.456或123e-2。
					Push(&S1,i);   //简单点说就是将数字字符串转换为double型数据
					k=0;
					break;//跳出这个循环
				}
		}
		switch(Precede(Gettop(&S2),ch))
		{
		case'<':Push(&S2,ch);scanf("%c",&ch);break;
		case'=':Pop(&S2,&ch); scanf("%c",&ch);break;
		case'>':Pop(&S1,&i);Pop(&S1,&j);Pop(&S2,&a);i=Operate(j,a,i);Push(&S1,i);break;	 
		}

	  // scanf("%c",&ch);
	}
		Pop(&S1,&i);
	printf("最后的结果：%f\n",i);
	free(S1.pbase );
	free(S2.pbase );
	return i;
}
