#include <stdio.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
int main() {
    struct SinhVien sv[50];
    int i;
    for(i = 0; i < 5; i++) {
        sv[i].id = i + 1;
        printf("Nhap thong tin sinh vien thu %d:\n", sv[i].id);

        printf("Nhap ten sinh vien: ");
        fgets(sv[i].name, sizeof(sv[i].name), stdin);

        printf("Nhap tuoi sinh vien: ");
        scanf("%d", &sv[i].age);
        getchar();

        printf("Nhap so dien thoai sinh vien: ");
        fgets(sv[i].phoneNumber, sizeof(sv[i].phoneNumber), stdin);

        printf("\n");
    }
    printf("Thong tin cac sinh vien da nhap:\n");
    for(i = 0; i < 5; i++) {
        printf("Sinh vien thu %d:\n", sv[i].id);
        printf("Ten: %s", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s", sv[i].phoneNumber);
        printf("\n");
    }

    return 0;
}

