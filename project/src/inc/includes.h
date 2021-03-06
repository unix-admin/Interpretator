#ifndef INCLUDES_H_
#define INCLUDES_H_
#pragma once
#include <iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
#include <iomanip>
#include <list>
#include <jsoncpp/json/json.h>
#include "logfile.h"
#include <regex>
#include <stdio.h>
//#include <chrono>

#include "fcgi_config.h"
#include "fcgiapp.h"

//#define SHOW_IN_CONSOLE

#ifndef DEBUG(data)
//#define DEBUG(data)
#endif

#define INFO(data)
#define ERROR(data)

using namespace std;

#ifndef DEBUG_BUILD
#define DEBUG_BUILD
#endif

#ifndef ERROR_BUILD
#define ERROR_BUILD
#endif

#ifndef INFO_BUILD
#define INFO_BUILD
#endif


#ifdef DEBUG_BUILD
 #define DEBUG(data) logfile::addLog("DEBUG:" + string(data))
#endif

#ifdef ERROR_BUILD
 #define ERROR(data) logfile::addLog("ERROR:" + string(data))
#endif

#ifdef INFO_BUILD
 #define INFO(data) logfile::addLog("INFO:" + string(data))
#endif
//#define THREAD_COUNT 1
//#define SOCKET_PATH "127.0.0.1:8000"

static int socketId;

string str_with_spec_character(string s) ;
void ReplaceAll(std::string &str, const std::string& from, const std::string& to);
void l12(string ll);
void l12(int ll);

// <= < == > >=
enum CompareMark {LessEquial = 0, Less = 1,  Equial = 2, More = 3, MoreEquial = 4, NotEquial = 5, Last = 6};
enum ValueTypes {VAL_INT = 0,VAL_FLOAT  = 1,VAL_BOOL = 2,VAL_STRING = 3, VAL_CHAR = 4, VAL_RANGE = 5, VAL_Last = 6};

/*
string getArrayCompareString(string name1, int arr1_size, ValueTypes type1,string name2, int arr2_size, ValueTypes type2, CompareMark mark, int lang);
string getCompareString(string name1,  ValueTypes type1,string name2, ValueTypes type2, CompareMark mark, int lang);*/

//Config *config;
struct Job {
	string session;
	string jobid;
	string code;
	int task;
	string lang;
};

struct Token{
	string session;
	string jobId;
	bool isValid = true;
};

#endif
