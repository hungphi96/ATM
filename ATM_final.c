#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i=0;
char taikhoan[4]="abc";
char matkhau[4]="123";
int luachon;
char Y = 'Y';
int rut,chuyen,stknhan,sodu=3000000;

void menu(void);
int login (char username[3],char password[3]);
char withdarw (int num);
char transfer (int id, int num);
char Check();

int main(int argc, char *argv[]) {
	fflush(stdin);
	printf("==== Chao mung ban den voi ATM ===");
	do {
		i++;
		if (login(taikhoan,matkhau)==1) {
			do {
				menu();
				scanf("%d", &luachon);
				switch (luachon) {
					case 2:
						Y=withdarw(rut);
						break;
					case 3:
						Y=transfer(stknhan,chuyen);
						break;
					case 4:
						Y= Check();
						break;
					case 5:
						printf("\nBan da chon thoat ra.");
						return;
						break;
					default:
						printf("\nBan phai chon theo menu.");
						printf("\nban muon tiep tuc khong? (Y/N):");
						scanf("%s", &Y);
						break;
				}

			} while (Y=='y'||Y=='Y');
		}
	} while(i<3 && (Y =='y'||Y=='Y'));
	if(i==3) printf("\nBan da nhap sai qua 3 lan");
	
	return 0;
}

void menu(void) {
	printf("\nXin moi lua chon:");
	printf("\n2. Rut tien.");
	printf("\n3. Chuyen tien.");
	printf("\n4. Kiem tra so du.");
	printf("\n5. Thoat ra.");
	printf("\n");
}

int login (char username[4],char password[4]) {
	char username_temp[4]="";
	char password_temp[4]="";
	printf("\nmoi ban nhap tai khoan: ");
	scanf("%s", &username_temp);
	printf("\nhap mat khau: ");
	scanf("%s", &password_temp);
	if(strcmp(username_temp, username)==0 && strcmp(password_temp, password) == 0) {
		printf("\nban da dang nhap thanh cong");
		return 1;
	} else {
		printf("\nban da nhap sai tai khoan hoac mat khau");
		return 0;
	}
}

char withdarw (int num) {
	char Y;
	printf ("nhap so tien muon rut : ");
	scanf("%d", &num);
	if(num%50==0 && num < 3000000 && num<=sodu ) {
		sodu=sodu-num;
		printf("\nban da rut %d dong.", num);
		printf("\nban muon tiep tuc khong? (Y/N):");
		scanf("%s", &Y);
	} else {
		printf("\nban nhap so tien khong hop le");
		printf("\nban muon tiep tuc khong? (Y/N):");
		scanf("%s", &Y);
	}
	return Y;
}

char transfer (int id, int num) {
	printf("Nhap so tai khoan gui den: ");
	scanf("%d", &id);
	printf("\nban muon chuyen bao nhieu? ");
	scanf("%d", &num);
	if(num<=sodu) {
		sodu = sodu-num;
		printf("Ban da chuyen %d dong den so tai khoan %d\n", num, id);
		printf("ban muon tiep tuc ko? (Y/N):");
		scanf("%s", &Y);
	} else {
		printf("so tai khoan cua ban khong du de chuyen khoan");
		printf("ban muon tiep tuc khong? (Y/N):");
		scanf("%s", &Y);
	}
	return Y;
}

char Check() {
	char Y;
	printf("\nso du cu ban la: %d dong", sodu);
	printf("\nban co muon tiep tuc ko? (Y/N):");
	scanf("%s", &Y);
	return Y;
}


