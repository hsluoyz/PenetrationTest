#if !defined(AFX_REPORT_H__D0F142B4_0E6F_4C81_811E_9283174B5022__INCLUDED_)
#define AFX_REPORT_H__D0F142B4_0E6F_4C81_811E_9283174B5022__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Report.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Report dialog
#include <string>
#include <vector>
typedef struct PointInfo
{
	std::string hotsName;
	std::string cveNumber;
	bool status;
	bool flag;
	CPoint point;
}PointInfo;

typedef std::vector<PointInfo> pointPath;
class Report : public CDialog
{
// Construction
public:
	Report(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Report)
	enum { IDD = IDD_DIALOG_REPORT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Report)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Report)
		// NOTE: the ClassWizard will add member functions here
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog();
	void DrawHost(CDC *pdc, CPoint point,COLORREF crColor);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORT_H__D0F142B4_0E6F_4C81_811E_9283174B5022__INCLUDED_)
