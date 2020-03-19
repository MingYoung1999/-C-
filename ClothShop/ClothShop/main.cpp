//2019/11/25
//資工三 陳茗洋 106590038
//開一間衣服店發大財

#include "MallUI.h"
#include "mall.h"
using namespace std;

int main()
{
	mall mall;
	MallUI ui(mall);
	ui.Execute();
	system("pause");
	return 0;
}