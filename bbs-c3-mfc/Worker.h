#pragma once
#include <string>
using namespace std;
class CWorker
{
public:
	CWorker(void);
	bool start(data & aData, CString aFileName);
	~CWorker(void);

	string format(string & aStr);

private:
	CString aa;
};
