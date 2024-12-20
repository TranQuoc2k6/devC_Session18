#include<stdio.h>
#include<string.h>

int main(){
    struct Dish{
        int id;
        char name[50];
        float price;
    };

    struct Dish dishMenu[100] = {{1, "Pizza", 450000},{2, "Salad", 300000},{3, "Sushi", 500000},{4, "Hamburger", 200000},{5, "Udon", 400000}};
    int menuSize = 5;
    int choice;

    do {
        printf("\n\n\t\t\t----MENU----\n");
        printf("1. In ra gia tri cac phan tu co trong menu mon an\n");
        printf("2. Them mot phan tu vao vi tri cuoi cung\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu tang gian theo gia\n");
        printf("6. Tim kiem phan tu theo name nhap vao tim kiem tuyen tinh\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                printf("\nDanh sach mon an\n");
                for (int i = 0; i < menuSize; i++) {
                    printf("%d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
                }
                break;
            }
            case 2: {
                if (menuSize < 100) {
                    struct Dish newDish;
                    printf("\nNhap id: ");
                    scanf("%d", &newDish.id);
                    getchar();
                    printf("Nhap ten mon an: ");
                    fgets(newDish.name, 50, stdin);
                    newDish.name[strcspn(newDish.name, "\n")] = 0; 
                    printf("Nhap gia: ");
                    scanf("%f", &newDish.price);

                    dishMenu[menuSize++] = newDish;
                    printf("Them mon an thanh cong\n");

                    printf("\nDanh sach mon an sau khi them:\n");
                    for (int i = 0; i < menuSize; i++) {
                        printf("%d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
                    }
                } else {
                    printf("Menu da day!\n");
                }
                break;
            }
            case 3: {
                int pos;
                printf("\nNhap vi tri can sua (1-%d): ", menuSize);
                scanf("%d", &pos);
                if (pos >= 1 && pos <= menuSize) {
                    struct Dish updatedDish;
                    printf("Nhap id moi: ");
                    scanf("%d", &updatedDish.id);
                    getchar();
                    printf("Nhap ten mon an moi: ");
                    fgets(updatedDish.name, 50, stdin);
                    updatedDish.name[strcspn(updatedDish.name, "\n")] = 0;
                    printf("Nhap gia moi: ");
                    scanf("%f", &updatedDish.price);
                    dishMenu[pos - 1] = updatedDish;
                    printf("Sua mon an thanh cong!\n");
                    printf("\nDanh sach mon an sau khi sua:\n");
                    for (int i = 0; i < menuSize; i++) {
                        printf("%d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
                    }
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            }
            case 4: {
                int pos;
                printf("\nNhap vi tri can xoa (1-%d): ", menuSize);
                scanf("%d", &pos);
                if (pos >= 1 && pos <= menuSize) {
                    for (int i = pos - 1; i < menuSize - 1; i++) {
                        dishMenu[i] = dishMenu[i + 1];
                    }
                    menuSize--;
                    printf("Xoa mon an thanh cong!\n");
                    printf("\nDanh sach mon an sau khi xoa:\n");
                    for (int i = 0; i < menuSize; i++) {
                        printf("%d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
                    }
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            }
            case 5: {
                for (int i=0; i<menuSize-1; i++) {
                    for (int j = i + 1; j < menuSize; j++) {
                        if (dishMenu[i].price > dishMenu[j].price) {
                            struct Dish temp = dishMenu[i];
                            dishMenu[i] = dishMenu[j];
                            dishMenu[j] = temp;
                        }
                    }
                }
                printf("\nDanh sach sau khi sap xep tang dan theo gia:\n");
                for(int i=0; i<menuSize; i++){
                	printf("%d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
				}
                break;
            }
            case 6: {
                char searchName[50];
                printf("\nNhap ten mon an can tim: ");
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;
                int found = 0;
                for (int i = 0; i < menuSize; i++) {
                    if (strcmp(dishMenu[i].name, searchName) == 0) {
                        printf("Tim thay: %d. %s: %.f\n", dishMenu[i].id, dishMenu[i].name, dishMenu[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay mon an\n");
                }
                break;
            }
            case 7: {
                printf("Thoat chuong trinh\n");
		printf("Vui long nhan Enter");
                break;
            }
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);
    return 0;
}

