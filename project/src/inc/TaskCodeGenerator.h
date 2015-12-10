/*
 * TaskCodeGenerator.h
 *
 *  Created on: Dec 4, 2015
 *      Author: root
 */

#ifndef TASKCODEGENERATOR_H_
#define TASKCODEGENERATOR_H_

#define ETALON_ENDING "_etalon"
#define ETALON_FOR_FUNCTION_ENDING "_for_etalon"

#include "includes.h"
#include "fcgio.h"
#include <sstream>
#include "cLang.h"
#include "codeclear.h"
#include "errorresponder.h"
#include "logfile.h"
#include "jsonParser.h"
#include "ctpl_stl.h"
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

namespace code {

class TaskCodeGenerator {
	FunctionData data;
	string header;
	string footer;

public:
	TaskCodeGenerator(jsonParser &jSON);
	virtual ~TaskCodeGenerator();
	static bool generateVariables(string &output, FunctionData functionData, vector<FunctionArgument> &variables);
	static string generateHeader(FunctionData functionData);
	static string generateFooter(FunctionData functionData);
	static string generateType(int type, int lang);
	static string generateVar(int type, string name, int lang, string value = string());

	static 	string convertStringToType(string argStringValue, int type, int lang);
	static string convertTypeToString(int type, int lang);
	static bool to_bool(std::string const& s);
	static string getStandartInclude(int lang);
	static string generateFunctionProtorype(FunctionData functionData, LangCompiler::compilerFlag = LangCompiler::Flag_CPP, string name = "function", char divider = ',', char space = ' ');
	static FunctionData parseTask(jsonParser &jSON);

	bool updateData(jsonParser &jSON);
	string getHeader();
	string getFooter();

	const string& getEtalon() const ;
};

} /* namespace code */

#endif /* TASKCODEGENERATOR_H_ */
