#if !defined(AFX_ADDTOOL_H__95DB1AF7_A7C7_479F_BFBD_286C9CB3C28E__INCLUDED_)
#define AFX_ADDTOOL_H__95DB1AF7_A7C7_479F_BFBD_286C9CB3C28E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddTool.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddTool dialog

class AddTool : public CDialog
{
// Construction
public:
	AddTool(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddTool)
	enum { IDD = IDD_DIALOG_ADDTOOL };
	int		m_Priority;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddTool)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddTool)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CString GetCveNumber() const;
	CString GetPath() const;
	CString GetName() const;
	CString GetDescription() const;
	CString GetMethod() const;
	int		GetPriority() const;
	
	BOOL OnInitDialog();
	CString GetCommand1() const;
	CString GetCommand2() const;
	CString GetCommand3() const;
	
	CString GetParameter11() const;
	CString GetParameter12() const;
	CString GetParameter13() const;
	CString GetParameter14() const;

	CString GetParameter21() const;
	CString GetParameter22() const;
	CString GetParameter23() const;
	CString GetParameter24() const;

	CString GetParameter31() const;
	CString GetParameter32() const;
	CString GetParameter33() const;
	CString GetParameter34() const;

private:
	int mPriority;
	CString mCve;
	CString mName;
	CString mPath;
	CString mDescription;
	CString mMethod;
	CString mCommand1;
	CString mCommand2;
	CString mCommand3;
	
	CString mParameter11;
	CString mParameter12;
	CString mParameter13;
	CString mParameter14;

	CString mParameter21;
	CString mParameter22;
	CString mParameter23;
	CString mParameter24;

	CString mParameter31;
	CString mParameter32;
	CString mParameter33;
	CString mParameter34;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTOOL_H__95DB1AF7_A7C7_479F_BFBD_286C9CB3C28E__INCLUDED_)
