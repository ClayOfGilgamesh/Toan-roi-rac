#pragma once
#ifndef DANHSACHKE_H
#define DANHSACHKE_H

#include<iostream>
#include<vector>
using namespace std;

class danhsachke
{
private:
	vector<vector<int>> DSke;

public:
	danhsachke(int size) { DSke.resize(size); }
	void  add_ke(int dinh, int  ke)
	{  
		DSke[dinh-1].push_back(ke-1);
	}
	void show_ke()
	{
		cout << "danh sach ke" << endl;
		cout << "Dinh                      ke" << endl;
		for (int i = 0; i < DSke.size(); i++)
		{
			cout << " " << (i + 1) << "                    ";
			for(int j=0;j<DSke.at(i).size(); j++)
				cout<<DSke.at(i).at(j)+1<<"  ";
			cout << endl;
		}
		
	}
	int sizeke() { return DSke.size(); }
	vector<int> get_ke(int dinh) { return DSke.at(dinh); }
	danhsachke& thisDSke() { return *this; }
};

#endif // !DANHSACHKE_H
