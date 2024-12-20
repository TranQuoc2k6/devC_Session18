#include<stdio.h>
int main(){
	struct Student{
		char fullName[50];
		int age;
		char phone[20];
	};
	struct Student user01={"Tran Anh Quoc", 18, "0393130688"};
	printf("%s\n", user01.fullName);
	printf("%d\n", user01.age);
	printf("%s\n", user01.phone);
	return 0;
}
