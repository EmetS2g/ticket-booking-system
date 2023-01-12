
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h> 

void mainInterFace();//系统主界面，用于退出登录 
void T_TouristsInterface();//游客登录界面 
void T_person_login();//验证用户名及密码是否正确 
void T_Menu();//游客查询 
void T_person();//个人信息管理
void T_person_check();//个人信息查询 
void T_person_change();//个人信息修改 
void T_person_change_password();//密码修改 
void T_person_change_phone();//电话修改 
void T_person_change_mail(); //邮箱修改 
void T_person_register();//用户注册 
int T_person_register_formatVerify_id(char[]);//检查格式 
int T_person_register_formatVerify_phone(char[]); 
int T_person_register_duplicateCheck(char[]);//用户名查重 

void T_spot_AttractionsInformation();//游客团体登陆后界面 
void T_spot_SettingRecommend();//景点推荐函数 
void T_spot_count_ByNameInquire();//声明通过名称查询的函数
void T_spot_count_Ticket();//声明通过是否有票查询的函数
int T_spot_count_Ticket_datecheek(int);//检验输入日期是否符合规范 
void T_spot_count_ScenicArea();//声明通过区域查询的函数 
void T_spot_count_ScenicArea_check(char[]);
void T_spot_count_Discount();//声明通过折扣信息查询的函数
void T_spot_count_Discount_1();//设有学生票和老人票的景点 
void T_spot_count_PriceOrder_FromLtoH();//两种不同排法 
void T_spot_count_PriceOrder_FromHtoL();
void T_spot_count_PriceOrder();//声明根据价格排序景点 
void T_spot_count_PriceOrder_datechange();//根据淡旺季改变价格以及总票量 
void T_spot_count_SalesOrder_FromLtoH();//两种不同排法 
void T_spot_count_SalesOrder_FromHtoL();
void T_spot_count_SalesOrder();//声明根据预定量排序景点 
void T_spot_other_bookInquire();//询问是否预订 
void T_spot_other_introduction(char []);//景点详情界面

void T_order_Information();//游客团订单总界面 
int T_order_add_Cancelorderdate(int,int,int);//计算文件中的天数
void T_order_add_CancelOrder();//取消订单 
void T_order_check_HistoryOrder();//查看订单 
int T_order_check_HistoryOrder_select(char []);//筛选和用户名对应的订单 
void T_order_add_Cancelordercancel(struct order [], char []);//订单删除子函
void T_order_add_Cancelordercancel_add1(char[],int);//返回售票量 
void T_order_add_Cancelordercancel_add2(char[],int,char[]);//返回余票量 

void T_person_order_fillIn();//游客团订单界面 
void T_person_order_spotsChoose(int, int, int, int, int, int, int, char[]);//景点选择 
void T_person_order_creat(char[], int, int, int, int, int, int, int, char[]);//选择时间生成订单 
float T_person_order_price(int, int, int, char[]);//计算单笔总价
void T_person_order_changeOrder2(char[], int, int);//修改order2内容 
void T_person_order_changespot(char[], int);//修改spot内容 
void T_person_order_inquire(int, int, int, int, int, int, int, char[]);//询问是否继续预订 

void A_Admininterface();// 管理员界面
void A_person();//管理员个人信息 
void A_spot();// 管理员景点信息 
void A_order();//管理员订单信息 
void A_order_check();//进入管理员-历史订单查询界面
void A_order_count();//进入管理员-统计订单界面 
void A_order_count_num();//进入按预定量排序界面
void A_order_count_peopleQuery();//进入访问人数排列界面 
void A_order_count_propit();//进入景点利润排序页面 
void A_order_count_age();//进入管理员—年龄层次统计
void A_order_count_sale();//进入管理员-对不同季度不同景点进行排序
void A_order_count_choose();//提供返回管理员订单统计信息界面
void A_order_count_sale_paixu();//进入管理员—对不同季度销售情况进行排序的子函数
void A_order_count_sale_check();//判断景点文件是否正确打开 
void A_order_count_age_fileCheck();//判断订单文件是否正确打开 
void A_person_change_password();//个人信息修改检测密码 
void A_person_change();//个人信息修改 
void A_person_change_email();//个人信息修改检测邮箱 
void A_spot_check();//景点信息查看 
void A_spot_add();//景点添加 
void A_spot_add_ID();//景点添加-检查ID 
void A_spot_add_name();// 景点添加-检查名称 
void A_spot_add_change();//景点发布前继续修改 
int A_spot_count_spotline();// 计算attractions文件行数 
void A_spot_add_change1();//写入spot文件 
void A_spot_add_change2();//写入spot文件 
void A_spot_add_change3();//添加景点后取消 
int A_order_count_spotline();//计算spot.txt的行数 
int A_order_count_order1line();//计算order1.txt的行数 

char touristname[20],touristpassword[20];//用户名以及密码 
char *settings[21];

struct T_account
{
	char idNum[11];
	char password[20];
	int peopleNum;
	int studentNum, adultNum, oldsNum;//年龄层次 
 	char phoneNum[12], emailNum[81];
};

struct spot//景点变量 
{
	char Scode[7];//景点代码 
    char Sname[81];//景点名称 
	int Ssale;//景点销售量 
	float Sprice;//景区票单价 
	int Sticket;//景点票总量 	
};

struct order//订单变量 
{
	char Oordercode[81];//订单代码 
	char Ospotcode[81];//订单中的景区代码 
	char Odate[81];//预定日期 
	char Ogodate[81];//出行日期 
	int Ochild;//订单中儿童人数 
	int Oadult;//订单中成人人数 
	int Oolds;//订单中的老人人数 
	int Ototal;//订单中的总人数 
	float Oprice;//一份订单中单个景点的价格 
};

struct//景点利润变量 
{
	char Ospotcode[81];//利润中的景点名字 
    float Oprofit;//一个景点的总利润 
}profit[81],temp2;

struct//景点预定量变量 
{
	char name[20];//统计预定量中的景点名字 
	int cline;//统计预定量中的单个景点的订单数目 

}c[81],temp3;

struct//管理员个人信息 
{
	char name[20];//名字 
	char password[20];//密码 
	char phone[20];//联系电话 
	char mail[20];//邮箱 
}admin;

struct//按季度对不同景点进行排序 
{ 
	char name[20];//景点名字 
  	int month1;//第一季度的销量 
  	int month2;//第二季度的销量 
  	int month3;//第三季度的销量 
  	int month4;//第四季度的销量 
}m[81],temp4,temp5,temp6,temp7;

struct attraction1 //景点信息 
{
	char ID[1000];//景点ID 
	char name[1000];// 景点名称 
	char intro[1000];//景点简介 
	char Hprice[1000];//旺季价格
	char Lprice[1000];//淡季价格
	char time[1000];//景点游览时间 
	char discount[1000];//景点折扣信息 
	char clas[1000];//景点级别 
	char number[1000];//景点限制人数 
	char area[1000];//景点所在地区 
	char fee[1000];//景点维护费用 
}attraction[81]; 

struct attraction3 //景点信息（价格计算用） 
{
	char PID[1000];//景点ID 
	char Pname[1000];// 景点名称 
	char Pintro[1000];//景点简介 
	char PHprice[1000];//旺季价格
	char PLprice[1000];//淡季价格
	char Ptime[1000];//景点游览时间 
	float Pdiscount;//景点折扣信息 
	char Pclas[1000];//景点级别 
	char Pnumber[1000];//景点限制人数 
	char Parea[1000];//景点所在地区 
	char Pfee[1000];//景点维护费用 
}attract[81];

struct attraction2//景点变量 
{
	char Scode[7];//景点代码 
    char Sname[81];//景点名称 
	char Ssale[81];//景点销售量 
	char Sprice[81];//景区票单价 
	char Sticket[81];//景点票总量
};
struct spotdata
{
	int go_date;
	char go_spotID[7];
	int go_sales;
	int go_totalsales;
} dataWithTime[1000];//表示不同时间不同景点票量情况的结构数组 

int main()
{
  	printf("————欢迎进入团体游景点门票预定系统————\n");
  	mainInterFace();
  	return 0; 
}

void mainInterFace()
{
	printf("\n请选择您的身份：\n1.旅游团\n2.管理员\n");
	int verify;
	int choose;
	char z[5];//容错 
 
	while(1)//容错 
	{
		verify = scanf("%d", &choose);
  
		if(verify == 1 && 0 < choose < 3)
		break;
  
		else 
		gets(z);
   
		printf("请输入正确的编号：\n");
	}
	switch(choose)
	{
		case 1:
		T_TouristsInterface();
  		break;
  	case 2:
  		A_Admininterface();
  		break;
  	default:
  		mainInterFace();
  }	
} 

void A_Admininterface()//管理员主界面 
{
	void A_login();//管理员登录界面 
		A_login();
	
	void A_check();//管理员查询界面 
		A_check();
	
}

void A_login()//进入管理员登录界面 
{
	FILE*adminfile = fopen("admin.txt","a+");
	//打开管理员信息存储文件
	
	if(adminfile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	char adminname[20],adminpassword[20];
	printf("\n--------------------\n");
	printf("请输入用户名：\n");
	scanf("%s",&adminname);
	printf("请输入密码：\n");
	scanf("%s",&adminpassword);
	printf("--------------------\n");
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
	
	//验证用户名及密码是否正确
	if(strcmp(adminname,admin.name) == 0 && strcmp(adminpassword,admin.password) == 0) 
	{
		printf("您已登陆成功！\n");
		fclose(adminfile);
	
	}

	else
	{
		printf("\n您输入的账号或密码有误，请重新输入！\n");
		A_login();
	}
}

void A_check()//管理员查询界面 
{
	int choose = 0;
	printf("\n您可以选择一下操作：");
	printf("\n1.个人信息\n2.景点信息\n3.订单信息\n4.退出登录\n5.退出系统\n请选择您接下来的操作：\n");
	int verify;
	char z[81];
	while(1)
 {
  verify = scanf("%d", &choose);
  
  if(verify == 1 && 0 < choose && choose < 6)
  	break;
  
  else
  {
   	gets(z);
   	printf("\n请输入正确的编号：\n");
  }
 }
	
	switch(choose)
	{
		case 1:
			A_person();//管理员个人信息 
			break;
		
		case 2:
			A_spot();//管理员景点信息 
			break;
		
		case 3:	
			A_order();//管理员订单信息 
			break;
		case 4:
			mainInterFace();//管理员主界面 
			break;
		default:
			printf("感谢您使用该系统，祝您工作顺利！"); 
			exit(1);
	}
}


void A_person()//管理员个人信息 
{
	int num;
	FILE*outfile;
	outfile = fopen("admin.txt","r");
	if(outfile == NULL)//判断文件是否能正确打开 
   {
   	printf("\n当前订单信息文件不能正确打开！\n");
   	exit(1);
   }
 	fscanf(outfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
 	fclose(outfile);
 	printf("---------------------------");
 	printf("\n以下是您的个人信息：\n"); 
	printf("\n用户ID：%s\n\n密码：%s\n\n联系电话：%s\n\n邮箱：%s\n",admin.name,admin.password,admin.phone,admin.mail);
	printf("---------------------------\n");
	printf("请选择接下来的操作\n1.修改个人信息\n2.返回\n\n");
	int choice;
	int verify;
 	char z[81];
 
	while(1)//容错 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 3)
 	 	break;
 
 	 else
  {
   		gets(z);
   		printf("\n您输入的数字有误，请输入正确的编号：\n");
  }
	} 
    
	if(choice == 1)
	{
		printf("\n欢迎进入个人信息修改界面！\n");
		printf("-------------------------\n");
		A_person_change(); 
	
	}
	else
		A_check();
}

void A_person_change()//个人信息修改 
{
	int choice;
	printf("请选择需要修改的信息：\n");	
	printf("1.密码\n2.邮箱\n3.返回上一级\n");
	 
	int verify;
 	char z[81];
 
	while(1)//容错 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 4)
 		break;
 
 	 else
  {
   		gets(z);
   		printf("\n您输入的数字有误，请输入正确的编号：\n");
   		printf("1.密码\n2.邮箱\n3.返回上一级\n");
  }
	} 
	switch(choice)
	{
		case 1:
		 A_person_change_password();//修改密码 
		 break;
		
		case 2:
		 A_person_change_email();//修改邮箱 
		 break;
		
		default:
		 A_person();;//返回上一级 
		
	}
}

void A_order()//进入管理员订单查询界面 
{
	
	
	int choose;
	printf("\n欢迎进入管理员订单信息界面！\n");
	printf("-----------------------------\n");
	printf("以下为您可以进行的操作：\n");
	printf("1.查看历史订单\n2.统计订单信息\n3.返回上一界面\n请输入您要查询的信息：");
	int verify;
    char z[81];//容错 
 while(1)//容错 
 {
  verify = scanf("%d", &choose);
  
  if(verify == 1 && 0 < choose && choose < 4)
  		break;
  
  else
  {
   		gets(z);
   		printf("\n\n请输入正确的编号：");
  }
 }
	switch(choose)
	{
		case 1://进入管理员-查看历史订单 
			A_order_check();
			break;
		case 2://进入管理员-统计订单信息 
			A_order_count();
			break;
		case 3://进入管理员-退出 
			A_check(); 
			break;
		default:
			A_order();
		
	}
}

void A_order_check()//进入管理员-历史订单查询界面 
{
   int ordernum,spotnum,peoplenum,money,choose;
   char orderdate[20],godate[20],age[20],ident[20];
   struct order order[81];
  
   printf("\n\n欢迎进入管理员历史订单查询界面！\n");
   printf("---------------------------------------\n");
   printf("以下为历史订单信息：\n\n")	;
   FILE *outFile;
   outFile = fopen("order1.txt","r");
   if(outFile == NULL)//判断文件是否能正确打开 
   {
   	printf("\n当前订单信息文件不能正确打开！\n");
   	exit(1);
   }
   //按相应格式在屏幕上输出订单信息 
   printf("---------------------------------------------------------------------------------------------------------\n");
   printf("订单编号      | 景点编号 |    预订日期   |    出行日期     | 儿童 | 成人 | 老人 | 总人数 | 总价格   \n");
   printf("---------------------------------------------------------------------------------------------------------\n");
   int i = 0;
  

 
while(fscanf(outFile,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice) != EOF)
   { 	
 	printf("%s %8s %16s %12s %6d %6d %6d %7d %10.2f\n",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,order[i].Ochild,order[i].Oadult,order[i].Oolds,order[i].Ototal,order[i].Oprice);
 	i ++;	
	 }
   
   fclose(outFile);
   //向用户提供返回操作 
   printf("---------------------------------------------------------------------------------------------------------");
   printf("\n\n请选择接下来的操作\n1.返回\n2.留在当前界面\n");
   int verify;
 char z[5];//容错 
 
 while(1)//容错 
 {
  verify = scanf("%d", &choose);
  
  if(verify == 1 && 0 < choose && choose <3)
  		break;
  
  else
  {
   		gets(z);
   		printf("请输入正确的编号：\n");
  }
 }
   if(choose == 1)
   		A_order();//管理员订单信息 
   
    
}

void A_person_change_password()//进入管理员界面—修改管理员密码 
{
	char afterpassword[20],newpassword[20];
	int choice;
	//判断文件是否正确打开 
	FILE*adminfile = fopen("admin.txt","r");
	
	 if(adminfile == NULL)//判断文件是否能正确打开 
   {
   	printf("\n当前订单信息文件不能正确打开！\n");
   	exit(1);
   }
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail); 
	fclose(adminfile);
	//修改密码 
	printf("\n请问您想修改为：\n");
	scanf("%s",afterpassword);
	
	printf("\n请再次确认密码：\n");
	scanf("%s",admin.password);
	
	while(1)
	{
	if (strcmp(afterpassword,admin.password) == 0)
		break;
	else
	{
		printf("\n两次输入的密码不一致\n");
		printf("请重新输入\n");
		printf("\n请问您想修改为：\n");
		scanf("%s",afterpassword);
	
		printf("\n请再次确认密码：\n");
		scanf("%s",admin.password);
	}
	}
	adminfile = fopen("admin.txt","w");
	fprintf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
	printf("\n您已修改成功！\n");	
	fclose(adminfile);
		
	A_person();;//提供返回上一界面的入口
}
void A_person_change_email()//进入管理员—邮箱修改 
{
	char input[20];
	FILE*adminfile = fopen("admin.txt","r");
	
	//判断文件是否正确打开 
	if(adminfile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);

	fclose(adminfile);
	
   // 修改邮箱 
	
	printf("\n请问您想修改为：\n");
	
	while(1)
	{
	scanf("%s",input);
	//验证邮箱格式符合规范 
	int atposition,dotposition;
	for(atposition = 0;atposition<strlen(input);atposition++)
	{
		if(input[atposition] == '@')
			break;
	}
	for(dotposition=0;dotposition<strlen(input);dotposition++)
	{
		if(input[dotposition] == '.')
			break;
	}
	
		if(atposition == 0||dotposition >= strlen(input)-1||atposition >= dotposition-1)
	{
		printf("\n此邮箱格式无效，请重新输入：");
	}
	
	else
	{	
        strcpy(admin.mail,input);
        adminfile = fopen("admin.txt","w");
		fprintf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
		fclose(adminfile);
		printf("\n修改成功！\n");
		
		A_person(); //跳转上一级  
		break;                  
	}
	} 
}

void A_spot()//管理员景点信息 
{
	int choice,attractionchoice;
	
	
	printf("\n欢迎进入管理员景点信息界面!\n");
	printf("-------------------------------\n");
	printf("您可以进行一下操作：\n");
	printf("1.查询景点信息.\n2.添加景点.\n3.返回.\n(请选择1.2.3.)\n");

	int verify;
 	char z[5];//容错 
 
	while(1)//容错 
 {
  verify = scanf("%d", &attractionchoice);
  
  	if(verify == 1 && 0 < attractionchoice && attractionchoice < 4)
  	break;
  
 	 else
  {
  	 gets(z);
  	 printf("请输入正确的编号：\n");
  }
 }
	 
	 switch(attractionchoice)
	 {
 		case 1://查询 
 		{
		 	A_spot_check();
		 }
		 break;
		 
		 case 2://添加
		 {
 			A_spot_add();
 		} 
 		break;
 		
 		case 3://返回
		 {
 			A_check();
 		} 
 		break;
 		
 		default:
	 	A_spot();
 	}
}

void A_spot_check()//查询所有景点信息 
{
	int i,a,choice;
	printf("欢迎进入查询景点信息\n");
	printf("---------------------\n");
	printf("以下为景点的基本信息：\n");
	
	FILE*infile;
	infile = fopen("attractions.txt","r");//打开景点信息所在文件 
	
	if(infile == NULL)//检测一次不成功的打开 
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	a = A_order_count_spotline(); 
	
	for(i = 0;i < a;i ++)//将景点信息输出 
	{
	while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee) != EOF)
	{
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
		printf("\n景点ID:%s\n\n名称:%s\n\n简介：%s\n\n旺季价格（元）：%s\n\n淡季价格：%s\n\n游览所需时间：%s\n\n学生票/老人票折扣：%s\n\n景区级别：%s\n\n景区单日总票数（人）：%s\n\n所属区域：%s\n\n维护费用（元）：%s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	}
	}
	fclose(infile);//关闭文件 
	printf("\n请选择你接下来的操作：\n");
	printf("1.添加景点\n2.返回\n");
		int verify;
 	char z[5];//容错 
 
	while(1)//容错 
 {
  verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 3)
  	break;
  
 	 else
  {
  	 gets(z);
  	 printf("请输入正确的编号：\n");
  }
 }
 switch(choice)
 {
 	case 1:
 		A_spot_add();
 		break;
 	case 2:
 		A_spot();
 		break;
 	default:
 		A_spot();
 }
	
	//返回上一级 
}


void A_spot_add()//添加景点 
{
	int choice,a,i,j,N,M,T = 1;
	FILE*file2,*infile;
	char enternum[10];
	char entername1[10];
	infile = fopen("attractions.txt","r");
	//判断文件是否正确打开 
	if(infile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	i = 0;
	a = A_order_count_spotline();

	for(i = 0;i < a;i ++)
	fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
    fclose(infile);
    
	printf("\n欢迎进入添加景点信息\n");
	printf("--------------------------\n");
	
	printf("请输入添加的景点ID(六位字符）:\n"); 
	scanf("%s",enternum);
		
	while(1)	
	{
		if(strlen(enternum) != 6)//检测ID是否长度为6 
    	T = 0; 

	for(i = 0;i < a;i ++)//检测ID是否重复 
	{ 
		if(strcmp(enternum,attraction[i].ID) == 0)
		{
			T = 0;
		}
	}
	if(T == 0)
	{
		T = 1;
		printf("\n编号格式错误或该景点编号已被使用，请重新输入\n");
	scanf("%s",enternum);
	}
	else 
	break;
 }
	strcpy(attraction[a].ID,enternum);
	printf("\n请输入添加的景点名称:\n");
	scanf("%s",entername1);
	while(1)
 {
	for(i = 0;i < a;i ++)
	{ 
		if(strcmp(entername1,attraction[i].name) == 0)
		{
		printf("\n该景点名称已存在，请重新输入\n");
		scanf("%s",entername1);
		
		}
	}
	break;
 }
	strcpy(attraction[a].name,entername1);
	
	//打开景点信息所在文件 
	
	printf("\n请输入景点简介；\n");
	scanf("%s",attraction[a].intro);
	printf("\n请输入景点旺季价格(元）：\n");
	scanf("%s",attraction[a].Hprice);

while(1)
	{   
		j = strcmp(attraction[a].Hprice,"0");
		M = strlen(attraction[a].Hprice);
		
		if(j < 0)
		T = 0; 
		
		for(i = 0; i < M; i ++)
		{
			if(isdigit(attraction[a].Hprice[i]) == 0)
	    	T = 0;
		}
	  if(T == 0)
		{
		T = 1; 
		printf("\n您输入的数字有误，请重新输入！\n");
	    scanf("%s",attraction[a].Hprice);
		}
		else
		break;  
	}
	printf("\n请输入景点淡季价格(元）：\n");
	scanf("%s",attraction[a].Lprice);

while(1)
	{   
		j = strcmp(attraction[a].Lprice,"0");
		M = strlen(attraction[a].Lprice);
		
		if(j < 0)
		T = 0; 
		
		for(i = 0; i <M; i++)
		{
			if(isdigit(attraction[a].Lprice[i]) == 0)
	    	T = 0;
		}
	  	if(T == 0)
		{
			T = 1; 
			printf("\n您输入的数字有误，请重新输入！\n");
	    	scanf("%s",attraction[a].Lprice);
		}
		else
			break;  
	}

	printf("\n请输入该景点游览所需时间（小时）：\n");
	scanf("%s",attraction[a].time);
	printf("\n请输入该景点的折扣信息：\n");
	scanf("%s",attraction[a].discount);
		T = 0;
	while(1)
	{
	if(attraction[a].discount[0] == '0'&&attraction[a].discount[1] == '.')
		T = 1;
	for(i = 2;i < strlen(attraction[a].discount);i ++)
	{
		if(isdigit(attraction[a].discount[i]) == 0)
		T = 0;
	}
	
	if(T == 0)
	{
	 printf("您输入的数字有错，请输入浮点数："); 
	 scanf("%s",attraction[a].discount);	
	}
	else
	break;
	} 
	
	printf("\n请输入该景区级别：\n");
	scanf("%s",attraction[a].clas);
	printf("\n请输入该景点单日总票数（人）：\n");
	scanf("%s",attraction[a].number);
	while(1)
	{   
		j=strcmp(attraction[a].number,"0");
		M=strlen(attraction[a].number);
		
		if(j < 0)
		T = 0; 
		
		for(i = 0; i < M; i++)
		{
			if(isdigit(attraction[a].number[i]) == 0)
	    	T = 0;
		}
	  if(T == 0)
		{
		T = 1; 
		printf("\n您输入的数字有误，请重新输入！\n");
	    scanf("%s",attraction[a].number);
		}
		else
		break;  
	}
	printf("\n请输入该景点区域：\n");
	scanf("%s",attraction[a].area);
	printf("\n请输入该景点维修所需费用（元）：\n");
	scanf("%s",attraction[a].fee); 
	
	//将新添加的信息写入文件
	infile = fopen("attractions.txt","w");
		//判断文件是否正确打开 
	if(infile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	for(i = 0;i < a+1;i ++)
		fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile); 
	printf("\n您已成功\n"); 
	printf("--------------------------------------------\n");
	A_spot_add_change1();
	printf("您还希望继续进行修改吗？(请输入1或2或3）\n");
	printf("1.再修改\n2.取消添加并返回\n3.完成添加并返回\n");

	
	int verify;
 	char z[5];//容错 
 
 	while(1)//容错 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice< 4)
 	 break;
  
  	else
  {
 		gets(z);
 		printf("请输入正确的编号：\n");
  }
 }

switch(choice)
	{
		case 1:
			A_spot_add_change();//继续进行修改 
			break;
		
		case 2:
	    	A_spot_add_change3();//添加景点后取消 
	    	A_spot();//返回上一级
			break; 
		
		case 3:
			A_spot();//返回上一级
		
		default:
			A_spot();//返回上一级
	}
}

void A_spot_add_change()//在发布之前继续修改 
{
	int choce,choice,choice1,i,a,T,j,M;
	FILE*infile = fopen("attractions.txt","r");//打开景点信息所在文件 
	
	if(infile == NULL)//检测一次不成功的打开 
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	a = A_order_count_spotline();
	for(i = 0;i < a;i ++)
	fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
	printf("\n\n--------------------------\n");
	printf("请问您想修改什么信息？\n");
	printf("1.ID\n2.名称\n3.简介\n4.旺季价格（元）\n5.淡季价格（元）\n6.游览所需时间（小时）\n7.折扣信息\n8.级别\n9.单日景区总票数（人）\n10.区域\n11.维修所需费用（元）\n");
    printf("\n请选择你所要进行的操作：（输入1~11进行选择）"); 
	int verify;
 	char z[5];//容错 
 
 	while(1)//容错 
 {
	verify = scanf("%d", &choce);
  
 	if(verify == 1 && 0 < choce && choce < 12)
  		break;
  
  	else
  {
   		gets(z);
   		printf("\n\n请输入正确的编号：\n");
  }
 }
	char enternum[81];
 	char enternum1[81];
	switch(choce)
	{
		case 1:
		{
			int a;
			FILE*infile;
            
			a = A_order_count_spotline();
      	 	printf("\n您想修改为：\n");
      	 	scanf("%s",enternum);
	        
	while(1)	
	{
	if(strlen(enternum)!=6)//检测ID是否长度为6 
    	T = 0; 

	for(i = 0;i < a;i++)//检测ID是否重复 
	{ 
		if(strcmp(enternum,attraction[i].ID) == 0)
		{
			T = 0;
		}
	}
		if(T == 0)
	{
		T = 1;
		printf("\n编号格式错误或该景点编号已被使用，请重新输入\n\n");
		scanf("%s",enternum);
	}
	
	else 
	break;
	}
	
		strcpy(attraction[a-1].ID,enternum);	
		}
		
		break;
			
		case 2:
		{  
			printf("\n您想修改为：\n");
			scanf("%s",enternum1);
			while(1)
 {
	for(i=0;i<a;i++)//检测ID是否重复 
	{ 
		if(strcmp(enternum1,attraction[i].name) == 0)
		{
		printf("\n该景点名称已存在，请重新输入\n");
		scanf("%s",enternum1);	
		}
	}
	break;
 }
		strcpy(attraction[a-1].name,enternum1);
		}
		
		break;
		
		case 3:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].intro);
		}
		break;
		
		case 4:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].Hprice);
			while(1)
		{   
			j = strcmp(attraction[a-1].Hprice,"0");
			M = strlen(attraction[a-1].Hprice);
		
			if(j < 0)
			T = 0; 
		
			for(i = 0; i <M; i++)
			{
			if(isdigit(attraction[a-1].Hprice[i]) == 0)
	    	T = 0;
			}
	  		if(T == 0)
			{
				T = 1; 
			printf("\n您输入的数字有误，请重新输入！\n");
	    	scanf("%s",attraction[a-1].Hprice);
			}
			else
			break;  
	}
		}
		break;
		
		case 5:
			{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].Lprice);
			while(1)
	{   
		j = strcmp(attraction[a-1].Lprice,"0");
		M = strlen(attraction[a-1].Lprice);
		
		if(j < 0)
		T = 0; 
		
		for(i = 0; i < M; i ++)
		{
			if(isdigit(attraction[a-1].Lprice[i]) == 0)
	    	T = 0;
		}
	  if(T == 0)
		{
			T = 1; 
			printf("\n您输入的数字有误，请重新输入！\n");
	    	scanf("%s",attraction[a-1].Lprice);
		}
		else
			break;  
	}
		}
		break;
		
		
		
		case 6:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].time);
		}
		break;
		
		case 7:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].discount);
				T = 0;
	while(1)
	{
	if(attraction[a-1].discount[0] == '0'&&attraction[a-1].discount[1] == '.')
	T = 1;
	for(i = 2;i < strlen(attraction[a-1].discount);i ++)
	{
		if(isdigit(attraction[a-1].discount[i]) == 0)
		T = 0;
	}
	
	if(T == 0)
	{
	 	printf("您输入的数字有错，请输入浮点数："); 
	 	scanf("%s",attraction[a-1].discount);	
	}
	else
		break;
	} 
	
			
		}
		break;
		
		case 8:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].clas);
		}
		break;
		
		case 9:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].number);
			while(1)
	{   
		j = strcmp(attraction[a-1].number,"0");
		M = strlen(attraction[a-1].number);
		
		if(j < 0)
		T = 0; 
		
		for(i = 0; i < M; i ++)
		{
			if(isdigit(attraction[a-1].number[i]) == 0)
	    	T = 0;
		}
	  if(T == 0)
		{
		T = 1; 
		printf("\n您输入的数字有误，请重新输入！\n");
	    scanf("%s",attraction[a-1].number);
		}
		else
		break;  
	}
		}
		break;
		
		case 10:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].area);
		}
		break;
		
		case 11:
		{
			printf("\n您想修改为：\n");
			scanf("%s",attraction[a-1].fee);
		}
		break;
		
		default:
		A_spot_add_change();
	}
	
	infile = fopen("attractions.txt","w");//将修改过后的信息写入文件 
	if(infile == NULL)//判断文件是否正确打开 
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	for(i = 0;i < a;i ++)
		fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
	A_spot_add_change2();
	printf("\n\n您已修改成功\n");
    printf("-------------------\n");
	printf("请问您还想继续修改吗？\n");
	printf("1.继续修改\n2.取消发布并返回上一界面\n3.完成修改并返回上一界面\n");

 
 	while(1)//容错 
 {
	verify = scanf("%d", &choice1);
  
 	if(verify == 1 && 0 < choice1 && choice1 < 4)
  	break;
  
  	else
  {
   	gets(z);
   	printf("请输入正确的编号：\n");
  }
 }
	
	
	switch(choice1)
	{
		case 1:
			A_spot_add_change();//继续进行修改 
			break;
		
		case 2:
			A_spot_add_change3();//添加景点后去取消 
			A_spot();//返回上一级 
		break;
		
		case 3:
			A_spot();//返回上一级 
		break;
		
		default:
			A_spot();//返回上一级 
	} 
}

void A_spot_add_change1()//将信息写入spot.txt文件 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//打开景点信息所在文件 
			//判断文件是否正确打开 
	if(infile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	a = A_spot_count_spotline();
	for(i = 0;i < a;i ++)
		fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
    FILE*outfile = fopen("spot.txt","r");
	struct attraction2 spot1[100];
	for(i = 0;i < a-1;i ++)
		fscanf(outfile,"%s %s %s %s %s",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	fclose(outfile);
	
	for(i = 0;i < a;i ++)
	{
		strcpy(spot1[i].Scode,attraction[i].ID);
		strcpy(spot1[i].Sname,attraction[i].name);
		strcpy(spot1[i].Sticket,attraction[i].number);

	} 
		strcpy(spot1[a-1].Ssale,"0");
		strcpy(spot1[a-1].Sprice,attraction[a-1].Hprice);
		outfile = fopen("spot.txt","w");
	for(i = 0;i < a;i ++)
		fprintf(outfile,"%s %s %s %s %s\n",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	fclose(outfile);
}

void A_spot_add_change2()//将信息写入spot.txt文件 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//打开景点信息所在文件 
		
			//判断文件是否正确打开 
	if(infile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	a = A_spot_count_spotline();
	for(i = 0;i < a;i ++)
		fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
    FILE*outfile=fopen("spot.txt","r");
	struct attraction2 spot1[100];
	for(i = 0;i < a;i ++)
		fscanf(outfile,"%s %s %s %s %s",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	fclose(outfile);
	
	for(i = 0;i < a;i ++)
	{
		strcpy(spot1[i].Scode,attraction[i].ID);
		strcpy(spot1[i].Sname,attraction[i].name);
		strcpy(spot1[i].Sticket,attraction[i].number);
    
	} 
		strcpy(spot1[a-1].Ssale,"0");
		strcpy(spot1[a-1].Sprice,attraction[a-1].Hprice);
		outfile = fopen("spot.txt","w");
	for(i = 0;i < a;i ++)
		fprintf(outfile,"%s %s %s %s %s\n",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	fclose(outfile);
}

void A_spot_add_change3()//添加景点后取消 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//打开景点信息所在文件
		 
			//判断文件是否正确打开 
	if(infile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	a = A_spot_count_spotline();
	for(i = 0;i < a;i ++)
		fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
    FILE*outfile = fopen("spot.txt","r");
    
    	//判断文件是否正确打开 
	if(outfile == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
	struct attraction2 spot1[100];
	for(i = 0;i < a;i ++)
		fscanf(outfile,"%s %s %s %s %s",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	fclose(outfile);
	outfile = fopen("spot.txt","w");
	for(i = 0;i < a-1;i ++)
		fprintf(outfile,"%s %s %s %s %s\n",spot1[i].Scode,spot1[i].Sname,spot1[i].Ssale,spot1[i].Sprice,spot1[i].Sticket);
	infile=fopen("attractions.txt","w");
	for(i = 0;i < a-1;i ++)
		fprintf(infile,"%s %s %s %s  %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(outfile);
	fclose(infile);
}





int A_spot_count_spotline()//计算attractions.txt文件的行数 
{
	FILE*file1;
   	file1 = fopen("attractions.txt", "r"); // 打开文件
   	//判断文件是否正确打开 
	if(file1 == NULL)
	{
		printf("\n不能正确打开文件");
		printf("\n请再次检查");
		exit(1);
	}
	
    int line = 0;
    char attractions[1000000];
   
    while (fgets(attractions, 1000000, file1)) 
        line++; // 累计行数
    fclose(file1);
    
	return(line);
	 }


void A_order_count()//进入管理员-统计订单界面 
{
	int choose;
	printf("\n\n欢迎进入管理员统计订单界面！\n");
	printf("------------------------------\n");
	printf("您可以选择以下操作："); 
    printf("\n1.按预定量对景点进行排序 \n2.按访问人数对景点进行排序\n3.统计各个景点的利润并排序\n4.统计不同景点的用户年龄层次分布\n5.按季度对不同景点的售票情况进行排序，比较不同景点在不同季度的访问情况\n6.返回上一界面\n");
	printf("\n请选择您需要查询的信息：（输入1~6进行选择）\n");
	int verify;
 	char z[81];//容错 
 while(1)//容错 
 {
 	verify = scanf("%d", &choose);
  
  	if(verify == 1 && 0 < choose && choose < 7)
  		break;
  
  	else
  {
   		gets(z);
   		printf("请输入正确的编号：\n");
  }
 }
	switch(choose)
	{
		case 1:
		 	A_order_count_num();//管理员-查询用户订单-按预定量排序 
			break;
		case 2:
			A_order_count_peopleQuery();//管理员-查询用户订单-按访问量排序 
			break;
		case 3:
			A_order_count_propit();//管理员-查询用户订单-按利润排序 
			break;
		case 4:
			A_order_count_age();//管理员-查询用户订单-统计年龄层次	
			break;
		case 5:
			A_order_count_sale();//管理员-查询用户订单-按季度对销量排序	
			break;
		default:
			A_order();//提供返回上一级的入口 
		
	}
	 
}


void A_order_count_peopleQuery()//进入访问人数排列界面 
{
	int i;
    int j,a;
    struct spot spot[81];
    struct spot temp;
    FILE *file1;
	file1 = fopen("spot.txt","r");//打开景点信息所在的文件 
	A_order_count_sale_check();
	fopen("spot.txt", "a+"); // 打开文件
	a = A_order_count_spotline();
	for(i = 0;i<a;i++)//将信息从文件中取出 
	{
 		fscanf(file1,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
	}
	fclose(file1);
 
	for(i = 0; i < a-1; i++)//用冒泡法对预定量进行排序 
	{
	for(j = 0; j < a-i-1; j++)
	{
     if(spot[j].Ssale < spot[j+1].Ssale)
      {
      temp = spot[j+1];
      spot[j+1] = spot[j];
      spot[j] = temp;
     
            }
        }
    }
    printf("------------------------------------\n");
    printf("   景点名称       |    访问人数\n");
    printf("------------------------------------\n");
    
    for(i = 0;i < a;i ++)//将最后结果打印出来 
    {
    	printf("%16s\t%d\n",spot[i].Sname,spot[i].Ssale);
    }
A_order_count_choose();//提供返回上一级的入口 
}

void A_order_count_num()//进入按预定量排序界面 
{
	struct order order[81];
	struct spot spot[81];
	FILE *file1,*file2,*file3,*file4;
 	file1 = fopen("order1.txt","r");//判断文件是否正确打开 
 	A_order_count_age_fileCheck();
	int i = 0,a,b,j;//取出文件信息 
	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice) != EOF)
  	{i++;} 
 	fclose(file1);
 	b = A_order_count_order1line();
 	a = A_order_count_spotline();
 	file3 = fopen("spot.txt","r");//打开景点信息所在的文件 
 	A_order_count_sale_check();
	for(i = 0;i < a;i ++)//将信息从文件中取出 
 {
 	fscanf(file3,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }
 	fclose(file3);
 	int countline[100];
 	for(j = 0;j < a;j ++)
 {
 	for(i = 0;i < b;i ++)//统计同一景点的预定量 
 		if(strcmp(spot[j].Scode,order[i].Ospotcode) == 0)
 		countline[j]++;
 }
 	for(j = 0;j < a;j ++)
 {
 		c[j].cline = countline[j];
 }
 	file2 = fopen("countline.txt","w");
 	for(i = 0;i < a;i ++)
 	fprintf(file2,"%s %d\n",spot[i].Sname,c[i].cline);
 	fclose(file2);
 	file4 = fopen("countline.txt","r");//打开景点信息所在的文件 
 	if(file4 == NULL)//判断是否正确打开 
 {
 		printf("当前景点信息文件不能正确打开！");
    	exit(1); 
 }
	i = 0;//将信息从文件中取出 
 	while(fscanf(file4,"%s %d",c[i].name,&c[i].cline) != EOF)
 	i++;
 	fclose(file1);
 	for(i = 0; i < a-1; i ++)//用冒泡法对预定量进行排序 
 {
  	for(j = 0; j < a-i-1; j ++)
   {
  	if(c[j].cline < c[j+1].cline)
      {
      temp3 = c[j+1];
      c[j+1] = c[j];
      c[j] = temp3;
      }
        }
    }
    printf("--------------------------------\n");
	printf("    景点名称       |  预定量\n");
	printf("--------------------------------\n"); 
    for(i = 0;i < a;i ++)//将最后结果打印出来
	printf("%16s\t%d\n",c[i].name,c[i].cline);
    A_order_count_choose();
}

void A_order_count_propit()//进入景点利润排序页面 
{
	struct order order[81];
	FILE *file1,*file2,*file3,*file4;
 	file1 = fopen("order1.txt","r");//判断文件是否能正确打开 
 	A_order_count_age_fileCheck();
 	int i = 0,N,line = 0,j,a;
 	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,
 													&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice)!=EOF)i++;
 	fclose(file1);
 	float earn[100];
 	fopen("order1.txt", "a+"); //计算行数 
 	N = A_order_count_order1line();
 	struct spot spot[81];
 	file3 = fopen("spot.txt","r");//打开景点信息所在的文件 
 	A_order_count_sale_check();
 	a = A_order_count_spotline();
 	for(i = 0;i < a;i ++)//将信息从文件中取出 
 {
 	fscanf(file3,"%s %s %d %f %d",spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }
 	fclose(file3);
	for(j = 0;j < a;j ++)
{
	for(i = 0;i < N;i ++)//统计同一景点的预定量 
	if(strcmp(spot[j].Scode,order[i].Ospotcode) == 0)
	earn[j]	+=	order[i].Oprice;
}
	for(j = 0;j < a;j ++)
{
	profit[j].Oprofit=earn[j];
}
 	file2 = fopen("profit.txt","w");
	for(i = 0;i < a;i ++)
 		fprintf(file2,"%s %f\n",spot[i].Sname,profit[i].Oprofit);
 	fclose(file2);
 	file4 = fopen("profit.txt","r");//打开景点信息所在的文件 
 	if(file4 == NULL)//判断是否正确打开 
 {
 	printf("当前景点信息文件不能正确打开！");
    exit(1); 
 }
 	i = 0;//将信息从文件中取出
 	while(fscanf(file4,"%s %f",profit[i].Ospotcode,&profit[i].Oprofit) != EOF)i++;
 	fclose(file1);
 	for(i = 0; i < a-1; i ++)//用冒泡法对预定量进行排序 
 {
  	for(j = 0; j < a-i-1; j ++)
   {
     if(profit[j].Oprofit < profit[j+1].Oprofit)
      {
      temp2 = profit[j+1];
      profit[j+1] = profit[j];
      profit[j] = temp2;
            }
        }
    }
    printf("---------------------------------\n");
    printf("    景点名称       |     利润\n");
	printf("---------------------------------\n"); 
    for(i = 0;i < a;i ++)//将最后结果打印出来 
    {
    	printf("%16s\t%5.2f\n",profit[i].Ospotcode,profit[i].Oprofit);
    }
	A_order_count_choose();	
}

void A_order_count_age()//进入管理员—年龄层次统计 
{   
  	struct order order[81];
  	struct spot spot[81];
  	FILE *file1,*file3;
  	int a,j;
  	file1 = fopen("order1.txt","r");//判断文件是否正确打开 
 	int i = 0,n,line = 0;
 	int child[100];
 	int adult[100];
 	int old1[100];
	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,
													&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice)!=EOF)i++;//取出信息 
	fclose(file1);
	file3 = fopen("spot.txt","r");
	a = A_order_count_spotline();
 	for(i = 0;i < a;i ++)//将信息从文件中取出 
 {
 	fscanf(file3,"%s %s %d %f %d",spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }

	line = A_order_count_order1line();
	for(j = 0;j < a;j ++)
{
 	for(i = 0;i < line;i ++)//统计单个景点的儿童，成人，老人的人数 
 {
  	if(strcmp(spot[j].Scode,order[i].Ospotcode) == 0)
  {
  		child[j] += order[i].Ochild;
  		adult[j] += order[i].Oadult;
  		old1[j] += order[i].Oolds;
  }
 }
}


	for(i = 0;i < a;i ++)
{
    float adultpercent[100],childpercent[100],oldpercent[100],sum[100];//计算年龄层次分布
   
	sum[i] = child[i] + adult[i] + old1[i];
	adultpercent[i] = adult[i]/sum[i];
	childpercent[i] = child[i]/sum[i];
	oldpercent[i] = old1[i]/sum[i];
	if(sum[i] == 0)
	{
		printf("--------------------------------------------------\n");
		printf("%s:没有该景点的订单，无法进行统计\n",spot[i].Sname);
	}
	else{
    	printf("--------------------------------------------------\n");
		printf("%s的年龄层次分布为\n",spot[i].Sname);
		printf("成人占%5.2f%,儿童占%5.2f%,老人占%5.2f%\n",adultpercent[i],childpercent[i],oldpercent[i]);
	}
}
	A_order_count_choose();
}
void A_order_count_sale()//进入管理员-对不同季度不同景点进行排序 
{    
    struct spot spot[1000];
	struct order order[1000];
    int i = 0,a,b,c,d,n,k,j;// 从文件中提取景点名字 
	FILE *file1,*file5,*file6;
 	file1 = fopen("spot.txt","r");
	n = A_order_count_spotline();
	k = A_order_count_order1line();
	for(i = 0;i < n;i ++)
 	fscanf(file1,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
	fclose(file1);

	file5 = fopen("order1.txt","r");//从文件中提出单个订单的销量 和日期
	i = 0;
	while(fscanf(file5,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,
												order[i].Ogodate,&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice)!=EOF)
   {
     i++;
	 }
	char string1[20] = "2018:01:01:00:00",string2[20] = "2018:03:31:23:59",string3[20]="2018:06:30:23:59",string4[20]="2018:09:30:23:59";
 for(j = 0;j < n;j ++)
 {
 for(i = 0;i < k;i ++)
 {
  	a = strcmp(string1,order[i].Ogodate);
  	b = strcmp(string2,order[i].Ogodate);
  	c = strcmp(string3,order[i].Ogodate);
  	d = strcmp(string4,order[i].Ogodate);
  if(strcmp(spot[j].Scode,order[i].Ospotcode)==0 ) //判断是否为同一景点 
{
 	if(a < 0 && b > 0)//按季度进行分类 
	m[j].month1 = m[j].month1+order[i].Ototal;
  	else if(b < 0 && c > 0)
  	m[j].month2 = m[j].month2+order[i].Ototal;
  	else if(c < 0 && d > 0)
  	m[j].month3 = m[j].month3+order[i].Ototal;
  	else
  	m[j].month4 = m[j].month4+order[i].Ototal;
}
}
 }
	file6 = fopen("month.txt","w");//存入month文件中
	for(i = 0;i < n;i ++)fprintf(file6,"%s %d %d %d %d\n",spot[i].Sname,m[i].month1,m[i].month2,m[i].month3,m[i].month4);
 	fclose(file6);
	A_order_count_sale_paixu();  
}

void A_order_count_sale_paixu()//进入管理员—对不同季度销售情况进行排序的子函数 
{
  	int i,j,n;
 	FILE *file7;
 	file7 = fopen("month.txt","r");//打开景点信息所在的文件 
 	if(file7 == NULL)//判断是否正确打开 
 {
 		printf("当前景点信息文件不能正确打开！");
    	exit(1); 
 }
 	n = A_order_count_spotline();
 	for(i = 0;i < n;i ++)//将信息从文件中取出 
 	fscanf(file7,"%s %d %d %d %d",m[i].name,&m[i].month1,&m[i].month2,&m[i].month3,&m[i].month4);
 	fclose(file7);
   for(i = 0; i < n-1; i ++)//用冒泡法对预定量进行排序 
 {
  	for(j = 0; j < n-i-1; j ++)
   {
     if(m[j].month1 < m[j+1].month1)
      {
      temp4 = m[j+1];
      m[j+1] = m[j];
      m[j] = temp4;
            }
        }
    }
    printf("-------------------------------------\n");
    printf("第一季度的景点排序为：（从大到小）\n");
	printf("  景点名称     |   销售量\n") ;
    for(i = 0;i < n;i ++) 
	printf("%16s\t%d\n",m[i].name,m[i].month1);
	printf("销售量最多的景区为：%s\n",m[0].name);//将最后结果打印出来
    for(i = 0; i < n-1; i ++)//用冒泡法对预定量进行排序 
 {
  	for(j = 0; j < n-i-1; j ++)
   {
     if(m[j].month2 < m[j+1].month2)
      {
      temp5 = m[j+1];
      m[j+1] = m[j];
      m[j] = temp5;
            }
        }
    }
    
     printf("-------------------------------------\n");
     printf("第二季度的景点排序为：（从大到小）\n"); 
     printf("  景点名称     |   销售量\n") ;
    for(i = 0;i < n;i ++) printf("%16s\t%d\n",m[i].name,m[i].month2);
	printf("销售量最多的景区为：%s\n",m[0].name);//将最后结果打印出来
    for(i = 0; i < n-1; i ++)//用冒泡法对预定量进行排序 
 {
  for(j = 0; j < n-i-1; j ++)
   {
     if(m[j].month3 < m[j+1].month3)
      {
      temp6 = m[j+1];
      m[j+1] = m[j];
      m[j] = temp6;
     
            }
        }
    } 
    printf("---------------------------------------\n");
    printf("第三季度的景点排序为：（从大到小）\n"); 
    printf("  景点名称     |   销售量\n") ;
	for(i = 0;i < n;i ++) 
	printf("%16s\t%d\n",m[i].name,m[i].month3);
	printf("销售量最多的景区为：%s\n",m[0].name);//将最后结果打印出来
	for(i = 0; i < n-1; i ++)//用冒泡法对预定量进行排序 
 {
  	for(j = 0; j < n-i-1; j ++)
   {
     if(m[j].month4 < m[j+1].month4)
      {
      temp7= m[j+1];
      m[j+1] = m[j];
      m[j] = temp7;
     
            }
        }
    }
    printf("---------------------------------------\n");
    printf("  景点名称     |   销售量\n") ;
	printf("第四季度的景点排序为：（从大到小）\n"); 
	for(i = 0;i < n;i ++) printf("%16s\t%d\n",m[i].name,m[i].month4);
	printf("销售量最多的景区为：%s\n",m[0].name);//将最后结果打印出来

    A_order_count_choose();
}

void A_order_count_choose()//提供返回管理员订单统计信息界面 
{
   int choose;
   printf("-------------------------------\n");
   printf("\n请选择接下来的操作\n1.返回上一级\n2.留在当前界面");
   int verify;
 	char z[5];//容错 
 
 while(1)//容错 
 {
  	verify = scanf("%d", &choose);
  
  	if(verify == 1 && 0 < choose && choose < 3)
  		break;
  
  	else
  {
   	gets(z);
   	printf("请输入正确的编号：\n");
  }
 }
   if(choose == 1)
   A_order_count();	
}	

void A_order_count_sale_check()//判断景点文件是否正确打开 
{
	FILE*file1;
	file1 = fopen("spot.txt","r");
	if(file1 == NULL) 
 {
 	printf("当前景点信息文件不能正确打开！");
    exit(1); 
 }	
}

void A_order_count_age_fileCheck()//判断订单文件是否正确打开 
{
	FILE *file1;
 	 //判断文件是否正确打开 
 	file1 = fopen("order1.txt","r");
 	if(file1 == NULL)
 {
	printf("当前景点信息文件不能正确打开！");
    exit(1); 
 }	
}

int A_order_count_spotline()//计算spot.txt的行数 
{
	FILE*file1;
   	file1 = fopen("spot.txt", "a+"); // 打开文件
    int line = 0;
    char spot1[100];
   	A_order_count_sale_check();
    while (fgets(spot1, 100, file1)) 
        line++; // 累计行数
    fclose(file1);
    
	return(line);
	 }
	 
 int A_order_count_order1line()//计算order1.txt的行数 
 {
 	FILE*file1;
 	file1 = fopen("order1.txt", "a+"); // 打开文件
    char order1[100];
    int line = 0;
   	A_order_count_age_fileCheck();
    while (fgets(order1, 100, file1)) 
        line++; // 累计行数
    fclose(file1);
    return(line);
 }
 
 void T_TouristsInterface() 
{
	int touristsOperation;
	printf("\n----------------------\n");
	printf("\n1.登录\n2.注册\n请选择接下来的操作：");//游客选择登录或注册 
	
	int verify;
	char z[81];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &touristsOperation);
		
		if(verify == 1 && 0 < touristsOperation < 3)
		break;
		
		else
		{
			gets(z);
			printf("您输入的数字有误，请从1或2中选择。\n");
		}
	}
	printf("\n----------------------\n");
	
	if(touristsOperation == 1)//游客进入登录界面 
	{
  		T_person_login();
	}
	
	else if(touristsOperation == 2)//游客进入注册界面 
	{
     	T_person_register();
	} 
	
	else
	T_TouristsInterface();
}

void T_person_login()
{
    FILE*outfile = fopen("T_information.txt","r");//打开管理员信息存储文件
	struct T_account tourist[81];

	int i = 0,j = 0,k;
	printf("\n----------------------\n");
	printf("\n请输入用户名：");
	scanf("%s",&touristname);
	printf("请输入密码：");
	scanf("%s",&touristpassword);
	printf("\n----------------------\n");

	while(fscanf(outfile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
													&tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum)!=EOF)
	
	//验证用户名及密码是否正确
{
	if(strcmp(touristname,tourist[i].idNum) == 0 && strcmp(touristpassword,tourist[i].password) == 0) 
	{
	printf("您已登录成功！\n");
    j = 1;
	}
	i ++;	
}    
	fclose(outfile);
	if(j != 1)//密码错误 
    {
	printf("您输入的账号或密码有误，请重新输入！\n");
    T_person_login();
    }
   
   
 	T_Menu();
}

// 进入游客查询界面
void T_Menu()
{
	int queryChoice = 0;
	
	printf("\n请选择您需要查询的信息：\n1.个人信息\n2.景点信息\n3.订单信息\n4.门票预订\n5.退出登录\n6.退出系统\n"); 
	
	int verify;
	char z[5];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &queryChoice);
		
		if(verify == 1 && 0 < queryChoice < 7)
		break;
		
		else
		{
			gets(z);
			printf("请输入正确的编号：\n");
		}
	}
	
	//进入游客查询界面后选择 
	switch(queryChoice) 
	{
		
		//游客个人信息 
		case 1:
			T_person();
			break;
		
		//游客查询景点信息 
		case 2:
			T_spot_AttractionsInformation();
			break;
	
		//游客查询订单信息 
		case 3:
			T_order_Information();
			break;
		
		//游客门票预订 
		case 4:
			T_person_order_fillIn();
			break;
			
		//退出登录
		case 5:
			mainInterFace();
			break;
			
		case 6:
			printf("\n感谢使用本系统，祝您旅程愉快！\n");
			exit(1);
			break;
			
		default:
			T_Menu();
		
	}
			
}  
void T_person()//个人信息管理 
{
	int choose;
	printf("\n您可进行以下操作：\n1.查看我的信息\n2.修改我的信息\n3.返回主菜单\n");
	
	int verify;
	char z[5];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("请输入正确的编号：\n");
		}
	}
	
	if(choose == 1)
	  T_person_check();//查看我的信息 
	  
	else if(choose == 2)
	  T_person_change();//信息修改 
	  
	else 
	  T_Menu();//返回主菜单 
	  
}
void T_person_check()
{
	FILE*infile = fopen("T_information.txt","r");
	int i = 0,choose;
	struct T_account tourist[81];
	if(infile == NULL)
	{
		printf("\n打开失败！");
		exit(1);
	}
	printf("\n————————————————————————————————————————————\n");
	printf("|用户名|  密码  |总人数|0-18岁（含18）|18-60岁（含60）|60岁以上|电话号码(11位)|电子邮箱|\n");
	printf("————————————————————————————————————————————\n");
    while(fscanf(infile," %s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
   {
   	if(strcmp(tourist[i].idNum,touristname) == 0)
   	printf("%s\t%s\t%d\t\t%d\t\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
	                                   tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
    i++;
   }
 	fclose(infile);
	printf("\n您可选择\n1.返回主菜单\n2.返回个人信息页\n3.退出\n");//下一步操作 
 	scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_Menu();
			break;//返回信息修改页 
		}
		else if(choose == 2)
		{
			T_person();
			break;//回到主菜单 
		}
		else if(choose == 3)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);//退出 
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 
   
} 
void T_person_change()//游客团信息修改页面 
{
	int choose;
		
	printf("\n欢迎进入个人信息修改界面！\n");
	printf("-------------------------\n");
	printf("请选择需要修改的信息：\n1.密码\n2.联系人手机\n3.邮箱\n4.返回主菜单\n");
	scanf("%d",&choose);
	
    while(1)
	{
		if(choose == 1)
		{	T_person_change_password();
		  	break;//修改密码
			 } 
		else if(choose == 2)
			{
			T_person_change_phone();
			break;//修改手机号
			} 
		else if(choose == 3)
			{
			T_person_change_mail(); 
			break;//修改邮箱 
			} 
		else if(choose == 4)
         {
		 	T_Menu();
		 	break;
			 } 
      	else
		{	printf("输入错误！请从1、2、3、4中选择！\n"); 
			scanf("%d",&choose);} 
	     
	}
}

void T_person_change_password()//密码修改 
{  
	char afterpassword[20],newpassword[20],temp1[20];
	int i = 0,choose;
	FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n打开失败！");
		exit(1);
	}
	
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum)!=EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)
{ 
	while(1) 
{
	printf("\n请输入新密码：\n");//密码查重 
	scanf("%s",afterpassword);
	
	printf("请再次确认密码：\n");
	scanf("%s",newpassword);
	
	if(strcmp(afterpassword,newpassword) != 0)
	{
	printf("两次输入的密码不一致,请重新输入!");
	}		
	else if(strcmp(afterpassword,newpassword) == 0)//修改密码 
    {
     	strcpy(temp1,tourist[i].password); 
		strcpy(tourist[i].password,newpassword); 
		strcpy(newpassword,temp1); //交换字符串 
		fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
	                                                   tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
		break;
    }  
}}
        
  
       else if(strcmp(tourist[i].idNum,touristname) != 0)
       {
		fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
  						                               tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
       }
       i++;
 }
    printf("您已修改成功！\n");	
	fclose(infile);
	fclose(outFile);
	remove("T_information.txt");//替换 
    rename("temp.txt","T_information.txt");
    printf("您可选择\n1.返回用户信息修改页面\n2.返回主菜单\n3.退出\n");//下一步操作 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//返回信息修改页 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//回到主菜单 
		}
		else if(choose == 3)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);//退出 
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 
}
	


void T_person_change_phone()//修改手机号 
{
	char afterphone[20],temp2[20];
	int i = 0,choose,check = 0;
	FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n打开失败！");
		exit(1);
	}
    printf("\n请输入新的手机号：\n");
	scanf("%s",afterphone);//修改电话号 
	check = T_person_register_formatVerify_phone(afterphone);//判断电话号输入是否正确 
	while(1)
	{
		if(check == 1)
		break;
		else if(check == 0)
	{
		printf("您输入的手机号有误，请重新输入：\n");
		scanf("%s",afterphone);
		check = T_person_register_formatVerify_phone(afterphone);
	} 
	} 
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)//找到对应的字符串 
{
 

 		strcpy(temp2,tourist[i].phoneNum); 
		strcpy(tourist[i].phoneNum,afterphone); 
		strcpy(afterphone,temp2); //交换字符串 
		fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
	                                                   tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
		

}
        
  
       else if(strcmp(tourist[i].idNum,touristname) != 0)
       {
       	fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
  						                               tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
       }
       i++;
 }
    printf("修改成功！\n");	
	fclose(infile);
	fclose(outFile);
    remove("T_information.txt");
    rename("temp.txt","T_information.txt");
  
  	printf("您可选择\n1.返回用户信息修改页面\n2.返回主菜单\n3.退出\n");//下一步操作 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//返回信息修改页 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//回到主菜单 
		}
		else if(choose == 3)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 

}
 
 
void T_person_change_mail()//修改邮箱
{
	char newemailNum[20];
	int atposition,dotposition,i = 0,choose;
    FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n打开失败！");
		exit(1);
	}
	printf("\n请输入新邮箱：\n");
	scanf("%s",newemailNum);
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)//找到对应字符串 
{
	while(1) 
{


    for(atposition = 0;atposition < strlen(newemailNum);atposition++)//核对邮箱格式 
	{
		if(newemailNum[atposition] == '@')
			break;
	}
	for(dotposition = 0;dotposition < strlen(newemailNum);dotposition++)
	{
		if(newemailNum[dotposition] == '.')
			break;
	}
	
		if(atposition == 0||dotposition >= strlen(newemailNum)-1||atposition>=dotposition-1)
	{
		printf("此邮箱格式无效，请重新输入：\n");
		scanf("%s",newemailNum);
	}
	
	else//更换邮箱 
	{	
 		strcpy(tourist[i].emailNum,newemailNum); 
		fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
	                                                   tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
		break;
    }  
}}
        
  
	else if(strcmp(tourist[i].idNum,touristname)!=0)
       {
		fprintf(outFile,"%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
  						                               tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
       }
  		i++;
 }
    printf("您已修改成功！\n");	
	fclose(infile);
	fclose(outFile);
    remove("T_information.txt");
    rename("temp.txt","T_information.txt");
   	printf("您可选择\n1.返回用户信息修改页面\n2.返回主菜单\n3.退出\n");//下一步操作 
    scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//返回信息修改页 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//回到主菜单 
		}
		else if(choose == 3)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);//退出 
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 
}
void T_person_register()
{
	struct T_account account;
	
	printf("\n————游客团注册————\n");
	printf("账号(由6-10位字母或数字组成): \n");
	
	while(1)
	{
		scanf("%s", account.idNum);
		if(T_person_register_formatVerify_id(account.idNum))
	 {
	 	if(T_person_register_duplicateCheck(account.idNum))
	 	break;
  		else 
		printf("用户名已被注册，请重新输入: \n");
  	  }
		    
		else 
		printf("请输入6-10位的游客团ID: \n");
	}
	
	printf("密码: \n");
	scanf("%s", account.password);
	
	printf("游客团人数: \n");
	scanf("%d", &account.peopleNum);
	
	printf("请输入对应年龄段人数"); 
	printf("0-18岁（含18）");
	scanf("%d", &account.studentNum);
	printf("18-60岁（含60）");
	scanf("%d", &account.adultNum);
	printf("60岁以上");
	scanf("%d", &account.oldsNum);
	
	printf("电话号码(11位): \n");
	while(1)
	{
		scanf("%s", account.phoneNum);
		if(T_person_register_formatVerify_phone(account.phoneNum))
		  break;
		else printf("请输入正确的电话号码: \n");
	}
	
	printf("电子邮箱: \n"); 
	while(1)
	{
		scanf("%s", account.emailNum);
		int T;
		int atposition,dotposition;
		for(atposition = 0;atposition < strlen(account.emailNum);atposition++)
		{
			if(account.emailNum[atposition] == '@')
				break;	
		}	
		for(dotposition=0;dotposition < strlen(account.emailNum);dotposition++)
		{
			if(account.emailNum[dotposition] == '.')
				break;	
		}
		if(atposition == 0||dotposition >= strlen(account.emailNum)-1||atposition >= dotposition-1)
		  T = 0;
		else T = 1;
			
		if(T)
		  break;
		else 
		printf("请输入正确格式的邮箱地址: \n");
	}
		
	FILE *information = fopen("T_information.txt", "a");
	if(information == NULL)
	{
		printf("文件错误\n");
		exit(1);
	}
	fprintf(information, "%s %s %d %d %d %d %s %s\n", account.idNum, account.password, account.peopleNum, account.studentNum, account.adultNum, account.oldsNum, account.phoneNum, account.emailNum);
	fclose(information);
	
	printf("注册成功！\n");
	printf("--------------------\n");
	T_TouristsInterface();//调用函数返回选择界面 
}
 
int T_person_register_formatVerify_id(char id[])
{
	int T;
	if(strlen(id) > 5 && strlen(id) < 11)
	  T = 1;
	else T = 0;
	return (T);
}

int T_person_register_formatVerify_phone(char phoneNum[])
{
	int i, T;
	if(strlen(phoneNum) == 11)
 		T = 1;
	else 
		T = 0;
	
	for(i = 0; i <11; i++)
	{
		if(isdigit(phoneNum[i]) == 0)
		T = 0;
	}
	return (T);
}


int T_person_register_duplicateCheck(char putInId[])
{
	struct T_account id[81];
	int i, T = 1;
	FILE *information = fopen("T_information.txt", "r");
	if(information == NULL)
	{
		printf("文件不存在\n");
		exit(1);
	}
	while(fscanf(information, "%s %s %d %d %d %d %s %s", id[i].idNum, id[i].password, &id[i].peopleNum, &id[i].studentNum, &id[i].adultNum, &id[i].oldsNum, id[i].phoneNum, id[i].emailNum) != EOF)
	{
		if(strcmp(id[i].idNum, putInId) == 0)
		{
			T = 0;
			break;
		}
		else 
		i++;
	} 
	
	fclose(information);
	
	return(T);
}

void T_spot_AttractionsInformation()
 {
    int WayofSearch = 0;
	
    T_spot_SettingRecommend(); 
    //这边是景点推荐函数。 
    printf("\n您好，现在您可以输入代码，选择如下方式进行景点查询：\n");
    printf("1.景点名称\n");
    printf("2.通过是否有票进行查询\n");
    printf("3.景点区域\n");
	printf("4.折扣信息\n");
	printf("5.根据价格排序查询\n");
	printf("6.根据预定量查询\n");
	printf("7.返回主菜单\n");
	
	int verify;
	char z[5];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &WayofSearch);
		
		if(verify == 1)
		break;
		
		else
		{
			gets(z);
			printf("请输入正确的编号：\n");
		}
	}
	
	while(1)
	{
		if(WayofSearch == 1)
		{
			T_spot_count_ByNameInquire();
			break;
		}
		else if(WayofSearch == 2)
		{
			T_spot_count_Ticket();
			break;
		}
		else if(WayofSearch == 3)
		{
			T_spot_count_ScenicArea();
			break;
		}
		else if(WayofSearch == 4)
		{
			
			T_spot_count_Discount();
			break;
		}
		else if(WayofSearch == 5)
		{
			
			T_spot_count_PriceOrder();
			break;
		}
		else if(WayofSearch == 6) 
		{
			
			T_spot_count_SalesOrder();
			break;
		}
		else if(WayofSearch == 7)
		{
			T_Menu();
			break; 
		}
		else 
		{
			printf("输入错误！请从1-7中选择！\n"); 
			scanf("%d",&WayofSearch);
		}
	}
 }
 
 void T_spot_count_ByNameInquire()//通过景点名称查询 
{
	char spotChoice[7];//声明选择变量
	struct spot spot[1000];
	
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	fclose(outFile);
	int num_spot = i;//记录景点数
	printf("\n-----------------------------\n");
	printf("以下为该系统中所有可查询景点"); 
	printf("\n-----------------------------\n");
	for(i = 0; i < num_spot; i++)
	  printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	  
	printf("\n请选择您感兴趣的景点，并输入其对应编号或输入000000返回上一级：");
	int verify = 0;
	i = 0;
	char judge[] = "000000";//用于判断返回的数组 
	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	
		for(i = 0; i < num_spot;  i++)//检查是否为有效景点编号 
	 	{
	 		if(strcmp(spot[i].Scode, spotChoice) == 0)
			verify = 1;
	 	}
	 	
	 	if(verify == 1)
	 	break;
	 	else if(strcmp(spotChoice, judge) == 0)
	 	break;
	 	else
	 	{
	 		i = 0;
	 		printf("\n请输入正确的景点编号,返回上一级请输入000000：\n");
	 	}
	 }
	
	if(strcmp(spotChoice, judge) == 0)
	  T_spot_AttractionsInformation();//调用函数返回上一级 
	
	else
	  T_spot_other_introduction(spotChoice);//调进入景点详情页面	
}

void T_spot_count_Ticket()
{
	struct spot spot[81];
	int neededDate, verify;
	char z[5];
	printf("\n请输入想要查询的日期（格式如20180501）：");
 	while(1)
 	{
	 	verify = scanf("%d", &neededDate);
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(neededDate) == 1)
				break;
	 		else printf("\n该日期不存在，请输入正确的日期: ");
	 	}
	 	else
		{
			gets(z);
			printf("\n请输入格式正确的日期: ");
		}
	 }
	 FILE *outFile_data = fopen("order2.txt", "r");//打开可读的每日景点售票情况文件
	 if(outFile_data == NULL)
	 {
 		printf("文件不存在");
		exit(1); 
 	}
	 int i = 0, j = 0, k = 0;//计数
	 int ticketLeft [1000];
	 char spotID_limitTicket [1000][7];
	 char spotID_noTicket [100][7];
	 int num_noTicket, num_limitTicket;
	 while(fscanf(outFile_data, "%d %s %d %d", &dataWithTime[i].go_date, dataWithTime[i].go_spotID, &dataWithTime[i].go_sales, &dataWithTime[i].go_totalsales) != EOF)
	 {
 		if(neededDate == dataWithTime[i].go_date)
 		{
		 	if(dataWithTime[i].go_totalsales - dataWithTime[i].go_sales == 0)
		 	{
	 			strcpy(spotID_noTicket[k],dataWithTime[i].go_spotID);
	 			k ++;
	 		}
	 		else if(dataWithTime[i].go_totalsales - dataWithTime[i].go_sales <= 15)
	 		{
		 		strcpy(spotID_limitTicket[j],dataWithTime[i].go_spotID);
		 		ticketLeft[j] = dataWithTime[i].go_totalsales - dataWithTime[i].go_sales;
		 		j ++;
		 	}
		 }
		 i ++;
 	}
 	fclose(outFile_data); 	
 	num_limitTicket = j;//记录票余量紧张的景点数
 	num_noTicket = k;//记录当日无票景点数
	i = 0;j = 0; k = 0;
	printf("\n| 编号 |   景点名称   |票余量|\n"); 
 	verify = 1;
 	int T = 1;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	verify = 1; 
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		for(k = 0; k < num_noTicket; k ++)
 		{
			if(strcmp(spot[i].Scode, spotID_noTicket[k]) == 0)
			{
				printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "售完");
				verify = 0;
			}
		 	
		 }
		if(verify == 1)
		{
			if(num_limitTicket != 0)
			{
				for(j = 0; j < num_limitTicket; j ++)
				{
					if(strcmp(spot[i].Scode, spotID_limitTicket[j]) == 0)
					{
						printf("%s.  %s\t\t%d\n", spot[i].Scode, spot[i].Sname, ticketLeft[j]);
						T = 0;
					}
				}
				if(T == 1)
				printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "充足");
				
			}
			else printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "充足");	
		}
		i ++;
		T = 1;
		verify = 1; 
 	}
 	fclose(outFile);
 	int num_spot = i;//景点数+1 
 	i = 0;j = 0;k = 0;
 	void T_spot_other_spotchoose();//输入景点编号的函数 
 	T_spot_other_spotchoose();
}

void T_spot_other_spotchoose()
{
	int i = 0;
	struct spot spot[81];
	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	{
		i ++;
	}
	int num_spot = i;
	printf("请选择您感兴趣的景点，并输入其对应编号（返回上一级请输入000000）：");
 	char spotChoice[7];
 	char returnNum[7] = "000000";
 	int verify = 0; 
 	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	verify = 0;
		for(i = 0; i < num_spot; i++)//检查是否为有效景点编号 
	 	{
	 		if(strcmp(spot[i].Scode, spotChoice) == 0)
			verify = 1;
	 	}
	 	i = 0; 
	 	
	 	if(strcmp(spotChoice, returnNum) == 0)
	 	{
	 		T_spot_AttractionsInformation();//调用函数返回上一级
	 		break;
	 	}
	 	if(verify == 1)
	 	break;
	 	else
	 	{	i = 0;
	 		printf("\n请输入正确编号（返回上一级输入000000）：");
	 	}
	 }
	if(strcmp(spotChoice, returnNum) != 0)
	 T_spot_other_introduction(spotChoice); 
}

int T_spot_count_Ticket_datecheek(int neededDate)
{
	int T = 0;
	
	if(neededDate >= 20180101 && neededDate <= 20180131)
	T = 1;
	else if(neededDate >= 20180201 && neededDate <= 20180228)
	T = 1;
	else if(neededDate >= 20180301 && neededDate <= 20180331)
	T = 1;
	else if(neededDate >= 20180401 && neededDate <= 20180430)
	T = 1;
	else if(neededDate >= 20180501 && neededDate <= 20180531)
	T = 1;
	else if(neededDate >= 20180601 && neededDate <= 20180630)
	T = 1;
	else if(neededDate >= 20180701 && neededDate <= 20180731)
	T = 1;
	else if(neededDate >= 20180801 && neededDate <= 20180831)
	T = 1;
	else if(neededDate >= 20180901 && neededDate <= 20180930)
	T = 1;
	else if(neededDate >= 20181001 && neededDate <= 20181031)
	T = 1;
	else if(neededDate >= 20181101 && neededDate <= 20181130)
	T = 1;
	else if(neededDate >= 20181201 && neededDate <= 20181231)
	T = 1;
	else T = 0;
	
	return(T);
}

void T_spot_count_ScenicArea()//区域查询 
{
	FILE *information;
	information = fopen("attractions.txt","r"); 
	
	printf("\n");
	
	if(information == 0)
	{
		printf("文件不存在");
		exit(1);
	}
	
	int i = 0, j, k = 1;//计数 
	int verify = 1;//验证 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//记录景点个数 
	printf("\n---------\n");
	printf("区域名称\n");
	printf("---------\n");
	for(i = num_spot-1; i >= 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(strcmp(attraction[i].area, attraction[j].area) == 0)
			verify = 0;
		}
		
		if(verify)
		{
			printf("%d.%s\n", k, attraction[i].area);
			k ++;
		}
	}
	
	printf("请选择您想要查询的区域（输入其中文名称）或输入000000返回上一级:");
	char areaChoice[81];//声明选择变量 
	char judge[]="000000";
	
	scanf("%s", areaChoice);
	
	if(strcmp(areaChoice, judge) == 0)
 	T_spot_AttractionsInformation();
	
	else 
	T_spot_count_ScenicArea_check(areaChoice);
}

void T_spot_count_ScenicArea_check(char areaChoice[])
{
	FILE *information;
	information = fopen("attractions.txt","r"); 
	char spotChoice[7];
	char judge[] = "000000";
	if(information == 0)
	{
		printf("文件不存在");
		exit(1);
	}
	
	int i = 0, j = 0;//计数 
	int verify = 0;//验证 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//记录景点个数 
	
	for(i = 0; i < num_spot; i ++)
	{
		if(strcmp(areaChoice, attraction[i].area) == 0)
		{
			printf("%s.%s\n", attraction[i].ID, attraction[i].name);
			j ++;
		} 
	}
	
	
	
	if(j == 0)
	{
		while(1)
		{
			printf("\n不存在该区域，请输入000000返回\n");
			scanf("%s", spotChoice);
			if(strcmp(spotChoice, judge) == 0)
			{
				T_spot_count_ScenicArea();
			}
		} 
	}
	else
	{
		printf("请输入您想要查看景点的六位数编号,或输入000000返回上一级：");
		char spotChoice[7];
		i = 0;
		while(1)
		{
			scanf("%s", spotChoice);
			for(i = 0; i < num_spot;  i++)//检查是否为有效景点编号 
			{
				if(strcmp(attraction[i].ID, spotChoice) == 0)
				verify = 1;
			}
			if(verify == 1)
			break;
			else if(strcmp(spotChoice, judge) == 0)//判断是否为退出编号 
			break;
			else
			{
				i = 0;
				printf("\n请输入您想要查看景点的六位数编号,或输入000000返回上一级：");
			}
	 	}
	
			if(strcmp(spotChoice, judge) == 0)
 			T_spot_count_ScenicArea();
	  
			else 
			T_spot_other_introduction(spotChoice);
	}
}

void T_spot_count_Discount()//折扣信息查询 
{
	printf("\n---------------------\n");
	printf("当前可选择的折扣方式\n"); 
	printf("---------------------\n");
	printf("1.设有学生票和老年半价票的景点\n2.返回上一级\n");
	
	int choice, verify;
	
	char z[5];//容错
	while(1)
	{
		verify = scanf("%d", &choice);
		if(verify == 1 && choice > 0 && choice < 3)
		break;
		else
		{
			gets(z);
			printf("\n请输入正确的编号：");
		}
	}
	char spotChoice[7], judge[9][7]={"000001", "000002", "000003", "000004", "000005", "000006", "000007", "000008", "000000" }; 
	
	switch(choice)
	{	
		case 1:
		T_spot_count_Discount_1();
		break;
		
		case 2:
  		T_spot_AttractionsInformation();
		break;
		
		default:
		T_spot_AttractionsInformation();
	}		
}

void T_spot_count_Discount_1()//设有学生票和老年票的景点 
{
	char spotChoice[7];//声明选择变量
	struct spot spot[1000];
	
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	fclose(outFile);
	int num_spot = i;//记录景点数
	printf("\n-----------------------------\n");
	printf("设有学生票和老年半价票的景点"); 
	printf("\n-----------------------------\n");
	for(i = 0; i < num_spot; i++)
	  printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	  
	printf("\n请选择您感兴趣的景点，并输入其对应编号或输入000000返回上一级：");
	int verify = 0;
	i = 0;
	char judge[] = "000000";//用于判断返回的数组 
	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	
		for(i = 0; i < num_spot;i ++)//检查是否为有效景点编号 
	 	{
	 		if(strcmp(spot[i].Scode, spotChoice) == 0)
			verify = 1;
	 	}
	 	
	 	if(verify == 1)
	 	break;
	 	else if(strcmp(spotChoice, judge) == 0)
	 	break;
	 	else
	 	{
	 		i = 0;
	 		printf("\n请输入正确的景点编号,返回上一级请输入000000：\n");
	 	}
	 }
	
	if(strcmp(spotChoice, judge) == 0)
	  T_spot_AttractionsInformation();//调用函数返回上一级 
	
	else
	  T_spot_other_introduction(spotChoice);//调进入景点详情页面
}

void T_spot_count_PriceOrder()//根据价格排序 
 {  int choose;
    T_spot_count_PriceOrder_datechange(); 
 	printf("\n您可选择:\n1.按价格从低到高查询\n2.按价格从高到低查询\n3.返回上一页\n");
	
	int verify;
	char z[5];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose && choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("\n请输入正确的编号：");
		}
	}
	
	while(1)
	{
		if(choose == 1)//从低到高 
		{
			
			T_spot_count_PriceOrder_FromLtoH();
			break;
		}
		else if(choose == 2)//从高到低 
		{
			
			T_spot_count_PriceOrder_FromHtoL();
			break;
		}
		else
		{
			T_spot_AttractionsInformation();
			break;//回到景点查询页面。 
		}
	}	 
 } 
 
 void T_spot_count_PriceOrder_datechange()//按淡旺季进行改变价格以及总票价
 {  
    int i = 0;
	float price1[8] = {30.00,260.00,60.00,40.00,10.00,175.00,130.00,100.00};
 	float price2[8] = {20.00,260.00,40.00,20.00,10.00,175.00,130.00,100.00};
  	int ticket1[8] = {200,200,200,200,100,100,100,100};
   	int ticket2[8] = {100,100,100,100,200,200,200,200};
 	struct spot dataWithTime[1000];
	int neededDate, verify,usedate;
	char z[5];
	printf("\n请输入想要查询的日期（格式如20180501）：");//输入查询日期 
 	while(1)
 	{
	 	verify = scanf("%d", &neededDate);//对输入日期进行检查 
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(neededDate) == 1)
	 		{
				break;
		 	}
	 		
	 		else 
		 	printf("\n该日期不存在，请输入正确的日期: ");
	 	}
	 	else
		{
			gets(z);
			printf("\n请输入格式正确的日期: ");
		}
	 } 
     
  	FILE *inFile;
	FILE *onFile;
    inFile = fopen("spot.txt","r");
    onFile = fopen("temp.txt","w");
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
    
	usedate = neededDate-2018*10000;
	while(fscanf(inFile,"%s %s %d %f %d",&dataWithTime[i].Scode,&dataWithTime[i].Sname,&dataWithTime[i].Ssale,
	                                  &dataWithTime[i].Sprice,&dataWithTime[i].Sticket) != EOF)
  {
     	if(i < 8)
   	{
         if(usedate >= 401&&usedate <= 1031)
	     fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,price1[i],ticket1[i]);
	     else
	     fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,price2[i],ticket2[i]);
      	
      }
         else
         fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,dataWithTime[i].Sprice,dataWithTime[i].Sticket);
         i++;
  }
        fclose(inFile);
        fclose(onFile);
        
        remove("spot.txt");
        rename("temp.txt","spot.txt");
        
} 
 
 void T_spot_count_SalesOrder()//根据预定量查询 
 {
	 int choose;
 	 printf("\n您可选择\n1.按预定量从低到高查询\n2.按预定量从高到低查询\n3.返回上一页\n");
	 
	int verify;
	char z[5];//容错 
	
	while(1)//容错 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose && choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("请输入正确的编号：\n");
		}
	}
	 
	while(1)
	{
		if(choose == 1)//从低到高 
		{
			T_spot_count_SalesOrder_FromLtoH();
			break;
		}
		else if(choose == 2)//从高到低 
		{
			T_spot_count_SalesOrder_FromHtoL();
			break;
		}
		else
		{
			T_spot_AttractionsInformation();
			break;//回到景点查询页面。 
		}
	} 
 }
 
 void T_spot_SettingRecommend()//推荐景点 
 {
 	int j,season;
  	char *name[21];
       
	int date1[21],date2[21],date3[21],date4[21];
	    
	time_t timefun;
  	struct tm *t;
  	time (&timefun);
  	t = gmtime(&timefun);
  	season = (1+t->tm_mon)*100+t->tm_mday;//获取用户时间并转成数字 
        
    FILE *inFile;
 	inFile = fopen("setting.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n打开失败");
		 exit(1); 
 	}
 	printf("\n------------------------------------------------------------------------------");
 	printf("\n推荐！根据当前季度为您推荐以下景点："); 
 	
 	for(j = 0;j < 8;j ++)
	 {
	 fscanf(inFile,"%s %d %d %d %d",settings,&date1[j],&date2[j],&date3[j],&date4[j]);
	 if(season >= date1[j]&&season <= date2[j])//选择出合适的景点 
	 printf("%s ",settings);
	}
	printf("\n------------------------------------------------------------------------------\n");
 	fclose(inFile);
 	
 }

 void T_spot_count_PriceOrder_FromLtoH()
 {
 	FILE *inFile;
 	int i = 0,j,choose,number = 0;
 	float k;
 	char temp1[81];
 	char temp2[81];
 	char Choose[81];
 	struct spot priceorder[81];
	inFile = fopen("spot.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n打开失败");
	 	exit(1); 
 	}

	while(fscanf(inFile,"%s %s %d %f %d",&priceorder[i].Scode,&priceorder[i].Sname,&priceorder[i].Ssale,
											&priceorder[i].Sprice,&priceorder[i].Sticket) != EOF)
{
	i++;
}
	number = i;//获得景点数 
	for(j = 1;j < number;j++)          //对景点通过价格排序 
        {for(i = 0;i < j;i++)         
            if(priceorder[i].Sprice > priceorder[j].Sprice)           
            {
                k = priceorder[i].Sprice;priceorder[i].Sprice = priceorder[j].Sprice;priceorder[j].Sprice = k;
                
                strcpy(temp1,priceorder[i].Sname); 
				strcpy(priceorder[i].Sname,priceorder[j].Sname); 
				strcpy(priceorder[j].Sname,temp1); //交换字符串 获得价格从小到大排序 
				
				strcpy(temp2,priceorder[i].Scode);
				strcpy(priceorder[i].Scode,priceorder[j].Scode);
				strcpy(priceorder[j].Scode,temp2);//交换字符串 获得对应的编号 
            }
		}
	printf("\n----------------------\n");
  	printf("景点按价格从低到高排序");
  	printf("\n----------------------\n");
  	for(i = 0;i < number;i++) printf("%s %s\n",priceorder[i].Scode,priceorder[i].Sname);
   	fclose(inFile);
    printf("您可选择\n1.输入编码查看景点详情\n2.直接预定\n3.返回景点菜单\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //转到预定函数 
		}
		else if(choose == 1)
		{
			printf("请输入景点代码：\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//检查是否为有效景点编号 
	 		{
	 			if(strcmp(priceorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n请输入正确的景点编号：\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	} 
	
}

 void T_spot_count_PriceOrder_FromHtoL()
 {
 	FILE *inFile;
 	int i = 0,j,choose,number = 0;
 	float k;
	char temp1[81];
 	char temp2[81];
 	char Choose[81]; 
 	struct spot priceorder[81];
 	inFile = fopen("spot.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n打开失败");
	 	exit(1); 
 	}
	 	while(fscanf(inFile,"%s %s %d %f %d",&priceorder[i].Scode,&priceorder[i].Sname,&priceorder[i].Ssale,
											&priceorder[i].Sprice,&priceorder[i].Sticket) != EOF)
{
	  i++;
}
	number = i;//获得景点数 
 	for(j = 1;j < number;j++)          //对景点通过价格排序 
        {for(i = 0;i < j;i++)         
        		if(priceorder[i].Sprice<priceorder[j].Sprice)           
            {
                k = priceorder[i].Sprice;priceorder[i].Sprice = priceorder[j].Sprice;priceorder[j].Sprice=k;
                
                strcpy(temp1,priceorder[i].Sname); 
				strcpy(priceorder[i].Sname,priceorder[j].Sname); 
				strcpy(priceorder[j].Sname,temp1); //交换字符串 获得价格从大到小排序 
				
				strcpy(temp2,priceorder[i].Scode);
				strcpy(priceorder[i].Scode,priceorder[j].Scode);
				strcpy(priceorder[j].Scode,temp2);//交换字符串 获得对应的编号 
            }
		}
	printf("\n----------------------\n");
	printf("景点按价格从高到低排序");
	printf("\n----------------------\n");
	for(i = 0;i < number;i++) printf("%s %s\n",priceorder[i].Scode,priceorder[i].Sname);
	fclose(inFile);
    printf("\n您可选择\n1.输入编码查看景点详情\n2.直接预定\n3.返回景点菜单\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //转到预定函数 
		}
		else if(choose == 1)
		{
			printf("请输入景点代码：\n");
			int verify = 0;
			i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//检查是否为有效景点编号 
	 		{
	 			if(strcmp(priceorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n请输入正确的景点编号：\n");
	 		}
	 	} 

			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	} 
 }

void T_spot_count_SalesOrder_FromLtoH()
 {
 	FILE *inFile;
 	int i = 0,j,k,choose,number = 0;
 	char temp1[81], temp2[81], Choose[81];
 	struct spot salesorder[81];
 	inFile = fopen("spot.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n打开失败");
		 exit(1); 
 	 }
	 	while(fscanf(inFile,"%s %s %d %f %d",&salesorder[i].Scode,&salesorder[i].Sname,&salesorder[i].Ssale,
											&salesorder[i].Sprice,&salesorder[i].Sticket) != EOF)
{
	  i++;
}
      number = i;//获得景点数 
      for(j = 1;j < number;j++)          //对景点销售量进行判断 
        {for(i = 0;i < j;i++)         
        		if(salesorder[i].Ssale>salesorder[j].Ssale)           
            {
            	k = salesorder[i].Ssale;salesorder[i].Ssale	=	salesorder[j].Ssale;salesorder[j].Ssale	=	k;
                strcpy(temp1,salesorder[i].Sname); 
				strcpy(salesorder[i].Sname,salesorder[j].Sname); 
				strcpy(salesorder[j].Sname,temp1); //交换字符串 获得销售量从小到大排序 
				
				strcpy(temp2,salesorder[i].Scode);
				strcpy(salesorder[i].Scode,salesorder[j].Scode);
				strcpy(salesorder[j].Scode,temp2);//交换字符串 获得对应的编号 
            }
		}
	printf("\n------------------------\n");
  	printf("景点按预定量从低到高排序");
  	printf("\n------------------------\n");
  	for(i = 0;i < number;i++) printf("%s %s\n",salesorder[i].Scode,salesorder[i].Sname);
  	fclose(inFile);
    printf("\n您可选择\n1.输入编码查看景点详情\n2.直接预定\n3.返回景点菜单\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
			T_spot_AttractionsInformation();
		else if(choose == 2)
			T_person_order_fillIn(); //转到预定函数 
		else if(choose == 1)
		{
			printf("请输入景点代码：\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//检查是否为有效景点编号 
	 		{
	 			if(strcmp(salesorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n请输入正确的景点编号：\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	} 
 }
 
void T_spot_count_SalesOrder_FromHtoL()
{
	FILE *inFile;
 	int i = 0,j,k,choose,number = 0;
 	char temp1[81];
 	char temp2[81];
 	char Choose[81]; 
 	struct spot salesorder[81];
 	inFile = fopen("spot.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n打开失败");
	 	exit(1); 
 	}
	while(fscanf(inFile,"%s %s %d %f %d",&salesorder[i].Scode,&salesorder[i].Sname,&salesorder[i].Ssale,
											&salesorder[i].Sprice,&salesorder[i].Sticket) != EOF)
{
	  i++;
}
      number = i;//获得景点数 
      for(j = 1;j < number;j++)   //对景点销售量进行判断          
        {for(i = 0;i < j;i++)         
            if(salesorder[i].Ssale<salesorder[j].Ssale)           
            {
                k = salesorder[i].Ssale;salesorder[i].Ssale = salesorder[j].Ssale;salesorder[j].Ssale = k;
                strcpy(temp1,salesorder[i].Sname); 
				strcpy(salesorder[i].Sname,salesorder[j].Sname); 
				strcpy(salesorder[j].Sname,temp1); //交换字符串 获得销售量从大到小排序 
				strcpy(temp2,salesorder[i].Scode);
				strcpy(salesorder[i].Scode,salesorder[j].Scode);
				strcpy(salesorder[j].Scode,temp2);//交换字符串 获得对应的编号 
            }
		}
	printf("\n------------------------\n");
  	printf("景点按预定量从高到低排序");
  	printf("\n------------------------\n");
   	for(i = 0;i < number;i++) printf("%s %s\n",salesorder[i].Scode,salesorder[i].Sname);
    fclose(inFile);
    printf("您可选择\n1.输入编码查看景点详情\n2.直接预定\n3.返回景点菜单\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //转到预定函数 
		}
		else if(choose == 1)
		{
			printf("请输入景点代码：\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//检查是否为有效景点编号 
	 		{
	 			if(strcmp(salesorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n请输入正确的景点编号：\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("输入错误！请从1、2、3中选择！\n"); 
			scanf("%d",&choose);
		} 
	} 
}

void T_spot_other_introduction(char spotChoice[])
{
	FILE *information;
	
	information = fopen("attractions.txt","r"); 
	
	if(information == 0)
	{
		printf("文件不存在");
		exit(1);
	}
	
	int i = 0;//计数 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//记录景点个数 
	i = 0;

	char attention[2][7] = {"000002", "000005"};

	while(i < num_spot)
	{
		if(strcmp(attraction[i].ID, spotChoice) == 0 && strcmp(attention[0],spotChoice) != 0 && strcmp(attention[1],spotChoice) != 0 ) 
		{
			printf("\n————————————————————\n");
			printf("\n%s\n\n景点介绍：%s\n\n建议游览时间：%s\n\n景点级别：%s\n\n旺季价格：%s\n\n淡季价格：%s\n\n学生票/老人票折扣：%s\n", attraction[i].name, attraction[i].intro, attraction[i].time, attraction[i].clas, attraction[i].Hprice, attraction[i].Lprice, attraction[i].discount);
			printf("\n————————————————————\n"); 
			break;
		}
		
		else if (strcmp(attraction[i].ID, spotChoice) == 0)
		{
			printf("\n————————————————————\n");
			printf("\n%s\n\n景点介绍：%s\n\n建议游览时间：%s\n\n景点级别：%s\n\n旺季价格：%s\n\n淡季价格：%s\n\n学生票/老人票折扣：%s\n", attraction[i].name, attraction[i].intro, attraction[i].time, attraction[i].clas, attraction[i].Hprice, attraction[i].Lprice, attraction[i].discount);
			printf("\n注意：该景点不适合老年人游览！");
			printf("\n————————————————————\n");
			break;
		}
		
		i++;
	}
	
	T_spot_other_bookInquire();//调用函数询问是否预订 	
} 

void T_spot_other_bookInquire()
{
	int choice;
	int verify;
	char z[5];
	
	printf("\n您想要现在进行预定吗？\n");
	printf("1.是 2.否(回到查询界面)\n");
		
	while(1)//容错 
	{
		verify = scanf("%d", &choice);
		
		if(verify == 1 && choice > 0 && choice < 3)
		break;
		
		else
		{
			gets(z);
			printf("请输入正确的编号：\n");
		}
	}
	
	switch(choice)
	{
		case 1:
  		  T_person_order_fillIn();
		  break;
		
		case 2:
		  T_spot_AttractionsInformation(); 
		  break;
	} 
}

void T_order_Information() //这里是旅游团订单管理 
{   
     int WayofSearch = 0;
     printf("\n您好，现在您可以输入代码，选择如下方式处理订单：\n");
     printf("1.取消预定\n");
	 printf("2.查询历史上的订单\n");
	 printf("3.返回主菜单\n");
	 scanf("%d",&WayofSearch);
	 while(1)
	 {
		if(WayofSearch == 1)
 		{
		 	T_order_add_CancelOrder();//取消订单子函数 
		 	break;
		 }
		else if(WayofSearch == 2)
		 {
 			T_order_check_HistoryOrder();//查询订单子函数 
 			break;
 		}
		else if(WayofSearch == 3)
 		{
		 	T_Menu();
		 	break;
		 }
		else
		 {
 			printf("输入错误！请从1-3中选择！\n"); 
			scanf("%d",&WayofSearch);
 		} 
 	} 
}

void T_order_add_CancelOrder()
{
	struct order ordercheck[81];
	int year,month,day,hour,minute,i = 0,icount=0,j=0;
	int nday,nyear,nhour,number;
	
	FILE *outFile;
 	outFile = fopen("order1.txt","r");
 	if(outFile == NULL)
	 {
 		printf("\n打开失败");
		 exit(1); 
 	}
 	
 	 time_t timep;//获取系统时间 
     struct tm *p;
     time (&timep);
     p = gmtime(&timep);
     nday = p->tm_yday;//获取当前天数 
     nyear = 1900+p->tm_year;//获取当前年份 
     nhour = 8+p->tm_hour;//获取当前时间
    
     printf("\n以下是您可以取消的订单（出行前24小时的订单才可取消）：\n");
     printf("\n—————————————————————————————————————————————————————————————————————————\n"); 
   	 printf("|订单编号\t\t|景点编号\t|预定时间\t\t|出行时间\t|未成年人人数（0-18)|成年人数(19-59)|老年人数（60—)|总票数|总价格|\n");
     printf("—————————————————————————————————————————————————————————————————————————\n"); 
 	while(fscanf(outFile,"%s %s %s %s %d %d %d %d %f",&ordercheck[i].Oordercode,&ordercheck[i].Ospotcode,&ordercheck[i].Odate,
	                                           &ordercheck[i].Ogodate,&ordercheck[i].Ochild,&ordercheck[i].Oadult,
											   &ordercheck[i].Oolds,&ordercheck[i].Ototal,&ordercheck[i].Oprice) != EOF)//因为订单数会变动 
	{
		i++;
	}
	 icount = i;
	for(i = 0;i<icount;i++)
	{
	j=T_order_check_HistoryOrder_select(ordercheck[i].Oordercode);
	sscanf(ordercheck[i].Ogodate,"%d:%d:%d:%d:%d",&year,&month,&day,&hour,&minute);//获取文件里的时间 
	number = T_order_add_Cancelorderdate(year,month,day);//计算文件中的天数，调用函数 
    if(nyear == year) //同一年 
   {if(nday < number&&nday == number --) 
   {if(nhour < hour && j == 1)//日期差一时间小 
   printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);}
   else if(nday < number&&nday != number --&&j ==1)
   printf("%s\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
											   
   }
  	else if(nyear == year --)//年末情况 跨年情况 
   {if((year % 4 == 0&&year % 100 != 0)||(year % 400 == 0))//闰年 
    {if(nday == 366&&number == 1)
     {if(nhour < hour&&j==1)
     printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);} 
	else if(nday < 366&&j==1)
     printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);}
   	else
     {
     	if(nday == 365&&number == 1)
     	{
	 	if(nhour < hour&&j==1)
        printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);}
   		else if(nday < 365&&j==1)
        printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
     }}
	else if(nyear < year--&&j==1)//相隔差一年以上 
 		printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
} 
	fclose(outFile);
	int choose;
	char ordercode[81];
	printf("—————————————————————————————————————————————————————————————————————————\n"); 
	printf("\n请选择你接下来想要进行的操作：\n1.取消订单\n2.返回订单管理页\n") ;//用户选择下一步 
	scanf("%d",&choose);
	while(1)
{
	if(choose == 1)
	{
		printf("请输入您想要取消的行程编号：");
	    scanf("%s",ordercode); 
	    T_order_add_Cancelordercancel(ordercheck,ordercode);//跳转取消订单子函 
	    break;
	}
	else if(choose == 2)
	{
		T_order_Information();
		break;
	}
	else
	{
		printf("输入错误！请从1和2中选择！\n"); 
		scanf("%d",&choose);
	}
	
}
}

void T_order_check_HistoryOrder()//历史订单查询 
{
	struct order ordercheck[81];
    int i = 0,choose,number = 0,j = 0,; 
    FILE *inFile;
 	inFile = fopen("order1.txt","r");
 	if(inFile ==NULL)
	 {
 		printf("\n打开失败");
		 exit(1); 
 	}
    printf("以下是您的历史订单：\n");
    printf("\n—————————————————————————————————————————————————————————————————————————\n"); 
    printf("订单编号\t\t景点编号\t预定时间\t\t出行时间\t未成年人人数（0-18) 成年人数(19-59) 老年人数（60—) 总票数  总价格\n");
 	printf("—————————————————————————————————————————————————————————————————————————\n"); 
	while(fscanf(inFile,"%s %s %s %s %d %d %d %d %f",&ordercheck[i].Oordercode,&ordercheck[i].Ospotcode,&ordercheck[i].Odate,
	                                           &ordercheck[i].Ogodate,&ordercheck[i].Ochild,&ordercheck[i].Oadult,
											   &ordercheck[i].Oolds,&ordercheck[i].Ototal,&ordercheck[i].Oprice)!=EOF)//读取文件 
	{
	   i++; 
     } 
     number = i;

     for(i = 0;i<number;i++)
	{
	int T_order_check_HistoryOrder_select(char []);
	j = T_order_check_HistoryOrder_select(ordercheck[i].Oordercode);
    if(j == 1)
   	 printf("%s\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
	}
	
	printf("—————————————————————————————————————————————————————————————————————————\n"); 

    fclose(inFile);
    printf("您可选择\n1.返回订单管理页面\n2.退出\n");//下一步操作 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_order_Information();//返回订单处理主菜单 
		}
		else if(choose == 2)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);
		}
		else
		{
			printf("输入错误！请从1和2中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 
}

int T_order_check_HistoryOrder_select(char ordercode[])
{
	
    int choose,number = 0,j = 0,wordsize1,wordsize2,T = 1; 
    
   
     wordsize1 = strlen(touristname);//用户名长度 
    wordsize2 = strlen(ordercode)-12;//订单中用户名长度 
	if(wordsize1 == wordsize2)
	{
	while(j < wordsize1)
	   {
	   if(touristname[j] != ordercode[j])
	   {
 		T = 0;
 		break;
	   }
    	else
    	j++;
	   }
	   }
    else
    	T = 0;

    	return(T);
}
void T_order_add_Cancelordercancel(struct order ordercheck[],char ordercode[])//订单删除子函 
{
	FILE *inFile;
	FILE *onFile;
	int i = 0,choose,tickettotal,number,T = 0;
	char ordercodes[81],godate[81];
  	inFile = fopen("order1.txt","r");
    onFile = fopen("temp.txt","w");
    
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
   
   
       while(fscanf(inFile,"%s %s %s %s %d %d %d %d %f",&ordercheck[i].Oordercode,&ordercheck[i].Ospotcode,&ordercheck[i].Odate,
	                                           &ordercheck[i].Ogodate,&ordercheck[i].Ochild,&ordercheck[i].Oadult,
											   &ordercheck[i].Oolds,&ordercheck[i].Ototal,&ordercheck[i].Oprice) != EOF)
     {
     	i++;
     }
     	 number = i;
     	 for(i=0;i<number;i++)
     	 {
 	     	if(strcmp(ordercheck[i].Oordercode,ordercode) == 0)
 	     	T = 1; 
 	     }
 	     if(T == 0)
 	     {
 			printf("\n您输入的订单号码有误，将返回上一页\n");
   			T_order_add_CancelOrder();
 	     }
 	     for(i = 0;i<number;i++)
     {
  	  	if(strcmp(ordercheck[i].Oordercode,ordercode) != 0)//检验是要删除的行吗?
       	fprintf(onFile,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);//不是则将这一行写入临时文件tmp.txt
      
        else if(strcmp(ordercheck[i].Oordercode,ordercode) == 0)
        {
		strcpy(ordercodes,ordercheck[i].Ospotcode);//删除订单票返回 
		tickettotal = ordercheck[i].Ototal;
		strcpy(godate,ordercheck[i].Ogodate);
        }
     }  
        fclose(inFile);
        fclose(onFile);
        remove("order1.txt");
        rename("temp.txt","order1.txt");
        printf("\n订单取消成功！\n");	
		T_order_add_Cancelordercancel_add1(ordercodes,tickettotal);
        T_order_add_Cancelordercancel_add2(ordercodes,tickettotal,godate);
     printf("\n您可选择\n1.返回订单管理页面\n2.退出\n");//下一步操作 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_order_Information();//返回订单处理子函 
		}
		else if(choose == 2)
		{
			printf("\n感谢使用本系统，祝您旅程愉快！\n"); 
			exit(1);
		}
		else
		{
			printf("输入错误！请从1和2中选择！\n"); 
			scanf("%d",&choose);
		} 
	   } 
}

int T_order_add_Cancelorderdate(int year,int month,int day)//计算文件中的天数 
  { 	
     int number;
  	if((year%4 == 0 && year%100 != 0)||(year%400 == 0))//闰年的情况 

   {

     switch(month)

     {

      case 1 :number = 0;break;

      case 2 :number = 31;break;

      case 3 :number = 60;break;

      case 4 :number = 91;break;

      case 5 :number = 121;break;

      case 6 :number = 152;break;

      case 7 :number = 182;break;

      case 8 :number = 213;break;

      case 9 :number = 244;break;

      case 10:number = 274;break;

      case 11:number = 305;break;

      case 12:number = 335;break; 

     }

     number = number + day;

   }

   else//非闰年 

   {

     switch(month)

     {

      case 1 :number = 0;break;

      case 2 :number = 31;break;

      case 3 :number = 59;break;

      case 4 :number = 90;break;

      case 5 :number = 120;break;

      case 6 :number = 151;break;

      case 7 :number = 181;break;

      case 8 :number = 212;break;

      case 9 :number = 243;break;

      case 10:number = 273;break;

      case 11:number = 304;break;

      case 12:number = 334;break; 

     }
      number=number+day;
	 }
	 return(number);
  }
  
void T_order_add_Cancelordercancel_add1(char spotscode[81],int saleticketcancel)
 {
 	int i = 0,newsale;
    struct spot dataWithTime[1000];
 	FILE *inFile;
    FILE *onFile;
    inFile = fopen("spot.txt","r");
    onFile = fopen("temp.txt","w");
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
   	while(fscanf(inFile,"%s %s %d %f %d",&dataWithTime[i].Scode,&dataWithTime[i].Sname,&dataWithTime[i].Ssale,
	                                  &dataWithTime[i].Sprice,&dataWithTime[i].Sticket) != EOF)
    {
    	if(strcmp(dataWithTime[i].Scode,spotscode) == 0)
    	{newsale = dataWithTime[i].Ssale-saleticketcancel;
    	fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,newsale,dataWithTime[i].Sprice,dataWithTime[i].Sticket);
    	}
		else
    	fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,dataWithTime[i].Sprice,dataWithTime[i].Sticket);
    	i ++;
    	
    }
     fclose(inFile);
     fclose(onFile);
        
     remove("spot.txt");
     rename("temp.txt","spot.txt");
 }
 
void T_order_add_Cancelordercancel_add2(char spotscode[81],int saleticketcancel,char orderdate[81] )
 {
 	int i = 0,newsale,year,month,hour,minute,filedate,day;
    struct spotdata dataWithTime[1000];
 	FILE *inFile;
    FILE *onFile;
    inFile = fopen("order2.txt","r");
    onFile = fopen("temp.txt","w");
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
    sscanf(orderdate,"%d:%d:%d:%d:%d",&year,&month,&day,&hour,&minute);//获取文件里的时间 
    filedate = year*10000+month*100+day;
   	while(fscanf(inFile,"%d %s %d %d", &dataWithTime[i].go_date, dataWithTime[i].go_spotID, 
	    								&dataWithTime[i].go_sales, &dataWithTime[i].go_totalsales) != EOF)
    {
    	if(strcmp(dataWithTime[i].go_spotID,spotscode) == 0&&dataWithTime[i].go_date == filedate)
    	{newsale = dataWithTime[i].go_sales-saleticketcancel;
    	fprintf(onFile,"%d\t%s\t%d\t%d\n", dataWithTime[i].go_date, dataWithTime[i].go_spotID, 
											newsale, dataWithTime[i].go_totalsales);
    	}
		else
    	fprintf(onFile,"%d\t%s\t%d\t%d\n", dataWithTime[i].go_date, dataWithTime[i].go_spotID, 
										dataWithTime[i].go_sales, dataWithTime[i].go_totalsales);
    	i++;
    	
    }
     fclose(inFile);
     fclose(onFile);
        
     remove("order2.txt");
     rename("temp.txt","order2.txt");
 
 } 
 
 
 
void T_person_order_fillIn()//游客预订门票主函数 接收登陆时ID 
{
	char* touristsID;
	//trcpy(touristsID, touristname);
	int total,sum;
	int children,adults,olds,students,kids,soldiers,fullTickets,halfTicket,sumTickets;
	
	printf("--------欢迎进入门票预订系统--------");
	 
	printf("\n请输入您所在旅游团的总人数： ");//记录该旅游团的总人数，年龄段及人员身份
	while(1)
	{
		char z[81];
		int verify;
		verify = scanf("%d",&total); 
		if(verify == 1 && total > 0)
		break;
		else 
		{
			gets(z);
			printf("\n人数不符合规范，请重新输入：");
		}
	} 
	
	// 统计各年龄段的人数 
	while(1)
	{
		printf("\n请分别输入对应年龄段的人数");
		printf("\n0~18岁（含18岁）:");
		scanf("%d",&children);
		printf("\n18~60岁："); 
		scanf("%d",&adults);
		printf("\n60岁（含60岁）以上:");
		scanf("%d",&olds);
		
		sum = children + adults + olds;
		if(sum == total)
		{
			break;
		}
		printf("\n————您输入的人数有误，请核对后重新输入————"); 
	}

	while(1)
	{
		//统计学生票人数 
		while(1)
		{
			printf("\n您需要的学生票张数：");
			scanf("%d",&students); 
		
			if(students <= total)
			{
				break;
			}
			printf("\n您输入的人数有误，请核对后重新输入"); 
		}
	
		//统计军人（免票）人数 
		while(1)
		{
			printf("\n您所在的团体中，军人有几位：");
			scanf("%d",&soldiers); 
		
			if(soldiers <= total)
			{
				break;
			}
			printf("\n您输入的人数有误，请核对后重新输入");
		} 
		
		//统计1.4米（包含1.4米）以下（免票）人数
		while(1)
		{
			printf("\n您所在的团体中,1.2米（含1.2米）以下的儿童有几位： ");
			scanf("%d",&kids);
		
			if(kids <= total)
			{
				break;
			}
			printf("\n您输入的人数有误，请核对后重新输入"); 
		}
		break;
	}
	
	char* T_person_order_idget();
	
	touristsID = T_person_order_idget();

	sumTickets = total;
	fullTickets = sumTickets - students - olds - soldiers - kids;
	halfTicket = students + olds;
	T_person_order_spotsChoose(sumTickets,fullTickets,halfTicket,olds,soldiers,children,adults,touristsID);
	
}

char* T_person_order_idget()
{
	char touristsID[2000];
	strcpy(touristsID, touristname);
	
	time_t timep;
	struct tm*p;
	time(&timep);
	p = gmtime(&timep);
		
	int yearNow, monthNow, dayNow, hourNow, minNow;
	yearNow = 1900+p->tm_year;
	monthNow = 1+p->tm_mon;
	dayNow = p->tm_mday;
	hourNow = 8+p->tm_hour;
	minNow = p->tm_min;
	
	char c_yearNow[5], c_monthNow[5], c_dayNow[5], c_hourNow[5], c_minNow[5];
	sprintf(c_yearNow, "%d", yearNow);
	sprintf(c_monthNow, "%02d",monthNow);
	sprintf(c_dayNow, "%02d",dayNow);
	sprintf(c_hourNow, "%02d",hourNow);
	sprintf(c_minNow, "%02d",minNow);
	
	strcat(touristsID, c_yearNow);
	strcat(touristsID, c_monthNow);
	strcat(touristsID, c_dayNow);
	strcat(touristsID, c_hourNow);
	strcat(touristsID, c_minNow);

	return touristsID;
}

void T_person_order_spotsChoose(int sumTickets,int fullTickets,int halfTicket,int olds,int soldiers,int children,int adults,char touristsID[])//选择景点并预订门票
{
	struct spot spot[1000];
	char selectedID[7];
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	fclose(outFile);
	int num_spot = i;//景点数+1
	
	//选择景点输入对应订单所需信息 
	printf("\n请选择您要预定的景点编号:\n");
	for(i = 0; i < num_spot; i++)
 		printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	
	int verify = 0;
	i = 0;
	while(1)
 	{
	 	scanf("%s", selectedID);
	 	
		for(i = 0; i < num_spot;  i++)//检查是否为有效景点编号 
	 	{
	 		if(strcmp(spot[i].Scode, selectedID) == 0)
			verify = 1;
	 	}
	 	
	 	if(verify == 1)
	 	break;
	 	else
	 	{
	 		i = 0;
	 		printf("\n请输入正确编号：\n");
	 	}
	 }
	 T_person_order_creat(selectedID, sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID);

}

void T_person_order_creat(char selectedID[], int sumTickets, int fullTickets, int halfTicket, int olds, int soldiers, int children, int adults, char touristsID[])
{	

	time_t timep;
	struct tm*p;
	time(&timep);
	p = gmtime(&timep);
		
	int tourDates, yearGo, monthGo, dayGo, yearNow, monthNow, dayNow, hourNow,minNow,verify, choice;
	char z[5];
	yearNow = 1900+p->tm_year;
	monthNow = 1+p->tm_mon;
	dayNow = p->tm_mday;
	hourNow = 8+p->tm_hour;
	minNow = p->tm_min;
	 
	int T_spot_count_Ticket_datecheek(int);//检验输入日期是否符合规范 
	printf("请输入想要查询的日期（格式如20180101）：\n");
 	while(1)
 	{
	 	verify = scanf("%d", &tourDates);
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(tourDates) == 1)
	 		{
		 		if(tourDates >= yearNow * 10000 + monthNow * 100 + dayNow)//判断是否为“当日”或之后日期
		 		  break;
		 		else printf("该日门票已过期，请重新输入日期: \n");
		 	}
	 		else printf("该日期不存在，请输入正确的日期: \n");
	 	}
	 	else
		{
			gets(z);
			printf("请输入格式正确的日期: \n");
		}
	 }
	 
	void T_person_order_datechange(int);
	T_person_order_datechange(tourDates);
	 
	yearGo = tourDates / 10000;
	monthGo = (tourDates - yearGo * 10000) / 100;
	dayGo = tourDates - yearGo * 10000 - monthGo * 100;
	
	int T_person_order_ticketVerify(char [], int, int);// 判断票余量是否充足的子函数
	if (T_person_order_ticketVerify(selectedID, sumTickets, tourDates) == 0)
	{
		printf("当前日期余票数不足，请选择：\n1.更改出行日期\n2.更换预订景点\n3.返回游客团体主菜单");
		char z[5];//容错 
		while(1)//容错
		{
			verify = scanf("%d", &choice);
			if(verify == 1 && choice > 0 && choice < 4)
			break;
			else
			{
				gets(z);
				printf("请输入正确的编号：\n");
			}
		}
		if(choice == 1)
		T_person_order_creat(selectedID, sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID); 
		else if(choice == 2)
		T_person_order_spotsChoose(sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID); 
		else
  		T_Menu();
		
	}
	else 
	printf("当前票余量充足可以进行预订\n"); 

	float price;
	price = T_person_order_price(fullTickets, halfTicket, soldiers, selectedID);//计算price

	printf("订单总票价为：%.2f\n", price);
	printf("1.确认预订\n2.取消（返回主菜单）\n请选择您接下来的操作：");
	
    int choose;
    scanf("%d", &choose);
    
	if(choose == 1)//将信息写入订单文件 
	{
		FILE *outFile_order = fopen("order1.txt","a");//打开具有外部名“order1.txt”的文件 
		if(outFile_order == NULL)//检测一次不成功的打开
		{
			printf("\n文件打开失败，请联系管理员\n");
			exit(1);		 
		}
	 	
		fprintf(outFile_order,"%s\t%s\t%d:%02d:%02d:%02d:%02d\t%02d:%02d:%02d:00:00",touristsID, selectedID, yearNow, monthNow, dayNow, hourNow, minNow, yearGo, monthGo, dayGo);//编号时间 
		fprintf(outFile_order,"\t%d\t%d\t%d\t%d\t%5.2f \n",children, adults, olds, sumTickets, price);//年龄段 人数 总价 
		fclose(outFile_order);
	
	printf("\n预订成功！");
	
	T_person_order_changeOrder2(selectedID, sumTickets, tourDates); 
	T_person_order_changespot(selectedID, sumTickets);
	T_person_order_inquire(sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID);//询问是否继续预订 
	}
	
	else T_Menu();
}

int T_person_order_ticketVerify(char selectedID[], int sumTickets, int tourDates)
{
	int T = 1;
	FILE *outFile_data = fopen("order2.txt", "r");//打开可读的每日景点售票情况文件
	if(outFile_data == NULL)
	{
 		printf("文件不存在");
		exit(1); 
 	}
 	
	int i = 0, j = 0;//计数
	
	while(fscanf(outFile_data, "%d %s %d %d", &dataWithTime[i].go_date, dataWithTime[i].go_spotID, &dataWithTime[i].go_sales, &dataWithTime[i].go_totalsales) != EOF)
	{
 		if(tourDates == dataWithTime[i].go_date)
 		{
		 	if(strcmp(selectedID, dataWithTime[i].go_spotID) == 0)
		 	{
	 			if(dataWithTime[i].go_totalsales - dataWithTime[i].go_sales < sumTickets)
	 			  T = 0;
	 		}
	 		else j++;
		 }
		 else j ++;
		 i ++; 
 	}
 	
 	if( i == j)
 	{
	 	struct spot spot[1000];
		 
		i = 0;
		FILE *outFile = fopen("spot.txt", "r");
	 	if(outFile == NULL)
	 	{
	 		printf("文件不存在");
	 		exit(1); 
	 	}
	 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 	  i ++;
	 	  
	 	fclose(outFile);
	 	int num_spot = i;//景点数+1
	 	for(i = 0; i < num_spot; i ++)
	 	{
	 		if(strcmp(spot[i].Scode,selectedID) == 0)
	 		  dataWithTime[j].go_totalsales = spot[i].Sticket;
	 	}
	 	if(dataWithTime[j].go_totalsales < sumTickets)
	 	  T = 0;
	} 	
 	
 	fclose(outFile_data);

	return(T);
}

float T_person_order_price(int fullTicket, int halfTicket, int soldiers, char selectedID[])
{
	struct spot spot[1000];
	float result, cut;
	
	FILE *information;
	
	information = fopen("attractions.txt","r"); 
	
	if(information == 0)
	{
		printf("文件不存在");
		exit(1);
	}
	
	int i = 0;//计数 
	while(fscanf(information, "%s %s %s %s %s %s %f %s %s %s %s\n",attract[i].PID, attract[i].Pname, attract[i].Pintro, attract[i].PHprice, attract[i].PLprice, attract[i].Ptime, &attract[i].Pdiscount, attract[i].Pclas, attract[i].Pnumber, attract[i].Parea, attract[i].Pfee) != EOF)
	{
		i ++;
	}
    fclose(information);
    int num_spot = i;//景点数+1
    for(i = 0; i < num_spot; i ++)
	{
		if(strcmp (attract[i].PID , selectedID) == 0)
		{
			cut = attract[i].Pdiscount;
		}
	}	
    
	
	i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	fclose(outFile);
 	
	for(i = 0; i < num_spot; i ++)
	{
		if(strcmp(spot[i].Scode, selectedID) == 0)
		{
			if(i == 0 || i == 2 || i == 3)
			
			result = spot[i].Sprice * fullTicket + spot[i].Sprice * cut *halfTicket; //算式 
			else result = spot[i].Sprice * ( fullTicket + soldiers) + spot[i].Sprice * cut *halfTicket;//算式 
		}
	}	
	return(result);
}

void T_person_order_changeOrder2(char selectedID[], int sumTickets, int tourDates)//景点编号，票数改变量，日期 
{
	int i = 0; 
	struct spot spot[1000];
	FILE *outFile = fopen("spot.txt", "r");//获取当日总票量 
 	if(outFile == NULL)
 	{
	 	printf("文件不存在");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	int num_spot = i;//景点数+1
 	fclose(outFile);
 	
 	FILE *outFile_data = fopen("order2.txt","r");//打开可读的具有外部名“order1.txt”文件 
	if(outFile_data==NULL)//检测一次不成功的打开
	{
		printf("\n文件打开失败，请联系管理员\n");
		exit(1);		 
	}
	int count_temp;
	i = 0;
	while(fscanf(outFile_data, "%d %s %d %d", &dataWithTime[i].go_date, &dataWithTime[i].go_spotID, &dataWithTime[i].go_sales, &dataWithTime[i].go_totalsales) != EOF)
		{
			i ++;
		}
		
	fclose(outFile_data);
	count_temp = i;
	
	FILE *inFile_data = fopen("order2.txt","w");//打开具有外部名“order1.txt”的文件
	int j = 0; 
	if(inFile_data==NULL)//检测一次不成功的打开
	{
		printf("\n文件打开失败，请联系管理员\n");
		exit(1);		 
	}
	for(i = 0; i < count_temp; i++)
	{
		if(dataWithTime[i].go_date == tourDates)
		{
			if(strcmp(dataWithTime[i].go_spotID, selectedID) == 0)
			{
				dataWithTime[i].go_sales += sumTickets;
				break;
			}
		}
	}
	if(i == count_temp)
	{
		dataWithTime[i].go_date = tourDates;
		strcpy(dataWithTime[i].go_spotID, selectedID);
		dataWithTime[i].go_sales = sumTickets;
		while(j < num_spot)
		{
			if(strcmp(selectedID, spot[j].Scode) == 0)
			{
				dataWithTime[i].go_totalsales = spot[j].Sticket;
				break;
			}
			else j ++;
		}
		for(i = 0; i <= count_temp; i ++)
		fprintf(inFile_data, "%d %s %d %d\n", dataWithTime[i].go_date, dataWithTime[i].go_spotID, dataWithTime[i].go_sales, dataWithTime[i].go_totalsales);
	}
	else
	{
		for(i = 0; i < count_temp; i ++)
		fprintf(inFile_data, "%d %s %d %d\n", dataWithTime[i].go_date, dataWithTime[i].go_spotID, dataWithTime[i].go_sales, dataWithTime[i].go_totalsales);
	} 
	fclose(inFile_data);
	
}

void T_person_order_changespot(char selectid[], int sumTickets)
{		
	int i = 0;
 	FILE *inFile;
	FILE *onFile;
	struct spot data[1000];
	
    inFile=fopen("spot.txt","r");
    if(inFile==NULL )
    {
        printf("\n打开失败\n");
        exit(1);
    }
    while(fscanf(inFile,"%s %s %d %f %d",data[i].Scode,&data[i].Sname,&data[i].Ssale,&data[i].Sprice,&data[i].Sticket)!=EOF)
	  i ++;
	fclose(inFile);
	
    int num_spot = i; 
    
    for(i = 0; i < num_spot; i++)
    {
    	if(strcmp(selectid, data[i].Scode) == 0)
    	{
	    	data[i].Ssale += sumTickets;
	    	break;
	    }
    }
    
    onFile=fopen("spot.txt","w"); 
	if(onFile==NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
    
    for(i = 0; i < num_spot; i ++)
      fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",data[i].Scode,data[i].Sname,data[i].Ssale,data[i].Sprice,data[i].Sticket);
      
    fclose(onFile);

}

void T_person_order_inquire(int sumTickets, int fullTickets, int halfTicket, int olds, int soldiers, int children, int adults, char touristsID[])
{
	int choice;
	printf("\n您是否还要继续预订其他景点：\n1.是\n2.否（返回游客团体主菜单）");
	scanf("%d",&choice);
	
	while(1)
	{
		if(choice==1||choice==2)
		{
			break;
		}
		printf("您输入的编号有误，请重新选择");
		scanf("%d",&choice);	 
	}	
	if(choice==1)
	{
		void T_person_order_spotsChoose(int,int,int,int,int,int,int,char[]);
		T_person_order_spotsChoose(sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID);
	}
	

	else 
	T_Menu(); 
}
 
void T_person_order_datechange(int tourDates)//按淡旺季进行改变价格以及总票数 
 {  
    int i=0;
	float price1[8]={30.00,260.00,60.00,40.00,10.00,175.00,130.00,100.00};
 	float price2[8]={20.00,260.00,40.00,20.00,10.00,175.00,130.00,100.00};
  	int ticket1[8]={200,200,200,200,100,100,100,100};
   	int ticket2[8]={100,100,100,100,200,200,200,200};
 	struct spot dataWithTime[1000];
	int verify,usedate;
	
  	FILE *inFile;
	FILE *onFile;
    inFile=fopen("spot.txt","r");
    onFile=fopen("temp.txt","w");
	 
	if(inFile==NULL || onFile==NULL)
    {
        printf("\n打开失败\n");
        exit(1);
    }
    
	usedate=tourDates -2018*10000;
	while(fscanf(inFile,"%s %s %d %f %d",&dataWithTime[i].Scode,&dataWithTime[i].Sname,&dataWithTime[i].Ssale,
	                                  &dataWithTime[i].Sprice,&dataWithTime[i].Sticket)!=EOF)
  {
     	if(i<8)
   	{
         if(usedate>=401&&usedate<=1031)
	     fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,price1[i],ticket1[i]);
	     else
	     fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,price2[i],ticket2[i]);
      	
      }
         else
         fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",dataWithTime[i].Scode,dataWithTime[i].Sname,dataWithTime[i].Ssale,dataWithTime[i].Sprice,dataWithTime[i].Sticket);
         i++;
  }
     
        fclose(inFile);
        fclose(onFile);
        
        remove("spot.txt");
        rename("temp.txt","spot.txt");
        
} 
