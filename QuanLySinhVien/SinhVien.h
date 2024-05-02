#ifndef SINHVIEN_H
#define SINHVIEN_H
#pragma once
#include <iostream>
#include <vector>

class SinhVien
{
private:
	std::string name;
	std::string mssv;
	std::string clas;
	std::string dpme;
public:
	SinhVien(std::string name, std::string mssv, std::string clas, std::string dqme);
	SinhVien();
	void setName(std::string name);
	void setMssv(std::string mssv);
	void setClas(std::string clas);
	void setDpem(std::string dpme);
	std::string getName();
	std::string getMssv();
	std::string getClas();
	std::string getDpme();

	std::string toString();
	void add(std::vector<SinhVien> &sv, SinhVien s);
	void del(std::vector<SinhVien>& sv, SinhVien s, size_t pos);
	void edit(std::vector<SinhVien>& sv, size_t pos);
	void show(std::vector<SinhVien> &sv);
};

#endif // !SINHVIEN_H

