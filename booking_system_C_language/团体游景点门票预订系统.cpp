
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h> 

void mainInterFace();//ϵͳ�����棬�����˳���¼ 
void T_TouristsInterface();//�ο͵�¼���� 
void T_person_login();//��֤�û����������Ƿ���ȷ 
void T_Menu();//�οͲ�ѯ 
void T_person();//������Ϣ����
void T_person_check();//������Ϣ��ѯ 
void T_person_change();//������Ϣ�޸� 
void T_person_change_password();//�����޸� 
void T_person_change_phone();//�绰�޸� 
void T_person_change_mail(); //�����޸� 
void T_person_register();//�û�ע�� 
int T_person_register_formatVerify_id(char[]);//����ʽ 
int T_person_register_formatVerify_phone(char[]); 
int T_person_register_duplicateCheck(char[]);//�û������� 

void T_spot_AttractionsInformation();//�ο������½����� 
void T_spot_SettingRecommend();//�����Ƽ����� 
void T_spot_count_ByNameInquire();//����ͨ�����Ʋ�ѯ�ĺ���
void T_spot_count_Ticket();//����ͨ���Ƿ���Ʊ��ѯ�ĺ���
int T_spot_count_Ticket_datecheek(int);//�������������Ƿ���Ϲ淶 
void T_spot_count_ScenicArea();//����ͨ�������ѯ�ĺ��� 
void T_spot_count_ScenicArea_check(char[]);
void T_spot_count_Discount();//����ͨ���ۿ���Ϣ��ѯ�ĺ���
void T_spot_count_Discount_1();//����ѧ��Ʊ������Ʊ�ľ��� 
void T_spot_count_PriceOrder_FromLtoH();//���ֲ�ͬ�ŷ� 
void T_spot_count_PriceOrder_FromHtoL();
void T_spot_count_PriceOrder();//�������ݼ۸����򾰵� 
void T_spot_count_PriceOrder_datechange();//���ݵ������ı�۸��Լ���Ʊ�� 
void T_spot_count_SalesOrder_FromLtoH();//���ֲ�ͬ�ŷ� 
void T_spot_count_SalesOrder_FromHtoL();
void T_spot_count_SalesOrder();//��������Ԥ�������򾰵� 
void T_spot_other_bookInquire();//ѯ���Ƿ�Ԥ�� 
void T_spot_other_introduction(char []);//�����������

void T_order_Information();//�ο��Ŷ����ܽ��� 
int T_order_add_Cancelorderdate(int,int,int);//�����ļ��е�����
void T_order_add_CancelOrder();//ȡ������ 
void T_order_check_HistoryOrder();//�鿴���� 
int T_order_check_HistoryOrder_select(char []);//ɸѡ���û�����Ӧ�Ķ��� 
void T_order_add_Cancelordercancel(struct order [], char []);//����ɾ���Ӻ�
void T_order_add_Cancelordercancel_add1(char[],int);//������Ʊ�� 
void T_order_add_Cancelordercancel_add2(char[],int,char[]);//������Ʊ�� 

void T_person_order_fillIn();//�ο��Ŷ������� 
void T_person_order_spotsChoose(int, int, int, int, int, int, int, char[]);//����ѡ�� 
void T_person_order_creat(char[], int, int, int, int, int, int, int, char[]);//ѡ��ʱ�����ɶ��� 
float T_person_order_price(int, int, int, char[]);//���㵥���ܼ�
void T_person_order_changeOrder2(char[], int, int);//�޸�order2���� 
void T_person_order_changespot(char[], int);//�޸�spot���� 
void T_person_order_inquire(int, int, int, int, int, int, int, char[]);//ѯ���Ƿ����Ԥ�� 

void A_Admininterface();// ����Ա����
void A_person();//����Ա������Ϣ 
void A_spot();// ����Ա������Ϣ 
void A_order();//����Ա������Ϣ 
void A_order_check();//�������Ա-��ʷ������ѯ����
void A_order_count();//�������Ա-ͳ�ƶ������� 
void A_order_count_num();//���밴Ԥ�����������
void A_order_count_peopleQuery();//��������������н��� 
void A_order_count_propit();//���뾰����������ҳ�� 
void A_order_count_age();//�������Ա��������ͳ��
void A_order_count_sale();//�������Ա-�Բ�ͬ���Ȳ�ͬ�����������
void A_order_count_choose();//�ṩ���ع���Ա����ͳ����Ϣ����
void A_order_count_sale_paixu();//�������Ա���Բ�ͬ���������������������Ӻ���
void A_order_count_sale_check();//�жϾ����ļ��Ƿ���ȷ�� 
void A_order_count_age_fileCheck();//�ж϶����ļ��Ƿ���ȷ�� 
void A_person_change_password();//������Ϣ�޸ļ������ 
void A_person_change();//������Ϣ�޸� 
void A_person_change_email();//������Ϣ�޸ļ������ 
void A_spot_check();//������Ϣ�鿴 
void A_spot_add();//������� 
void A_spot_add_ID();//�������-���ID 
void A_spot_add_name();// �������-������� 
void A_spot_add_change();//���㷢��ǰ�����޸� 
int A_spot_count_spotline();// ����attractions�ļ����� 
void A_spot_add_change1();//д��spot�ļ� 
void A_spot_add_change2();//д��spot�ļ� 
void A_spot_add_change3();//��Ӿ����ȡ�� 
int A_order_count_spotline();//����spot.txt������ 
int A_order_count_order1line();//����order1.txt������ 

char touristname[20],touristpassword[20];//�û����Լ����� 
char *settings[21];

struct T_account
{
	char idNum[11];
	char password[20];
	int peopleNum;
	int studentNum, adultNum, oldsNum;//������ 
 	char phoneNum[12], emailNum[81];
};

struct spot//������� 
{
	char Scode[7];//������� 
    char Sname[81];//�������� 
	int Ssale;//���������� 
	float Sprice;//����Ʊ���� 
	int Sticket;//����Ʊ���� 	
};

struct order//�������� 
{
	char Oordercode[81];//�������� 
	char Ospotcode[81];//�����еľ������� 
	char Odate[81];//Ԥ������ 
	char Ogodate[81];//�������� 
	int Ochild;//�����ж�ͯ���� 
	int Oadult;//�����г������� 
	int Oolds;//�����е��������� 
	int Ototal;//�����е������� 
	float Oprice;//һ�ݶ����е�������ļ۸� 
};

struct//����������� 
{
	char Ospotcode[81];//�����еľ������� 
    float Oprofit;//һ������������� 
}profit[81],temp2;

struct//����Ԥ�������� 
{
	char name[20];//ͳ��Ԥ�����еľ������� 
	int cline;//ͳ��Ԥ�����еĵ�������Ķ�����Ŀ 

}c[81],temp3;

struct//����Ա������Ϣ 
{
	char name[20];//���� 
	char password[20];//���� 
	char phone[20];//��ϵ�绰 
	char mail[20];//���� 
}admin;

struct//�����ȶԲ�ͬ����������� 
{ 
	char name[20];//�������� 
  	int month1;//��һ���ȵ����� 
  	int month2;//�ڶ����ȵ����� 
  	int month3;//�������ȵ����� 
  	int month4;//���ļ��ȵ����� 
}m[81],temp4,temp5,temp6,temp7;

struct attraction1 //������Ϣ 
{
	char ID[1000];//����ID 
	char name[1000];// �������� 
	char intro[1000];//������ 
	char Hprice[1000];//�����۸�
	char Lprice[1000];//�����۸�
	char time[1000];//��������ʱ�� 
	char discount[1000];//�����ۿ���Ϣ 
	char clas[1000];//���㼶�� 
	char number[1000];//������������ 
	char area[1000];//�������ڵ��� 
	char fee[1000];//����ά������ 
}attraction[81]; 

struct attraction3 //������Ϣ���۸�����ã� 
{
	char PID[1000];//����ID 
	char Pname[1000];// �������� 
	char Pintro[1000];//������ 
	char PHprice[1000];//�����۸�
	char PLprice[1000];//�����۸�
	char Ptime[1000];//��������ʱ�� 
	float Pdiscount;//�����ۿ���Ϣ 
	char Pclas[1000];//���㼶�� 
	char Pnumber[1000];//������������ 
	char Parea[1000];//�������ڵ��� 
	char Pfee[1000];//����ά������ 
}attract[81];

struct attraction2//������� 
{
	char Scode[7];//������� 
    char Sname[81];//�������� 
	char Ssale[81];//���������� 
	char Sprice[81];//����Ʊ���� 
	char Sticket[81];//����Ʊ����
};
struct spotdata
{
	int go_date;
	char go_spotID[7];
	int go_sales;
	int go_totalsales;
} dataWithTime[1000];//��ʾ��ͬʱ�䲻ͬ����Ʊ������Ľṹ���� 

int main()
{
  	printf("����������ӭ���������ξ�����ƱԤ��ϵͳ��������\n");
  	mainInterFace();
  	return 0; 
}

void mainInterFace()
{
	printf("\n��ѡ��������ݣ�\n1.������\n2.����Ա\n");
	int verify;
	int choose;
	char z[5];//�ݴ� 
 
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &choose);
  
		if(verify == 1 && 0 < choose < 3)
		break;
  
		else 
		gets(z);
   
		printf("��������ȷ�ı�ţ�\n");
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

void A_Admininterface()//����Ա������ 
{
	void A_login();//����Ա��¼���� 
		A_login();
	
	void A_check();//����Ա��ѯ���� 
		A_check();
	
}

void A_login()//�������Ա��¼���� 
{
	FILE*adminfile = fopen("admin.txt","a+");
	//�򿪹���Ա��Ϣ�洢�ļ�
	
	if(adminfile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	char adminname[20],adminpassword[20];
	printf("\n--------------------\n");
	printf("�������û�����\n");
	scanf("%s",&adminname);
	printf("���������룺\n");
	scanf("%s",&adminpassword);
	printf("--------------------\n");
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
	
	//��֤�û����������Ƿ���ȷ
	if(strcmp(adminname,admin.name) == 0 && strcmp(adminpassword,admin.password) == 0) 
	{
		printf("���ѵ�½�ɹ���\n");
		fclose(adminfile);
	
	}

	else
	{
		printf("\n��������˺Ż������������������룡\n");
		A_login();
	}
}

void A_check()//����Ա��ѯ���� 
{
	int choose = 0;
	printf("\n������ѡ��һ�²�����");
	printf("\n1.������Ϣ\n2.������Ϣ\n3.������Ϣ\n4.�˳���¼\n5.�˳�ϵͳ\n��ѡ�����������Ĳ�����\n");
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
   	printf("\n��������ȷ�ı�ţ�\n");
  }
 }
	
	switch(choose)
	{
		case 1:
			A_person();//����Ա������Ϣ 
			break;
		
		case 2:
			A_spot();//����Ա������Ϣ 
			break;
		
		case 3:	
			A_order();//����Ա������Ϣ 
			break;
		case 4:
			mainInterFace();//����Ա������ 
			break;
		default:
			printf("��л��ʹ�ø�ϵͳ��ף������˳����"); 
			exit(1);
	}
}


void A_person()//����Ա������Ϣ 
{
	int num;
	FILE*outfile;
	outfile = fopen("admin.txt","r");
	if(outfile == NULL)//�ж��ļ��Ƿ�����ȷ�� 
   {
   	printf("\n��ǰ������Ϣ�ļ�������ȷ�򿪣�\n");
   	exit(1);
   }
 	fscanf(outfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
 	fclose(outfile);
 	printf("---------------------------");
 	printf("\n���������ĸ�����Ϣ��\n"); 
	printf("\n�û�ID��%s\n\n���룺%s\n\n��ϵ�绰��%s\n\n���䣺%s\n",admin.name,admin.password,admin.phone,admin.mail);
	printf("---------------------------\n");
	printf("��ѡ��������Ĳ���\n1.�޸ĸ�����Ϣ\n2.����\n\n");
	int choice;
	int verify;
 	char z[81];
 
	while(1)//�ݴ� 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 3)
 	 	break;
 
 	 else
  {
   		gets(z);
   		printf("\n�����������������������ȷ�ı�ţ�\n");
  }
	} 
    
	if(choice == 1)
	{
		printf("\n��ӭ���������Ϣ�޸Ľ��棡\n");
		printf("-------------------------\n");
		A_person_change(); 
	
	}
	else
		A_check();
}

void A_person_change()//������Ϣ�޸� 
{
	int choice;
	printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n");	
	printf("1.����\n2.����\n3.������һ��\n");
	 
	int verify;
 	char z[81];
 
	while(1)//�ݴ� 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 4)
 		break;
 
 	 else
  {
   		gets(z);
   		printf("\n�����������������������ȷ�ı�ţ�\n");
   		printf("1.����\n2.����\n3.������һ��\n");
  }
	} 
	switch(choice)
	{
		case 1:
		 A_person_change_password();//�޸����� 
		 break;
		
		case 2:
		 A_person_change_email();//�޸����� 
		 break;
		
		default:
		 A_person();;//������һ�� 
		
	}
}

void A_order()//�������Ա������ѯ���� 
{
	
	
	int choose;
	printf("\n��ӭ�������Ա������Ϣ���棡\n");
	printf("-----------------------------\n");
	printf("����Ϊ�����Խ��еĲ�����\n");
	printf("1.�鿴��ʷ����\n2.ͳ�ƶ�����Ϣ\n3.������һ����\n��������Ҫ��ѯ����Ϣ��");
	int verify;
    char z[81];//�ݴ� 
 while(1)//�ݴ� 
 {
  verify = scanf("%d", &choose);
  
  if(verify == 1 && 0 < choose && choose < 4)
  		break;
  
  else
  {
   		gets(z);
   		printf("\n\n��������ȷ�ı�ţ�");
  }
 }
	switch(choose)
	{
		case 1://�������Ա-�鿴��ʷ���� 
			A_order_check();
			break;
		case 2://�������Ա-ͳ�ƶ�����Ϣ 
			A_order_count();
			break;
		case 3://�������Ա-�˳� 
			A_check(); 
			break;
		default:
			A_order();
		
	}
}

void A_order_check()//�������Ա-��ʷ������ѯ���� 
{
   int ordernum,spotnum,peoplenum,money,choose;
   char orderdate[20],godate[20],age[20],ident[20];
   struct order order[81];
  
   printf("\n\n��ӭ�������Ա��ʷ������ѯ���棡\n");
   printf("---------------------------------------\n");
   printf("����Ϊ��ʷ������Ϣ��\n\n")	;
   FILE *outFile;
   outFile = fopen("order1.txt","r");
   if(outFile == NULL)//�ж��ļ��Ƿ�����ȷ�� 
   {
   	printf("\n��ǰ������Ϣ�ļ�������ȷ�򿪣�\n");
   	exit(1);
   }
   //����Ӧ��ʽ����Ļ�����������Ϣ 
   printf("---------------------------------------------------------------------------------------------------------\n");
   printf("�������      | ������ |    Ԥ������   |    ��������     | ��ͯ | ���� | ���� | ������ | �ܼ۸�   \n");
   printf("---------------------------------------------------------------------------------------------------------\n");
   int i = 0;
  

 
while(fscanf(outFile,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice) != EOF)
   { 	
 	printf("%s %8s %16s %12s %6d %6d %6d %7d %10.2f\n",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,order[i].Ochild,order[i].Oadult,order[i].Oolds,order[i].Ototal,order[i].Oprice);
 	i ++;	
	 }
   
   fclose(outFile);
   //���û��ṩ���ز��� 
   printf("---------------------------------------------------------------------------------------------------------");
   printf("\n\n��ѡ��������Ĳ���\n1.����\n2.���ڵ�ǰ����\n");
   int verify;
 char z[5];//�ݴ� 
 
 while(1)//�ݴ� 
 {
  verify = scanf("%d", &choose);
  
  if(verify == 1 && 0 < choose && choose <3)
  		break;
  
  else
  {
   		gets(z);
   		printf("��������ȷ�ı�ţ�\n");
  }
 }
   if(choose == 1)
   		A_order();//����Ա������Ϣ 
   
    
}

void A_person_change_password()//�������Ա���桪�޸Ĺ���Ա���� 
{
	char afterpassword[20],newpassword[20];
	int choice;
	//�ж��ļ��Ƿ���ȷ�� 
	FILE*adminfile = fopen("admin.txt","r");
	
	 if(adminfile == NULL)//�ж��ļ��Ƿ�����ȷ�� 
   {
   	printf("\n��ǰ������Ϣ�ļ�������ȷ�򿪣�\n");
   	exit(1);
   }
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail); 
	fclose(adminfile);
	//�޸����� 
	printf("\n���������޸�Ϊ��\n");
	scanf("%s",afterpassword);
	
	printf("\n���ٴ�ȷ�����룺\n");
	scanf("%s",admin.password);
	
	while(1)
	{
	if (strcmp(afterpassword,admin.password) == 0)
		break;
	else
	{
		printf("\n������������벻һ��\n");
		printf("����������\n");
		printf("\n���������޸�Ϊ��\n");
		scanf("%s",afterpassword);
	
		printf("\n���ٴ�ȷ�����룺\n");
		scanf("%s",admin.password);
	}
	}
	adminfile = fopen("admin.txt","w");
	fprintf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
	printf("\n�����޸ĳɹ���\n");	
	fclose(adminfile);
		
	A_person();;//�ṩ������һ��������
}
void A_person_change_email()//�������Ա�������޸� 
{
	char input[20];
	FILE*adminfile = fopen("admin.txt","r");
	
	//�ж��ļ��Ƿ���ȷ�� 
	if(adminfile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	fscanf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);

	fclose(adminfile);
	
   // �޸����� 
	
	printf("\n���������޸�Ϊ��\n");
	
	while(1)
	{
	scanf("%s",input);
	//��֤�����ʽ���Ϲ淶 
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
		printf("\n�������ʽ��Ч�����������룺");
	}
	
	else
	{	
        strcpy(admin.mail,input);
        adminfile = fopen("admin.txt","w");
		fprintf(adminfile,"%s %s %s %s",admin.name,admin.password,admin.phone,admin.mail);
		fclose(adminfile);
		printf("\n�޸ĳɹ���\n");
		
		A_person(); //��ת��һ��  
		break;                  
	}
	} 
}

void A_spot()//����Ա������Ϣ 
{
	int choice,attractionchoice;
	
	
	printf("\n��ӭ�������Ա������Ϣ����!\n");
	printf("-------------------------------\n");
	printf("�����Խ���һ�²�����\n");
	printf("1.��ѯ������Ϣ.\n2.��Ӿ���.\n3.����.\n(��ѡ��1.2.3.)\n");

	int verify;
 	char z[5];//�ݴ� 
 
	while(1)//�ݴ� 
 {
  verify = scanf("%d", &attractionchoice);
  
  	if(verify == 1 && 0 < attractionchoice && attractionchoice < 4)
  	break;
  
 	 else
  {
  	 gets(z);
  	 printf("��������ȷ�ı�ţ�\n");
  }
 }
	 
	 switch(attractionchoice)
	 {
 		case 1://��ѯ 
 		{
		 	A_spot_check();
		 }
		 break;
		 
		 case 2://���
		 {
 			A_spot_add();
 		} 
 		break;
 		
 		case 3://����
		 {
 			A_check();
 		} 
 		break;
 		
 		default:
	 	A_spot();
 	}
}

void A_spot_check()//��ѯ���о�����Ϣ 
{
	int i,a,choice;
	printf("��ӭ�����ѯ������Ϣ\n");
	printf("---------------------\n");
	printf("����Ϊ����Ļ�����Ϣ��\n");
	
	FILE*infile;
	infile = fopen("attractions.txt","r");//�򿪾�����Ϣ�����ļ� 
	
	if(infile == NULL)//���һ�β��ɹ��Ĵ� 
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	a = A_order_count_spotline(); 
	
	for(i = 0;i < a;i ++)//��������Ϣ��� 
	{
	while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee) != EOF)
	{
		printf("\n-------------------------------------------------------------------------------------------------------------------\n");
		printf("\n����ID:%s\n\n����:%s\n\n��飺%s\n\n�����۸�Ԫ����%s\n\n�����۸�%s\n\n��������ʱ�䣺%s\n\nѧ��Ʊ/����Ʊ�ۿۣ�%s\n\n��������%s\n\n����������Ʊ�����ˣ���%s\n\n��������%s\n\nά�����ã�Ԫ����%s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	}
	}
	fclose(infile);//�ر��ļ� 
	printf("\n��ѡ����������Ĳ�����\n");
	printf("1.��Ӿ���\n2.����\n");
		int verify;
 	char z[5];//�ݴ� 
 
	while(1)//�ݴ� 
 {
  verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice < 3)
  	break;
  
 	 else
  {
  	 gets(z);
  	 printf("��������ȷ�ı�ţ�\n");
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
	
	//������һ�� 
}


void A_spot_add()//��Ӿ��� 
{
	int choice,a,i,j,N,M,T = 1;
	FILE*file2,*infile;
	char enternum[10];
	char entername1[10];
	infile = fopen("attractions.txt","r");
	//�ж��ļ��Ƿ���ȷ�� 
	if(infile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	i = 0;
	a = A_order_count_spotline();

	for(i = 0;i < a;i ++)
	fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
    fclose(infile);
    
	printf("\n��ӭ������Ӿ�����Ϣ\n");
	printf("--------------------------\n");
	
	printf("��������ӵľ���ID(��λ�ַ���:\n"); 
	scanf("%s",enternum);
		
	while(1)	
	{
		if(strlen(enternum) != 6)//���ID�Ƿ񳤶�Ϊ6 
    	T = 0; 

	for(i = 0;i < a;i ++)//���ID�Ƿ��ظ� 
	{ 
		if(strcmp(enternum,attraction[i].ID) == 0)
		{
			T = 0;
		}
	}
	if(T == 0)
	{
		T = 1;
		printf("\n��Ÿ�ʽ�����þ������ѱ�ʹ�ã�����������\n");
	scanf("%s",enternum);
	}
	else 
	break;
 }
	strcpy(attraction[a].ID,enternum);
	printf("\n��������ӵľ�������:\n");
	scanf("%s",entername1);
	while(1)
 {
	for(i = 0;i < a;i ++)
	{ 
		if(strcmp(entername1,attraction[i].name) == 0)
		{
		printf("\n�þ��������Ѵ��ڣ�����������\n");
		scanf("%s",entername1);
		
		}
	}
	break;
 }
	strcpy(attraction[a].name,entername1);
	
	//�򿪾�����Ϣ�����ļ� 
	
	printf("\n�����뾰���飻\n");
	scanf("%s",attraction[a].intro);
	printf("\n�����뾰�������۸�(Ԫ����\n");
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
		printf("\n������������������������룡\n");
	    scanf("%s",attraction[a].Hprice);
		}
		else
		break;  
	}
	printf("\n�����뾰�㵭���۸�(Ԫ����\n");
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
			printf("\n������������������������룡\n");
	    	scanf("%s",attraction[a].Lprice);
		}
		else
			break;  
	}

	printf("\n������þ�����������ʱ�䣨Сʱ����\n");
	scanf("%s",attraction[a].time);
	printf("\n������þ�����ۿ���Ϣ��\n");
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
	 printf("������������д������븡������"); 
	 scanf("%s",attraction[a].discount);	
	}
	else
	break;
	} 
	
	printf("\n������þ�������\n");
	scanf("%s",attraction[a].clas);
	printf("\n������þ��㵥����Ʊ�����ˣ���\n");
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
		printf("\n������������������������룡\n");
	    scanf("%s",attraction[a].number);
		}
		else
		break;  
	}
	printf("\n������þ�������\n");
	scanf("%s",attraction[a].area);
	printf("\n������þ���ά��������ã�Ԫ����\n");
	scanf("%s",attraction[a].fee); 
	
	//������ӵ���Ϣд���ļ�
	infile = fopen("attractions.txt","w");
		//�ж��ļ��Ƿ���ȷ�� 
	if(infile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	for(i = 0;i < a+1;i ++)
		fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile); 
	printf("\n���ѳɹ�\n"); 
	printf("--------------------------------------------\n");
	A_spot_add_change1();
	printf("����ϣ�����������޸���(������1��2��3��\n");
	printf("1.���޸�\n2.ȡ����Ӳ�����\n3.�����Ӳ�����\n");

	
	int verify;
 	char z[5];//�ݴ� 
 
 	while(1)//�ݴ� 
 {
  	verify = scanf("%d", &choice);
  
  	if(verify == 1 && 0 < choice && choice< 4)
 	 break;
  
  	else
  {
 		gets(z);
 		printf("��������ȷ�ı�ţ�\n");
  }
 }

switch(choice)
	{
		case 1:
			A_spot_add_change();//���������޸� 
			break;
		
		case 2:
	    	A_spot_add_change3();//��Ӿ����ȡ�� 
	    	A_spot();//������һ��
			break; 
		
		case 3:
			A_spot();//������һ��
		
		default:
			A_spot();//������һ��
	}
}

void A_spot_add_change()//�ڷ���֮ǰ�����޸� 
{
	int choce,choice,choice1,i,a,T,j,M;
	FILE*infile = fopen("attractions.txt","r");//�򿪾�����Ϣ�����ļ� 
	
	if(infile == NULL)//���һ�β��ɹ��Ĵ� 
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	a = A_order_count_spotline();
	for(i = 0;i < a;i ++)
	fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
	printf("\n\n--------------------------\n");
	printf("���������޸�ʲô��Ϣ��\n");
	printf("1.ID\n2.����\n3.���\n4.�����۸�Ԫ��\n5.�����۸�Ԫ��\n6.��������ʱ�䣨Сʱ��\n7.�ۿ���Ϣ\n8.����\n9.���վ�����Ʊ�����ˣ�\n10.����\n11.ά��������ã�Ԫ��\n");
    printf("\n��ѡ������Ҫ���еĲ�����������1~11����ѡ��"); 
	int verify;
 	char z[5];//�ݴ� 
 
 	while(1)//�ݴ� 
 {
	verify = scanf("%d", &choce);
  
 	if(verify == 1 && 0 < choce && choce < 12)
  		break;
  
  	else
  {
   		gets(z);
   		printf("\n\n��������ȷ�ı�ţ�\n");
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
      	 	printf("\n�����޸�Ϊ��\n");
      	 	scanf("%s",enternum);
	        
	while(1)	
	{
	if(strlen(enternum)!=6)//���ID�Ƿ񳤶�Ϊ6 
    	T = 0; 

	for(i = 0;i < a;i++)//���ID�Ƿ��ظ� 
	{ 
		if(strcmp(enternum,attraction[i].ID) == 0)
		{
			T = 0;
		}
	}
		if(T == 0)
	{
		T = 1;
		printf("\n��Ÿ�ʽ�����þ������ѱ�ʹ�ã�����������\n\n");
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
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",enternum1);
			while(1)
 {
	for(i=0;i<a;i++)//���ID�Ƿ��ظ� 
	{ 
		if(strcmp(enternum1,attraction[i].name) == 0)
		{
		printf("\n�þ��������Ѵ��ڣ�����������\n");
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
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",attraction[a-1].intro);
		}
		break;
		
		case 4:
		{
			printf("\n�����޸�Ϊ��\n");
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
			printf("\n������������������������룡\n");
	    	scanf("%s",attraction[a-1].Hprice);
			}
			else
			break;  
	}
		}
		break;
		
		case 5:
			{
			printf("\n�����޸�Ϊ��\n");
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
			printf("\n������������������������룡\n");
	    	scanf("%s",attraction[a-1].Lprice);
		}
		else
			break;  
	}
		}
		break;
		
		
		
		case 6:
		{
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",attraction[a-1].time);
		}
		break;
		
		case 7:
		{
			printf("\n�����޸�Ϊ��\n");
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
	 	printf("������������д������븡������"); 
	 	scanf("%s",attraction[a-1].discount);	
	}
	else
		break;
	} 
	
			
		}
		break;
		
		case 8:
		{
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",attraction[a-1].clas);
		}
		break;
		
		case 9:
		{
			printf("\n�����޸�Ϊ��\n");
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
		printf("\n������������������������룡\n");
	    scanf("%s",attraction[a-1].number);
		}
		else
		break;  
	}
		}
		break;
		
		case 10:
		{
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",attraction[a-1].area);
		}
		break;
		
		case 11:
		{
			printf("\n�����޸�Ϊ��\n");
			scanf("%s",attraction[a-1].fee);
		}
		break;
		
		default:
		A_spot_add_change();
	}
	
	infile = fopen("attractions.txt","w");//���޸Ĺ������Ϣд���ļ� 
	if(infile == NULL)//�ж��ļ��Ƿ���ȷ�� 
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	for(i = 0;i < a;i ++)
		fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
	A_spot_add_change2();
	printf("\n\n�����޸ĳɹ�\n");
    printf("-------------------\n");
	printf("��������������޸���\n");
	printf("1.�����޸�\n2.ȡ��������������һ����\n3.����޸Ĳ�������һ����\n");

 
 	while(1)//�ݴ� 
 {
	verify = scanf("%d", &choice1);
  
 	if(verify == 1 && 0 < choice1 && choice1 < 4)
  	break;
  
  	else
  {
   	gets(z);
   	printf("��������ȷ�ı�ţ�\n");
  }
 }
	
	
	switch(choice1)
	{
		case 1:
			A_spot_add_change();//���������޸� 
			break;
		
		case 2:
			A_spot_add_change3();//��Ӿ����ȥȡ�� 
			A_spot();//������һ�� 
		break;
		
		case 3:
			A_spot();//������һ�� 
		break;
		
		default:
			A_spot();//������һ�� 
	} 
}

void A_spot_add_change1()//����Ϣд��spot.txt�ļ� 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//�򿪾�����Ϣ�����ļ� 
			//�ж��ļ��Ƿ���ȷ�� 
	if(infile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
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

void A_spot_add_change2()//����Ϣд��spot.txt�ļ� 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//�򿪾�����Ϣ�����ļ� 
		
			//�ж��ļ��Ƿ���ȷ�� 
	if(infile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
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

void A_spot_add_change3()//��Ӿ����ȡ�� 
{
	
	int i = 0,j = 0,a = 0;
	FILE*infile = fopen("attractions.txt","r");//�򿪾�����Ϣ�����ļ�
		 
			//�ж��ļ��Ƿ���ȷ�� 
	if(infile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
	a = A_spot_count_spotline();
	for(i = 0;i < a;i ++)
		fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID,attraction[i].name,attraction[i].intro,attraction[i].Hprice,attraction[i].Lprice,attraction[i].time,attraction[i].discount,attraction[i].clas,attraction[i].number,attraction[i].area,attraction[i].fee);
	fclose(infile);
    FILE*outfile = fopen("spot.txt","r");
    
    	//�ж��ļ��Ƿ���ȷ�� 
	if(outfile == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
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





int A_spot_count_spotline()//����attractions.txt�ļ������� 
{
	FILE*file1;
   	file1 = fopen("attractions.txt", "r"); // ���ļ�
   	//�ж��ļ��Ƿ���ȷ�� 
	if(file1 == NULL)
	{
		printf("\n������ȷ���ļ�");
		printf("\n���ٴμ��");
		exit(1);
	}
	
    int line = 0;
    char attractions[1000000];
   
    while (fgets(attractions, 1000000, file1)) 
        line++; // �ۼ�����
    fclose(file1);
    
	return(line);
	 }


void A_order_count()//�������Ա-ͳ�ƶ������� 
{
	int choose;
	printf("\n\n��ӭ�������Աͳ�ƶ������棡\n");
	printf("------------------------------\n");
	printf("������ѡ�����²�����"); 
    printf("\n1.��Ԥ�����Ծ���������� \n2.�����������Ծ����������\n3.ͳ�Ƹ����������������\n4.ͳ�Ʋ�ͬ������û������ηֲ�\n5.�����ȶԲ�ͬ�������Ʊ����������򣬱Ƚϲ�ͬ�����ڲ�ͬ���ȵķ������\n6.������һ����\n");
	printf("\n��ѡ������Ҫ��ѯ����Ϣ��������1~6����ѡ��\n");
	int verify;
 	char z[81];//�ݴ� 
 while(1)//�ݴ� 
 {
 	verify = scanf("%d", &choose);
  
  	if(verify == 1 && 0 < choose && choose < 7)
  		break;
  
  	else
  {
   		gets(z);
   		printf("��������ȷ�ı�ţ�\n");
  }
 }
	switch(choose)
	{
		case 1:
		 	A_order_count_num();//����Ա-��ѯ�û�����-��Ԥ�������� 
			break;
		case 2:
			A_order_count_peopleQuery();//����Ա-��ѯ�û�����-������������ 
			break;
		case 3:
			A_order_count_propit();//����Ա-��ѯ�û�����-���������� 
			break;
		case 4:
			A_order_count_age();//����Ա-��ѯ�û�����-ͳ��������	
			break;
		case 5:
			A_order_count_sale();//����Ա-��ѯ�û�����-�����ȶ���������	
			break;
		default:
			A_order();//�ṩ������һ������� 
		
	}
	 
}


void A_order_count_peopleQuery()//��������������н��� 
{
	int i;
    int j,a;
    struct spot spot[81];
    struct spot temp;
    FILE *file1;
	file1 = fopen("spot.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
	A_order_count_sale_check();
	fopen("spot.txt", "a+"); // ���ļ�
	a = A_order_count_spotline();
	for(i = 0;i<a;i++)//����Ϣ���ļ���ȡ�� 
	{
 		fscanf(file1,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
	}
	fclose(file1);
 
	for(i = 0; i < a-1; i++)//��ð�ݷ���Ԥ������������ 
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
    printf("   ��������       |    ��������\n");
    printf("------------------------------------\n");
    
    for(i = 0;i < a;i ++)//���������ӡ���� 
    {
    	printf("%16s\t%d\n",spot[i].Sname,spot[i].Ssale);
    }
A_order_count_choose();//�ṩ������һ������� 
}

void A_order_count_num()//���밴Ԥ����������� 
{
	struct order order[81];
	struct spot spot[81];
	FILE *file1,*file2,*file3,*file4;
 	file1 = fopen("order1.txt","r");//�ж��ļ��Ƿ���ȷ�� 
 	A_order_count_age_fileCheck();
	int i = 0,a,b,j;//ȡ���ļ���Ϣ 
	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice) != EOF)
  	{i++;} 
 	fclose(file1);
 	b = A_order_count_order1line();
 	a = A_order_count_spotline();
 	file3 = fopen("spot.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
 	A_order_count_sale_check();
	for(i = 0;i < a;i ++)//����Ϣ���ļ���ȡ�� 
 {
 	fscanf(file3,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }
 	fclose(file3);
 	int countline[100];
 	for(j = 0;j < a;j ++)
 {
 	for(i = 0;i < b;i ++)//ͳ��ͬһ�����Ԥ���� 
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
 	file4 = fopen("countline.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
 	if(file4 == NULL)//�ж��Ƿ���ȷ�� 
 {
 		printf("��ǰ������Ϣ�ļ�������ȷ�򿪣�");
    	exit(1); 
 }
	i = 0;//����Ϣ���ļ���ȡ�� 
 	while(fscanf(file4,"%s %d",c[i].name,&c[i].cline) != EOF)
 	i++;
 	fclose(file1);
 	for(i = 0; i < a-1; i ++)//��ð�ݷ���Ԥ������������ 
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
	printf("    ��������       |  Ԥ����\n");
	printf("--------------------------------\n"); 
    for(i = 0;i < a;i ++)//���������ӡ����
	printf("%16s\t%d\n",c[i].name,c[i].cline);
    A_order_count_choose();
}

void A_order_count_propit()//���뾰����������ҳ�� 
{
	struct order order[81];
	FILE *file1,*file2,*file3,*file4;
 	file1 = fopen("order1.txt","r");//�ж��ļ��Ƿ�����ȷ�� 
 	A_order_count_age_fileCheck();
 	int i = 0,N,line = 0,j,a;
 	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,
 													&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice)!=EOF)i++;
 	fclose(file1);
 	float earn[100];
 	fopen("order1.txt", "a+"); //�������� 
 	N = A_order_count_order1line();
 	struct spot spot[81];
 	file3 = fopen("spot.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
 	A_order_count_sale_check();
 	a = A_order_count_spotline();
 	for(i = 0;i < a;i ++)//����Ϣ���ļ���ȡ�� 
 {
 	fscanf(file3,"%s %s %d %f %d",spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }
 	fclose(file3);
	for(j = 0;j < a;j ++)
{
	for(i = 0;i < N;i ++)//ͳ��ͬһ�����Ԥ���� 
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
 	file4 = fopen("profit.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
 	if(file4 == NULL)//�ж��Ƿ���ȷ�� 
 {
 	printf("��ǰ������Ϣ�ļ�������ȷ�򿪣�");
    exit(1); 
 }
 	i = 0;//����Ϣ���ļ���ȡ��
 	while(fscanf(file4,"%s %f",profit[i].Ospotcode,&profit[i].Oprofit) != EOF)i++;
 	fclose(file1);
 	for(i = 0; i < a-1; i ++)//��ð�ݷ���Ԥ������������ 
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
    printf("    ��������       |     ����\n");
	printf("---------------------------------\n"); 
    for(i = 0;i < a;i ++)//���������ӡ���� 
    {
    	printf("%16s\t%5.2f\n",profit[i].Ospotcode,profit[i].Oprofit);
    }
	A_order_count_choose();	
}

void A_order_count_age()//�������Ա��������ͳ�� 
{   
  	struct order order[81];
  	struct spot spot[81];
  	FILE *file1,*file3;
  	int a,j;
  	file1 = fopen("order1.txt","r");//�ж��ļ��Ƿ���ȷ�� 
 	int i = 0,n,line = 0;
 	int child[100];
 	int adult[100];
 	int old1[100];
	while(fscanf(file1,"%s %s %s %s %d %d %d %d %f",order[i].Oordercode,order[i].Ospotcode,order[i].Odate,order[i].Ogodate,
													&order[i].Ochild,&order[i].Oadult,&order[i].Oolds,&order[i].Ototal,&order[i].Oprice)!=EOF)i++;//ȡ����Ϣ 
	fclose(file1);
	file3 = fopen("spot.txt","r");
	a = A_order_count_spotline();
 	for(i = 0;i < a;i ++)//����Ϣ���ļ���ȡ�� 
 {
 	fscanf(file3,"%s %s %d %f %d",spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
 }

	line = A_order_count_order1line();
	for(j = 0;j < a;j ++)
{
 	for(i = 0;i < line;i ++)//ͳ�Ƶ�������Ķ�ͯ�����ˣ����˵����� 
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
    float adultpercent[100],childpercent[100],oldpercent[100],sum[100];//���������ηֲ�
   
	sum[i] = child[i] + adult[i] + old1[i];
	adultpercent[i] = adult[i]/sum[i];
	childpercent[i] = child[i]/sum[i];
	oldpercent[i] = old1[i]/sum[i];
	if(sum[i] == 0)
	{
		printf("--------------------------------------------------\n");
		printf("%s:û�иþ���Ķ������޷�����ͳ��\n",spot[i].Sname);
	}
	else{
    	printf("--------------------------------------------------\n");
		printf("%s�������ηֲ�Ϊ\n",spot[i].Sname);
		printf("����ռ%5.2f%,��ͯռ%5.2f%,����ռ%5.2f%\n",adultpercent[i],childpercent[i],oldpercent[i]);
	}
}
	A_order_count_choose();
}
void A_order_count_sale()//�������Ա-�Բ�ͬ���Ȳ�ͬ����������� 
{    
    struct spot spot[1000];
	struct order order[1000];
    int i = 0,a,b,c,d,n,k,j;// ���ļ�����ȡ�������� 
	FILE *file1,*file5,*file6;
 	file1 = fopen("spot.txt","r");
	n = A_order_count_spotline();
	k = A_order_count_order1line();
	for(i = 0;i < n;i ++)
 	fscanf(file1,"%s %s %d %f %d",&spot[i].Scode,spot[i].Sname,&spot[i].Ssale,&spot[i].Sprice,&spot[i].Sticket);
	fclose(file1);

	file5 = fopen("order1.txt","r");//���ļ�������������������� ������
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
  if(strcmp(spot[j].Scode,order[i].Ospotcode)==0 ) //�ж��Ƿ�Ϊͬһ���� 
{
 	if(a < 0 && b > 0)//�����Ƚ��з��� 
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
	file6 = fopen("month.txt","w");//����month�ļ���
	for(i = 0;i < n;i ++)fprintf(file6,"%s %d %d %d %d\n",spot[i].Sname,m[i].month1,m[i].month2,m[i].month3,m[i].month4);
 	fclose(file6);
	A_order_count_sale_paixu();  
}

void A_order_count_sale_paixu()//�������Ա���Բ�ͬ���������������������Ӻ��� 
{
  	int i,j,n;
 	FILE *file7;
 	file7 = fopen("month.txt","r");//�򿪾�����Ϣ���ڵ��ļ� 
 	if(file7 == NULL)//�ж��Ƿ���ȷ�� 
 {
 		printf("��ǰ������Ϣ�ļ�������ȷ�򿪣�");
    	exit(1); 
 }
 	n = A_order_count_spotline();
 	for(i = 0;i < n;i ++)//����Ϣ���ļ���ȡ�� 
 	fscanf(file7,"%s %d %d %d %d",m[i].name,&m[i].month1,&m[i].month2,&m[i].month3,&m[i].month4);
 	fclose(file7);
   for(i = 0; i < n-1; i ++)//��ð�ݷ���Ԥ������������ 
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
    printf("��һ���ȵľ�������Ϊ�����Ӵ�С��\n");
	printf("  ��������     |   ������\n") ;
    for(i = 0;i < n;i ++) 
	printf("%16s\t%d\n",m[i].name,m[i].month1);
	printf("���������ľ���Ϊ��%s\n",m[0].name);//���������ӡ����
    for(i = 0; i < n-1; i ++)//��ð�ݷ���Ԥ������������ 
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
     printf("�ڶ����ȵľ�������Ϊ�����Ӵ�С��\n"); 
     printf("  ��������     |   ������\n") ;
    for(i = 0;i < n;i ++) printf("%16s\t%d\n",m[i].name,m[i].month2);
	printf("���������ľ���Ϊ��%s\n",m[0].name);//���������ӡ����
    for(i = 0; i < n-1; i ++)//��ð�ݷ���Ԥ������������ 
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
    printf("�������ȵľ�������Ϊ�����Ӵ�С��\n"); 
    printf("  ��������     |   ������\n") ;
	for(i = 0;i < n;i ++) 
	printf("%16s\t%d\n",m[i].name,m[i].month3);
	printf("���������ľ���Ϊ��%s\n",m[0].name);//���������ӡ����
	for(i = 0; i < n-1; i ++)//��ð�ݷ���Ԥ������������ 
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
    printf("  ��������     |   ������\n") ;
	printf("���ļ��ȵľ�������Ϊ�����Ӵ�С��\n"); 
	for(i = 0;i < n;i ++) printf("%16s\t%d\n",m[i].name,m[i].month4);
	printf("���������ľ���Ϊ��%s\n",m[0].name);//���������ӡ����

    A_order_count_choose();
}

void A_order_count_choose()//�ṩ���ع���Ա����ͳ����Ϣ���� 
{
   int choose;
   printf("-------------------------------\n");
   printf("\n��ѡ��������Ĳ���\n1.������һ��\n2.���ڵ�ǰ����");
   int verify;
 	char z[5];//�ݴ� 
 
 while(1)//�ݴ� 
 {
  	verify = scanf("%d", &choose);
  
  	if(verify == 1 && 0 < choose && choose < 3)
  		break;
  
  	else
  {
   	gets(z);
   	printf("��������ȷ�ı�ţ�\n");
  }
 }
   if(choose == 1)
   A_order_count();	
}	

void A_order_count_sale_check()//�жϾ����ļ��Ƿ���ȷ�� 
{
	FILE*file1;
	file1 = fopen("spot.txt","r");
	if(file1 == NULL) 
 {
 	printf("��ǰ������Ϣ�ļ�������ȷ�򿪣�");
    exit(1); 
 }	
}

void A_order_count_age_fileCheck()//�ж϶����ļ��Ƿ���ȷ�� 
{
	FILE *file1;
 	 //�ж��ļ��Ƿ���ȷ�� 
 	file1 = fopen("order1.txt","r");
 	if(file1 == NULL)
 {
	printf("��ǰ������Ϣ�ļ�������ȷ�򿪣�");
    exit(1); 
 }	
}

int A_order_count_spotline()//����spot.txt������ 
{
	FILE*file1;
   	file1 = fopen("spot.txt", "a+"); // ���ļ�
    int line = 0;
    char spot1[100];
   	A_order_count_sale_check();
    while (fgets(spot1, 100, file1)) 
        line++; // �ۼ�����
    fclose(file1);
    
	return(line);
	 }
	 
 int A_order_count_order1line()//����order1.txt������ 
 {
 	FILE*file1;
 	file1 = fopen("order1.txt", "a+"); // ���ļ�
    char order1[100];
    int line = 0;
   	A_order_count_age_fileCheck();
    while (fgets(order1, 100, file1)) 
        line++; // �ۼ�����
    fclose(file1);
    return(line);
 }
 
 void T_TouristsInterface() 
{
	int touristsOperation;
	printf("\n----------------------\n");
	printf("\n1.��¼\n2.ע��\n��ѡ��������Ĳ�����");//�ο�ѡ���¼��ע�� 
	
	int verify;
	char z[81];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &touristsOperation);
		
		if(verify == 1 && 0 < touristsOperation < 3)
		break;
		
		else
		{
			gets(z);
			printf("������������������1��2��ѡ��\n");
		}
	}
	printf("\n----------------------\n");
	
	if(touristsOperation == 1)//�οͽ����¼���� 
	{
  		T_person_login();
	}
	
	else if(touristsOperation == 2)//�οͽ���ע����� 
	{
     	T_person_register();
	} 
	
	else
	T_TouristsInterface();
}

void T_person_login()
{
    FILE*outfile = fopen("T_information.txt","r");//�򿪹���Ա��Ϣ�洢�ļ�
	struct T_account tourist[81];

	int i = 0,j = 0,k;
	printf("\n----------------------\n");
	printf("\n�������û�����");
	scanf("%s",&touristname);
	printf("���������룺");
	scanf("%s",&touristpassword);
	printf("\n----------------------\n");

	while(fscanf(outfile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
													&tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum)!=EOF)
	
	//��֤�û����������Ƿ���ȷ
{
	if(strcmp(touristname,tourist[i].idNum) == 0 && strcmp(touristpassword,tourist[i].password) == 0) 
	{
	printf("���ѵ�¼�ɹ���\n");
    j = 1;
	}
	i ++;	
}    
	fclose(outfile);
	if(j != 1)//������� 
    {
	printf("��������˺Ż������������������룡\n");
    T_person_login();
    }
   
   
 	T_Menu();
}

// �����οͲ�ѯ����
void T_Menu()
{
	int queryChoice = 0;
	
	printf("\n��ѡ������Ҫ��ѯ����Ϣ��\n1.������Ϣ\n2.������Ϣ\n3.������Ϣ\n4.��ƱԤ��\n5.�˳���¼\n6.�˳�ϵͳ\n"); 
	
	int verify;
	char z[5];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &queryChoice);
		
		if(verify == 1 && 0 < queryChoice < 7)
		break;
		
		else
		{
			gets(z);
			printf("��������ȷ�ı�ţ�\n");
		}
	}
	
	//�����οͲ�ѯ�����ѡ�� 
	switch(queryChoice) 
	{
		
		//�ο͸�����Ϣ 
		case 1:
			T_person();
			break;
		
		//�οͲ�ѯ������Ϣ 
		case 2:
			T_spot_AttractionsInformation();
			break;
	
		//�οͲ�ѯ������Ϣ 
		case 3:
			T_order_Information();
			break;
		
		//�ο���ƱԤ�� 
		case 4:
			T_person_order_fillIn();
			break;
			
		//�˳���¼
		case 5:
			mainInterFace();
			break;
			
		case 6:
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n");
			exit(1);
			break;
			
		default:
			T_Menu();
		
	}
			
}  
void T_person()//������Ϣ���� 
{
	int choose;
	printf("\n���ɽ������²�����\n1.�鿴�ҵ���Ϣ\n2.�޸��ҵ���Ϣ\n3.�������˵�\n");
	
	int verify;
	char z[5];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("��������ȷ�ı�ţ�\n");
		}
	}
	
	if(choose == 1)
	  T_person_check();//�鿴�ҵ���Ϣ 
	  
	else if(choose == 2)
	  T_person_change();//��Ϣ�޸� 
	  
	else 
	  T_Menu();//�������˵� 
	  
}
void T_person_check()
{
	FILE*infile = fopen("T_information.txt","r");
	int i = 0,choose;
	struct T_account tourist[81];
	if(infile == NULL)
	{
		printf("\n��ʧ�ܣ�");
		exit(1);
	}
	printf("\n����������������������������������������������������������������������������������������\n");
	printf("|�û���|  ����  |������|0-18�꣨��18��|18-60�꣨��60��|60������|�绰����(11λ)|��������|\n");
	printf("����������������������������������������������������������������������������������������\n");
    while(fscanf(infile," %s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
   {
   	if(strcmp(tourist[i].idNum,touristname) == 0)
   	printf("%s\t%s\t%d\t\t%d\t\t%d\t%d\t%s\t%s\n",tourist[i].idNum,tourist[i].password,tourist[i].peopleNum,tourist[i].studentNum,
	                                   tourist[i].adultNum,tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum);
    i++;
   }
 	fclose(infile);
	printf("\n����ѡ��\n1.�������˵�\n2.���ظ�����Ϣҳ\n3.�˳�\n");//��һ������ 
 	scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_Menu();
			break;//������Ϣ�޸�ҳ 
		}
		else if(choose == 2)
		{
			T_person();
			break;//�ص����˵� 
		}
		else if(choose == 3)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);//�˳� 
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 
   
} 
void T_person_change()//�ο�����Ϣ�޸�ҳ�� 
{
	int choose;
		
	printf("\n��ӭ���������Ϣ�޸Ľ��棡\n");
	printf("-------------------------\n");
	printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n1.����\n2.��ϵ���ֻ�\n3.����\n4.�������˵�\n");
	scanf("%d",&choose);
	
    while(1)
	{
		if(choose == 1)
		{	T_person_change_password();
		  	break;//�޸�����
			 } 
		else if(choose == 2)
			{
			T_person_change_phone();
			break;//�޸��ֻ���
			} 
		else if(choose == 3)
			{
			T_person_change_mail(); 
			break;//�޸����� 
			} 
		else if(choose == 4)
         {
		 	T_Menu();
		 	break;
			 } 
      	else
		{	printf("����������1��2��3��4��ѡ��\n"); 
			scanf("%d",&choose);} 
	     
	}
}

void T_person_change_password()//�����޸� 
{  
	char afterpassword[20],newpassword[20],temp1[20];
	int i = 0,choose;
	FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n��ʧ�ܣ�");
		exit(1);
	}
	
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum)!=EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)
{ 
	while(1) 
{
	printf("\n�����������룺\n");//������� 
	scanf("%s",afterpassword);
	
	printf("���ٴ�ȷ�����룺\n");
	scanf("%s",newpassword);
	
	if(strcmp(afterpassword,newpassword) != 0)
	{
	printf("������������벻һ��,����������!");
	}		
	else if(strcmp(afterpassword,newpassword) == 0)//�޸����� 
    {
     	strcpy(temp1,tourist[i].password); 
		strcpy(tourist[i].password,newpassword); 
		strcpy(newpassword,temp1); //�����ַ��� 
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
    printf("�����޸ĳɹ���\n");	
	fclose(infile);
	fclose(outFile);
	remove("T_information.txt");//�滻 
    rename("temp.txt","T_information.txt");
    printf("����ѡ��\n1.�����û���Ϣ�޸�ҳ��\n2.�������˵�\n3.�˳�\n");//��һ������ 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//������Ϣ�޸�ҳ 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//�ص����˵� 
		}
		else if(choose == 3)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);//�˳� 
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 
}
	


void T_person_change_phone()//�޸��ֻ��� 
{
	char afterphone[20],temp2[20];
	int i = 0,choose,check = 0;
	FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n��ʧ�ܣ�");
		exit(1);
	}
    printf("\n�������µ��ֻ��ţ�\n");
	scanf("%s",afterphone);//�޸ĵ绰�� 
	check = T_person_register_formatVerify_phone(afterphone);//�жϵ绰�������Ƿ���ȷ 
	while(1)
	{
		if(check == 1)
		break;
		else if(check == 0)
	{
		printf("��������ֻ����������������룺\n");
		scanf("%s",afterphone);
		check = T_person_register_formatVerify_phone(afterphone);
	} 
	} 
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)//�ҵ���Ӧ���ַ��� 
{
 

 		strcpy(temp2,tourist[i].phoneNum); 
		strcpy(tourist[i].phoneNum,afterphone); 
		strcpy(afterphone,temp2); //�����ַ��� 
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
    printf("�޸ĳɹ���\n");	
	fclose(infile);
	fclose(outFile);
    remove("T_information.txt");
    rename("temp.txt","T_information.txt");
  
  	printf("����ѡ��\n1.�����û���Ϣ�޸�ҳ��\n2.�������˵�\n3.�˳�\n");//��һ������ 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//������Ϣ�޸�ҳ 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//�ص����˵� 
		}
		else if(choose == 3)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 

}
 
 
void T_person_change_mail()//�޸�����
{
	char newemailNum[20];
	int atposition,dotposition,i = 0,choose;
    FILE*infile = fopen("T_information.txt","r");
	FILE*outFile = fopen("temp.txt","w");
	struct T_account tourist[81];
	if(infile == NULL||outFile == NULL)
	{
		printf("\n��ʧ�ܣ�");
		exit(1);
	}
	printf("\n�����������䣺\n");
	scanf("%s",newemailNum);
 	while(fscanf(infile,"%s %s %d %d %d %d %s %s",tourist[i].idNum,tourist[i].password,&tourist[i].peopleNum,&tourist[i].studentNum,
	                                   &tourist[i].adultNum,&tourist[i].oldsNum,tourist[i].phoneNum,tourist[i].emailNum) != EOF)
{  
	if(strcmp(tourist[i].idNum,touristname) == 0)//�ҵ���Ӧ�ַ��� 
{
	while(1) 
{


    for(atposition = 0;atposition < strlen(newemailNum);atposition++)//�˶������ʽ 
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
		printf("�������ʽ��Ч�����������룺\n");
		scanf("%s",newemailNum);
	}
	
	else//�������� 
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
    printf("�����޸ĳɹ���\n");	
	fclose(infile);
	fclose(outFile);
    remove("T_information.txt");
    rename("temp.txt","T_information.txt");
   	printf("����ѡ��\n1.�����û���Ϣ�޸�ҳ��\n2.�������˵�\n3.�˳�\n");//��һ������ 
    scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_person_change();
			break;//������Ϣ�޸�ҳ 
		}
		else if(choose == 2)
		{
			T_Menu();
			break;//�ص����˵� 
		}
		else if(choose == 3)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);//�˳� 
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 
}
void T_person_register()
{
	struct T_account account;
	
	printf("\n���������ο���ע�ᡪ������\n");
	printf("�˺�(��6-10λ��ĸ���������): \n");
	
	while(1)
	{
		scanf("%s", account.idNum);
		if(T_person_register_formatVerify_id(account.idNum))
	 {
	 	if(T_person_register_duplicateCheck(account.idNum))
	 	break;
  		else 
		printf("�û����ѱ�ע�ᣬ����������: \n");
  	  }
		    
		else 
		printf("������6-10λ���ο���ID: \n");
	}
	
	printf("����: \n");
	scanf("%s", account.password);
	
	printf("�ο�������: \n");
	scanf("%d", &account.peopleNum);
	
	printf("�������Ӧ���������"); 
	printf("0-18�꣨��18��");
	scanf("%d", &account.studentNum);
	printf("18-60�꣨��60��");
	scanf("%d", &account.adultNum);
	printf("60������");
	scanf("%d", &account.oldsNum);
	
	printf("�绰����(11λ): \n");
	while(1)
	{
		scanf("%s", account.phoneNum);
		if(T_person_register_formatVerify_phone(account.phoneNum))
		  break;
		else printf("��������ȷ�ĵ绰����: \n");
	}
	
	printf("��������: \n"); 
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
		printf("��������ȷ��ʽ�������ַ: \n");
	}
		
	FILE *information = fopen("T_information.txt", "a");
	if(information == NULL)
	{
		printf("�ļ�����\n");
		exit(1);
	}
	fprintf(information, "%s %s %d %d %d %d %s %s\n", account.idNum, account.password, account.peopleNum, account.studentNum, account.adultNum, account.oldsNum, account.phoneNum, account.emailNum);
	fclose(information);
	
	printf("ע��ɹ���\n");
	printf("--------------------\n");
	T_TouristsInterface();//���ú�������ѡ����� 
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
		printf("�ļ�������\n");
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
    //����Ǿ����Ƽ������� 
    printf("\n���ã�����������������룬ѡ�����·�ʽ���о����ѯ��\n");
    printf("1.��������\n");
    printf("2.ͨ���Ƿ���Ʊ���в�ѯ\n");
    printf("3.��������\n");
	printf("4.�ۿ���Ϣ\n");
	printf("5.���ݼ۸������ѯ\n");
	printf("6.����Ԥ������ѯ\n");
	printf("7.�������˵�\n");
	
	int verify;
	char z[5];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &WayofSearch);
		
		if(verify == 1)
		break;
		
		else
		{
			gets(z);
			printf("��������ȷ�ı�ţ�\n");
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
			printf("����������1-7��ѡ��\n"); 
			scanf("%d",&WayofSearch);
		}
	}
 }
 
 void T_spot_count_ByNameInquire()//ͨ���������Ʋ�ѯ 
{
	char spotChoice[7];//����ѡ�����
	struct spot spot[1000];
	
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	fclose(outFile);
	int num_spot = i;//��¼������
	printf("\n-----------------------------\n");
	printf("����Ϊ��ϵͳ�����пɲ�ѯ����"); 
	printf("\n-----------------------------\n");
	for(i = 0; i < num_spot; i++)
	  printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	  
	printf("\n��ѡ��������Ȥ�ľ��㣬���������Ӧ��Ż�����000000������һ����");
	int verify = 0;
	i = 0;
	char judge[] = "000000";//�����жϷ��ص����� 
	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	
		for(i = 0; i < num_spot;  i++)//����Ƿ�Ϊ��Ч������ 
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
	 		printf("\n��������ȷ�ľ�����,������һ��������000000��\n");
	 	}
	 }
	
	if(strcmp(spotChoice, judge) == 0)
	  T_spot_AttractionsInformation();//���ú���������һ�� 
	
	else
	  T_spot_other_introduction(spotChoice);//�����뾰������ҳ��	
}

void T_spot_count_Ticket()
{
	struct spot spot[81];
	int neededDate, verify;
	char z[5];
	printf("\n��������Ҫ��ѯ�����ڣ���ʽ��20180501����");
 	while(1)
 	{
	 	verify = scanf("%d", &neededDate);
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(neededDate) == 1)
				break;
	 		else printf("\n�����ڲ����ڣ���������ȷ������: ");
	 	}
	 	else
		{
			gets(z);
			printf("\n�������ʽ��ȷ������: ");
		}
	 }
	 FILE *outFile_data = fopen("order2.txt", "r");//�򿪿ɶ���ÿ�վ�����Ʊ����ļ�
	 if(outFile_data == NULL)
	 {
 		printf("�ļ�������");
		exit(1); 
 	}
	 int i = 0, j = 0, k = 0;//����
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
 	num_limitTicket = j;//��¼Ʊ�������ŵľ�����
 	num_noTicket = k;//��¼������Ʊ������
	i = 0;j = 0; k = 0;
	printf("\n| ��� |   ��������   |Ʊ����|\n"); 
 	verify = 1;
 	int T = 1;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
 	verify = 1; 
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		for(k = 0; k < num_noTicket; k ++)
 		{
			if(strcmp(spot[i].Scode, spotID_noTicket[k]) == 0)
			{
				printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "����");
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
				printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "����");
				
			}
			else printf("%s.  %s\t\t%s\n", spot[i].Scode, spot[i].Sname, "����");	
		}
		i ++;
		T = 1;
		verify = 1; 
 	}
 	fclose(outFile);
 	int num_spot = i;//������+1 
 	i = 0;j = 0;k = 0;
 	void T_spot_other_spotchoose();//���뾰���ŵĺ��� 
 	T_spot_other_spotchoose();
}

void T_spot_other_spotchoose()
{
	int i = 0;
	struct spot spot[81];
	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	{
		i ++;
	}
	int num_spot = i;
	printf("��ѡ��������Ȥ�ľ��㣬���������Ӧ��ţ�������һ��������000000����");
 	char spotChoice[7];
 	char returnNum[7] = "000000";
 	int verify = 0; 
 	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	verify = 0;
		for(i = 0; i < num_spot; i++)//����Ƿ�Ϊ��Ч������ 
	 	{
	 		if(strcmp(spot[i].Scode, spotChoice) == 0)
			verify = 1;
	 	}
	 	i = 0; 
	 	
	 	if(strcmp(spotChoice, returnNum) == 0)
	 	{
	 		T_spot_AttractionsInformation();//���ú���������һ��
	 		break;
	 	}
	 	if(verify == 1)
	 	break;
	 	else
	 	{	i = 0;
	 		printf("\n��������ȷ��ţ�������һ������000000����");
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

void T_spot_count_ScenicArea()//�����ѯ 
{
	FILE *information;
	information = fopen("attractions.txt","r"); 
	
	printf("\n");
	
	if(information == 0)
	{
		printf("�ļ�������");
		exit(1);
	}
	
	int i = 0, j, k = 1;//���� 
	int verify = 1;//��֤ 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//��¼������� 
	printf("\n---------\n");
	printf("��������\n");
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
	
	printf("��ѡ������Ҫ��ѯ�������������������ƣ�������000000������һ��:");
	char areaChoice[81];//����ѡ����� 
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
		printf("�ļ�������");
		exit(1);
	}
	
	int i = 0, j = 0;//���� 
	int verify = 0;//��֤ 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//��¼������� 
	
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
			printf("\n�����ڸ�����������000000����\n");
			scanf("%s", spotChoice);
			if(strcmp(spotChoice, judge) == 0)
			{
				T_spot_count_ScenicArea();
			}
		} 
	}
	else
	{
		printf("����������Ҫ�鿴�������λ�����,������000000������һ����");
		char spotChoice[7];
		i = 0;
		while(1)
		{
			scanf("%s", spotChoice);
			for(i = 0; i < num_spot;  i++)//����Ƿ�Ϊ��Ч������ 
			{
				if(strcmp(attraction[i].ID, spotChoice) == 0)
				verify = 1;
			}
			if(verify == 1)
			break;
			else if(strcmp(spotChoice, judge) == 0)//�ж��Ƿ�Ϊ�˳���� 
			break;
			else
			{
				i = 0;
				printf("\n����������Ҫ�鿴�������λ�����,������000000������һ����");
			}
	 	}
	
			if(strcmp(spotChoice, judge) == 0)
 			T_spot_count_ScenicArea();
	  
			else 
			T_spot_other_introduction(spotChoice);
	}
}

void T_spot_count_Discount()//�ۿ���Ϣ��ѯ 
{
	printf("\n---------------------\n");
	printf("��ǰ��ѡ����ۿ۷�ʽ\n"); 
	printf("---------------------\n");
	printf("1.����ѧ��Ʊ��������Ʊ�ľ���\n2.������һ��\n");
	
	int choice, verify;
	
	char z[5];//�ݴ�
	while(1)
	{
		verify = scanf("%d", &choice);
		if(verify == 1 && choice > 0 && choice < 3)
		break;
		else
		{
			gets(z);
			printf("\n��������ȷ�ı�ţ�");
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

void T_spot_count_Discount_1()//����ѧ��Ʊ������Ʊ�ľ��� 
{
	char spotChoice[7];//����ѡ�����
	struct spot spot[1000];
	
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	fclose(outFile);
	int num_spot = i;//��¼������
	printf("\n-----------------------------\n");
	printf("����ѧ��Ʊ��������Ʊ�ľ���"); 
	printf("\n-----------------------------\n");
	for(i = 0; i < num_spot; i++)
	  printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	  
	printf("\n��ѡ��������Ȥ�ľ��㣬���������Ӧ��Ż�����000000������һ����");
	int verify = 0;
	i = 0;
	char judge[] = "000000";//�����жϷ��ص����� 
	while(1)
 	{
	 	scanf("%s", spotChoice);
	 	
		for(i = 0; i < num_spot;i ++)//����Ƿ�Ϊ��Ч������ 
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
	 		printf("\n��������ȷ�ľ�����,������һ��������000000��\n");
	 	}
	 }
	
	if(strcmp(spotChoice, judge) == 0)
	  T_spot_AttractionsInformation();//���ú���������һ�� 
	
	else
	  T_spot_other_introduction(spotChoice);//�����뾰������ҳ��
}

void T_spot_count_PriceOrder()//���ݼ۸����� 
 {  int choose;
    T_spot_count_PriceOrder_datechange(); 
 	printf("\n����ѡ��:\n1.���۸�ӵ͵��߲�ѯ\n2.���۸�Ӹߵ��Ͳ�ѯ\n3.������һҳ\n");
	
	int verify;
	char z[5];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose && choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("\n��������ȷ�ı�ţ�");
		}
	}
	
	while(1)
	{
		if(choose == 1)//�ӵ͵��� 
		{
			
			T_spot_count_PriceOrder_FromLtoH();
			break;
		}
		else if(choose == 2)//�Ӹߵ��� 
		{
			
			T_spot_count_PriceOrder_FromHtoL();
			break;
		}
		else
		{
			T_spot_AttractionsInformation();
			break;//�ص������ѯҳ�档 
		}
	}	 
 } 
 
 void T_spot_count_PriceOrder_datechange()//�����������иı�۸��Լ���Ʊ��
 {  
    int i = 0;
	float price1[8] = {30.00,260.00,60.00,40.00,10.00,175.00,130.00,100.00};
 	float price2[8] = {20.00,260.00,40.00,20.00,10.00,175.00,130.00,100.00};
  	int ticket1[8] = {200,200,200,200,100,100,100,100};
   	int ticket2[8] = {100,100,100,100,200,200,200,200};
 	struct spot dataWithTime[1000];
	int neededDate, verify,usedate;
	char z[5];
	printf("\n��������Ҫ��ѯ�����ڣ���ʽ��20180501����");//�����ѯ���� 
 	while(1)
 	{
	 	verify = scanf("%d", &neededDate);//���������ڽ��м�� 
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(neededDate) == 1)
	 		{
				break;
		 	}
	 		
	 		else 
		 	printf("\n�����ڲ����ڣ���������ȷ������: ");
	 	}
	 	else
		{
			gets(z);
			printf("\n�������ʽ��ȷ������: ");
		}
	 } 
     
  	FILE *inFile;
	FILE *onFile;
    inFile = fopen("spot.txt","r");
    onFile = fopen("temp.txt","w");
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n��ʧ��\n");
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
 
 void T_spot_count_SalesOrder()//����Ԥ������ѯ 
 {
	 int choose;
 	 printf("\n����ѡ��\n1.��Ԥ�����ӵ͵��߲�ѯ\n2.��Ԥ�����Ӹߵ��Ͳ�ѯ\n3.������һҳ\n");
	 
	int verify;
	char z[5];//�ݴ� 
	
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &choose);
		
		if(verify == 1 && 0 < choose && choose < 4)
		break;
		
		else
		{
			gets(z);
			printf("��������ȷ�ı�ţ�\n");
		}
	}
	 
	while(1)
	{
		if(choose == 1)//�ӵ͵��� 
		{
			T_spot_count_SalesOrder_FromLtoH();
			break;
		}
		else if(choose == 2)//�Ӹߵ��� 
		{
			T_spot_count_SalesOrder_FromHtoL();
			break;
		}
		else
		{
			T_spot_AttractionsInformation();
			break;//�ص������ѯҳ�档 
		}
	} 
 }
 
 void T_spot_SettingRecommend()//�Ƽ����� 
 {
 	int j,season;
  	char *name[21];
       
	int date1[21],date2[21],date3[21],date4[21];
	    
	time_t timefun;
  	struct tm *t;
  	time (&timefun);
  	t = gmtime(&timefun);
  	season = (1+t->tm_mon)*100+t->tm_mday;//��ȡ�û�ʱ�䲢ת������ 
        
    FILE *inFile;
 	inFile = fopen("setting.txt","r");
 	if(inFile == NULL)
	 {
 		printf("\n��ʧ��");
		 exit(1); 
 	}
 	printf("\n------------------------------------------------------------------------------");
 	printf("\n�Ƽ������ݵ�ǰ����Ϊ���Ƽ����¾��㣺"); 
 	
 	for(j = 0;j < 8;j ++)
	 {
	 fscanf(inFile,"%s %d %d %d %d",settings,&date1[j],&date2[j],&date3[j],&date4[j]);
	 if(season >= date1[j]&&season <= date2[j])//ѡ������ʵľ��� 
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
 		printf("\n��ʧ��");
	 	exit(1); 
 	}

	while(fscanf(inFile,"%s %s %d %f %d",&priceorder[i].Scode,&priceorder[i].Sname,&priceorder[i].Ssale,
											&priceorder[i].Sprice,&priceorder[i].Sticket) != EOF)
{
	i++;
}
	number = i;//��þ����� 
	for(j = 1;j < number;j++)          //�Ծ���ͨ���۸����� 
        {for(i = 0;i < j;i++)         
            if(priceorder[i].Sprice > priceorder[j].Sprice)           
            {
                k = priceorder[i].Sprice;priceorder[i].Sprice = priceorder[j].Sprice;priceorder[j].Sprice = k;
                
                strcpy(temp1,priceorder[i].Sname); 
				strcpy(priceorder[i].Sname,priceorder[j].Sname); 
				strcpy(priceorder[j].Sname,temp1); //�����ַ��� ��ü۸��С�������� 
				
				strcpy(temp2,priceorder[i].Scode);
				strcpy(priceorder[i].Scode,priceorder[j].Scode);
				strcpy(priceorder[j].Scode,temp2);//�����ַ��� ��ö�Ӧ�ı�� 
            }
		}
	printf("\n----------------------\n");
  	printf("���㰴�۸�ӵ͵�������");
  	printf("\n----------------------\n");
  	for(i = 0;i < number;i++) printf("%s %s\n",priceorder[i].Scode,priceorder[i].Sname);
   	fclose(inFile);
    printf("����ѡ��\n1.�������鿴��������\n2.ֱ��Ԥ��\n3.���ؾ���˵�\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //ת��Ԥ������ 
		}
		else if(choose == 1)
		{
			printf("�����뾰����룺\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//����Ƿ�Ϊ��Ч������ 
	 		{
	 			if(strcmp(priceorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n��������ȷ�ľ����ţ�\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
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
 		printf("\n��ʧ��");
	 	exit(1); 
 	}
	 	while(fscanf(inFile,"%s %s %d %f %d",&priceorder[i].Scode,&priceorder[i].Sname,&priceorder[i].Ssale,
											&priceorder[i].Sprice,&priceorder[i].Sticket) != EOF)
{
	  i++;
}
	number = i;//��þ����� 
 	for(j = 1;j < number;j++)          //�Ծ���ͨ���۸����� 
        {for(i = 0;i < j;i++)         
        		if(priceorder[i].Sprice<priceorder[j].Sprice)           
            {
                k = priceorder[i].Sprice;priceorder[i].Sprice = priceorder[j].Sprice;priceorder[j].Sprice=k;
                
                strcpy(temp1,priceorder[i].Sname); 
				strcpy(priceorder[i].Sname,priceorder[j].Sname); 
				strcpy(priceorder[j].Sname,temp1); //�����ַ��� ��ü۸�Ӵ�С���� 
				
				strcpy(temp2,priceorder[i].Scode);
				strcpy(priceorder[i].Scode,priceorder[j].Scode);
				strcpy(priceorder[j].Scode,temp2);//�����ַ��� ��ö�Ӧ�ı�� 
            }
		}
	printf("\n----------------------\n");
	printf("���㰴�۸�Ӹߵ�������");
	printf("\n----------------------\n");
	for(i = 0;i < number;i++) printf("%s %s\n",priceorder[i].Scode,priceorder[i].Sname);
	fclose(inFile);
    printf("\n����ѡ��\n1.�������鿴��������\n2.ֱ��Ԥ��\n3.���ؾ���˵�\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //ת��Ԥ������ 
		}
		else if(choose == 1)
		{
			printf("�����뾰����룺\n");
			int verify = 0;
			i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//����Ƿ�Ϊ��Ч������ 
	 		{
	 			if(strcmp(priceorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n��������ȷ�ľ����ţ�\n");
	 		}
	 	} 

			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
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
 		printf("\n��ʧ��");
		 exit(1); 
 	 }
	 	while(fscanf(inFile,"%s %s %d %f %d",&salesorder[i].Scode,&salesorder[i].Sname,&salesorder[i].Ssale,
											&salesorder[i].Sprice,&salesorder[i].Sticket) != EOF)
{
	  i++;
}
      number = i;//��þ����� 
      for(j = 1;j < number;j++)          //�Ծ��������������ж� 
        {for(i = 0;i < j;i++)         
        		if(salesorder[i].Ssale>salesorder[j].Ssale)           
            {
            	k = salesorder[i].Ssale;salesorder[i].Ssale	=	salesorder[j].Ssale;salesorder[j].Ssale	=	k;
                strcpy(temp1,salesorder[i].Sname); 
				strcpy(salesorder[i].Sname,salesorder[j].Sname); 
				strcpy(salesorder[j].Sname,temp1); //�����ַ��� �����������С�������� 
				
				strcpy(temp2,salesorder[i].Scode);
				strcpy(salesorder[i].Scode,salesorder[j].Scode);
				strcpy(salesorder[j].Scode,temp2);//�����ַ��� ��ö�Ӧ�ı�� 
            }
		}
	printf("\n------------------------\n");
  	printf("���㰴Ԥ�����ӵ͵�������");
  	printf("\n------------------------\n");
  	for(i = 0;i < number;i++) printf("%s %s\n",salesorder[i].Scode,salesorder[i].Sname);
  	fclose(inFile);
    printf("\n����ѡ��\n1.�������鿴��������\n2.ֱ��Ԥ��\n3.���ؾ���˵�\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
			T_spot_AttractionsInformation();
		else if(choose == 2)
			T_person_order_fillIn(); //ת��Ԥ������ 
		else if(choose == 1)
		{
			printf("�����뾰����룺\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//����Ƿ�Ϊ��Ч������ 
	 		{
	 			if(strcmp(salesorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n��������ȷ�ľ����ţ�\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
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
 		printf("\n��ʧ��");
	 	exit(1); 
 	}
	while(fscanf(inFile,"%s %s %d %f %d",&salesorder[i].Scode,&salesorder[i].Sname,&salesorder[i].Ssale,
											&salesorder[i].Sprice,&salesorder[i].Sticket) != EOF)
{
	  i++;
}
      number = i;//��þ����� 
      for(j = 1;j < number;j++)   //�Ծ��������������ж�          
        {for(i = 0;i < j;i++)         
            if(salesorder[i].Ssale<salesorder[j].Ssale)           
            {
                k = salesorder[i].Ssale;salesorder[i].Ssale = salesorder[j].Ssale;salesorder[j].Ssale = k;
                strcpy(temp1,salesorder[i].Sname); 
				strcpy(salesorder[i].Sname,salesorder[j].Sname); 
				strcpy(salesorder[j].Sname,temp1); //�����ַ��� ����������Ӵ�С���� 
				strcpy(temp2,salesorder[i].Scode);
				strcpy(salesorder[i].Scode,salesorder[j].Scode);
				strcpy(salesorder[j].Scode,temp2);//�����ַ��� ��ö�Ӧ�ı�� 
            }
		}
	printf("\n------------------------\n");
  	printf("���㰴Ԥ�����Ӹߵ�������");
  	printf("\n------------------------\n");
   	for(i = 0;i < number;i++) printf("%s %s\n",salesorder[i].Scode,salesorder[i].Sname);
    fclose(inFile);
    printf("����ѡ��\n1.�������鿴��������\n2.ֱ��Ԥ��\n3.���ؾ���˵�\n");
    scanf("%d",&choose);
	while(1)
	{
		if(choose == 3)
		{
			T_spot_AttractionsInformation();
		}
		else if(choose == 2)
		{
			T_person_order_fillIn(); //ת��Ԥ������ 
		}
		else if(choose == 1)
		{
			printf("�����뾰����룺\n");
		int verify = 0;
		i = 0;
		while(1)
 		{
	 		scanf("%s", Choose);
	 	
			for(i = 0; i < number;  i++)//����Ƿ�Ϊ��Ч������ 
	 		{
	 			if(strcmp(salesorder[i].Scode, Choose) == 0)
				verify = 1;
	 		}
	 	
	 		if(verify == 1)
	 		break;

	 		else
	 		{
	 			i = 0;
	 			printf("\n��������ȷ�ľ����ţ�\n");
	 		}
	 	} 
			T_spot_other_introduction(Choose);
		}
		else
		{
			printf("����������1��2��3��ѡ��\n"); 
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
		printf("�ļ�������");
		exit(1);
	}
	
	int i = 0;//���� 
	while(fscanf(information, "%s %s %s %s %s %s %s %s %s %s %s\n",attraction[i].ID, attraction[i].name, attraction[i].intro, attraction[i].Hprice, attraction[i].Lprice, attraction[i].time, attraction[i].discount, attraction[i].clas, attraction[i].number, attraction[i].area, attraction[i].fee) != EOF)
	{
		i ++;
	}
    fclose(information);
	int num_spot = i;//��¼������� 
	i = 0;

	char attention[2][7] = {"000002", "000005"};

	while(i < num_spot)
	{
		if(strcmp(attraction[i].ID, spotChoice) == 0 && strcmp(attention[0],spotChoice) != 0 && strcmp(attention[1],spotChoice) != 0 ) 
		{
			printf("\n����������������������������������������\n");
			printf("\n%s\n\n������ܣ�%s\n\n��������ʱ�䣺%s\n\n���㼶��%s\n\n�����۸�%s\n\n�����۸�%s\n\nѧ��Ʊ/����Ʊ�ۿۣ�%s\n", attraction[i].name, attraction[i].intro, attraction[i].time, attraction[i].clas, attraction[i].Hprice, attraction[i].Lprice, attraction[i].discount);
			printf("\n����������������������������������������\n"); 
			break;
		}
		
		else if (strcmp(attraction[i].ID, spotChoice) == 0)
		{
			printf("\n����������������������������������������\n");
			printf("\n%s\n\n������ܣ�%s\n\n��������ʱ�䣺%s\n\n���㼶��%s\n\n�����۸�%s\n\n�����۸�%s\n\nѧ��Ʊ/����Ʊ�ۿۣ�%s\n", attraction[i].name, attraction[i].intro, attraction[i].time, attraction[i].clas, attraction[i].Hprice, attraction[i].Lprice, attraction[i].discount);
			printf("\nע�⣺�þ��㲻�ʺ�������������");
			printf("\n����������������������������������������\n");
			break;
		}
		
		i++;
	}
	
	T_spot_other_bookInquire();//���ú���ѯ���Ƿ�Ԥ�� 	
} 

void T_spot_other_bookInquire()
{
	int choice;
	int verify;
	char z[5];
	
	printf("\n����Ҫ���ڽ���Ԥ����\n");
	printf("1.�� 2.��(�ص���ѯ����)\n");
		
	while(1)//�ݴ� 
	{
		verify = scanf("%d", &choice);
		
		if(verify == 1 && choice > 0 && choice < 3)
		break;
		
		else
		{
			gets(z);
			printf("��������ȷ�ı�ţ�\n");
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

void T_order_Information() //�����������Ŷ������� 
{   
     int WayofSearch = 0;
     printf("\n���ã�����������������룬ѡ�����·�ʽ��������\n");
     printf("1.ȡ��Ԥ��\n");
	 printf("2.��ѯ��ʷ�ϵĶ���\n");
	 printf("3.�������˵�\n");
	 scanf("%d",&WayofSearch);
	 while(1)
	 {
		if(WayofSearch == 1)
 		{
		 	T_order_add_CancelOrder();//ȡ�������Ӻ��� 
		 	break;
		 }
		else if(WayofSearch == 2)
		 {
 			T_order_check_HistoryOrder();//��ѯ�����Ӻ��� 
 			break;
 		}
		else if(WayofSearch == 3)
 		{
		 	T_Menu();
		 	break;
		 }
		else
		 {
 			printf("����������1-3��ѡ��\n"); 
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
 		printf("\n��ʧ��");
		 exit(1); 
 	}
 	
 	 time_t timep;//��ȡϵͳʱ�� 
     struct tm *p;
     time (&timep);
     p = gmtime(&timep);
     nday = p->tm_yday;//��ȡ��ǰ���� 
     nyear = 1900+p->tm_year;//��ȡ��ǰ��� 
     nhour = 8+p->tm_hour;//��ȡ��ǰʱ��
    
     printf("\n������������ȡ���Ķ���������ǰ24Сʱ�Ķ����ſ�ȡ������\n");
     printf("\n��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 
   	 printf("|�������\t\t|������\t|Ԥ��ʱ��\t\t|����ʱ��\t|δ������������0-18)|��������(19-59)|����������60��)|��Ʊ��|�ܼ۸�|\n");
     printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 
 	while(fscanf(outFile,"%s %s %s %s %d %d %d %d %f",&ordercheck[i].Oordercode,&ordercheck[i].Ospotcode,&ordercheck[i].Odate,
	                                           &ordercheck[i].Ogodate,&ordercheck[i].Ochild,&ordercheck[i].Oadult,
											   &ordercheck[i].Oolds,&ordercheck[i].Ototal,&ordercheck[i].Oprice) != EOF)//��Ϊ��������䶯 
	{
		i++;
	}
	 icount = i;
	for(i = 0;i<icount;i++)
	{
	j=T_order_check_HistoryOrder_select(ordercheck[i].Oordercode);
	sscanf(ordercheck[i].Ogodate,"%d:%d:%d:%d:%d",&year,&month,&day,&hour,&minute);//��ȡ�ļ����ʱ�� 
	number = T_order_add_Cancelorderdate(year,month,day);//�����ļ��е����������ú��� 
    if(nyear == year) //ͬһ�� 
   {if(nday < number&&nday == number --) 
   {if(nhour < hour && j == 1)//���ڲ�һʱ��С 
   printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);}
   else if(nday < number&&nday != number --&&j ==1)
   printf("%s\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
											   
   }
  	else if(nyear == year --)//��ĩ��� ������� 
   {if((year % 4 == 0&&year % 100 != 0)||(year % 400 == 0))//���� 
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
	else if(nyear < year--&&j==1)//�����һ������ 
 		printf("%s\t\t%s\t\t%s\t%s\t%d\t\t%d\t\t\t%d\t\t%d\t%.2f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);
} 
	fclose(outFile);
	int choose;
	char ordercode[81];
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 
	printf("\n��ѡ�����������Ҫ���еĲ�����\n1.ȡ������\n2.���ض�������ҳ\n") ;//�û�ѡ����һ�� 
	scanf("%d",&choose);
	while(1)
{
	if(choose == 1)
	{
		printf("����������Ҫȡ�����г̱�ţ�");
	    scanf("%s",ordercode); 
	    T_order_add_Cancelordercancel(ordercheck,ordercode);//��תȡ�������Ӻ� 
	    break;
	}
	else if(choose == 2)
	{
		T_order_Information();
		break;
	}
	else
	{
		printf("����������1��2��ѡ��\n"); 
		scanf("%d",&choose);
	}
	
}
}

void T_order_check_HistoryOrder()//��ʷ������ѯ 
{
	struct order ordercheck[81];
    int i = 0,choose,number = 0,j = 0,; 
    FILE *inFile;
 	inFile = fopen("order1.txt","r");
 	if(inFile ==NULL)
	 {
 		printf("\n��ʧ��");
		 exit(1); 
 	}
    printf("������������ʷ������\n");
    printf("\n��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 
    printf("�������\t\t������\tԤ��ʱ��\t\t����ʱ��\tδ������������0-18) ��������(19-59) ����������60��) ��Ʊ��  �ܼ۸�\n");
 	printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 
	while(fscanf(inFile,"%s %s %s %s %d %d %d %d %f",&ordercheck[i].Oordercode,&ordercheck[i].Ospotcode,&ordercheck[i].Odate,
	                                           &ordercheck[i].Ogodate,&ordercheck[i].Ochild,&ordercheck[i].Oadult,
											   &ordercheck[i].Oolds,&ordercheck[i].Ototal,&ordercheck[i].Oprice)!=EOF)//��ȡ�ļ� 
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
	
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n"); 

    fclose(inFile);
    printf("����ѡ��\n1.���ض�������ҳ��\n2.�˳�\n");//��һ������ 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_order_Information();//���ض����������˵� 
		}
		else if(choose == 2)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);
		}
		else
		{
			printf("����������1��2��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 
}

int T_order_check_HistoryOrder_select(char ordercode[])
{
	
    int choose,number = 0,j = 0,wordsize1,wordsize2,T = 1; 
    
   
     wordsize1 = strlen(touristname);//�û������� 
    wordsize2 = strlen(ordercode)-12;//�������û������� 
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
void T_order_add_Cancelordercancel(struct order ordercheck[],char ordercode[])//����ɾ���Ӻ� 
{
	FILE *inFile;
	FILE *onFile;
	int i = 0,choose,tickettotal,number,T = 0;
	char ordercodes[81],godate[81];
  	inFile = fopen("order1.txt","r");
    onFile = fopen("temp.txt","w");
    
	 
	if(inFile == NULL || onFile == NULL)
    {
        printf("\n��ʧ��\n");
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
 			printf("\n������Ķ����������󣬽�������һҳ\n");
   			T_order_add_CancelOrder();
 	     }
 	     for(i = 0;i<number;i++)
     {
  	  	if(strcmp(ordercheck[i].Oordercode,ordercode) != 0)//������Ҫɾ��������?
       	fprintf(onFile,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%f\n",ordercheck[i].Oordercode,ordercheck[i].Ospotcode,ordercheck[i].Odate,
	                                           ordercheck[i].Ogodate,ordercheck[i].Ochild,ordercheck[i].Oadult,
											   ordercheck[i].Oolds,ordercheck[i].Ototal,ordercheck[i].Oprice);//��������һ��д����ʱ�ļ�tmp.txt
      
        else if(strcmp(ordercheck[i].Oordercode,ordercode) == 0)
        {
		strcpy(ordercodes,ordercheck[i].Ospotcode);//ɾ������Ʊ���� 
		tickettotal = ordercheck[i].Ototal;
		strcpy(godate,ordercheck[i].Ogodate);
        }
     }  
        fclose(inFile);
        fclose(onFile);
        remove("order1.txt");
        rename("temp.txt","order1.txt");
        printf("\n����ȡ���ɹ���\n");	
		T_order_add_Cancelordercancel_add1(ordercodes,tickettotal);
        T_order_add_Cancelordercancel_add2(ordercodes,tickettotal,godate);
     printf("\n����ѡ��\n1.���ض�������ҳ��\n2.�˳�\n");//��һ������ 
       scanf("%d",&choose);
	   while(1)
	   {
		 if(choose == 1)
		{
			T_order_Information();//���ض��������Ӻ� 
		}
		else if(choose == 2)
		{
			printf("\n��лʹ�ñ�ϵͳ��ף���ó���죡\n"); 
			exit(1);
		}
		else
		{
			printf("����������1��2��ѡ��\n"); 
			scanf("%d",&choose);
		} 
	   } 
}

int T_order_add_Cancelorderdate(int year,int month,int day)//�����ļ��е����� 
  { 	
     int number;
  	if((year%4 == 0 && year%100 != 0)||(year%400 == 0))//�������� 

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

   else//������ 

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
        printf("\n��ʧ��\n");
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
        printf("\n��ʧ��\n");
        exit(1);
    }
    sscanf(orderdate,"%d:%d:%d:%d:%d",&year,&month,&day,&hour,&minute);//��ȡ�ļ����ʱ�� 
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
 
 
 
void T_person_order_fillIn()//�ο�Ԥ����Ʊ������ ���յ�½ʱID 
{
	char* touristsID;
	//trcpy(touristsID, touristname);
	int total,sum;
	int children,adults,olds,students,kids,soldiers,fullTickets,halfTicket,sumTickets;
	
	printf("--------��ӭ������ƱԤ��ϵͳ--------");
	 
	printf("\n�����������������ŵ��������� ");//��¼�������ŵ�������������μ���Ա���
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
			printf("\n���������Ϲ淶�����������룺");
		}
	} 
	
	// ͳ�Ƹ�����ε����� 
	while(1)
	{
		printf("\n��ֱ������Ӧ����ε�����");
		printf("\n0~18�꣨��18�꣩:");
		scanf("%d",&children);
		printf("\n18~60�꣺"); 
		scanf("%d",&adults);
		printf("\n60�꣨��60�꣩����:");
		scanf("%d",&olds);
		
		sum = children + adults + olds;
		if(sum == total)
		{
			break;
		}
		printf("\n�������������������������˶Ժ��������롪������"); 
	}

	while(1)
	{
		//ͳ��ѧ��Ʊ���� 
		while(1)
		{
			printf("\n����Ҫ��ѧ��Ʊ������");
			scanf("%d",&students); 
		
			if(students <= total)
			{
				break;
			}
			printf("\n�����������������˶Ժ���������"); 
		}
	
		//ͳ�ƾ��ˣ���Ʊ������ 
		while(1)
		{
			printf("\n�����ڵ������У������м�λ��");
			scanf("%d",&soldiers); 
		
			if(soldiers <= total)
			{
				break;
			}
			printf("\n�����������������˶Ժ���������");
		} 
		
		//ͳ��1.4�ף�����1.4�ף����£���Ʊ������
		while(1)
		{
			printf("\n�����ڵ�������,1.2�ף���1.2�ף����µĶ�ͯ�м�λ�� ");
			scanf("%d",&kids);
		
			if(kids <= total)
			{
				break;
			}
			printf("\n�����������������˶Ժ���������"); 
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

void T_person_order_spotsChoose(int sumTickets,int fullTickets,int halfTicket,int olds,int soldiers,int children,int adults,char touristsID[])//ѡ�񾰵㲢Ԥ����Ʊ
{
	struct spot spot[1000];
	char selectedID[7];
	int i = 0;
 	FILE *outFile = fopen("spot.txt", "r");
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	fclose(outFile);
	int num_spot = i;//������+1
	
	//ѡ�񾰵������Ӧ����������Ϣ 
	printf("\n��ѡ����ҪԤ���ľ�����:\n");
	for(i = 0; i < num_spot; i++)
 		printf("%s. %s\n", spot[i].Scode, spot[i].Sname);
	
	int verify = 0;
	i = 0;
	while(1)
 	{
	 	scanf("%s", selectedID);
	 	
		for(i = 0; i < num_spot;  i++)//����Ƿ�Ϊ��Ч������ 
	 	{
	 		if(strcmp(spot[i].Scode, selectedID) == 0)
			verify = 1;
	 	}
	 	
	 	if(verify == 1)
	 	break;
	 	else
	 	{
	 		i = 0;
	 		printf("\n��������ȷ��ţ�\n");
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
	 
	int T_spot_count_Ticket_datecheek(int);//�������������Ƿ���Ϲ淶 
	printf("��������Ҫ��ѯ�����ڣ���ʽ��20180101����\n");
 	while(1)
 	{
	 	verify = scanf("%d", &tourDates);
	 	if(verify == 1)
	 	{
	 		if(T_spot_count_Ticket_datecheek(tourDates) == 1)
	 		{
		 		if(tourDates >= yearNow * 10000 + monthNow * 100 + dayNow)//�ж��Ƿ�Ϊ�����ա���֮������
		 		  break;
		 		else printf("������Ʊ�ѹ��ڣ���������������: \n");
		 	}
	 		else printf("�����ڲ����ڣ���������ȷ������: \n");
	 	}
	 	else
		{
			gets(z);
			printf("�������ʽ��ȷ������: \n");
		}
	 }
	 
	void T_person_order_datechange(int);
	T_person_order_datechange(tourDates);
	 
	yearGo = tourDates / 10000;
	monthGo = (tourDates - yearGo * 10000) / 100;
	dayGo = tourDates - yearGo * 10000 - monthGo * 100;
	
	int T_person_order_ticketVerify(char [], int, int);// �ж�Ʊ�����Ƿ������Ӻ���
	if (T_person_order_ticketVerify(selectedID, sumTickets, tourDates) == 0)
	{
		printf("��ǰ������Ʊ�����㣬��ѡ��\n1.���ĳ�������\n2.����Ԥ������\n3.�����ο��������˵�");
		char z[5];//�ݴ� 
		while(1)//�ݴ�
		{
			verify = scanf("%d", &choice);
			if(verify == 1 && choice > 0 && choice < 4)
			break;
			else
			{
				gets(z);
				printf("��������ȷ�ı�ţ�\n");
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
	printf("��ǰƱ����������Խ���Ԥ��\n"); 

	float price;
	price = T_person_order_price(fullTickets, halfTicket, soldiers, selectedID);//����price

	printf("������Ʊ��Ϊ��%.2f\n", price);
	printf("1.ȷ��Ԥ��\n2.ȡ�����������˵���\n��ѡ�����������Ĳ�����");
	
    int choose;
    scanf("%d", &choose);
    
	if(choose == 1)//����Ϣд�붩���ļ� 
	{
		FILE *outFile_order = fopen("order1.txt","a");//�򿪾����ⲿ����order1.txt�����ļ� 
		if(outFile_order == NULL)//���һ�β��ɹ��Ĵ�
		{
			printf("\n�ļ���ʧ�ܣ�����ϵ����Ա\n");
			exit(1);		 
		}
	 	
		fprintf(outFile_order,"%s\t%s\t%d:%02d:%02d:%02d:%02d\t%02d:%02d:%02d:00:00",touristsID, selectedID, yearNow, monthNow, dayNow, hourNow, minNow, yearGo, monthGo, dayGo);//���ʱ�� 
		fprintf(outFile_order,"\t%d\t%d\t%d\t%d\t%5.2f \n",children, adults, olds, sumTickets, price);//����� ���� �ܼ� 
		fclose(outFile_order);
	
	printf("\nԤ���ɹ���");
	
	T_person_order_changeOrder2(selectedID, sumTickets, tourDates); 
	T_person_order_changespot(selectedID, sumTickets);
	T_person_order_inquire(sumTickets, fullTickets, halfTicket, olds, soldiers, children, adults, touristsID);//ѯ���Ƿ����Ԥ�� 
	}
	
	else T_Menu();
}

int T_person_order_ticketVerify(char selectedID[], int sumTickets, int tourDates)
{
	int T = 1;
	FILE *outFile_data = fopen("order2.txt", "r");//�򿪿ɶ���ÿ�վ�����Ʊ����ļ�
	if(outFile_data == NULL)
	{
 		printf("�ļ�������");
		exit(1); 
 	}
 	
	int i = 0, j = 0;//����
	
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
	 		printf("�ļ�������");
	 		exit(1); 
	 	}
	 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 	  i ++;
	 	  
	 	fclose(outFile);
	 	int num_spot = i;//������+1
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
		printf("�ļ�������");
		exit(1);
	}
	
	int i = 0;//���� 
	while(fscanf(information, "%s %s %s %s %s %s %f %s %s %s %s\n",attract[i].PID, attract[i].Pname, attract[i].Pintro, attract[i].PHprice, attract[i].PLprice, attract[i].Ptime, &attract[i].Pdiscount, attract[i].Pclas, attract[i].Pnumber, attract[i].Parea, attract[i].Pfee) != EOF)
	{
		i ++;
	}
    fclose(information);
    int num_spot = i;//������+1
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
	 	printf("�ļ�������");
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
			
			result = spot[i].Sprice * fullTicket + spot[i].Sprice * cut *halfTicket; //��ʽ 
			else result = spot[i].Sprice * ( fullTicket + soldiers) + spot[i].Sprice * cut *halfTicket;//��ʽ 
		}
	}	
	return(result);
}

void T_person_order_changeOrder2(char selectedID[], int sumTickets, int tourDates)//�����ţ�Ʊ���ı��������� 
{
	int i = 0; 
	struct spot spot[1000];
	FILE *outFile = fopen("spot.txt", "r");//��ȡ������Ʊ�� 
 	if(outFile == NULL)
 	{
	 	printf("�ļ�������");
		exit(1); 
	 }
 	while(fscanf(outFile,"%s %s %d %f %d", spot[i].Scode, spot[i].Sname, &spot[i].Ssale, &spot[i].Sprice, &spot[i].Sticket) != EOF)
	 {
		i ++;
 	}
 	
 	int num_spot = i;//������+1
 	fclose(outFile);
 	
 	FILE *outFile_data = fopen("order2.txt","r");//�򿪿ɶ��ľ����ⲿ����order1.txt���ļ� 
	if(outFile_data==NULL)//���һ�β��ɹ��Ĵ�
	{
		printf("\n�ļ���ʧ�ܣ�����ϵ����Ա\n");
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
	
	FILE *inFile_data = fopen("order2.txt","w");//�򿪾����ⲿ����order1.txt�����ļ�
	int j = 0; 
	if(inFile_data==NULL)//���һ�β��ɹ��Ĵ�
	{
		printf("\n�ļ���ʧ�ܣ�����ϵ����Ա\n");
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
        printf("\n��ʧ��\n");
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
        printf("\n��ʧ��\n");
        exit(1);
    }
    
    for(i = 0; i < num_spot; i ++)
      fprintf(onFile,"%s\t%s\t%d\t%f\t%d\n",data[i].Scode,data[i].Sname,data[i].Ssale,data[i].Sprice,data[i].Sticket);
      
    fclose(onFile);

}

void T_person_order_inquire(int sumTickets, int fullTickets, int halfTicket, int olds, int soldiers, int children, int adults, char touristsID[])
{
	int choice;
	printf("\n���Ƿ�Ҫ����Ԥ���������㣺\n1.��\n2.�񣨷����ο��������˵���");
	scanf("%d",&choice);
	
	while(1)
	{
		if(choice==1||choice==2)
		{
			break;
		}
		printf("������ı������������ѡ��");
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
 
void T_person_order_datechange(int tourDates)//�����������иı�۸��Լ���Ʊ�� 
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
        printf("\n��ʧ��\n");
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
