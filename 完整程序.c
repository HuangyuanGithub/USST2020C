//开发者：黄逸辰 1935021312 电子信息类
//开发者：孔祥瑞 1935030316 电子信息类
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct goods    //商品
{
	int num;//商品编号
	char name[20];//商品名称
	char type[20];//商品型号
	float price;//商品价格
	char place[20];//商品产地
	int have;//商品库存
	int buy;//商品销量
};

struct user   //当前使用的顾客
{
	char name[20] ;//顾客名字
	long long num;//顾客手机号
	char city[20];//顾客所在城市
	char adress[80];//顾客地址
	float yue;//顾客余额
};

struct all_user     //所有注册用户
{
	char name[20];//所有用户名字
	long long num;//所有用户手机号
	char city[20];//所有用户的所在城市
	char adress[80];//所有用户的地址
	float yue;//所有用户的余额
};

struct buyer      //购买订单
{
    int num;//购买商品编号
	char name[20];//购买商品名字
	char type[20];//购买商品型号
	char place[20];//购买商品产地
    int x;//购买数量
    int shu;//购买种数
};

int zhuye() //主界面
{
    int a;
    Sleep(1000) ;
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t----------------- 欢迎进入商品管理系统 -----------------\n");
	Sleep(100);
	printf("\t\t\t\t\t\t************************\n");
	printf("\n");
	Sleep(1000);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 您是？               *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.顾客               *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.管理者             *\n");
	printf("\t\t\t\t\t\t************************\n");
	Sleep(1000);
	printf("\n\t\t\t\t\t\t请输入您的选择（1或2）：");
	scanf("%d",&a);
	while (a!=1 && a!=2)
    {
        printf("您的的输入有误，请再次输入：");
        scanf("%d",&a);
    }
	return a;
}

int scan(struct goods g[]) //读取商品信息
{
	printf("正在读取商品信息...\n") ;
    FILE *fp;
    int n=0;
    fp=fopen("goods.txt","r");
    if (fp==NULL)
    {
        printf("无法打开goods文件\n");
        exit(0);
    }
    while (!feof(fp))
    {
    fscanf (fp,"%d%s%s%f%s%d%d",&g[n].num,g[n].name,g[n].type,&g[n].price,g[n].place,&g[n].have,&g[n].buy); //读取goods.txt中的商品信息
    n++;
    }
    fclose(fp);
    Sleep(2000);
    n=n-1;
    printf("共有%d件商品",n);
    Sleep(1000);
    printf("\n读取完成\n");
    system("pause");
    system("cls");
    return n;
}

void scan_location(char location[][10])//读取文件中的省级行政区信息
{
	int i;
	FILE *fp;
	fp=fopen("location.txt","r");
	 if (fp==NULL)
    {
        printf("无法打开location文件\n");
        exit(0);
    }
    for(i=0;i<34;i++)
    {
    	fscanf(fp,"%s",location[i]);
	}
	fclose(fp);
 }

int readuser(struct all_user u[]) //读取目前已存的全部用户信息
{
    FILE *fp;
    int n=0;
    fp=fopen("user.txt","r");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
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

int yanzheng(struct user *p,struct all_user u[],int n,char location[][10]) //验证顾客手机号		//运用查找算法
{
    int a=0,i=0,k=0;
    printf("请输入您的手机号：");
    scanf("%lld",&p->num);
     while (p->num<=10000000000||p->num>=19999999999)
    {
        printf("手机号错误要求重新输入");
        scanf("%lld",&p->num);
    }
    for (i=0;i<n;i++)
    {
        if (p->num==u[i].num)
        {
            printf("欢迎您！ %s\n",u[i].name);		//查找输入的手机号是否与文件中已存手机号相符
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
            printf("您还不是我们的顾客请注册\n");
            n=zhuce(p,u,n,location);
            a++;
        }
    system("pause");
    system("cls");
    return n;
}

int zhuce(struct user *p,struct all_user u[],int n,char location[][10]) //新用户注册  //运用查找算法
{	int i;
	system("pause");
    system("cls");
	printf("现在开始注册：\n");
	Sleep(1000);
    printf("请输入您的姓名：\n");
    scanf("%s",u[n].name);
    strcpy(p->name,u[n].name);
    printf("请输入您的手机号：\n");
    scanf("%lld",&u[n].num);
    while (u[n].num<=10000000000||u[n].num>=19999999999)
    {
        printf("手机号错误要求重新输入");
        scanf("%lld",&u[n].num);
    }
    p->num = u[n].num;
    printf("请输入您所居住的行政区：\n");
    scanf("%s",&u[n].city);

		for(i=0;i<34;i++)
	    {
	    	if(strcmp(u[n].city,location[i]) == 0)
	    	{
	    		strcpy(p->city,u[n].city);
	    		printf("录入行政区成功！");			//查找输入的行政区是否与文件中的行政区匹配
	    		break;
			}
			if(i == 33 )
			{
				printf("您输入的省级行政区不在配送范围内，请重新输入。\n");
				scanf("%s",&u[n].city);
				i = 0;
			}
		}
    printf("请输入您的地址：\n");
    scanf("%s",u[n].adress);
    strcpy(p-> adress , u[n].adress);
	printf("请输入您想要存入的金额：\n");
    scanf("%f",&u[n].yue);
    while (u[n].yue<0)
          {
              printf("存款不能小于0，请重新输入\n");
                scanf("%f",&u[n].yue);
          }
    p->yue = u[n].yue;
    FILE *fp;
    fp=fopen("user.txt","a");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    fprintf(fp,"%s %lld %s %s %.2f\n",u[n].name,u[n].num,u[n].city,u[n].adress,u[n].yue); //向文件中打印注册信息
    fclose(fp);
    printf("恭喜你完成注册");
    n=n+1;
    return n;
}

void menu1() //主菜单1
{
	Sleep(1000) ;
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t----------------- 欢迎进入商品订购系统 -----------------\n");
	Sleep(100);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\n");
}
void menu3() //主菜单2
{
 	Sleep(1000);
	printf("\t\t\t\t\t\t************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 本系统支持以下功能:  *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.商品信息查询       *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.商品订购           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 3.存款服务           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 4.刷新界面           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 5.退出本系统         *\n");
	printf("\t\t\t\t\t\t************************\n");
	Sleep(1000);
}


void print(struct goods g[],int n) //输出商品信息
{
    int i;
    printf("______________________________________________________________________________________________________________________\n");
    printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
    for (i=0;i<n;i++)
    {
    	Sleep(100);
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",g[i].num,g[i].name,g[i].type,g[i].price,g[i].place,g[i].have,g[i].buy);
	}

    printf("______________________________________________________________________________________________________________________\n");
}

void rank(struct goods a[],int n)	//运用排序算法
{
	int choice2;
	char choice1,choice3;
	int i,j;
	int s_num,s_have,s_buy;
	char s_name[20],s_type[20],s_place[20];
	float s_price;
	fflush(stdin);
	Sleep(1000);
	printf("默认排列顺序为：按商品编号排序。请输入y或n确认，是否需要将商品进行个性化排序？\n");
	scanf("%c",&choice1);
	while(choice1!='n'&&choice1!='y')
	{
		printf("输入有误请重新输入： ");
		while(choice1!='\n') choice1 = getchar();
		scanf("%c",&choice1);
	}
	while(1)
	{

		if(choice1 == 'n')
		{
			break;
		}
		printf("1.按价格由高至低排序， 2.按销量由高至低销量\n");
		scanf("%d",&choice2);
		while(choice2 != 1 && choice2 !=2)
		{
			printf("请输入正确的数字！\n");
			fflush(stdin);
			scanf("%d",&choice2);
		}
		if(choice2 == 1)
		{
			printf("______________________________________________________________________________________________________________________\n");
	    	printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-i;j++)
				{
					if(a[j].price < a[j+1].price)			//将商品信息按价格由高至低冒泡排序
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
	    	printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
			for(i=0;i<n-1;i++)			                     ////将商品按销量由高至低选择排序
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
		for(i=0;i<n-1;i++)			//运用冒泡排序，返回默认商品编号由小至大排序
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
		printf("是否继续排序？请输入y或n确认\n");
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("输入有误请重新输入： ");
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

float purchase1(struct goods a[],int n,char items[][30],struct buyer d[]) //顾客挑选商品流程   //运用查找算法
{
	int i,choice,x; //x是购买数量
	float sum = 0;
	char choice2,choice3;
	int j=0;
	printf("----------------------------------------------------------------\n");
	Sleep(1000);
	printf("欢迎订购!\n");
	Sleep(1000);
	printf("以下为商品信息及价格\n");
	printf("----------------------------------------------------------------\n");
	Sleep(1000);
	printf("商品编号    名称                    价格    库存数量\n");
	for(i = 0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%-10.2f%-8d\n",a[i].num,a[i].name,a[i].price,a[i].have);
	}
	Sleep(1000);
	printf("----------------------------------------------------------------\n");
	Sleep(3000);
	printf("---------------已为您接入智能客服---------------\n");
	Sleep(1000);
	printf("您好!\n");
	Sleep(1000);
	do
	{
		printf("请输入您想购买的商品编号：");
		scanf("%d",&choice);
		for(i=0;i<n;i++)  //运用查找，验证输入商品编号与已有商品编号相符，并统计
		{
				if(a[i].num == choice)
				{
					printf("\n");
					printf("您选择的是: %s ,您需要购买几件？",a[i].name);
					strcpy(items[j],a[i].name);
					printf("\n请输入购买数量：");
					scanf("%d",&x);
					while (x<0)
					{
					    printf("输入错误，请重新输入:");
					    scanf("%d",&x);
					}
					while(x>a[i].have)
					{
						fflush(stdin) ;
						printf("库存不足，请重新输入:");
						scanf("%d",&x);
					}
					printf("\n");
					printf("您已选择了%d件 %s .\n",x,items[j]);
					printf("请输入y或n确认已选择的商品信息\n");
					fflush(stdin);
					scanf("%c",&choice2);
					while(choice2!='n'&&choice2!='y')
					{
						printf("输入有误请重新输入:");
						while(choice2!='\n') choice2 = getchar();
						scanf("%c",&choice2);
					}
					if(choice2=='n')
					{
						printf("您已将 %s 移除\n",items[j]);
						break;
					}
					printf("----------------------------------------------------------------\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN); //调字体颜色至黄色
					printf("好的！您已将%d件 %s 加入购物车.\n",x,items[j]);
					d[j].num=a[i].num;
					strcpy(d[j].name,a[i].name);
					strcpy(d[j].type,a[i].type);
					strcpy(d[j].place,a[i].place);
					d[j].x=x;
					sum = sum + x * a[i].price;
					Sleep(100);
					printf("目前购物车中商品总价为%.1f元\n",sum);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //调字体颜色至白色
					j++;
					break;

				}

			if(i==n-1  &&	a[i].num != choice )	//判断输入商品编号是否正确
			{
				printf("您输入的商品编号有误！\n");
			}

		}
		while(choice!='\n') choice = getchar();
		Sleep(2000);
		printf("----------------------------------------------------------------\n");
		printf("请问是否要继续购买？请输入y或n\n");
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("输入有误请重新输入！\n");
			while(choice3!='\n') choice3 = getchar();
			scanf("%c",&choice3);
		}
		if(choice3=='n')
		{
			break;
		}
		printf("----------------------------------------------------------------\n");
	}while(1); //计算用户购买的总金额
	printf("----------------------------------------------------------------\n");
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE); //调字体颜色至青色
	printf("---------------请确认您的购买清单---------------\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■\n");
	for(i=0;i<j;i++)
	{
		Sleep(100);
		printf("■%d.",i+1);
		puts(items[i]);
	}
	printf("■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	d[0].shu=j;
	return sum;
}

int purchase2(struct user *p,float sum,char items[][30],char location[][10],int k,int user_num,	struct all_user c[],struct goods a[],struct buyer d[],int n) //余额验证  //运用查找算法
{


	k = 0;
	if(sum == 0)
	{
		return k;
	 }
	int i,j;
	char choice,choice2;
	Sleep(1000);
	purchase3(p,items,location); //接入地址填写函数
	Sleep(2000);
	printf("----------------------------------------------------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	printf("您的账户余额为：%.2f元\n",p->yue);
	Sleep(1000);
	printf("您需要支付：%.2f元\n",sum);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	while(1)
	{
		if(p->yue < sum)
		{	Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("您的余额不足！\n");
			Sleep(1000);
			printf("是否进行充值？\n");
			Sleep(100);
			printf("请输入y或n: ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
			while(choice!='n'&&choice!='y')
			{
				printf("输入有误请重新输入！\n");
				scanf("%c",&choice);
			}
			if(choice=='n')
			{
				printf("订单已取消，感谢使用。\n");
				return k;
			}
			Sleep(1000);
			printf("好的，已启动存款服务\n");
			Sleep(2000);
			printf("----------------------------------------------------------------\n");
			save(p,c,user_num); //接入存款函数
		}
		if(p->yue >= sum)
		{
			printf("----------------------------------------------------------------\n");
			Sleep(1000);
			printf("确认购买？金额将从余额中扣除。请输入y或n确认。\n");
			while(choice2!='\n') choice2 = getchar();
			scanf("%c",&choice2);
			while(choice2!='n'&&choice2!='y')
			{
				printf("输入有误请重新输入！\n");
				while(choice2!='\n') choice2 = getchar();
				scanf("%c",&choice2);
			}
			if(choice2=='n')
			{
				Sleep(1000);
				printf("订单已取消,感谢使用\n");
				return k;
			}
			p->yue = p->yue - sum;
			Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("购买成功！\n");
			Sleep(1000);
			FILE *fp;
			fp = fopen("user.txt","w") ;
			if (fp == NULL)
			{
				printf("无法打开user.txt");
			}
			for (i=0;i<user_num;i++)
			{
				if(p->num == c[i].num)   //查找所有用户中特定得用户信息，修改其余额数据并存入user.txt
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
			printf("账户当前余额为%.2f元\n",p->yue);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Sleep(1000);
			printf("订单信息已发送给您\n");
			Sleep(1000);
			printf("----------------------------------------------------------------\n");
			printf("交易已完成。\n");
			printf("----------------------------------------------------------------\n");

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(d[i].num==a[j].num)
                    {
                        a[j].have=a[j].have-d[i].x;		//查找并锁定用户所订购商品编号，从而删减对应商品的库存并增加对应商品销量
                        a[j].buy=a[j].buy+d[i].x;
                    }
                }
            }
	        fp=fopen("goods.txt","w");
	        if (fp==NULL)
	        {
	        printf("无法打开goods文件\n");
	        exit(0);
	        }
	        for(i=0;i<n;i++)
	        {

	        	fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);//读取goods.txt中的商品信息
	        }
	       	fclose(fp);
	        k = 1;
			break;

			Sleep(1000);
			printf("您的账户余额为：%.2f元\n",p->yue);
		}
	}
	return k;
}

void purchase3(struct user *p,char items[][30],char location[][10]) //确认收货地址	运用查找算法
{
	printf("----------------------------------------------------------------\n");
	int i=0;
	char choice;
	char loca[20];
	printf("您的默认收货行政区为%s,是否修改?\n",p->city);
	printf("请输入y或n: ") ;
	while(choice!='\n') choice = getchar();
	scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("输入有误请重新输入!\n");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice=='y')
		{
			printf("----------------------------------------------------------------\n");
			printf("请输入您的收货行政区：");
			scanf("%s",loca);
			for(i=0;i<34;i++)
		    {
		    	if(strcmp(loca,location[i]) == 0)
		    	{
		    		strcpy(p->city,loca);
		    		printf("录入收货行政区成功！\n");	//查找并验证输入行政区是否正确
		    		break;
				}
				if(i == 33 )
				{
					printf("您输入的省级行政区不在配送范围内，请重新输入。\n");
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
		printf("您的具体收货地址为 %s %s \n",p->city,p->adress);
		printf("----------------------------------------------------------------\n");
		printf("请输入y或n确认地址： ");
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("输入有误请重新输入： ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice == 'y')
		{
			break;
		}
		if(choice == 'n')
        {
            printf("请输入新的地址");
			scanf("%s",p->adress);
        }

	}while(1);


}

void output(struct user *p,struct buyer d[]) //输出目前已有商品信息
{

    int i;
    char f[20];
    printf("您的订单如下:\n");
   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("商品编号      名称              型号    产地  购买数量    收件地址\n");
    for(i=0;i<d[0].shu;i++)
	{
		Sleep(100) ;
		printf("%-12d%  -20s%-8s%-5s   %-10d %-8s\n",d[i].num,d[i].name,d[i].type,d[i].place,d[i].x,p->adress);

    }
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    FILE *fp;
    strcpy(f,p->name);
    strcat(f, ".txt");
    fp=fopen(f,"w");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    fprintf(fp,"商品编号      名称              型号    产地  购买数量    收件地址\n");
    for(i=0;i<d[0].shu;i++)
	{
		fprintf(fp,"%-8d%  -24s%-8s%-5s   %-10d %-8s\n",d[i].num,d[i].name,d[i].type,d[i].place,d[i].x,p->adress);

    }
    fclose(fp);
}

void save(struct user *p,struct all_user a[],int x)//存款服务    //运用查找算法
{
	char choice;
	float saving;
	int i=0;
	int n;
	char choice2;
	printf("---------------您好，欢迎使用存款服务---------------\n");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	Sleep(1000);
	printf("您目前的账户余额为:%.2f元\n",p->yue);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("----------------------------------------------------------------\n");
	do
	{
		Sleep(1000);
		printf("是否继续存款？请输入y或n: ");
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("输入有误请重新输入:");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice=='n')
		{
			Sleep(1000);
			printf("您已取消存款\n");
			printf("----------------------------------------------------------------\n");
			break;
		}
		Sleep(1000);
		printf("好的，请输入存款金额：");
		scanf("%f",&saving);
		while(1)
		{
			if(saving>0)
			{
				break;
			}
			if(saving<=0)
			{
				printf("存款不应为零或负数！");
				printf("请重新输入：");
				scanf("%f",&saving);
			}
		}
		fflush(stdin);
		printf("\n请确认您是否想要存入%.2f元？请输入y或n确认。\n",saving);
		scanf("%c",&choice2);
		while(choice2!='n'&&choice2!='y')
		{
			printf("输入有误请重新输入:");
			while(choice2!='\n') choice2 = getchar();
			scanf("%c",&choice2);
		}
		printf("----------------------------------------------------------------\n");
		if(choice2 == 'y')
		{

			printf("存款成功！\n");
			p->yue = saving + p->yue;
			Sleep(1000);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			printf("您目前的账户余额为:%.2f元\n",p->yue);
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
				if(p->num == a[i].num)	       //查找对应用户手机号，并修改该用户的余额
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
	printf("感谢您使用存款服务(＾▽＾)\n");
}


void quit() //退出程序
{
	Sleep(2000);
	printf("感谢您使用本系统，再见！(￣▽￣)~*");
	Sleep(1000);
	exit(0);
}

void scan_id(int *q)
{
	int i;
	FILE *fp;
	fp = fopen("管理员.txt","r");
	if(fp == NULL)
	{
		printf("无法打开管理员.txt");
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
	printf("您好请输入您的管理员id：");
	scanf("%d",&id);
		for(i=0;i<2;i++)
		{
			if(id == *(q+i))
			{
				Sleep(1000);
				printf("\n管理员id输入正确，欢迎您！\n") ;
				break;
			}
			if(i==1 && id != *(q+i))
			{
				printf("您输入的管理员密码有误，请重新输入：");
				fflush(stdin);
				scanf("%d",&id);
				i = -1;
			}
	}
	system("pause");
	system("cls");
}

void menu2() //主菜单
{

	Sleep(1000) ;
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 欢迎进入管理员管理系统 *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t**************************\n");
	printf("\n");
	Sleep(1000);
}
void menu4()
{
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 本系统支持以下功能:    *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 1.商品信息检索         *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 2.商品管理             *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 3.刷新界面             *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t* 4.退出本系统           *\n");
	Sleep(100);
	printf("\t\t\t\t\t\t**************************\n");
	Sleep(1000);
}
void manage1()
{
	printf("______________________________________________________________________________________________________________________\n");
	printf("\t\t\t\t-----------------您已进入商品管理菜单-----------------\n");
}
void manage2()
{
	Sleep(1000);
	printf("______________________________________________________________________________________________________________________\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	printf("\t\t\t\t\t\t1.商品添加管理\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t2.商品删除管理\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t3.商品库存管理\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t4.商品价格管理\n");
	Sleep(100) ;
	printf("\t\t\t\t\t\t5.返回主菜单  \n");
	Sleep(100) ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);+
	printf("______________________________________________________________________________________________________________________\n");
}

void m_print(struct goods a[],int n)
{
	int i;
	printf("______________________________________________________________________________________________________________________\n");
	printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
	for (i=0;i<n;i++)
	{
		Sleep(100);
		printf(" %-8d%-24s%-10s%-10.2f%-5s   %-6d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
	}
	printf("______________________________________________________________________________________________________________________\n");
}



int add(struct goods a[],int n)	//运用查找，插入算法
{
    int i;
    printf("现在开始添加商品\n");
    Sleep(1000);
    printf("请输入添加商品的名字\n");
    scanf("%s",a[n].name);
    printf("请输入添加商品的型号\n");
    scanf("%s",a[n].type);
    printf("请输入添加商品的产地\n");
    scanf("%s",a[n].place);
    printf("请输入添加商品的价格\n");
    scanf("%f",&a[n].price);
     while(a[n].price<0)
    {
        printf("输入错误请重新输入");
        scanf("%f",&a[n].price);
    }
    printf("请输入添加商品的库存\n");
    scanf("%d",&a[n].have);
    while(a[n].have<0)
    {
        printf("输入错误请重新输入");
        scanf("%d",&a[n].have);
    }
    a[n].buy=0;		                        //插入新商品至商品末尾
    a[n].num=1001+n;
    printf("商品已添加\n");
    n=n+1;
    Sleep(1000);
    printf("______________________________________________________________________________________________________________________\n");
    printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
    for (i=0;i<n;i++)
    {
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-10d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
    	Sleep(100);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("无法打开goods文件\n");
        exit(0);
        }
      for(i=0;i<n;i++)
      fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
     fclose(fp);
     return n;
     }

int  dele(struct goods a[],int n)	//运用查找，删除算法
{
    int no,i,j;
    char choice;
    printf("商品编号    名称                    价格\n");
	for(i = 0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%.2f\n",a[i].num,a[i].name,a[i].price);
	}
	Sleep(1000);
    printf("输入您所要删除的商品的代号");
    scanf("%d",&no);
    while(no>1000+n||no<1001)
    {
        printf("输入错误请重新输入");
        scanf("%d",&no);
    }
		printf("请确认您要删除%d吗？（y/n）",no);
		while(choice!='\n') choice = getchar();
		scanf("%c",&choice);
		while(choice!='n'&&choice!='y')
		{
			printf("输入有误请重新输入： ");
			while(choice!='\n') choice = getchar();
			scanf("%c",&choice);
		}
		if(choice == 'y')
		{
			for (i=0;i<n;i++)	//删除对应商品信息，用后一位替代前一位
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
    printf("商品编号    名称                  型号     价格      产地  库存数量   销量\n");
    for (i=0;i<n;i++)
    {
    	printf(" %-8d%-24s%-10s%-10.2f%-5s   %-10d    %-8d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
    	Sleep(100);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("无法打开goods文件\n");
        exit(0);
        }
      for(i=0;i<n;i++)
      fprintf (fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
     fclose(fp);
     printf("删除成功\n");
		}
		if(choice == 'n')
        {
            printf("删除已取消\n");
        }

     return n;
}

void repertory(struct goods a[],int n)	//运用查找算法
{
	int k;//判定添加或删除库存的变量
	int i;
	int x1; //商品编号
	int x2; //库存的变化量
	printf("您好！已为您打印出商品清单\n");
    printf("______________________________________________________________________________________________________________________\n");
	printf("商品编号    名称                  库存\n");
	for(i=0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
	}
	printf("您需要添加库存还是减少库存？\n");
	while(1)
	{
		printf("输入1表示增加库存，输入2表示减少库存:\n");
		scanf("%d",&k);
		while(k != 1 && k !=2)
		{
			printf("请输入正确的数字！\n");
			fflush(stdin);
			scanf("%d",&k);
		}
		if(k==1)
		{
			printf("请输入您想添加库存的商品编号：");
			scanf("%d",&x1);
			 while(x1>1000+n||x1<1001)
		    {
		        printf("输入错误请重新输入");
		        fflush(stdin);
		        scanf("%d",&x1);
		    }
			for(i=0;i<n;i++)
			{
				if(x1==a[i].num)
				{
					printf("请输入添加的库存量:");	//查找输入商品编号对应商品，并且添加其库存
					scanf("%d",&x2);
					while(x2<0)
					{

						printf("\n请输入大于零的数:");
						fflush(stdin);
						scanf("%d",&x2);

					}
					if(x2==0)
					{
						printf("库存未发生变化\n");
						Sleep(1000);
						break;
					}
					a[i].have = a[i].have + x2;
					printf("\n添加成功！\n");
					Sleep(1000);
				}
			}
			printf("______________________________________________________________________________________________________________________\n");
			printf("商品编号    名称                  库存\n");
			for(i=0;i<n;i++)
			{
				Sleep(100);
				printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
			}
			FILE *fp;
			fp = fopen("goods.txt","w");
			if(fp == NULL)
			{
				printf("无法打开goods.txt");
			}
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
			}
			fclose(fp);
			printf("已为您更新库存\n");
		}
		if(k==2)
		{
			printf("请输入您想删减库存的商品编号：");
			scanf("%d",&x1);
			 while(x1>1000+n||x1<1001)
    {
        printf("输入错误请重新输入");
        fflush(stdin);
        scanf("%d",&x1);
    }
			for(i=0;i<n;i++)
			{
				if(x1==a[i].num)
				{
					printf("请输入删减的库存量:");
					scanf("%d",&x2);
					while(x2<0)
					{

						printf("\n请输入大于零的数:");
						fflush(stdin);
						scanf("%d",&x2);

					}
					if(x2==0)
					{
						printf("库存未发生变化\n");
						Sleep(1000);
						break;
					}
					while(1)
					{
						if(a[i].have - x2 < 0) //判断库存正负
						{
							printf("库存不能为负！请重新输入：");
							fflush(stdin);
							scanf("%d",&x2);
						}
						if(a[i].have - x2 >= 0)
						{
							break;
						}
					}
					a[i].have = a[i].have - x2;   //查找输入商品编号对应商品，并且删减其库存
					printf("\n删减成功！\n");
				}
			}
			printf("______________________________________________________________________________________________________________________\n");
			printf("商品编号    名称                  库存\n");
			for(i=0;i<n;i++)
			{
				Sleep(100);
				printf("%-8d%-26s%-d\n",a[i].num,a[i].name,a[i].have);
			}
			FILE *fp; //将更改后的库存写入文件
			fp = fopen("goods.txt","w");
			if(fp == NULL)
			{
				printf("无法打开goods.txt");
			}
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%d %s %s %.2f %s %d %d\n",a[i].num,a[i].name,a[i].type,a[i].price,a[i].place,a[i].have,a[i].buy);
			}
			fclose(fp);
			printf("已为您更新库存\n");
		}
		printf("是否要继续更改库存？请输入y或n确认：\n");
		char choice3;
		while(choice3!='\n') choice3 = getchar();
		scanf("%c",&choice3);
		while(choice3!='n'&&choice3!='y')
		{
			printf("输入有误请重新输入:");
			while(choice3!='\n') choice3 = getchar();
			scanf("%c",&choice3);
		}
		if(choice3 == 'n')
		{
			break;
		}
	}
}

void price (struct goods a[],int n)	//运用查找算法
{
    int no,i;
    float m;
    printf("商品编号    名称                    价格\n");
	for(i=0;i<n;i++)
	{
		Sleep(100);
		printf("%-8d%-28s%.2f\n",a[i].num,a[i].name,a[i].price);
	}

    printf("输入您所要修改价格的商品的代号");
    scanf("%d",&no);
     while(no>1000+n||no<1001)
    {
        printf("输入错误请重新输入");
        scanf("%d",&no);
    }
    printf("请输入新的价格");
    scanf("%f",&m);
     while(m<0)
    {
        printf("输入错误请重新输入");
        scanf("%f",&m);
    }
    for (i=0;i<n;i++)
      {
          if (a[i].num==no)	//查找输入商品编号对应商品，并修改其售价
          break ;
      }
    a[i].price=m;
    printf("______________________________________________________________________________________________________________________\n");
	printf("商品编号    名称                    价格\n");
    for (i=0;i<n;i++)
    {
     	Sleep(100);
     	printf(" %-8d%-24s%-10.2f\n",a[i].num,a[i].name,a[i].price);
	}

    FILE *fp;
    fp=fopen("goods.txt","w");
        if (fp==NULL)
        {
        printf("无法打开goods文件\n");
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
	char items[50][30];//顾客购买物品名单
	char location[34][10]; //发货区域
	int choice,n,user_num;
	float sum;
	int k; //判断是否需要打印订单
	int w;//选择菜单
	w = zhuye();
	if(w == 1)
	{
		system("cls");
		n = scan(a);
		scan_location(location);//读取发货地址
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
			printf("\t\t\t\t\t\t请输入1~5选择功能:");
			scanf("%d",&choice);
			switch (choice)
			{
				case 1: print(a,n);rank(a,n);break;
				case 2:
				{
					sum = purchase1(a,n,items,d);	//	读入购买信息
					k = purchase2(p,sum,items,location,k,user_num,c,a,d,n);//支付流程
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
				default:printf("请输入有效命令！\n");
			}
			while(choice!='\n') choice = getchar();
		}
	}
	char id[16];
	int all_id[2],*q;
	q = all_id;
	int choice2,choice3;
	int x = 1; //离开子菜单
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
			printf("\t\t\t\t\t\t请输入1~4选择功能:");
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
						printf("请输入1~5选择功能:");
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
				default:printf("请输入有效命令！\n");
			}
			fflush(stdin);
		}

    }
	return 0;
}












