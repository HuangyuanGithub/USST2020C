//�����ߣ����ݳ� 1935021312 ������Ϣ��
//�����ߣ������� 1935030316 ������Ϣ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct goods    //��Ʒ
{
	int num;//��Ʒ���
	char name[20];//��Ʒ����
	char type[20];//��Ʒ�ͺ�
	float price;//��Ʒ�۸�
	char place[20];//��Ʒ����
	int have;//��Ʒ���
	int buy;//��Ʒ����
};

struct user   //��ǰʹ�õĹ˿�
{
	char name[20] ;//�˿�����
	long long num;//�˿��ֻ���
	char city[20];//�˿����ڳ���
	char adress[80];//�˿͵�ַ
	float yue;//�˿����
};

struct all_user     //����ע���û�
{
	char name[20];//�����û�����
	long long num;//�����û��ֻ���
	char city[20];//�����û������ڳ���
	char adress[80];//�����û��ĵ�ַ
	float yue;//�����û������
};

struct buyer      //���򶩵�
{
    int num;//������Ʒ���
	char name[20];//������Ʒ����
	char type[20];//������Ʒ�ͺ�
	char place[20];//������Ʒ����
    int x;//��������
    int shu;//��������
};

int zhuye() //������
{
    int a;
    Sleep(1000) ;
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t----------------- ��ӭ������Ʒ����ϵͳ -----------------\n");
	Sleep(100);
	printf("\t\t\t\t\t\t************************\n");
	printf("\n");
	Sleep(1000);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* ���ǣ�               *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.�˿�               *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.������             *\n");
	printf("\t\t\t\t\t\t************************\n");
	Sleep(1000);
	printf("\n\t\t\t\t\t\t����������ѡ��1��2����");
	scanf("%d",&a);
	while (a!=1 && a!=2)
    {
        printf("���ĵ������������ٴ����룺");
        scanf("%d",&a);
    }
	return a;
}

int scan(struct goods g[]) //��ȡ��Ʒ��Ϣ
{
	printf("���ڶ�ȡ��Ʒ��Ϣ...\n") ;
    FILE *fp;
    int n=0;
    fp=fopen("goods.txt","r");
    if (fp==NULL)
    {
        printf("�޷���goods�ļ�\n");
        exit(0);
    }
    while (!feof(fp))
    {
    fscanf (fp,"%d%s%s%f%s%d%d",&g[n].num,g[n].name,g[n].type,&g[n].price,g[n].place,&g[n].have,&g[n].buy); //��ȡgoods.txt�е���Ʒ��Ϣ
    n++;
    }
    fclose(fp);
    Sleep(2000);
    n=n-1;
    printf("����%d����Ʒ",n);
    Sleep(1000);
    printf("\n��ȡ���\n");
    system("pause");
    system("cls");
    return n;
}

void scan_location(char location[][10])//��ȡ�ļ��е�ʡ����������Ϣ
{
	int i;
	FILE *fp;
	fp=fopen("location.txt","r");
	 if (fp==NULL)
    {
        printf("�޷���location�ļ�\n");
        exit(0);
    }
    for(i=0;i<34;i++)
    {
    	fscanf(fp,"%s",location[i]);
	}
	fclose(fp);
 }

int readuser(struct all_user u[]) //��ȡĿǰ�Ѵ��ȫ���û���Ϣ
{
    FILE *fp;
    int n=0;
    fp=fopen("user.txt","r");
    if (fp==NULL)
    {
        printf("�޷����ļ�\n");
        exit(0);
    }
    while (!feof(fp))
    {
    fscanf (fp,"%s%lld%s%s%f",u[n].name,&u[n].num,u[n].city,u[n].adress,&u[n].yue);
    n++;
    }
    fclose(fp);
    return n-1;
}

int yanzheng(struct user *p,struct all_user u[],int n,char location[][10]) //��֤�˿��ֻ���		//���ò����㷨
{
    int a=0,i=0,k=0;
    printf("�����������ֻ��ţ�");
    scanf("%lld",&p->num);
     while (p->num<=10000000000||p->num>=19999999999)
    {
        printf("�ֻ��Ŵ���Ҫ����������");
        scanf("%lld",&p->num);
    }
    for (i=0;i<n;i++)
    {
        if (p->num==u[i].num)
        {
            printf("��ӭ���� %s\n",u[i].name);		//����������ֻ����Ƿ����ļ����Ѵ��ֻ������
            strcpy(p->name,u[i].name);
            p->yue = u[i].yue;
            strcpy(p->city,u[i].city);
            strcpy(p->adress,u[i].adress);
            k=1;
            break;
        }
    }
    if(k==0)
        {
            printf("�����������ǵĹ˿���ע��\n");
            n=zhuce(p,u,n,location);
            a++;
        }
    system("pause");
    system("cls");
    return n;
}

int zhuce(struct user *p,struct all_user u[],int n,char location[][10]) //���û�ע��  //���ò����㷨
{	int i;
	system("pause");
    system("cls");
	printf("���ڿ�ʼע�᣺\n");
	Sleep(1000);
    printf("����������������\n");
    scanf("%s",u[n].name);
    strcpy(p->name,u[n].name);
    printf("�����������ֻ��ţ�\n");
    scanf("%lld",&u[n].num);
    while (u[n].num<=10000000000||u[n].num>=19999999999)
    {
        printf("�ֻ��Ŵ���Ҫ����������");
        scanf("%lld",&u[n].num);
    }
    p->num = u[n].num;
    printf("������������ס����������\n");
    scanf("%s",&u[n].city);

		for(i=0;i<34;i++)
	    {
	    	if(strcmp(u[n].city,location[i]) == 0)
	    	{
	    		strcpy(p->city,u[n].city);
	    		printf("¼���������ɹ���");			//����������������Ƿ����ļ��е�������ƥ��
	    		break;
			}
			if(i == 33 )
			{
				printf("�������ʡ���������������ͷ�Χ�ڣ����������롣\n");
				scanf("%s",&u[n].city);
				i = 0;
			}
		}
    printf("���������ĵ�ַ��\n");
    scanf("%s",u[n].adress);
    strcpy(p-> adress , u[n].adress);
	printf("����������Ҫ����Ľ�\n");
    scanf("%f",&u[n].yue);
    while (u[n].yue<0)
          {
              printf("����С��0������������\n");
                scanf("%f",&u[n].yue);
          }
    p->yue = u[n].yue;
    FILE *fp;
    fp=fopen("user.txt","a");
    if (fp==NULL)
    {
        printf("�޷����ļ�\n");
        exit(0);
    }
    fprintf(fp,"%s %lld %s %s %.2f\n",u[n].name,u[n].num,u[n].city,u[n].adress,u[n].yue); //���ļ��д�ӡע����Ϣ
    fclose(fp);
    printf("��ϲ�����ע��");
    n=n+1;
    return n;
}

void menu1() //���˵�1
{
	Sleep(1000) ;
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t----------------- ��ӭ������Ʒ����ϵͳ -----------------\n");
	Sleep(100);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\n");
}
void menu3() //���˵�2
{
 	Sleep(1000);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* ��ϵͳ֧�����¹���:  *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.��Ʒ��Ϣ��ѯ       *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.��Ʒ����           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 3.������           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 4.ˢ�½���           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 5.�˳���ϵͳ         *\n");
	printf("\t\t\t\t\t\t************************\n");
	Sleep(1000);
}


void print(struct goods g[],int n) //�����Ʒ��Ϣ
{
    int i;
    printf("______________________________________________________________________________________________________________________\n");
    printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
    for (i=0;i<n;i++)
    {
    	Sleep(100);
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",g[i].num,g[i].name,g[i].type,g[i].price,g[i].place,g[i].have,g[i].buy);
	}

    printf("______________________________________________________________________________________________________________________\n");
}

void rank(struct goods a[],int n)	//���������㷨
{
	int choice2;
	char choice1,choice3;
	int i,j;
	int s_num,s_have,s_buy;
	char s_name[20],s_type[20],s_place[20];
	float s_price;
	fflush(stdin);
	Sleep(1000);
	printf("Ĭ������˳��Ϊ������Ʒ�������������y��nȷ�ϣ��Ƿ���Ҫ����Ʒ���и��Ի�����\n");
	scanf("%c",&choice1);
	while(choice1!='n'&&choice1!='y')
	{
		printf("�����������������룺 ");
		while(choice1!='\n') choice1 = getchar();
		scanf("%c",&choice1);
	}
	while(1)
	{

		if(choice1 == 'n')
		{
			break;
		}
		printf("1.���۸��ɸ��������� 2.�������ɸ���������\n");
		scanf("%d",&choice2);
		while(choice2 != 1 && choice2 !=2)
		{
			printf("��������ȷ�����֣�\n");
			fflush(stdin);
			scanf("%d",&choice2);
		}
		if(choice2 == 1)
		{
			printf("______________________________________________________________________________________________________________________\n");
	    	printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-i;j++)
				{
					if(a[j].price < a[j+1].price)			//����Ʒ��Ϣ���۸��ɸ�����ð������
					{

						s_num = a[j].num;
						a[j].num = a[j+1].num;
						a[j+1].num = s_num;
						strcpy(s_name,a[j].name);
						strcpy(a[j].name,a[j+1].name);
						strcpy(a[j+1].name,s_name);
						strcpy(s_type,a[j].type);
						strcpy(a[j].type,a[j+1].type);
						strcpy(a[j+1].type,s_type);
						s_price = a[j].price;
						a[j].price = a[j+1].price;
						a[j+1].price = s_price;
						strcpy(s_place,a[j].place);
						strcpy(a[j].place,a[j+1].place);
						strcpy(a[j+1].place,s_place);
						s_have = a[j].have;
						a[j].have = a[j+1].have;
						a[j+1].have = s_have;
						s_buy = a[j].buy;
						a[j].buy = a[j+1].buy;
						a[j+1].buy = s_buy;
					}
				}
			}
			for (i=0;i<n;i++)
			{
				Sleep(100);
				printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
			}

		}
		if(choice2 == 2)
		{
			printf("______________________________________________________________________________________________________________________\n");
	    	printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
			for(i=0;i<n-1;i++)			                     ////����Ʒ�������ɸ�����ѡ������
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i].buy < a[j].buy)
					{
						s_num = a[j].num;
						a[j].num = a[i].num;
						a[i].num = s_num;
						strcpy(s_name,a[j].name);
						strcpy(a[j].name,a[i].name);
						strcpy(a[i].name,s_name);
						strcpy(s_type,a[j].type);
						strcpy(a[j].type,a[i].type);
						strcpy(a[i].type,s_type);
						s_price = a[j].price;
						a[j].price = a[i].price;
						a[i].price = s_price;
						strcpy(s_place,a[j].place);
						strcpy(a[j].place,a[i].place);
						strcpy(a[i].place,s_place);
						s_have = a[j].have;
						a[j].have = a[i].have;
						a[i].have = s_have;
						s_buy = a[j].buy;
						a[j].buy = a[i].buy;
						a[i].buy = s_buy;
					}
				}
			}
			for (i=0;i<n;i++)
			{
				Sleep(100);
	    		printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
	    	}
		}
		for(i=0;i<n-1;i++)			//����ð�����򣬷���Ĭ����Ʒ�����С��������
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i].num > a[j].num)
				{
					s_num = a[j].num;
					a[j].num = a[i].num;
					a[i].num = s_num;
					strcpy(s_name,a[j].name);
					strcpy(a[j].name,a[i].name);
					strcpy(a[i].name,s_name);
					strcpy(s_type,a[j].type);
					strcpy(a[j].type,a[i].type);
					strcpy(a[i].type,s_type);
					s_price = a[j].price;
					a[j].price = a[i].price;
					a[i].price = s_price;
					strcpy(s_place,a[j].place);
					strcpy(a[j].place,a[i].place);
					strcpy(a[i].place,s_place);
					s_have = a[j].have;
					a[j].have = a[i].have;
					a[i].have = s_have;
					s_buy = a[j].buy;
					a[j].buy = a[i].buy;
					a[i].buy = s_buy;
				}
			}
		}
		fflush(stdin);
		printf("�Ƿ��������������y��nȷ��\n");
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("�����������������룺 ");
			while(choice3!='\n') choice3 = getchar();
			scanf("%c",&choice3);
		}
		if(choice3 == 'n')
		{
			break;
		}
		printf("______________________________________________________________________________________________________________________\n");
		fflush(stdin);
	}

}

float purchase1(struct goods a[],int n,char items[][30],struct buyer d[]) //�˿���ѡ��Ʒ����   //���ò����㷨
{
	int i,choice,x; //x�ǹ�������
	float sum = 0;
	char choice2,choice3;
	int j=0;
	printf("----------------------------------------------------------------\n");
	Sleep(1000);
	printf("��ӭ����!\n");
	Sleep(1000);
	printf("����Ϊ��Ʒ��Ϣ���۸�\n");
	printf("----------------------------------------------------------------\n");
	Sleep(1000);
	printf("��Ʒ���    ����                    �۸�    �������\n");
	for(i = 0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%-10.2f%-8d\n",a[i].num,a[i].name,a[i].price,a[i].have);
	}
	Sleep(1000);
	printf("----------------------------------------------------------------\n");
	Sleep(3000);
	printf("---------------��Ϊ���������ܿͷ�---------------\n");
	Sleep(1000);
	printf("����!\n");
	Sleep(1000);
	do
	{
		printf("���������빺�����Ʒ��ţ�");
		scanf("%d",&choice);
		for(i=0;i<n;i++)  //���ò��ң���֤������Ʒ�����������Ʒ����������ͳ��
		{
				if(a[i].num == choice)
				{
					printf("\n");
					printf("��ѡ�����: %s ,����Ҫ���򼸼���",a[i].name);
					strcpy(items[j],a[i].name);
					printf("\n�����빺��������");
					scanf("%d",&x);
					while (x<0)
					{
					    printf("�����������������:");
					    scanf("%d",&x);
					}
					while(x>a[i].have)
					{
						fflush(stdin) ;
						printf("��治�㣬����������:");
						scanf("%d",&x);
					}
					printf("\n");
					printf("����ѡ����%d�� %s .\n",x,items[j]);
					printf("������y��nȷ����ѡ�����Ʒ��Ϣ\n");
					fflush(stdin);
					scanf("%c",&choice2);
					while(choice2!='n'&&choice2!='y')
					{
						printf("������������������:");
						while(choice2!='\n') choice2 = getchar();
						scanf("%c",&choice2);
					}
					if(choice2=='n')
					{
						printf("���ѽ� %s �Ƴ�\n",items[j]);
						break;
					}
					printf("----------------------------------------------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN); //��������ɫ����ɫ
					printf("�õģ����ѽ�%d�� %s ���빺�ﳵ.\n",x,items[j]);
					d[j].num=a[i].num;
					strcpy(d[j].name,a[i].name);
					strcpy(d[j].type,a[i].type);
					strcpy(d[j].place,a[i].place);
					d[j].x=x;
					sum = sum + x * a[i].price;
					Sleep(100);
					printf("Ŀǰ���ﳵ����Ʒ�ܼ�Ϊ%.1fԪ\n",sum);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //��������ɫ����ɫ
					j++;
					break;

				}

			if(i==n-1  &&	a[i].num != choice )	//�ж�������Ʒ����Ƿ���ȷ
			{
				printf("���������Ʒ�������\n");
			}

		}
		while(choice!='\n') choice = getchar();
		Sleep(2000);
		printf("----------------------------------------------------------------\n");
		printf("�����Ƿ�Ҫ��������������y��n\n");
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("�����������������룡\n");
			while(choice3!='\n') choice3 = getchar();
			scanf("%c",&choice3);
		}
		if(choice3=='n')
		{
			break;
		}
		printf("----------------------------------------------------------------\n");
	}while(1); //�����û�������ܽ��
	printf("----------------------------------------------------------------\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE); //��������ɫ����ɫ
	printf("---------------��ȷ�����Ĺ����嵥---------------\n");
	printf("������������������������������������������\n");
	printf("��\n");
	for(i=0;i<j;i++)
	{
		Sleep(100);
		printf("��%d.",i+1);
		puts(items[i]);
	}
	printf("��\n");
	printf("������������������������������������������\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	d[0].shu=j;
	return sum;
}

int purchase2(struct user *p,float sum,char items[][30],char location[][10],int k,int user_num,	struct all_user c[],struct goods a[],struct buyer d[],int n) //�����֤  //���ò����㷨
{


	k = 0;
	if(sum == 0)
	{
		return k;
	 }
	int i,j;
	char choice,choice2;
	Sleep(1000);
	purchase3(p,items,location); //�����ַ��д����
	Sleep(2000);
	printf("----------------------------------------------------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	printf("�����˻����Ϊ��%.2fԪ\n",p->yue);
	Sleep(1000);
	printf("����Ҫ֧����%.2fԪ\n",sum);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	while(1)
	{
		if(p->yue < sum)
		{	Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("�������㣡\n");
			Sleep(1000);
			printf("�Ƿ���г�ֵ��\n");
			Sleep(100);
			printf("������y��n: ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
			while(choice!='n'&&choice!='y')
			{
				printf("�����������������룡\n");
				scanf("%c",&choice);
			}
			if(choice=='n')
			{
				printf("������ȡ������лʹ�á�\n");
				return k;
			}
			Sleep(1000);
			printf("�õģ�������������\n");
			Sleep(2000);
			printf("----------------------------------------------------------------\n");
			save(p,c,user_num); //�������
		}
		if(p->yue >= sum)
		{
			printf("----------------------------------------------------------------\n");
			Sleep(1000);
			printf("ȷ�Ϲ��򣿽�������п۳���������y��nȷ�ϡ�\n");
			while(choice2!='\n') choice2 = getchar();
			scanf("%c",&choice2);
			while(choice2!='n'&&choice2!='y')
			{
				printf("�����������������룡\n");
				while(choice2!='\n') choice2 = getchar();
				scanf("%c",&choice2);
			}
			if(choice2=='n')
			{
				Sleep(1000);
				printf("������ȡ��,��лʹ��\n");
				return k;
			}
			p->yue = p->yue - sum;
			Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("����ɹ���\n");
			Sleep(1000);
			FILE *fp;
			fp = fopen("user.txt","w") ;
			if (fp == NULL)
			{
				printf("�޷���user.txt");
			}
			for (i=0;i<user_num;i++)
			{
				if(p->num == c[i].num)   //���������û����ض����û���Ϣ���޸���������ݲ�����user.txt
				{
					c[i].yue = p->yue;
					break;
				}
			}
			for (i=0;i<user_num;i++)
			{

				fprintf(fp,"%s %lld %s %s %.2f\n",c[i].name,c[i].num,c[i].city,c[i].adress,c[i].yue);
			}
			fclose(fp);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			printf("�˻���ǰ���Ϊ%.2fԪ\n",p->yue);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Sleep(1000);
			printf("������Ϣ�ѷ��͸���\n");
			Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("��������ɡ�\n");
			printf("----------------------------------------------------------------\n");

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(d[i].num==a[j].num)
                    {
                        a[j].have=a[j].have-d[i].x;		//���Ҳ������û���������Ʒ��ţ��Ӷ�ɾ����Ӧ��Ʒ�Ŀ�沢���Ӷ�Ӧ��Ʒ����
                        a[j].buy=a[j].buy+d[i].x;
                    }
                }
            }
	        fp=fopen("goods.txt","w");
	        if (fp==NULL)
	        {
	        printf("�޷���goods�ļ�\n");
	        exit(0);
	        }
	        for(i=0;i<n;i++)
	        {

	        	fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);//��ȡgoods.txt�е���Ʒ��Ϣ
	        }
	       	fclose(fp);
	        k = 1;
			break;

			Sleep(1000);
			printf("�����˻����Ϊ��%.2fԪ\n",p->yue);
		}
	}
	return k;
}

void purchase3(struct user *p,char items[][30],char location[][10]) //ȷ���ջ���ַ	���ò����㷨
{
	printf("----------------------------------------------------------------\n");
	int i=0;
	char choice;
	char loca[20];
	printf("����Ĭ���ջ�������Ϊ%s,�Ƿ��޸�?\n",p->city);
	printf("������y��n: ") ;
	while(choice!='\n') choice = getchar();
	scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("������������������!\n");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice=='y')
		{
			printf("----------------------------------------------------------------\n");
			printf("�����������ջ���������");
			scanf("%s",loca);
			for(i=0;i<34;i++)
		    {
		    	if(strcmp(loca,location[i]) == 0)
		    	{
		    		strcpy(p->city,loca);
		    		printf("¼���ջ��������ɹ���\n");	//���Ҳ���֤�����������Ƿ���ȷ
		    		break;
				}
				if(i == 33 )
				{
					printf("�������ʡ���������������ͷ�Χ�ڣ����������롣\n");
					scanf("%s",&loca);
					i = 0;
				}
			}
			strcpy(p->city,loca);
			Sleep(1000);
		}
	do
	{
		printf("----------------------------------------------------------------\n");
		printf("���ľ����ջ���ַΪ %s %s \n",p->city,p->adress);
		printf("----------------------------------------------------------------\n");
		printf("������y��nȷ�ϵ�ַ�� ");
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("�����������������룺 ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice == 'y')
		{
			break;
		}
		if(choice == 'n')
        {
            printf("�������µĵ�ַ");
			scanf("%s",p->adress);
        }

	}while(1);


}

void output(struct user *p,struct buyer d[]) //���Ŀǰ������Ʒ��Ϣ
{

    int i;
    char f[20];
    printf("���Ķ�������:\n");
   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("������������������������������������������������������������������������������������\n");
    printf("��Ʒ���      ����              �ͺ�    ����  ��������    �ռ���ַ\n");
    for(i=0;i<d[0].shu;i++)
	{
		Sleep(100) ;
		printf("%-12d%  -20s%-8s%-5s   %-10d %-8s\n",d[i].num,d[i].name,d[i].type,d[i].place,d[i].x,p->adress);

    }
    printf("������������������������������������������������������������������������������������\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    FILE *fp;
    strcpy(f,p->name);
    strcat(f, ".txt");
    fp=fopen(f,"w");
    if (fp==NULL)
    {
        printf("�޷����ļ�\n");
        exit(0);
    }
    fprintf(fp,"��Ʒ���      ����              �ͺ�    ����  ��������    �ռ���ַ\n");
    for(i=0;i<d[0].shu;i++)
	{
		fprintf(fp,"%-8d%  -24s%-8s%-5s   %-10d %-8s\n",d[i].num,d[i].name,d[i].type,d[i].place,d[i].x,p->adress);

    }
    fclose(fp);
}

void save(struct user *p,struct all_user a[],int x)//������    //���ò����㷨
{
	char choice;
	float saving;
	int i=0;
	int n;
	char choice2;
	printf("---------------���ã���ӭʹ�ô�����---------------\n");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	Sleep(1000);
	printf("��Ŀǰ���˻����Ϊ:%.2fԪ\n",p->yue);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("----------------------------------------------------------------\n");
	do
	{
		Sleep(1000);
		printf("�Ƿ������������y��n: ");
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("������������������:");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice=='n')
		{
			Sleep(1000);
			printf("����ȡ�����\n");
			printf("----------------------------------------------------------------\n");
			break;
		}
		Sleep(1000);
		printf("�õģ����������");
		scanf("%f",&saving);
		while(1)
		{
			if(saving>0)
			{
				break;
			}
			if(saving<=0)
			{
				printf("��ӦΪ�������");
				printf("���������룺");
				scanf("%f",&saving);
			}
		}
		fflush(stdin);
		printf("\n��ȷ�����Ƿ���Ҫ����%.2fԪ��������y��nȷ�ϡ�\n",saving);
		scanf("%c",&choice2);
		while(choice2!='n'&&choice2!='y')
		{
			printf("������������������:");
			while(choice2!='\n') choice2 = getchar();
			scanf("%c",&choice2);
		}
		printf("----------------------------------------------------------------\n");
		if(choice2 == 'y')
		{

			printf("���ɹ���\n");
			p->yue = saving + p->yue;
			Sleep(1000);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			printf("��Ŀǰ���˻����Ϊ:%.2fԪ\n",p->yue);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);+
			printf("----------------------------------------------------------------\n");
			FILE *fp;
			fp = fopen("user.txt","w") ;
			if (fp == NULL)
			{
				printf("user.txt");
			}
			for (i=0;i<x;i++)
			{
				if(p->num == a[i].num)	       //���Ҷ�Ӧ�û��ֻ��ţ����޸ĸ��û������
				{
					a[i].yue = p->yue;
					break;
				}
			}
			for (i=0;i<x;i++)
			{

				fprintf(fp,"%s %lld %s %s %.2f\n",a[i].name,a[i].num,a[i].city,a[i].adress,a[i].yue);
			}
			fclose(fp);
		}

	} while(1);
	Sleep(1000);
	printf("��л��ʹ�ô�����(�ި���)\n");
}


void quit() //�˳�����
{
	Sleep(2000);
	printf("��л��ʹ�ñ�ϵͳ���ټ���(������)~*");
	Sleep(1000);
	exit(0);
}

void scan_id(int *q)
{
	int i;
	FILE *fp;
	fp = fopen("����Ա.txt","r");
	if(fp == NULL)
	{
		printf("�޷��򿪹���Ա.txt");
		exit(0);
	}
	for (i=0;i<2;i++)
	{
		fscanf(fp,"%d",q+i);
	}
	fclose(fp);
}

void justify(int *q)
{	int i;
	int id;
	printf("�������������Ĺ���Աid��");
	scanf("%d",&id);
		for(i=0;i<2;i++)
		{
			if(id == *(q+i))
			{
				Sleep(1000);
				printf("\n����Աid������ȷ����ӭ����\n") ;
				break;
			}
			if(i==1 && id != *(q+i))
			{
				printf("������Ĺ���Ա�����������������룺");
				fflush(stdin);
				scanf("%d",&id);
				i = -1;
			}
	}
	system("pause");
	system("cls");
}

void menu2() //���˵�
{

	Sleep(1000) ;
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* ��ӭ�������Ա����ϵͳ *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t**************************\n");
	printf("\n");
	Sleep(1000);
}
void menu4()
{
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* ��ϵͳ֧�����¹���:    *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.��Ʒ��Ϣ����         *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.��Ʒ����             *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 3.ˢ�½���             *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 4.�˳���ϵͳ           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(1000);
}
void manage1()
{
	printf("______________________________________________________________________________________________________________________\n");
	printf("\t\t\t\t-----------------���ѽ�����Ʒ����˵�-----------------\n");
}
void manage2()
{
	Sleep(1000);
	printf("______________________________________________________________________________________________________________________\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	printf("\t\t\t\t\t\t1.��Ʒ��ӹ���\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t2.��Ʒɾ������\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t3.��Ʒ������\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t4.��Ʒ�۸����\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t5.�������˵�  \n");
	Sleep(100) ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);+
	printf("______________________________________________________________________________________________________________________\n");
}

void m_print(struct goods a[],int n)
{
	int i;
	printf("______________________________________________________________________________________________________________________\n");
	printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
	for (i=0;i<n;i++)
	{
		Sleep(100);
		printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
	}
	printf("______________________________________________________________________________________________________________________\n");
}



int add(struct goods a[],int n)	//���ò��ң������㷨
{
    int i;
    printf("���ڿ�ʼ�����Ʒ\n");
    Sleep(1000);
    printf("�����������Ʒ������\n");
    scanf("%s",a[n].name);
    printf("�����������Ʒ���ͺ�\n");
    scanf("%s",a[n].type);
    printf("�����������Ʒ�Ĳ���\n");
    scanf("%s",a[n].place);
    printf("�����������Ʒ�ļ۸�\n");
    scanf("%f",&a[n].price);
     while(a[n].price<0)
    {
        printf("�����������������");
        scanf("%f",&a[n].price);
    }
    printf("�����������Ʒ�Ŀ��\n");
    scanf("%d",&a[n].have);
    while(a[n].have<0)
    {
        printf("�����������������");
        scanf("%d",&a[n].have);
    }
    a[n].buy=0;		                        //��������Ʒ����Ʒĩβ
    a[n].num=1001+n;
    printf("��Ʒ�����\n");
    n=n+1;
    Sleep(1000);
    printf("______________________________________________________________________________________________________________________\n");
    printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
    for (i=0;i<n;i++)
    {
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-10d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
    	Sleep(100);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("�޷���goods�ļ�\n");
        exit(0);
        }
      for(i=0;i<n;i++)
      fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
     fclose(fp);
     return n;
     }

int  dele(struct goods a[],int n)	//���ò��ң�ɾ���㷨
{
    int no,i,j;
    char choice;
    printf("��Ʒ���    ����                    �۸�\n");
	for(i = 0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%.2f\n",a[i].num,a[i].name,a[i].price);
	}
	Sleep(1000);
    printf("��������Ҫɾ������Ʒ�Ĵ���");
    scanf("%d",&no);
    while(no>1000+n||no<1001)
    {
        printf("�����������������");
        scanf("%d",&no);
    }
		printf("��ȷ����Ҫɾ��%d�𣿣�y/n��",no);
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("�����������������룺 ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice == 'y')
		{
			for (i=0;i<n;i++)	//ɾ����Ӧ��Ʒ��Ϣ���ú�һλ���ǰһλ
      {
          if (a[i].num==no)
            break;
      }

      for(j=0;j<n-i-1;j++)
      {
          strcpy(a[i+j].name,a[i+j+1].name);
          strcpy(a[i+j].type,a[i+j+1].type);
          strcpy(a[i+j].place,a[i+j+1].place);
          a[i+j].price=a[i+j+1].price;
          a[i+j].have=a[i+j+1].have;
          a[i+j].buy=a[i+j+1].buy;
      }
      n=n-1;
      printf("______________________________________________________________________________________________________________________\n");
    printf("��Ʒ���    ����                  �ͺ�     �۸�      ����  �������   ����\n");
    for (i=0;i<n;i++)
    {
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-10d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
    	Sleep(100);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("�޷���goods�ļ�\n");
        exit(0);
        }
      for(i=0;i<n;i++)
      fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
     fclose(fp);
     printf("ɾ���ɹ�\n");
		}
		if(choice == 'n')
        {
            printf("ɾ����ȡ��\n");
        }

     return n;
}

void repertory(struct goods a[],int n)	//���ò����㷨
{
	int k;//�ж���ӻ�ɾ�����ı���
	int i;
	int x1; //��Ʒ���
	int x2; //���ı仯��
	printf("���ã���Ϊ����ӡ����Ʒ�嵥\n");
    printf("______________________________________________________________________________________________________________________\n");
	printf("��Ʒ���    ����                  ���\n");
	for(i=0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
	}
	printf("����Ҫ��ӿ�滹�Ǽ��ٿ�棿\n");
	while(1)
	{
		printf("����1��ʾ���ӿ�棬����2��ʾ���ٿ��:\n");
		scanf("%d",&k);
		while(k != 1 && k !=2)
		{
			printf("��������ȷ�����֣�\n");
			fflush(stdin);
			scanf("%d",&k);
		}
		if(k==1)
		{
			printf("������������ӿ�����Ʒ��ţ�");
			scanf("%d",&x1);
			 while(x1>1000+n||x1<1001)
		    {
		        printf("�����������������");
		        fflush(stdin);
		        scanf("%d",&x1);
		    }
			for(i=0;i<n;i++)
			{
				if(x1==a[i].num)
				{
					printf("��������ӵĿ����:");	//����������Ʒ��Ŷ�Ӧ��Ʒ�������������
					scanf("%d",&x2);
					while(x2<0)
					{

						printf("\n��������������:");
						fflush(stdin);
						scanf("%d",&x2);

					}
					if(x2==0)
					{
						printf("���δ�����仯\n");
						Sleep(1000);
						break;
					}
					a[i].have = a[i].have + x2;
					printf("\n��ӳɹ���\n");
					Sleep(1000);
				}
			}
			printf("______________________________________________________________________________________________________________________\n");
			printf("��Ʒ���    ����                  ���\n");
			for(i=0;i<n;i++)
			{
				Sleep(100);
				printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
			}
			FILE *fp;
			fp = fopen("goods.txt","w");
			if(fp == NULL)
			{
				printf("�޷���goods.txt");
			}
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
			}
			fclose(fp);
			printf("��Ϊ�����¿��\n");
		}
		if(k==2)
		{
			printf("����������ɾ��������Ʒ��ţ�");
			scanf("%d",&x1);
			 while(x1>1000+n||x1<1001)
    {
        printf("�����������������");
        fflush(stdin);
        scanf("%d",&x1);
    }
			for(i=0;i<n;i++)
			{
				if(x1==a[i].num)
				{
					printf("������ɾ���Ŀ����:");
					scanf("%d",&x2);
					while(x2<0)
					{

						printf("\n��������������:");
						fflush(stdin);
						scanf("%d",&x2);

					}
					if(x2==0)
					{
						printf("���δ�����仯\n");
						Sleep(1000);
						break;
					}
					while(1)
					{
						if(a[i].have - x2 < 0) //�жϿ������
						{
							printf("��治��Ϊ�������������룺");
							fflush(stdin);
							scanf("%d",&x2);
						}
						if(a[i].have - x2 >= 0)
						{
							break;
						}
					}
					a[i].have = a[i].have - x2;   //����������Ʒ��Ŷ�Ӧ��Ʒ������ɾ������
					printf("\nɾ���ɹ���\n");
				}
			}
			printf("______________________________________________________________________________________________________________________\n");
			printf("��Ʒ���    ����                  ���\n");
			for(i=0;i<n;i++)
			{
				Sleep(100);
				printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
			}
			FILE *fp; //�����ĺ�Ŀ��д���ļ�
			fp = fopen("goods.txt","w");
			if(fp == NULL)
			{
				printf("�޷���goods.txt");
			}
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
			}
			fclose(fp);
			printf("��Ϊ�����¿��\n");
		}
		printf("�Ƿ�Ҫ�������Ŀ�棿������y��nȷ�ϣ�\n");
		char choice3;
		while(choice3!='\n') choice3 = getchar();
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("������������������:");
			while(choice3!='\n') choice3 = getchar();
			scanf("%c",&choice3);
		}
		if(choice3 == 'n')
		{
			break;
		}
	}
}

void price (struct goods a[],int n)	//���ò����㷨
{
    int no,i;
    float m;
    printf("��Ʒ���    ����                    �۸�\n");
	for(i=0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%.2f\n",a[i].num,a[i].name,a[i].price);
	}

    printf("��������Ҫ�޸ļ۸����Ʒ�Ĵ���");
    scanf("%d",&no);
     while(no>1000+n||no<1001)
    {
        printf("�����������������");
        scanf("%d",&no);
    }
    printf("�������µļ۸�");
    scanf("%f",&m);
     while(m<0)
    {
        printf("�����������������");
        scanf("%f",&m);
    }
    for (i=0;i<n;i++)
      {
          if (a[i].num==no)	//����������Ʒ��Ŷ�Ӧ��Ʒ�����޸����ۼ�
          break ;
      }
    a[i].price=m;
    printf("______________________________________________________________________________________________________________________\n");
	printf("��Ʒ���    ����                    �۸�\n");
    for (i=0;i<n;i++)
    {
     	Sleep(100);
     	printf(" %-8d%-24s%-10.2f\n",a[i].num,a[i].name,a[i].price);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("�޷���goods�ļ�\n");
        exit(0);
        }
      for(i=0;i<n;i++)
      fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
     fclose(fp);
}

int main()
{
	struct goods a[20];
	struct user b,*p;
	struct all_user c[200];
	struct buyer d[20];
	p = &b;
	char items[50][30];//�˿͹�����Ʒ����
	char location[34][10]; //��������
	int choice,n,user_num;
	float sum;
	int k; //�ж��Ƿ���Ҫ��ӡ����
	int w;//ѡ��˵�
	w = zhuye();
	if(w == 1)
	{
		system("cls");
		n = scan(a);
		scan_location(location);//��ȡ������ַ
		user_num = readuser(c);
		user_num = yanzheng(p,c,user_num,location);
		menu1();
		while(1)
		{
			Sleep(1000);
			printf("______________________________________________________________________________________________________________________\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			menu3();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("______________________________________________________________________________________________________________________\n");
			printf("\t\t\t\t\t\t������1~5ѡ����:");
			scanf("%d",&choice);
			switch (choice)
			{
				case 1: print(a,n);rank(a,n);break;
				case 2:
				{
					sum = purchase1(a,n,items,d);	//	���빺����Ϣ
					k = purchase2(p,sum,items,location,k,user_num,c,a,d,n);//֧������
					if(k)
					{
						output(p,d);
					}
					break;
				}
				case 3:save(p,c,user_num);break;
				case 4:system("cls");menu1();break;
				case 5:quit();break;
				case '\n':break;
				default:printf("��������Ч���\n");
			}
			while(choice!='\n') choice = getchar();
		}
	}
	char id[16];
	int all_id[2],*q;
	q = all_id;
	int choice2,choice3;
	int x = 1; //�뿪�Ӳ˵�
	if (w==2)
    {
	   	system("cls");
	   	scan_id(q);
	   	int i;
	   	for(i=0;i<2;i++)
	   	{
	   		printf("%d\n",*(q+i));
	   }
		justify(q);
		n = scan(a);
		menu2();
		while(1)
		{
			menu4();
			Sleep(1000);
			printf("______________________________________________________________________________________________________________________\n");
			printf("\t\t\t\t\t\t������1~4ѡ����:");
			scanf("%d",&choice2);
			switch (choice2)
			{
				case 1:m_print(a,n);break;
				case 2:
				{
					manage1();
					while(x)
					{
						manage2();
						printf("������1~5ѡ����:");
						scanf("%d",&choice3);
						switch(choice3)
						{
							case 1: n=add(a,n);break;
							case 2:	n=dele(a,n);break;
							case 3: repertory(a,n); break;
							case 4: price(a,n);break;
							case 5: x=0 ;break;
						}
					}
					x = 1;

					break;
				}
				case 3:system("cls"); break;
				case 4:quit();break;
				case'\n':break;
				default:printf("��������Ч���\n");
			}
			fflush(stdin);
		}

    }
	return 0;
}












