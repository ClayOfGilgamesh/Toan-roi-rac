#pragma once
#ifndef GARPH_H
#define GARPH_H
#include"danhsachcanh.h"
#include"danhsachke.h"
#include"Matrix.h"

class Garph:public matrix,public danhsachcanh,public danhsachke
{
private:
	int size;
public:
	Garph(int);
	Garph(matrix&);
	void Mtk_dsc() {
		for (int i = 0; i < matrix::getRow(); i++)
		{
			for (int j = 0; j < matrix::getCol(); j++)
				if (matrix::getValue(i, j) == 1) danhsachcanh::add_edge(i, j);
		}
	}
	void Mtk_dsk()
	{
		for (int i = 0; i < matrix::getRow(); i++)
		{
			for (int j = 0; j < matrix::getCol(); j++)
				if (matrix::getValue(i, j) == 1) danhsachke::add_ke(i,j);
		}
	}
	int egdNum()
	{
		int count = 0;
		int k;
		int l;
		for ( k=0; k < matrix::getRow(); k++)
			for ( l=0; l < matrix::getCol(); l++)
				if (matrix::getValue(k, l) == 1)
					count++;
		return count;
	}
	int getGsize() { return size; }
};
Garph::Garph(int s):matrix(s,s),danhsachke(s)
{
	size = s;
}
Garph::Garph(matrix& m) :matrix(m),danhsachke(m.getCol())
{
	size = m.getCol();
}

#endif // !GARPH_H

