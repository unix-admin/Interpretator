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

//#include <chrono>

#include "fcgi_config.h"
#include "fcgiapp.h"

using namespace std;

//#define THREAD_COUNT 1
//#define SOCKET_PATH "127.0.0.1:8000"

static int socketId;

string str_with_spec_character(string s) ;
void ReplaceAll(std::string &str, const std::string& from, const std::string& to);
void l12(string ll);
void l12(int ll);




//Config *config;
struct Job {
	string session;
	int jobid;
	string code;
	int task;
	string lang;
};

struct Token{
	string session;
	long jobId;
};
struct FunctionArgument{
	int type=0;
	bool isArray = false;
	int size=0;
	vector<string> value;
	string name;
};
struct FunctionData{
	enum ReturnValueTypes {RET_VAL_INT = 0,RET_VAL_FLOAT  = 1,RET_VAL_BOOL = 2,RET_VAL_STRING = 3,RET_VAL_RANGE = 4, Last = 5};
	int returnValueType = RET_VAL_INT;
	bool isArray = false;
	bool isRange = false;
	int result_array_size;
	int size=0;
	string functionName;
	vector<string> result;
	vector<FunctionArgument> args;
	int getResultArraySize()
	{
		return result_array_size;
	}
	string getReturnType(){
		switch(returnValueType){
		case RET_VAL_INT:
			return "int";
			break;
		case RET_VAL_FLOAT:
			return "float";
			break;
		case RET_VAL_BOOL:
			return "bool";
			break;
		case RET_VAL_STRING:
			return "string";
			break;
		case RET_VAL_RANGE:
			return "range";
			break;
		}
		return "";
	}

};







#endif
