/*
 * jsonParser.h
 *
 *  Created on: Jun 3, 2015
 *      Author: root
 */

#include "includes.h"
#include "logfile.h"

using namespace Json;


#ifndef JSONPARSER_H_
#define JSONPARSER_H_


#define	 FIELD_TASK_ID  "task"
#define FIELD_CODE_TEXT  "code"
#define FIELD_CODE_LANGUAGE  "lang"
#define FIELD_OPERATION "operation"
#define FIELD_SESSION "session"
#define FIELD_JOBID "jobid"
#define FIELD_TOKEN "token"
#define JsonValue Value
#define FIELD_HEADER "header"
#define FIELD_ETALON "etalon"
#define FIELD_FOOTER "footer"
#define FIELD_NAME "name"
#define FIELD_FUNCTION_NAME "function_name"
#define FIELD_ARGS "args"
#define FIELD_IS_ARRAY "is_array"
#define FIELD_SIZE "size"
#define FIELD_TYPE "type"
#define FIELD_CMP_RESULT "compare_result"
#define FIELD_CMP_ARG "compare_argument"
#define FIELD_ARG_NAME "arg_name"
#define FIELD_VALUE "value"
#define FIELD_RESULTS "results"
#define FUNCTION "function"
#define ARGS "args"
#define FIELD_ETALON_VALUE "etalon_value"


/*


/*{
"code" : " System.out.println(\"Hello World!\"); ",

"task": "7",
"lang": "java"
}*/

/*
{
"code" : " std::cout << \"Hello World!\" << std::endl;",
"task": "2",
"lang": "c++"
}

 */



class jsonParser {

	Json::Value parsedFromString;
	Reader reader;
	string json;
	bool bJsonValid;
	list <Value> t_find;
	string last_error;

	int range_first;
	int range_last;

	bool is_results_array;
	int results_array_size;
	bool is_results_range;

	int unit_test_num;
public:
	bool isResultsArray();
	int getResultsArraySize();
	bool isResultsRange();
	string getLastError();
	jsonParser(string json);
	jsonParser();
	bool setJson(string in_json);

	int getRangeFirst();
	int getRangeLast();
	/*
	 *  not wooooorking
	 */
	static Value getRoot(string json);
	Value getRoot();
	Value getObject(string name, bool everyWhere);
	static bool isJson(string in_json);
	bool isJson();
	bool isValidFields();
	virtual ~jsonParser();


	bool rangeValidation(bool &range_size_inited, int &range_size, string range, string field_name);
	bool mustBeArrayFloat(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeArrayInt(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeArrayString(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeArrayBool(Json::Value object, string name , string ps = "", string ps2 = "");

	bool mustBeNotArrayFloat(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeNotArrayInt(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeNotArrayString(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustBeNotArrayBool(Json::Value object, string name , string ps = "", string ps2 = "");

	bool mustBeNotArray(Json::Value object, string name , string ps = "");
	bool mustBeArray(Json::Value object, string name , string ps = "");
	bool mustHaveSizeMoreZero(Json::Value object, string name , string ps = "");
	bool mustBeInt(Json::Value object, string name , string ps = "");
	bool mustBeBool(Json::Value object, string name , string ps = "");
	bool mustBeFloat(Json::Value object, string name , string ps = "");
	bool mustBeString(Json::Value object, string name , string ps = "");
	bool mustExist(Json::Value object, string name , string ps = "");

	bool mustExistBeInt(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustExistBeFloat(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustExistBeString(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustExistBeBool(Json::Value object, string name , string ps = "", string ps2 = "");
	bool mustExistBeArray(Json::Value object, string name , string ps = "", string ps2 = "");

	bool mustHaveSizeMoreZeroAndBeNotTwoDimensionalArray(Json::Value object, string name , string ps = "", string ps2 = "");

private:
	/*
	 *  no check is array? problem with find elemet // crash // not use
	 */
	Value findInArray(Value &array, string &name);
};

#endif /* JSONPARSER_H_ */
