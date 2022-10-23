#pragma once
#ifndef XULYFILE_H
#define XULYFILE_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include"Garph.h"
#include"Matrix.h"
#include"danhsachcanh.h"
using namespace std;



void DocFileM(string file, matrix& a) 
{

    ifstream input(file);
    int t = 0;
    string title;
    getline(input, title);
    title.clear();
    for (int rows = 0; rows < a.getRow(); ++rows)
    {
        string line;
        getline(input, line);
        for (int cols = 0; cols < a.getCol(); cols++)
        {
            string element = "";
            while (t < line.length())
            {
                if (line[t] != ' ') { element = line[t]; break; }
                else { t++; }
            }
            a.setValue(rows, cols, atoi(element.c_str()));
            t++;
            element.clear();
        }
        t = 0;
        line.clear();
    }
}

/*
    hàm này xuất ma trận ra file
*/
void XuatFileM(string file, matrix a,const char* title) {
    ofstream output(file);
    output << title << endl;
    for (int i = 0; i < a.getRow(); ++i)
    {
        for (int j = 0; j < a.getCol(); ++j)
        {
            output << a.getValue(i,j) << "  ";
        }
        output << endl;
    }
}
void XuatFileDScanh(string file, danhsachcanh ds)
{
    ofstream output(file);
    //output << title << endl;
    output << "Dinh1               Dinh2" << endl;
    for (int i = 0; i < ds.sizecanh(); i++)
    {
        output <<" "<< ds.first(i) << "                    " << ds.second(i) << endl;
    }
}
void DocDScanh(string file, danhsachcanh& ds,int size)
{
    ifstream input(file);
    string title;
    getline(input, title);
    for (int i = 0; i < size; i++)
    {
        string line;
        int t = 0;
        getline(input, line);
        string element1 = "";
        string element2 = "";
        while (line[t] == ' ') { t++; }
        element1 = line[t];
        t++;
        while (line[t] == ' ') { t++; }
        element2 = line[t];
        ds.add_edge(atoi(element1.c_str()), atoi(element2.c_str()));
        element1.clear();
        element2.clear();
    }
}
void XuatFileDSke(string file, danhsachke DSke)
{
    ofstream output(file);
    output << "Dinh                      ke" << endl;
    for (int i = 0; i < DSke.sizeke(); i++)
    {
        output << " " << (i + 1) << "                    ";
        for (int j = 0; j < DSke.get_ke(i).size(); j++)
            output << DSke.get_ke(i).at(j) + 1 << "  ";
        output << endl;
    }
}
void DocFileDSke(string file, danhsachke ds,int size)
{
    ifstream input(file);
    string title;
    getline(input, title);
    for (int i = 0; i < size; i++)
    {
        string line;
        int t = 0;
        getline(input, line);
        
        while (t < line.length())
        {
            string element = "";
            if (line[t] != ' ') { element = line[t]; ds.add_ke(i, atoi(element.c_str())); t++;}
            else { t++; element.clear(); }
        }  
        t = 0;   
    }
}

#endif // !XULYFILE_H

