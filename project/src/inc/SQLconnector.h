//============================================================================
// Name        : SQLconector.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef SQLSYSTEM_H_
#define SQLSYSTEM_H_

#include "includes.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include "config.h"
#include <mutex>
#include </usr/include/mysql/mysql.h>
#include <time.h>
 #include </usr/include/mysql/errmsg.h>

extern Config* config;
using namespace std;

string getDateTime();

int timeSeconds();

string str_with_spec_character(string s) ;

class ConnectorSQL
{
	std::recursive_mutex _lock;
	  ConnectorSQL(ConnectorSQL const&);
		  ConnectorSQL& operator= (ConnectorSQL const&);
		  ConnectorSQL();
		  ~ConnectorSQL();
public:
	 static ConnectorSQL& getInstance();
	bool connectToHostDB(const char *host,const char *port, const char *user, const char *password, const char *database);
	bool connectToTable(string table, vector<string> labels);
	bool addRecordsInToTable(vector<map<int,string> > records) ;
	bool addRecordsInToTable(map<int,string>  records) ;
	bool updateRecordsInToTable(map<int,string> records,map<int,string>  where);
	vector<map<int,string> >   getAllRecordsFromTable(string where ="1") ;
	//id-label is first label which you set!!!
	bool isConnectedToTable();
	string getCustomCodeOfProgram(string ID, string text_of_program,int thrdId,string lang);
	string getFullCodeOfProgram(string ID,int thrdId) ;
	static string getAssignmentTable(string lang);
	static vector<string>  getAssignmentTableLabels();
void closeConection();
private:
bool connect_table;
	 string tableName;
	 string labels;
	//string records;
	 vector<string> labels_vec;
	 int labels_num;
	  MYSQL *connection;

	 MYSQL_RES *resptr;
	 MYSQL_ROW row;
	 MYSQL_FIELD *field;
	   MYSQL mysql;
};

int testamana (void);
#endif
