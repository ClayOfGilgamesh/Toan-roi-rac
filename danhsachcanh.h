#pragma once
#ifndef DANHSACHCANH_H
#define DANHSACHCANH_H
#include<iostream>
#include<vector>
using namespace std;
class danhsachcanh {
private:
	vector<pair<int,int>>DScanh;
public:
	danhsachcanh() { }
	void add_edge(int f, int s) {DScanh.push_back({f,s}); }
	void show_edge()
	{
		cout << "danh sach canh" << endl;
		cout << "Dinh1               Dinh2" << endl;
		for (int i = 0; i < DScanh.size(); i++)
		{
			cout <<" " << (DScanh[i].first)+1 << "                    " << (DScanh[i].second)+1 << endl;
		}
	}
	int sizecanh() { return DScanh.size(); }
	int first(int i) { return DScanh[i].first;}
	int second(int i) { return DScanh[i].second;}
	danhsachcanh& thisDScanh() { return *this; }
};
#endif // !DANHSACHCANH_H

