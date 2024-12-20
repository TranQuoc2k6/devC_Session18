#include<stdio.h>
int main(){
	struct Student{
		char fullName[50];
		int age;
		char phoneNumber[20];
	};
	struct Student user01;
	printf("Moi ban nhap thong tin cho sinh vien 01:\n");
	printf("Ho va ten: ");
	fgets(user01.fullName, sizeof(user01.fullName), stdin);
	printf("Tuoi: ");
	scanf("%d", &user01.age);
	fflush(stdin);
	printf("So dien thoai: ");
	fgets(user01.phoneNumber, sizeof(user01.phoneNumber), stdin);
	return 0;
}

