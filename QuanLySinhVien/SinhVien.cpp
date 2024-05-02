#include "SinhVien.h"
#include <string>
#include <algorithm>
#include <iomanip>

SinhVien::SinhVien(std::string name, std::string mssv, std::string clas, std::string dpme)
{
	this->name = name;
	this->mssv = mssv;
	this->clas = clas;
	this->dpme = dpme;

}

SinhVien::SinhVien()
{
}

void SinhVien::setName(std::string name)
{
	this->name = name;
}

void SinhVien::setMssv(std::string mssv)
{ 
	this->mssv = mssv;
}

void SinhVien::setClas(std::string clas)
{
	this->clas = clas;
}

void SinhVien::setDpem(std::string dpme)
{
	this->dpme = dpme;
}

std::string SinhVien::getName()
{
	return this->name;
}

std::string SinhVien::getMssv()
{
	return this->mssv;
}

std::string SinhVien::getClas()
{
	return this->clas;
}

std::string SinhVien::getDpme()
{
	return this->dpme;
}

std::string SinhVien::toString()
{
	return this->name + " " + this->mssv + " " + this->clas + " " + this->dpme + " ";
}

void SinhVien::add(std::vector<SinhVien>& sv, SinhVien s)
{
	std::string tmp;
	std::cout << "NHAP THONG TIN SINH VIEN\n" << std::endl;
	std::cin.ignore(256, '\n');
	std::cout << "Ho va ten sinh vien: "; std::getline(std::cin, tmp);
	s.setName(tmp);
	std::cout << "Mssv: "; std::getline(std::cin, tmp);
	s.setMssv(tmp);
	std::cout << "Lop: "; std::getline(std::cin, tmp);
	s.setClas(tmp);
	std::cout << "Khoa: "; std::getline(std::cin, tmp);
	s.setDpem(tmp);
	sv.push_back(s);
	std::cout << "\nDa nhan du lieu xong" << std::endl;
}

void SinhVien::del(std::vector<SinhVien>& sv, SinhVien s, size_t pos)
{
	system("cls");
	std::cout << "THONG TIN SINH VIEN: " << sv[pos].getMssv() << std::endl;
	std::cout << "Ho va ten sinh vien: " << sv[pos].getName() << std::endl;
	std::cout << "Lop: " << sv[pos].getClas() << std::endl;
	std::cout << "Khoa: " << sv[pos].getDpme() << std::endl;

	char choice;
	std::cout << "\nBan co chac chan xoa (y/n): "; std::cin >> choice;
	if (choice == 'y') {
		std::swap(sv[pos], sv.back());
		sv.pop_back();
		std::cout << "Da xoa thanh cong!!!" << std::endl;
	}
	if (choice == 'n') {
		std::cout << "\nTro lai menu..." << std::endl;
	}
}

void SinhVien::edit(std::vector<SinhVien>& sv, size_t pos)
{
	int choice;
	bool flag = true;
	do {
		system("cls");
		std::cout << "THONG TIN SINH VIEN: " << sv[pos].getMssv() << std::endl;
		std::cout << "Ho va ten sinh vien: " << sv[pos].getName() << std::endl;
		std::cout << "Lop: " << sv[pos].getClas() << std::endl;
		std::cout << "Khoa: " << sv[pos].getDpme() << std::endl;
		
		std::cout << "<<<<<<<<<<<<<<<<<<<<" << std::endl;
		std::cout << "1. Sua ho va ten" << std::endl;
		std::cout << "2. Sua lop" << std::endl;
		std::cout << "3. Sua khoa" << std::endl;
		std::cout << "0. Khong sua" << std::endl;
		std::cout << "<<<<<<<<<<<<<<<<<<<<" << std::endl;
		
		std::cout << "Moi ban chon: "; std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cin.ignore(265, '\n');
			std::string tmp;
			std::cout << "Ho va ten sinh vien: ";
			std::getline(std::cin, tmp);
			sv[pos].setName(tmp);
			std::cout << "Doi thanh cong" << std::endl;
		}
			system("pause");
			break;
		case 2: {
			std::cin.ignore(265, '\n');
			std::string tmp;
			std::cout << "Lop: ";
			std::getline(std::cin, tmp);
			sv[pos].setClas(tmp);
			std::cout << "Doi thanh cong" << std::endl;
		}
			system("pause");
			break;
		case 3: {
			std::cin.ignore(265, '\n');
			std::string tmp;
			std::cout << "Khoa: ";
			std::getline(std::cin, tmp);
			sv[pos].setDpem(tmp);
			std::cout << "Doi thanh cong" << std::endl;
		}
			system("pause");
			break;
		
		default: {
			std::cout << "Thoat sua thong tin" << std::endl;
			flag = false;
		}
		}
	} while (flag);
}

void SinhVien::show(std::vector<SinhVien>& sv)
{	
	std::cout << "DANH SACH THONG TIN SINH VIEN\n" << std::endl;
	if (sv.size() == 0) std::cout << "Danh sach rong" << std::endl;
	else {
		std::cout << "+" << std::setfill('-') << std::setw(13) << "+"
			<< std::setfill('-') << std::setw(24) << "+"
			<< std::setfill('-') << std::setw(18) << "+"
			<< std::setfill('-') << std::setw(25) << "+" << std::endl;
		std::cout << std::left << std::setfill(' ') << "|" << std::setw(12) << "MSSV"
			<< std::setfill(' ') << "|" << std::setw(23) << "Ho va Ten"
			<< std::setfill(' ') << "|" << std::setw(17) << "Lop"
			<< std::setfill(' ') << "|" << std::setw(24) << "Khoa"
			<< std::right << "|" << std::endl;
		std::cout << std::right << "+" << std::setfill('-') << std::setw(13) << "+"
			<< std::setfill('-') << std::setw(24) << "+"
			<< std::setfill('-') << std::setw(18) << "+"
			<< std::setfill('-') << std::setw(25) << "+" << std::endl;
		for (size_t i = 0; i < sv.size(); ++i) {
			std::cout << std::left << std::setfill(' ') << "|" << std::setw(12) << sv[i].getMssv()
				<< std::setfill(' ') << "|" << std::setw(23) << sv[i].getName()
				<< std::setfill(' ') << "|" << std::setw(17) << sv[i].getClas()
				<< std::setfill(' ') << "|" << std::setw(24) << sv[i].getDpme()
				<< std::right << "|" << std::endl;
		}
		std::cout << std::right << "+" << std::setfill('-') << std::setw(13) << "+"
			<< std::setfill('-') << std::setw(24) << "+"
			<< std::setfill('-') << std::setw(18) << "+"
			<< std::setfill('-') << std::setw(25) << "+" << std::endl;
	}
}






