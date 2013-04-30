#if !defined(AFX_UPDATE_H__D998B8C4_8867_4DC2_971A_8D6A8DCBDF22__INCLUDED_)
#define AFX_UPDATE_H__D998B8C4_8867_4DC2_971A_8D6A8DCBDF22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Update.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// Update thread

class Update : public CWinThread
{
	DECLARE_DYNCREATE(Update)
public:
	Update();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Update)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Update();

	// Generated message map functions
	//{{AFX_MSG(Update)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATE_H__D998B8C4_8867_4DC2_971A_8D6A8DCBDF22__INCLUDED_)
