#if !defined(AFX_TESTINFO_H__422CB88A_3AD5_4AA4_8860_4AA83C456C4D__INCLUDED_)
#define AFX_TESTINFO_H__422CB88A_3AD5_4AA4_8860_4AA83C456C4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestInfo.h : header file
//
#include "Client.h"
#include "global.h"
#include "Report.h"
#include <fstream.h>
/////////////////////////////////////////////////////////////////////////////
// TestInfo dialog
class TestInfo : public CDialog
{
// Construction
public:
	TestInfo(CWnd* pParent = NULL);   // standard constructor
	~TestInfo();
// Dialog Data
	//{{AFX_DATA(TestInfo)
	enum { IDD = IDD_DIALOG_PENTESTINFO };
	CEdit	m_testInfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TestInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TestInfo)
	afx_msg void OnTimer(UINT nIdEvent);
	afx_msg void OnButtonShowReport();
	virtual void OnOK();
	afx_msg void OnButtonProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog();
	void DisplayInfo();
	void WriteInfo();
	void SearchBase();

	static UINT Penetrate(LPVOID lpParam);

private:
	CString m_strBeginInfo;
	bool mFlag;
	std::string m_strAllInfo;
	CString mAllDisplay;
	bool mStatus;
	bool mSearchBase;
	bool mThreadStatus;	//记录连接服务器的进程是否开始
	bool mTimeWarining;	//记录时间MessageBox的状态
	Report *mReport;
	ofstream fout;
	CWinThread* mThread;
	//ifstream fin;
	CFile mFile;
	CFile mFileIn;
	static int i;
	SYSTEMTIME mCurrentTime;
	static bool mFinishStatus;

	static TestInfo* s_pTestInfo;
};

//UINT WriteInfo(LPVOID lpParam);
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTINFO_H__422CB88A_3AD5_4AA4_8860_4AA83C456C4D__INCLUDED_)
