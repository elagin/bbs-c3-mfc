#include "StdAfx.h"

#include <fstream>
#include "Worker.h"

#include <iostream>

string CWorker::setCell(const string & aSrt)
{
	string res;
	res.append("\"");
	res.append(aSrt);
	res.append("\"");
	return res;
}


bool CWorker::start( const TDATA & aData, const CString & aFileName )
{
	CWaitCursor cursor;
	ofstream os;
	os.open (aFileName, ios::app);
	os << "Number #1;Formatted #1;Number #2;Formatted #2" << endl;

	if( aData.firstEnd > aData.firstStart )
	{
		long count = aData.firstEnd - aData.firstStart;

		long j = aData.secondStart;
		for(long i = aData.firstStart; i <= (aData.firstStart + count);  )
		{
			os << setCell(lexical_cast<string>(i))
				<< ";"
				<< setCell(format(lexical_cast<string>(i)))
				<< ";"
				<< setCell(lexical_cast<string>(j))
				<< ";"
				<< setCell(format(lexical_cast<string>(j)))
				<< ";"
				<< endl;
			j+=11;
			i+=11;
		}
	}
	os.close();
	return true;
}

string CWorker::format( const string & aStr )
{
	string res = aStr;
	res.insert( 2, "-");
	res.insert( 7, "-");
	return res;
}
