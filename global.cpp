#include "StdAfx.h"
#include "global.h"

//Define variables
Scheme *scheme = new Scheme();
char bufError[100];
bool dispalyPath = false;
//file's name that to parse
char* FilePath;

//vector that store metasploit's parameters
std::vector<Metasploit> arrMetasploits;

//vector that store scheme which have Serializationed 
typedef std::vector<std::string> strPath;			
std::vector<strPath> str2DArrAttackStrings;

//vector that store host's status
typedef std::vector<Status> pathStatus;
std::vector<pathStatus> str2DArrHostStatus;

//vector that store path's name
std::vector<std::string> g_strArrPathNames;

//store penetration testing time span in int
int timeSpan = 0;
int schemeBeginTime = 0;
int schemeEndTime = 0;
Scheme::Scheme()
{
	mPathNumber = 0;
}

Scheme::~Scheme()
{
}

//Get all penetration tesint paths
vecPath Scheme::GetAllPath() const
{
	return mPath;
}

//Get scheme's target that to penetration testing 
vecStr Scheme::GetSchemeTarget() const
{
	return mSchTarget;
}

//Get scheme's goal
Goal Scheme::GetSchemeGoal() const
{
	return mSchGoal;
}

//Get penetration testing path numbers
int Scheme::GetPathNumber() const
{
	return mPathNumber;
}

//Get the time when start penetration testing
std::string& Scheme::GetBeginTime()
{
	return mSchBeginTime;
}

//Get the time when stop penetration testing
std::string& Scheme::GetEndTime()
{
	return mSchEndTime;
}

//Set scheme's target
void Scheme::SetTarget(const std::string &target)
{
	mSchTarget.push_back(target);
}

//Set when start penetration tesing
void Scheme::SetBeginTime(const std::string &beginTime)
{
	mSchBeginTime = beginTime;

}

//Set when stop penetration testing
void Scheme::SetEndTime(const std::string &endTime)
{
	mSchEndTime = endTime;
}

//Set path numbers
void Scheme::SetPathNumber(int number)
{
	mPathNumber = number;
}

//Set scheme's goal
void Scheme::SetSchemeGoal(const Goal &goal)
{
	mSchGoal = goal;
}

//Insert penetration tesing case to scheme
void Scheme::InsertCase(std::string name, const PentestCase &pentestcase)
{
	vecPath::iterator it = mPath.begin();
	int i = 0;
	for (; it != mPath.end(); ++it)
	{
		if ((*it).pathName == name)
		{
			
			mPath[i].pathCase.push_back(pentestcase);
		}
		++i;
	}
}

//Insert path to the scheme
void Scheme::InsertPath(const PentestPath &pentestpath)
{
	vecPath::iterator it = mPath.begin();
	std::string pathName = pentestpath.pathName;
	bool flag = true;
	for (; it != mPath.end(); ++it)
	{
		if (pathName == (*it).pathName)
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		mPath.push_back(pentestpath);
	}
	mPathNumber++;
}



//Initialize penetration tesing tool database
void InitMetasploit()
{
	Metasploit meta[VULNERABILITY];
	//一个Metasploit就是一个漏洞的利用方式，ip就是RHOST，cveNumber是给人看的，其它的是给metasploit传过去的参数
	meta[0].cveNumber = "cve-2009-3548";
	meta[0].exploit = "multi/http/tomcat_mgr_deploy";
	meta[0].ip = "192.168.6.2";
	meta[0].parameter = "RPORT=8180 USERNAME=tomcat PASSWORD=tomcat";
	meta[0].payload = "linux/x86/shell/bind_tcp";
	meta[0].platform = "linux";

	meta[1].cveNumber = "cve-2004-2687";
	meta[1].exploit = "unix/misc/distcc_exec";
	meta[1].ip = "192.168.6.2";
	meta[1].parameter = "";
	meta[1].payload = "cmd/unix/bind_perl";
	meta[1].platform = "linux";

	meta[2].cveNumber = "cve-2007-5423";
	meta[2].exploit = "unix/webapp/tikiwiki_graph_formula_exec";
	meta[2].ip = "192.168.6.2";
	meta[2].parameter = "";
	meta[2].payload = "php/bind_perl";
	meta[2].platform = "linux";

	meta[3].cveNumber = "cve-2005-2877";
	meta[3].exploit = "unix/webapp/twiki_history";
	meta[3].ip = "192.168.6.2";
	meta[3].parameter = "URI=/twiki/bin";
	meta[3].payload = "cmd/unix/bind_perl";
	meta[3].platform = "linux";

	meta[4].cveNumber = "cve-2004-1037";
	meta[4].exploit = "unix/webapp/twiki_search";
	meta[4].ip = "192.168.6.2";
	meta[4].parameter = "";
	meta[4].payload = "cmd/unix/bind_perl";
	meta[4].platform = "linux";

	meta[5].cveNumber = "cve-2010-0580";
	meta[5].exploit = "scanner/http/tomcat_mgr_login";
	meta[5].ip = "192.168.6.2";
	meta[5].parameter = "";
	meta[5].payload = "cmd/unix/bind_perl";
	meta[5].platform = "linux";
	
	meta[6].cveNumber = "cve-2003-0352";
	meta[6].exploit = "windows/dcerpc/ms03_026_dcom";
	meta[6].ip = "192.168.6.2";
	meta[6].parameter = "";
	meta[6].payload = "windows/shell/bind_tcp";
	meta[6].platform = "windows";

	meta[7].cveNumber = "cve-2006-3439";
	meta[7].exploit = "windows/smb/ms06_040_netapi";
	meta[7].ip = "192.168.6.2";
	meta[7].parameter = "";
	meta[7].payload = "windows/shell/bind_tcp";
	meta[7].platform = "windows";
	
	meta[8].cveNumber = "cve-2008-4250";
	meta[8].exploit = "windows/smb/ms08_067_netapi";
	meta[8].ip = "192.168.6.2";
	meta[8].parameter = "";
	meta[8].payload = "windows/shell/bind_tcp";
	meta[8].platform = "windows";

	meta[9].cveNumber = "cve-2004-1080";
	meta[9].exploit = "windows/wins/ms04_045_wins";
	meta[9].ip = "192.168.6.2";
	meta[9].parameter = "";
	meta[9].payload = "windows/shell/bind_tcp";
	meta[9].platform = "windows";

	meta[10].cveNumber = "cve-2010-0249";
	meta[10].exploit = "windows/browser/ms10_002_aurora";
	meta[10].ip = "192.168.6.2";
	meta[10].parameter = "";
	meta[10].payload = "windows/shell/bind_tcp";
	meta[10].platform = "windows";
	
	meta[11].cveNumber = "cve-2010-0103";
	meta[11].exploit = "windows/backdoor/energizer_duo_payload";
	meta[11].ip = "192.168.6.2";
	meta[11].parameter = "";
	meta[11].payload = "windows/shell/bind_tcp";
	meta[11].platform = "windows";

	meta[12].cveNumber = "cve-2005-4267";
	meta[12].exploit = "windows/imap/eudora_list";
	meta[12].ip = "192.168.6.2";
	meta[12].parameter = "";
	meta[12].payload = "windows/shell/bind_tcp";
	meta[12].platform = "windows";

	meta[13].cveNumber = "cve-1999-0520";
	meta[13].exploit = "linux/samba/chain_reply";
	meta[13].ip = "192.168.6.2";
	meta[13].parameter = "";
	meta[13].payload = "linux/x86/shell/bind_tcp";
	meta[13].platform = "linux";


	for(int i = 0; i < VULNERABILITY; ++i)
	{
		arrMetasploits.push_back(meta[i]);
	}
	std::string beginTime = scheme->GetBeginTime();
	std::string endTime = scheme->GetEndTime();
	
	std::string first = beginTime.substr(0, 2);
	std::string second = endTime.substr(3, 2);
	int hour = atoi(first.c_str());
	int minute = atoi(second.c_str());
	schemeBeginTime = hour * 60 + minute;

	first = endTime.substr(0, 2);
	second = endTime.substr(3, 2);
	hour = atoi(first.c_str());
	minute = atoi(second.c_str());
	schemeEndTime = hour * 60 + minute;
}
