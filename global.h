#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <map>

const VULNERABILITY = 14;

//struct that recode all parameter to send to server
typedef struct Metasploit
{
	std::string cveNumber;		//CVE number
	std::string exploit;		//exploit
	std::string payload;		//payload
	std::string ip;				//ip address
	std::string parameter;		//parameter
	std::string platform;		//type of platform
};

//struct that recode status of host
typedef struct Status
{
	std::string hotsName;		//host's name 
	std::string cveNumber;		//CVE number
	std::string accType;		//privilege's type
	bool status;				//host's status, false represent fail, true represent success
}Status;

//struct that recode goal
typedef struct Goal
{
	std::string strHost;
	std::string accType;
}Goal;

//struct that recode exception
typedef struct Exceptation
{
	std::string strHost;
	std::string accType;
}Exceptation;

//struct that recode privilege
typedef struct Privilege
{
	std::string strHost;
	std::string accType;
}Privilege;

//struct that recode variable
typedef struct Variable
{
	int iType;							//variable's type 
	std::string name;					//variable's name
	union{
		std::string* time;				//time's value
		Goal* goal;						//goal's value
		Exceptation* exceptation;		//exception's value
	}value;
}Variable;

//struct that recode penetration testing case
typedef struct PentestCase
{
	Goal goal;							//gaol
	Privilege pri;						//pricondition
	Exceptation exp;					//exception
	std::string method;					//method
	std::string cvenumber;				//cve number
}PentestCase;

//strcut that recode penetration testing path
typedef struct PentestPath
{
	std::vector<PentestCase> pathCase;
	std::string pathName;
}PentestPath;

typedef std::vector<PentestPath> vecPath;
typedef std::vector<std::string> vecStr;
typedef std::vector<Status> pathStatus;

//penetration testing scheme
class Scheme
{
public:
	Scheme();
	virtual ~Scheme();

	int GetPathNumber() const;
	std::string& GetBeginTime();
	std::string& GetEndTime();
	vecPath GetAllPath() const;
	Goal GetSchemeGoal() const;
	vecStr GetSchemeTarget() const;

	void SetTarget(const std::string &target);
	void SetBeginTime(const std::string &beginTime);
	void SetEndTime(const std::string &endTime);
	void SetPathNumber(int number);
	void InsertCase(std::string name, const PentestCase &pentestcase);
	void InsertPath(const PentestPath &pentestcase);
	void SetSchemeGoal(const Goal &goal);

private:
	Goal mSchGoal;
	std::string mSchBeginTime;
	std::string mSchEndTime;
	vecStr mSchTarget;
	int mPathNumber;
	vecPath mPath;
};


int PtsMain(char *fileName);
#endif