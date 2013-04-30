#include "DataConnection.h"

//数据库操作封装类，采用ADO技术实现


//Constructor
DataConnection::DataConnection()
{
	//do nothing
}

//Destructor
DataConnection::~DataConnection()
{
	//do nothing
}

//Initialize connectiong to database
void  DataConnection::OnInitADOConn()
{
	
	::CoInitialize(NULL);
	HRESULT hr;
	
	try
	{	
		hr = m_pConnection.CreateInstance("ADODB.Connection");
		
		if(m_pConnection->State) m_pConnection->Close(); 

		if( SUCCEEDED(hr) )
		{
			m_pConnection->ConnectionTimeout = 5;
			_bstr_t strConnect = "Provider=SQLOLEDB;Server=127.0.0.1;Database=tool;uid=sa;pwd="; //连接本机SQL Server数据库软件中的tool数据库
			m_pConnection->Open(strConnect,"","",adModeUnknown);
		}
	}
	
	catch(_com_error e) //连接失败，比如SQL Server数据库没装
	{
		MessageBox(NULL,e.Description(),"Information",MB_ICONINFORMATION | MB_OK);
	}
}

//Get record of database
bool DataConnection::GetRecordSet(_RecordsetPtr &m_pRecordset , _bstr_t bstrSQL)
//第一个参数是引用类型，也就是传出参数，可看做函数的返回值，第二个参数是SQL语句，是输入。
{
	try
	{	
		if(m_pConnection==NULL) //初始化连接
			OnInitADOConn();
		
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pConnection->CursorLocation = adUseClient;
		
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		return true;
	}
	
	catch(_com_error e) //失败
	{		
		MessageBox(NULL,e.Description(),"提示",MB_ICONINFORMATION | MB_OK);
		return false;
	}
}


BOOL DataConnection::ExecuteSQL(_bstr_t bstrSQL)
{	
	try
	{	
		if(m_pConnection == NULL) //初始化连接
		{
			OnInitADOConn();
		}
		
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e) //失败
	{
		MessageBox(NULL,e.Description(),"Information",MB_ICONINFORMATION | MB_OK);
		return false;
	}
}

//Close the connection
//关闭记录集和连接
void DataConnection::ExitConnect()
{

	if (m_pRecordset != NULL)
	{
		m_pRecordset->Close();
	}
	m_pConnection->Close();
	::CoUninitialize();
}

