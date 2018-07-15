# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<ctype.h>
# define MAXBUFFER 30
typedef struct Node_shuju//���ݽڵ�
{
	double val;
    //int val;
	struct Node_shuju *pNext;
}NODE,*PNODE;

typedef struct Node_yunsuan//������ڵ�
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
void Init(PSTACK ps);//��ʼ������ջ
void Init(PSTACK1 ps);//��ʼ�������ջ
void Push(PSTACK1 ps,char val);
void Push(PSTACK ps,double val);
void traverse(PSTACK ps);//����
bool Pop(PSTACK ps,double *pdata);
bool Pop(PSTACK1 ps,char *pdata);
bool empty(PSTACK ps);
bool empty(PSTACK1 ps);
void clear(PSTACK ps);//���
double Gettop(PSTACK ps);//��ջ�����򷵻�ֵΪջ��Ԫ��
char Gettop(PSTACK1 ps);//��ջ�����򷵻�ֵΪջ��Ԫ��
double Operate(double j,char a,double i);
void print_user(); //��������ӭ����
void libolan_calculator();//�沨��������
//�����������֮���ÿո��������#��Ϊ������־
double calculator();//��������������#��Ϊ������־
char Precede(char stack_top,char ch);//�ж����ȼ�����,����ֵΪ'>','<','='
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
void Init(PSTACK ps)//��ʼ������ջ
{
	ps->ptop=(PNODE)malloc(sizeof(NODE));
	if(NULL==ps->ptop)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		ps->pbase =ps->ptop ;
		ps->pbase ->pNext =NULL;
	}
}
void Init(PSTACK1 ps)//��ʼ�������ջ
{
	ps->ptop =(PNODE1)malloc(sizeof(NODE1));
	if(NULL==ps->ptop )
	{
		printf("��̬�ڴ����ʧ��\n");
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
void traverse(PSTACK ps)//����
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
double Gettop(PSTACK ps)//��ջ�����򷵻�ֵΪջ��Ԫ��
{
	if(ps->ptop==ps->pbase )
	{
		printf("ջ�գ���ջ��Ԫ��");
		exit(-1);
	}
	else
		return(ps->ptop ->val );
}
char Gettop(PSTACK1 ps)//��ջ�����򷵻�ֵΪջ��Ԫ��
{
	if(ps->ptop==ps->pbase )
	{
		printf("ջ�գ���ջ��Ԫ��");
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
char Precede(char stack_top,char ch)//�ж����ȼ�����,����ֵΪ'>','<','='
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
void libolan_calculator()//�沨��������
{
	char ch;
	double i,j;
		STACK S1;
		char str[MAXBUFFER];
		int k=0;
	Init(&S1);
	//Init(&S2);
	printf("�밴�沨�����ʽ������������ݣ������������֮���ÿո������#����Ϊ������־:\n");
	scanf("%c",&ch);

	while(ch!='#')
	{
		while(isdigit(ch)||ch=='.')//��������,����isdigit()�жϲ���ch�Ƿ�Ϊ����������0��9��������cΪ���������֣��򷵻�TRUE�����򷵻�NULL(0)��
		{
			str[k++]=ch;
			str[k]='\0';
			if(k>=MAXBUFFER)
			{
				printf("����ĵ������ݹ���\n");
				exit(-1);
			}
				scanf("%c",&ch);
				if(ch==' ')
				{
					i=atof(str);   //����atof()���ܣ�����˵�� atof()��ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�����nptr�ַ����ɰ��������š�С�����E(e)����ʾָ�����֣���123.456��123e-2��
					Push(&S1,i);   //�򵥵�˵���ǽ������ַ���ת��Ϊdouble������
					k=0;
					break;//�������ѭ��
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
			{printf("\n��������Ϊ�㣡\n");exit(-1);}break;
		}
			
		scanf("%c",&ch);
	}
	Pop(&S1,&i);
	printf("���Ľ����%f\n",i);
   
}
void print_user()  //��������ӭ����
{
 printf("\n   ��ӭʹ��C���԰�ģ�������  \n\n");
 printf("************************************************************************\n");
 printf(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
 printf(" |  ģ�������ʹ��˵��   |\n\n");
 printf(" |       ���ߣ����  |\n\n");
 printf(" | �����������'+'��'-'��'*'��'/'��'()'������ |\n");
 printf("  ��ȷ�ı��ʽ�磺1+A(7-8)+S(9*8)#  \n");
 printf(" | ����'#'��ʾ���ʽ�������!!   |\n\n");
 printf(" |     ��ӭʹ��!!!-->-->      |\n");
 printf(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
 printf("************************************************************************\n\n");
}
double calculator()        //��������������#��Ϊ������־
{
	print_user();
	printf("������ʽ(ע��Ҫ��Ӣ�����뷨����������)  ����4+2*3-2*(10-3)#  ������������ʽ��\n");
	char ch,a;
	long int k=0;double i,j;
	char str[MAXBUFFER];
	STACK S1;STACK1 S2;//S1Ϊ����ջ��S2Ϊ�����ջ
	Init(&S1);
	Init(&S2);
	Push(&S2,'#');
	scanf("%c",&ch);
	while(ch!='#'||Gettop(&S2)!='#')
	{
		while(isdigit(ch)||ch=='.')//��������,����isdigit()�жϲ���ch�Ƿ�Ϊ����������0��9��������chΪ���������֣��򷵻�TRUE�����򷵻�NULL(0)��
		{
			str[k]=ch;
			++k;
			str[k]='\0';
			if(k>=MAXBUFFER)
			{
				printf("����ĵ������ݹ���\n");
				exit(-1);
			}
				scanf("%c",&ch);
				if(isdigit(ch)==NULL)
				{
					i=atof(str);   //����atof()���ܣ�����˵�� atof()��ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�����nptr�ַ����ɰ��������š�С�����E(e)����ʾָ�����֣���123.456��123e-2��
					Push(&S1,i);   //�򵥵�˵���ǽ������ַ���ת��Ϊdouble������
					k=0;
					break;//�������ѭ��
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
	printf("���Ľ����%f\n",i);
	free(S1.pbase );
	free(S2.pbase );
	return i;
}
