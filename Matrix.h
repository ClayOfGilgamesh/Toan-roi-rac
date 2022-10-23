#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<string>
#include<cmath>
#include<Windows.h>
#include<vector>
using namespace std;
class matrix
{
	friend istream& operator>>(istream& in, matrix& m)
	{
		cout << "Enter the matrix:" << endl;
		for (int i = 0; i < m.row; ++i)
		{
			for (int j = 0; j < m.col; ++j)
			{
				cout << "element[" << i << "][" << j << "] = ";
				in >> m.data.at(i).at(j);

			}
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const matrix& m)
	{
		out << "The matrix" << endl;
		for (int i = 0; i < m.row; ++i)
		{
			for (int j = 0; j < m.col; ++j)
			{
				out << m.data.at(i).at(j) << " ";
			}
			out << endl;
		}
		return out;
	}
	friend matrix& operator+(matrix& n, matrix& m)
	{
		matrix temp(n);
		if (n.row != m.row || n.col != m.col)
		{
			cerr << "Matrix size do not match.";
			return n;
		}
		for (int i = 0; i < n.row; i++)
		{
			for (int j = 0; j < n.col; j++)
			{
				n.data.at(i).at(j) = n.data.at(i).at(j) + m.data.at(i).at(j);
			}
		}
		return n;
	}
	friend matrix& operator*(matrix& n, matrix& m)
	{
		if (n.row != m.col || n.col != m.row)
		{
			cout << "Matrix size do not match.";
			return n;
		}
		matrix c(n.row, m.col);
		for (int i = 0; i < n.row; ++i)
			for (int j = 0; j < m.col; ++j)
				for (int k = 0; k < n.col; ++k)
					c.data.at(i).at(j) = c.data.at(i).at(j) + n.data.at(i).at(k) * m.data.at(k).at(j);
		n = c;
		return n;
	}
public:
	matrix() {};
	matrix(int r, int c)
	{
		row = r;
		col = c;
		data.resize(row);
		for (int i = 0; i < row; i++)
		{
			data[i].resize(col);
			for (int j = 0; j < col; j++)
				data.at(i).at(j) = 0;
		}
	}
	matrix(matrix& m)
	{
		row = m.row;
		col = m.col;
		data.resize(row);
		for (int i = 0; i < row; i++)
		{
			data[i].resize(col);
			for (int j = 0; j < col; j++)
				data.at(i).at(j) = m.data.at(i).at(j);
		}
	}
	~matrix()
	{
		data.clear();
	}
	//operator overload
	matrix& operator=(matrix m)
	{
		row = m.row;
		col = m.col;
		data.resize(m.row);
		for (int i = 0; i< m.row; i++)
		{
			data.at(i).resize(m.col);
		}
		
		for (int i = 0; i < m.row; i++)
		{
			for (int j = 0; j < m.col; j++)
			{
				data.at(i).at(j) = m.data.at(i).at(j);
			}
		}
		return *this;
	}
	bool operator==(const matrix& m)
	{
		if (row != m.row || col != m.col) return false;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (data.at(i).at(j) != m.data.at(i).at(j)) return false;
			}
		}
		return true;
	}
	int getRow()
	{
		return row;
	}
	int getCol()
	{
		return col;
	}
	void setValue(int r, int c, int e)
	{
		data.at(r).at(c) = e;
	}
	int getValue(int r, int c)
	{
		return data.at(r).at(c);
	}
	matrix& thisMatrix() { return *this; }

private:
	int row;
	int col;
	vector<vector<int>> data;
};

#endif // !MATRIX_H
