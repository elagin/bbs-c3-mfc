#pragma once
#include <string>
using namespace std;
class CWorker
{
public:
	bool start(const data & aData, const CString & aFileName);
	string format(const string & aStr);

private:
	bool checkFile( const CString & fileName );
	string setCell(const string & aSrt);

private:
	CString aa;
};
