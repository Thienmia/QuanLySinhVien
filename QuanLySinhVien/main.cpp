#include <iostream>
#include <vector>
#include <cstdio>
#include "SinhVien.h"

void menu();

int main()
{
    std::vector<SinhVien> sv;
    SinhVien s;
    int choice;
    bool flag = true;
    do {
        system("cls");
        menu();
        std::cout << "Nhap lua chon: "; std::cin >> choice;
        switch (choice) {
            case 1:
                system("cls");
                s.add(sv, s);
                system("pause");
                break;
            case 2: {
                    std::string tmp;
                    bool isDel = false;
                    std::cout << "Nhap vao mssv: "; std::cin >> tmp;
                    for (size_t i = 0; i < sv.size(); ++i) {
                        if (sv[i].getMssv() == tmp) {
                            s.del(sv, s, i);
                            isDel = true;
                            break;
                        }
                    }
                    if (!isDel) std::cout << "Khong tim thay" << std::endl;
                }
                system("pause");
                break;
            case 3: {
                    std::string tmp;
                    bool isDel = false;
                    std::cout << "Nhap vao mssv: "; std::cin >> tmp;
                    for (size_t i = 0; i < sv.size(); ++i) {
                        if (sv[i].getMssv() == tmp) {
                            system("cls");
                            s.edit(sv, i);
                            isDel = true;
                            break;
                        }
                    }
                    if (!isDel) std::cout << "Khong tim thay" << std::endl;
                }
                system("pause");
                break;
            case 4:
                system("cls");
                s.show(sv);
                system("pause");
                break;
            default:
                flag = false;
                break;
        }
    } while (flag);
    return 0;
}

void menu()
{
    std::cout << "================= MENU =================" << std::endl;
    std::cout << "1. Them thong tin sinh vien" << std::endl;
    std::cout << "2. Xoa thong tin sinh vien" << std::endl;
    std::cout << "3. Chinh sua thong tinh sinh vien" << std::endl;
    std::cout << "4. Hien thi danh sach thong tin sinh vien" << std::endl;
    std::cout << "0. Thoat" << std::endl;
    std::cout << "========================================" << std::endl;
}
