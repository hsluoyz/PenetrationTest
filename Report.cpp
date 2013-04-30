// Report.cpp : implementation file
//

#include "stdafx.h"
#include "PentestTool.h"
#include "Report.h"
#include "global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Report dialog

//extern external variables
extern std::vector<pathStatus> str2DArrHostStatus;
extern std::vector<std::string> g_strArrPathNames;
extern Scheme* scheme;
extern bool dispalyPath;
Report::Report(CWnd* pParent /*=NULL*/)
	: CDialog(Report::IDD, pParent)
{
	//{{AFX_DATA_INIT(Report)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void Report::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Report)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Report, CDialog)
	//{{AFX_MSG_MAP(Report)
		// NOTE: the ClassWizard will add message map macros here
		ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Report message handlers

//paint path of scheme

//画图的函数就别看了吧，挺伤脑细胞的
void Report::OnPaint()
{	
	if (dispalyPath == false)
	{
		return;
	}
	CPaintDC dc(this);
	CDC* pdc=GetDC();
	pdc->SetBkMode(TRANSPARENT);

	CRect rect;
	GetClientRect(&rect);
	CPoint CenterPos;
	CenterPos=rect.CenterPoint();
	CPoint attackerPos;
	attackerPos.x = CenterPos.x + 200;
	attackerPos.y = CenterPos.y - 140;
	DrawHost(pdc, attackerPos, RGB(255,0,0));

	pdc->TextOut(attackerPos.x + 20, attackerPos.y - 10,"tester");

	int count = str2DArrHostStatus.size();
	std::vector<pathStatus>::iterator iter = str2DArrHostStatus.begin();
	PointInfo pointInfo;
	std::vector<pointPath> pointScheme;
	for (; iter != str2DArrHostStatus.end(); ++iter)
	{
		int number = (*iter).size();
		pointPath pointpath;
		for (int j = 0; j < number; ++j)
		{
			pointInfo.cveNumber = (*iter)[j].cveNumber;
			pointInfo.hotsName = (*iter)[j].hotsName;
			pointInfo.status = (*iter)[j].status;
			pointInfo.point.x = attackerPos.x;
			pointInfo.point.y = attackerPos.y + (j+1) * 80;
			pointInfo.flag = true;
			pointpath.push_back(pointInfo);
		}
		pointScheme.push_back(pointpath);
	}

	int pathNumber = str2DArrHostStatus.size();
	if (pathNumber == 2)
	{
		int loop = pointScheme[0].size();
		for (int k = 0; k < loop; ++k)
		{
			if ((pointScheme[0][k].hotsName != pointScheme[1][k].hotsName)\
				|| (pointScheme[0][k].cveNumber != pointScheme[1][k].cveNumber))
			{
				pointScheme[0][k].point.x -= 50;
				pointScheme[1][k].point.x += 50;
			}
			else
			{
				pointScheme[1][k].flag = false;
			}
		}
	}
	pathNumber = 0;
	for (std::vector<pointPath>::iterator it = pointScheme.begin(); it != pointScheme.end(); ++it)
	{
		int number = (*it).size();
		for (int j = 0; j < number; ++j)
		{
			if ((*it)[j].status == true)
			{
				DrawHost(pdc, (*it)[j].point, RGB(0, 255, 0));
				CPen pen, *oldp;
				pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
				oldp = pdc->SelectObject(&pen);
				if (j == 0)
				{
					pdc->MoveTo(attackerPos.x, attackerPos.y);
					pdc->LineTo((*it)[j].point.x, (*it)[j].point.y);
					pdc->SelectObject(oldp);
				}
				else
				{
					pdc->MoveTo((*it)[j-1].point.x, (*it)[j-1].point.y);
					pdc->LineTo((*it)[j].point.x, (*it)[j].point.y);
					pdc->SelectObject(oldp);
				}
				CString cveNumber;
				CString hostIp;
				cveNumber.Format("%s", (*it)[j].cveNumber.c_str());
				hostIp.Format("%s", (*it)[j].hotsName.c_str());

				if (pathNumber == 0)
				{
					pdc->TextOut((*it)[j].point.x - 100, (*it)[j].point.y, cveNumber);
					pdc->TextOut((*it)[j].point.x -100, (*it)[j].point.y - 20, hostIp);
				}
				else
				{
					if ((*it)[j].flag == true)
					{
						pdc->TextOut((*it)[j].point.x + 10, (*it)[j].point.y, cveNumber);
						pdc->TextOut((*it)[j].point.x + 10, (*it)[j].point.y - 20, hostIp);
					}
					
				}
			}
		}
		pathNumber++;
	}
} 

//Display penetration tesing report
BOOL Report::OnInitDialog()
{

	string strGoalInfo = "Gain " + scheme->GetSchemeGoal().accType + " right of " + scheme->GetSchemeGoal().strHost; //总的完成情况
	vector<pathStatus>::iterator iterArrHostStatus = str2DArrHostStatus.begin();
	string strPathDisplayInfo; //每条路径的信息
	string strReportInfo; //strReportInfo = strGoalInfo + strPathDisplayInfo;
	bool bSuccess = false;
	for (int i = 0; iterArrHostStatus != str2DArrHostStatus.end(); ++iterArrHostStatus)
	{
		int iHostStatusCntForOnePath = (*iterArrHostStatus).size();
		string strPathName = g_strArrPathNames[i];
		strPathDisplayInfo += strPathName;
		strPathDisplayInfo += "\r\n";
		strPathDisplayInfo += "{";
		strPathDisplayInfo += "\r\n";
		char buffer[5];
		for (int j = 0; j < iHostStatusCntForOnePath; ++j)
		{
			strPathDisplayInfo += "step";
			itoa(j + 1, buffer, 5); //int转char*，转到buffer里
			//buffer[1] = '\0';
			strPathDisplayInfo += std::string(buffer);
			buffer[0] = '\0';
			buffer[1] = '\0';
			strPathDisplayInfo += ": Exploit ";
			strPathDisplayInfo += (*iterArrHostStatus)[j].cveNumber;
			strPathDisplayInfo += " of ";
			strPathDisplayInfo += (*iterArrHostStatus)[j].hotsName;
			if ((*iterArrHostStatus)[j].status == true)
			{
				strPathDisplayInfo += " gain ";
				strPathDisplayInfo += "\r\n";
				strPathDisplayInfo += (*iterArrHostStatus)[j].accType;
				strPathDisplayInfo += "\r\n";
				if ( j == (iHostStatusCntForOnePath -1))
				{
					bSuccess = true; //如果路径的最后一个主机的status也是true，说明此路径渗透成功
				}
			}
			else
			{
				strPathDisplayInfo += " fail"; //此路径渗透失败 bSuccess = false
				strPathDisplayInfo += "\r\n";
			}
		}
		//pathStr += "\r\n";
		strPathDisplayInfo += "}";
		strPathDisplayInfo += "\r\n";
		++i;
	}
	if (bSuccess == true)
	{
		strGoalInfo += " success";
		strGoalInfo += "\r\n";
	}
	else
	{
		strGoalInfo += " fail";
		strGoalInfo += "\r\n";
	}
	strReportInfo = strGoalInfo + strPathDisplayInfo; //strGoalInfo是总的完成情况，strPathDisplayInfo是每条路径的信息
	CString strTemp;
	strTemp.Format("%s", strReportInfo.c_str()); //string转CString，方法还是麻烦了
	GetDlgItem(IDC_EDIT_REPORT)->SetWindowTextA(strTemp); //显示到IDC_EDIT_REPORT编辑框里
	/****************************************************
	//测试代码
	*****************************************************/
	/*std::string goalStr;
	goalStr = "Gain user right of 10.2.1.15\r\n";
	goalStr += "fistpath\r\n{\r\nstep1:Exploit CVE-2010-0806 of 10.2.1.15 success, \r\ngain user right\r\n}\r\n";
	goalStr += "secodepath\r\n{\r\nstep1:Exploit CVE-2003-0533 of 10.2.1.15 fail\r\n}\r\n";
	goalStr += "thirdpath\r\n{\r\nstep1:Exploit CVE-2002-0392 of 10.2.1.15 fail\r\n}\r\n";
	goalStr += "fourthpath\r\n{\r\nstep1:Exploit CVE-2003-0352 of 10.2.1.15 success, \r\ngain user right\r\n}\r\n";
	goalStr += "fifthpath\r\n{\r\nstep1:Exploit CVE-2003-0818 of 10.2.1.15 success, \r\ngain user right\r\n}\r\n";
	GetDlgItem(IDC_EDIT_REPORT)->SetWindowTextA(goalStr.c_str());


	std::string goalStr;
	goalStr = "Gain root right of 10.2.3.21\r\n";
	goalStr += "fistpath\r\n{\r\nstep1:Exploit CVE-2009-3548 of 10.2.1.22 success, \r\ngain user right\r\n";
	goalStr += "step2:Exploit CVE-2003-0352 of 10.2.2.11 success, \r\ngain administrator right\r\n";
	goalStr += "step3:Exploit CVE-2004-2687 of 10.2.3.21 success, \r\ngain root right\r\n}\r\n";

	goalStr += "secondpath\r\n{\r\nstep1:Exploit CVE-2006-3439 of 10.2.1.15 success, \r\ngain user right\r\n";
	goalStr += "step2:Exploit CVE-2005-2877 of 10.2.2.10 success, \r\ngain root right\r\n";
	goalStr += "step3:Exploit CVE-2004-2687 of 10.2.3.21 success, \r\ngain root right\r\n}\r\n";
	GetDlgItem(IDC_EDIT_REPORT)->SetWindowTextA(goalStr.c_str());*/
	return true;
}

//Drow host
//画图的函数就别看了吧，挺伤脑细胞的
void Report::DrawHost(CDC *pdc, CPoint point,COLORREF crColor)
{
	CBrush brush,*pold;
	brush.CreateSolidBrush(crColor);
	pold=pdc->SelectObject(&brush);

	pdc->Rectangle(point.x-5,point.y-5,point.x+5,point.y+5);
	pdc->SelectObject(pold);
}

