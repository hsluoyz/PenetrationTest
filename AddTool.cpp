// AddTool.cpp : implementation file
//

#include "stdafx.h"
#include "PentestTool.h"
#include "AddTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// AddTool dialog


AddTool::AddTool(CWnd* pParent /*=NULL*/)
	: CDialog(AddTool::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddTool)
	m_Priority = 0;
	//}}AFX_DATA_INIT
}

//Initialize the dialog box
BOOL AddTool::OnInitDialog()
{
	CDialog::OnInitDialog();
	return true;
}

void AddTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddTool)
	DDX_Text(pDX, IDC_EDIT_PRIORITY, m_Priority);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddTool, CDialog)
	//{{AFX_MSG_MAP(AddTool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// AddTool message handlers

//Get tool's cve number
CString AddTool::GetCveNumber() const
{
	return mCve;
}

//Get tool's store path
CString AddTool::GetPath() const
{
	return mPath;
}

//Get tool's name
CString AddTool::GetName() const
{
	return mName;
}

//Get tool's description
CString AddTool::GetDescription() const
{
	return mDescription;
}

//Get tool's priority
int	AddTool::GetPriority() const
{

	return mPriority;
}

//Get tool's method
CString AddTool::GetMethod() const
{
	return mMethod;
}

//Get tool's first command
CString AddTool::GetCommand1() const
{
	return mCommand1;
}

//Get tool's second command if exist
CString AddTool::GetCommand2() const
{
	return mCommand2;
}

//Get tool's third command if exist
CString AddTool::GetCommand3() const
{
	return mCommand3;
}

//Get tool's first parameter of first command if exist
CString AddTool::GetParameter11() const
{
	return mParameter11;
}

//Get tool's second parameter of first command if exist
CString AddTool::GetParameter12() const
{
	return mParameter12;
}

//Get tool's third parameter of first command if exist
CString AddTool::GetParameter13() const
{
	return mParameter13;
}

//Get tool's four parameter of first command if exist
CString AddTool::GetParameter14() const
{
	return mParameter14;
}

//Get tool's first parameter of second command if exist
CString AddTool::GetParameter21() const
{
	return mParameter21;
}

//Get tool's second parameter of second command if exist
CString AddTool::GetParameter22() const
{
	return mParameter22;
}

//Get tool's third parameter of second command if exist
CString AddTool::GetParameter23() const
{
	return mParameter23;
}

//Get tool's four parameter of second command if exist
CString AddTool::GetParameter24() const
{
	return mParameter24;
}

//Get tool's first parameter of third command if exist
CString AddTool::GetParameter31() const
{
	return mParameter31;
}

//Get tool's second parameter of third command if exist
CString AddTool::GetParameter32() const
{
	return mParameter32;
}

//Get tool's third parameter of third command if exist
CString AddTool::GetParameter33() const
{
	return mParameter33;
}

//Get tool's four parameter of third command if exist
CString AddTool::GetParameter34() const
{
	return mParameter34;
}

//Set values of all CEDIT and return
void AddTool::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	mPriority = m_Priority;
	GetDlgItem(IDC_EDIT_CVE)->GetWindowTextA(mCve);
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(mName);
	GetDlgItem(IDC_EDIT_PATH)->GetWindowText(mPath);
	GetDlgItem(IDC_EDIT_DESCRIPTION)->GetWindowText(mDescription);
	GetDlgItem(IDC_EDIT_METHOD)->GetWindowText(mMethod);
	
	GetDlgItem(IDC_EDIT_COMMAND1)->GetWindowText(mCommand1);
	GetDlgItem(IDC_EDIT_COMMAND2)->GetWindowText(mCommand2);
	GetDlgItem(IDC_EDIT_COMMAND3)->GetWindowText(mCommand3);

	GetDlgItem(IDC_EDIT_PARAMETER11)->GetWindowText(mParameter11);
	GetDlgItem(IDC_EDIT_PARAMETER12)->GetWindowText(mParameter12);
	GetDlgItem(IDC_EDIT_PARAMETER13)->GetWindowText(mParameter13);
	GetDlgItem(IDC_EDIT_PARAMETER14)->GetWindowText(mParameter14);
	
	GetDlgItem(IDC_EDIT_PARAMETER21)->GetWindowText(mParameter21);
	GetDlgItem(IDC_EDIT_PARAMETER22)->GetWindowText(mParameter22);
	GetDlgItem(IDC_EDIT_PARAMETER23)->GetWindowText(mParameter23);
	GetDlgItem(IDC_EDIT_PARAMETER24)->GetWindowText(mParameter24);

	GetDlgItem(IDC_EDIT_PARAMETER31)->GetWindowText(mParameter31);
	GetDlgItem(IDC_EDIT_PARAMETER32)->GetWindowText(mParameter32);
	GetDlgItem(IDC_EDIT_PARAMETER33)->GetWindowText(mParameter33);
	GetDlgItem(IDC_EDIT_PARAMETER34)->GetWindowText(mParameter34);
	CDialog::OnOK();
}
