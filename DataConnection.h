#ifndef _DATACONNECTION_H_
#define _DATACONNECTION_H_

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")

#if !defined(AFX_ADOCONN_H__F6DE5F99_6D46_4C88_9477_B340501EA230__INCLUDED_)
#define AFX_ADOCONN_H__F6DE5F99_6D46_4C88_9477_B340501EA230__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DataConnection
{	
public:
	DataConnection();
	virtual ~DataConnection();
	void  OnInitADOConn();
	bool GetRecordSet(_RecordsetPtr &m_pRecordset , _bstr_t bstrSQL);
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void ExitConnect();

private:
	_ConnectionPtr m_pConnection;//添加一个指向Connection对象的指针:
	_RecordsetPtr m_pRecordset;	//添加一个指向Recordset对象的指针:
};

#endif // !defined(AFX_ADOCONN_H__F6DE5F99_6D46_4C88_9477_B340501EA230__INCLUDED_)

#endif