#include <stdio.h>

#define INFORMATION_FORMAT "%05u;%s;%s;%s;%s;%s;%s;%s\n"
//ID;NAME;SEX;AGE;EDU;SAL;ADD;TEL

FILE* dbfp;	//Database file pointer.
unsigned int idLast = 0;
unsigned int memberNum = 0;
char name[100];
char sex[100];
char age[100];
char edu[100];
char sal[100];
char add[100];
char tel[100];

int init();
int newAccount();
int viewAccount();
int searchAccount();
int editAccount();

int main(void)
{
	printf("\nWelcome to Staff Information Manage System.\n\n");
	if(init() == 0){
		
	}
	else{
		printf("Init failed\n");
		return -1;
	}
	while(1){
		int funcSelect = 0;
		printf("\n	***  Function list  ***\n");
		printf("	1. Create a new account.\n");
		printf("	2. View the staff list.\n");
		printf("	3. Search a staff member.\n");
		if(scanf("%d",&funcSelect)){
			printf("\n");
			switch(funcSelect){
				case 1:
				if(newAccount()==0){
					printf("New account has been successfully created.\n");
				}
				else{
					printf("Operation failed.\n");
				}
				break;
				case 2:
				if(viewAccount()==0){
					printf("All members were shown\n");
				}
				else{
					printf("Operation failed.\n");
				}
				break;
				case 3:
				if(searchAccount()==0){
					printf("Search finished.\n");
				}
				else{
					printf("Account not found, operation failed.\n");
				}
				break;
				default:
				return 0;
				break;
			}
		}
		else{
			return 0;
		}
		
	}
	fclose(dbfp);
	return 0;
}
//Initialize
int init(){
	if(dbfp = fopen("./SIMS_DATABASE.db", "a+")){	//A txt based database...
		char* temp;
		FILE* fptemp = dbfp;
		while(fscanf(fptemp,"%05u%s",&idLast,temp)>0)		//Get the last ID.
			memberNum++;
		printf("%u members' information loaded. The last ID is:%05u\n",memberNum,idLast);
	}
	else{
		return -1;
	}
	return 0;
}

int newAccount(){
	idLast++;
	printf("The new account id is %05u.\n",idLast);
	printf("Please insert the NAME:");
	scanf("%s",name);
	printf("Please insert the SEX:");
	scanf("%s",sex);
	printf("Please insert the AGE:");
	scanf("%s",age);
	printf("Please insert the EDUCATION:");
	scanf("%s",edu);
	printf("Please insert the SALLARY:");
	scanf("%s",sal);
	printf("Please insert the ADDRESS:");
	scanf("%s",add);
	printf("Please insert the TELEPHONE NUMBER:");
	scanf("%s",tel);
	printf("\n");
	FILE* fptemp = dbfp;
	fseek(fptemp,0L,SEEK_END);
	fprintf(fptemp,INFORMATION_FORMAT,idLast,name,sex,age,edu,sal,add,tel);
	fflush(fptemp);
	return 0;
}

int viewAccount(){
	FILE* fptemp = dbfp;
	fseek(fptemp,0L,SEEK_SET);
	unsigned int id;
	printf("ID	NAME	SEX	AGE	EDU	SAL	ADD	TEL\n");
	while(fscanf(fptemp,"%05u;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s",&id,name,sex,age,edu,sal,add,tel)>0)
		printf("%05u	%s	%s	%s	%s	%s	%s	%s\n",id,name,sex,age,edu,sal,add,tel);
	return 0;
}

int searchAccount(){
	FILE* fptemp = dbfp;
	fseek(fptemp,0L,SEEK_SET);
	unsigned int id,id2;
	printf("Please insert ID to search an account:");
	scanf("%u",&id);
	while(fscanf(fptemp,"%05u;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s",&id2,name,sex,age,edu,sal,add,tel)>0){
		if(id == id2){
		printf("ID	NAME	SEX	AGE	EDU	SAL	ADD		TEL\n");
		printf("%05u	%s	%s	%s	%s	%s	%s		%s\n",id,name,sex,age,edu,sal,add,tel);
		return 0;
		}
	}
	return -1;
}
