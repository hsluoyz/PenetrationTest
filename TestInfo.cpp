// TestInfo.cpp : implementation file
//
#include "stdafx.h"
#include <vector>
#include "PentestTool.h"
#include "TestInfo.h"
#include "Report.h"
#include "Update.h"
#include "DataConnection.h"
//#include <fstream.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//using namespace std;
/////////////////////////////////////////////////////////////////////////////
// TestInfo dialog
TestInfo* TestInfo::s_pTestInfo = NULL;
int TestInfo::i = 1;
bool TestInfo::mFinishStatus = false;
extern Scheme* scheme;
typedef std::vector<std::string> strPath;
extern std::vector<strPath> str2DArrAttackStrings;
extern std::vector<pathStatus> str2DArrHostStatus;
std::vector<std::string> toolParameter;
extern int schemeBeginTime;
extern int schemeEndTime;
//Client *client = new Client("192.168.1.246", 6666);
//std::ofstream oout;
TestInfo::TestInfo(CWnd* pParent /*=NULL*/)
	: CDialog(TestInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(TestInfo)
	//}}AFX_DATA_INIT
	m_strBeginInfo = _T("Begin perform penetration tesing.....");
	m_strAllInfo = m_strBeginInfo;
	mFlag = true; //没用
	mStatus = true; //跳过路径标志位，见Line 159
	mThreadStatus = false; //进程启动标志位
	mSearchBase = false; //没用
	mTimeWarining = true; //是否进行时间提醒，但是这个不完全管用，见Line 113
	mReport = new Report();
	i = 0;
	//GetDlgItem(IDC_BUTTON_REPORT)->EnableWindow(FALSE);
	s_pTestInfo = this;
}

TestInfo::~TestInfo()
{
	delete mReport;
}

BOOL TestInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetDlgItem(IDC_EDIT_PENTESTINFO)->SetWindowTextA(m_strBeginInfo); //设置编辑框IDC_EDIT_PENTESTINFO的内容为m_strBeginInfo
	GetDlgItem(IDC_BUTTON_REPORT)->EnableWindow(TRUE); //让按钮IDC_BUTTON_REPORT变为可用（灰色表示不可用）
	SetTimer(1, 3000, NULL); //设置1号计时器，每3秒触发一次
	return true;
}

void TestInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TestInfo)
	DDX_Control(pDX, IDC_EDIT_PENTESTINFO, m_testInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(TestInfo, CDialog)
	//{{AFX_MSG_MAP(TestInfo)
		ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_REPORT, OnButtonShowReport)
	ON_BN_CLICKED(IDC_BUTTON_PROCESS, OnButtonProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TestInfo message handlers

//1号定时器的响应函数，参数nIdEvent就是定时器编号1，因为只有一个定时器，所以没用switch case判断编号
void TestInfo::OnTimer(UINT nIdEvent)
{
	//if (mFlag == true)
	//{
	//	DisplayInfo();
	//}
	//WriteInfo();
	WriteInfo(); //从log.txt里读取文本，在“控制台编辑框”里显示
	if (mFinishStatus == false)
	{
		GetDlgItem(IDC_BUTTON_REPORT)->EnableWindow(TRUE);
	}
	GetLocalTime(&mCurrentTime); //读取当前时间
	int hour = static_cast<int> (mCurrentTime.wHour);
	int minute = static_cast<int> (mCurrentTime.wMinute);
	int sum = hour * 60 + minute; //换算成分钟
	if ( (sum < schemeBeginTime) || (sum > schemeEndTime))
	{
		//进来了表示不符合渗透测试时间，这个功能鸡肋的很，可以去掉
		DWORD dwCode;
		if (mThreadStatus) //这里是有问题的，即使mTimeWarining为false，这里也会终止渗透
		{
			::GetExitCodeThread(mThread, &dwCode);
			::TerminateThread(mThread, dwCode);
			::CloseHandle(mThread->m_hThread);
		}
		if (mTimeWarining) //而这里仅仅是弹出个框而已，没有做任何终止渗透的处理
		{
			mTimeWarining = false;
			MessageBox("渗透测试时间不符合方案要求或者时间已用完", "时间提醒", MB_ICONERROR);
			GetDlgItem(IDC_BUTTON_REPORT)->EnableWindow(TRUE);
		}
		
	}
}

UINT TestInfo::Penetrate(LPVOID lpParam)
{

	int i =0;
	Sleep(10); //此进程挂起10ms，不知何意
	//s_pTestInfo实际上就是这个TestInfo类实例，因为多线程里的工作者线程函数Penetrate必须是全局函数，所以只能通过全局或静态指针来调用类中的东西了
	s_pTestInfo->mFlag = false; //mFlag赋值后从来没用过，不看也罢
	s_pTestInfo->fout.open("log.txt", ios::app);
	if (!s_pTestInfo->fout.is_open())
	{
		//MessageBox("Open file error", "ERROR", MB_ICONERROR);
	}
	//Client就是一个普通的socket封装类
	Client *client = new Client("192.168.6.2", 6666); //连接渗透测试服务器，这里应该改成192.168.1.177了
	vector<strPath>::iterator iterStrArrAttackStringsForOnePath = str2DArrAttackStrings.begin();
	vector<pathStatus>::iterator iterArrHostStatusForOnePath = str2DArrHostStatus.begin();
	char buffer[10000];
	string allParameter = ""; //没用
	
	int iPathIndex = 0;
	int iCaseIndex = 0;
	strPath strArrAttackStringsForOnePath;
	for (; iterStrArrAttackStringsForOnePath != str2DArrAttackStrings.end(); ++iterStrArrAttackStringsForOnePath, ++iterArrHostStatusForOnePath)
	{
		iCaseIndex = 0;
		pathStatus arrHostStatusForOnePath = *iterArrHostStatusForOnePath;
		strArrAttackStringsForOnePath = *iterStrArrAttackStringsForOnePath;
		string strAttackString; //攻击字符串
		string successStr = ""; //没用，后面都注释掉了
		string failStr = ""; //没用
	
		strPath::iterator iterStrAttackString = strArrAttackStringsForOnePath.begin();
		s_pTestInfo->mStatus = true;
		for (; iterStrAttackString != strArrAttackStringsForOnePath.end(); iterStrAttackString++)
		{
			if (s_pTestInfo->mStatus == false) //如果socket返回fail，则mStatus置false，即跳过此路径的渗透
			{
				break;
			}
			strAttackString = *iterStrAttackString; //攻击字符串
			/*if (allParameter.find(parameter) != std::string::npos)
			{
				schemeStatus[pathIndex][caseIndex].status = true;
				successStr += "Case to penetrate";
				successStr += schemeStatus[pathIndex][caseIndex].hotsName;
				successStr += " for ";
				successStr += schemeStatus[pathIndex][caseIndex].cveNumber;
				successStr += "have executed.";
				//successStr += "\r\n";
				instance->fout << successStr.c_str() << endl;
				//WriteInfo(successStr.c_str());
				caseIndex++;
				continue;
			}
			else 
			{
				allParameter += parameter;
			}*/
			allParameter += strAttackString; //没用
			Sleep(50);
			client->Send(strAttackString); //向渗透测试服务器发送攻击字符串（不是攻击本身）
			int begin = 0;
			int end = 0;
			begin = strAttackString.find("RHOST"); //目的是找“RHOST=192.168.1.1 ”这样的字符串
			end = strAttackString.find(" ", begin);
			string hostName = strAttackString.substr(begin + 6, end); //begin + 6表示跳过“RHOST=”，最后hostName为192.168.1.1
			string strTemp = "Penetrate host ";
			strTemp += hostName;
			strTemp += "......Please wait!\r\n";
			//mAllInfo += temp;
			//把控制台文字写到文件里，然后计时器响应函数再读取文件，显示在控制台编辑框里，DZY写的好别扭啊
			s_pTestInfo->fout << strTemp.c_str(); //标准的C++文件读写方式，DZY思路挺乱的，文件读写一会用C++的fstream，一会用MFC的CFile
			s_pTestInfo->fout.close();
			Sleep(6); //这个sleep好诡异
			while (true) //同步接受socket返回值
			{
				int len = client->Recive(buffer);
				buffer[len] = '\0';
				if ((len > 0) && (strcmp(buffer, "success") == 0))
				{
					str2DArrHostStatus[iPathIndex][iCaseIndex].status = true; //表示host渗透成功
					s_pTestInfo->fout.open("log.txt", ios::app);
					s_pTestInfo->fout << "penetrate "<< hostName.c_str() << "success" << endl;
					s_pTestInfo->fout.close();
					iCaseIndex++;
					break;
				}
				else if ((len > 0) && (strcmp(buffer, "fail") == 0))
				{
					//when a case is fail, then will ignore the path's other cases
					str2DArrHostStatus[iPathIndex][iCaseIndex].status = false; //表示host渗透失败
					s_pTestInfo->fout.open("log.txt", ios::app);
					s_pTestInfo->fout << "penetrate "<< hostName.c_str() << "fail" << endl;
					s_pTestInfo->fout.close();
					s_pTestInfo->mStatus = false; //跳出这层for循环，渗透另一条路径
					//instance->fout << buffer << endl;
					iCaseIndex++;
					break;
				}
				else
				{
					//socket接收到的不是success也不是fail，说明是一些执行状态信息，直接写到文件里
					s_pTestInfo->fout.open("log.txt", ios::app);
					s_pTestInfo->fout << buffer;
					s_pTestInfo->fout.close();
					continue;
				}
			}
		}
		iPathIndex++;
	}
	mFinishStatus = true; //表示渗透完成，计时器响应函数就不再更新了
	//GetDlgItem(IDC_BUTTON_REPORT)->EnableWindow(TRUE);
	return 0;
}

void TestInfo::WriteInfo()
{
	
	mFile.Open("log.txt", CFile::modeRead | CFile::shareDenyNone);
	int nLen = mFile.GetLength();
	char buffer[100000];
	buffer[nLen+1] =0;
	mFile.Read(buffer, nLen);
	mFile.Close();
	GetDlgItem(IDC_EDIT_PENTESTINFO)->SetWindowText(buffer);
	UpdateData(FALSE); //更新内容操作，由于GetDlgItem相当于把控件直接绑定CEdit变量，这时是不需要UpdateData的，DZY多此一举了
	m_testInfo.SetScrollPos(SB_VERT,m_testInfo.GetLineCount(),TRUE);
	m_testInfo.SetSel(-1); //这两行表示滚动条随着内容增加一起滚动
}

void TestInfo::OnButtonShowReport() 
{
	// TODO: Add your control notification handler code here
	mReport->DoModal(); //显示报告窗口
}

void TestInfo::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnCancel(); //默认的退出函数
}

//“查看过程”按钮的响应函数，这才是渗透的开始
void TestInfo::OnButtonProcess()
{
	// TODO: Add your control notification handler code here
	int i = 0;
	if (mSearchBase) //mSearchBase这个东西初始化为false后，就从没有置1过，所以SearchBase永远不可能调用
	{
		SearchBase();
	}
	mThread = AfxBeginThread(Penetrate, NULL, 0, 0, 0, NULL); //MFC标准的多线程方式之一  工作者线程方式
	mThreadStatus = true; //表示已经开始渗透
}
void TestInfo::SearchBase()
{
	//从没有调用过的一个酱油函数，不用看了！！！
	vecPath path = scheme->GetAllPath();
	vecPath::iterator pathIt = path.begin();
	PentestCase pCase;
	PentestPath pPath;
	std::vector<PentestCase> pathCases;
	std::string cveNumber;
	for (; pathIt != path.end(); ++pathIt)
	{	
		pPath = *pathIt;
		pathCases = pPath.pathCase;

		for (std::vector<PentestCase>::iterator caseIt = pathCases.begin(); caseIt != pathCases.end(); ++ caseIt)
		{
			pCase = *caseIt;

			cveNumber = pCase.cvenumber;
			CString strSql;
			strSql.Format("select ToolDescription.toolName, \
							ToolDescription.toolPath, Command.* from \
							Command, ToolDescription where toolCveNumber='%s'", cveNumber.c_str());

			DataConnection dataConnection;
			_RecordsetPtr pRecordset;
			dataConnection.OnInitADOConn();
	
			if(!dataConnection.GetRecordSet(pRecordset , (_bstr_t)strSql))
			{
				return;
			}
			_variant_t  parameter;
			CString str;
			parameter = pRecordset->GetCollect("toolName");
			str=parameter.vt==VT_NULL?"":(char*)(_bstr_t)parameter;;
			toolParameter.push_back(str.GetBuffer(str.GetLength()));
		}
	}
}

