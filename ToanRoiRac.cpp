

#include"Garph.h"
#include"danhsachcanh.h"
#include"danhsachke.h"
#include"Matrix.h"
#include"XuLyFile.h"
using namespace std;
int main()
{
	
		matrix a(6, 6);
		matrix b(5, 5);
		string file = "input1.txt";
		string file2 = "input2.txt";
		string file1_1 = "input1_1.txt";
		string file1_2 = "input1_2.txt";
		Garph g(6);
		DocFileM(file, g.thisMatrix());
		g.Mtk_dsc();
		XuatFileDScanh(file1_1, g.thisDScanh());
		g.show_edge();
		g.Mtk_dsk();
		//XuatFileDSke(file1_2, g.thisDSke());
		//g.show_ke();
		danhsachke c(6);
        return 0;
}


