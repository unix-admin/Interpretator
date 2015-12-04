#include "inc/main.h"

#include <ctime>
#include "inc/ctpl_stl.h"
#include "inc/SQLConnectionPool.h"
//extern Con(hash<string>()(jobid)^hash<string>()(jobid))fig *config;
using namespace std;
using namespace Json;

void ReplaceAll(std::string &str, const std::string& from, const std::string& to){
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
}
struct ThreadArguments {
	int id;
};

ctpl::thread_pool tasksPool(4);

class Later
{
public:
	template <class callable, class... arguments>
	Later(int after, bool async, callable&& f, arguments&&... args)
	{
		std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

		if (async)
		{
			std::thread([after, task]() {
				std::this_thread::sleep_for(std::chrono::milliseconds(after));
				task();
			}).detach();
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(after));
			task();
		}
	}

};
/*
 *  need insert into SQL
 */

void l12(string ll) {
	logfile::addLog(ll);
}

void l12(int ll) {
	logfile::addLog(to_string(ll));
}



void addUserToHistory(string userIp, string code) {
	vector<string> labl;
	labl.push_back("ID");
	labl.push_back("ip");
	labl.push_back("code");
	labl.push_back("date_time");
	if (SqlConnectionPool::getInstance().connectToTable("history", labl))
	{
		string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
		map<int, string> temp;
		temp.insert( { 1, userIp });
		temp.insert( { 2, str_with_spec_character(code) });
		temp.insert( { 3, s_datime });
		SqlConnectionPool::getInstance().addRecordsInToTable(temp);
	}
}


void processTask(int id,Job job) {

	//	logfile::addLog("Connection");
	// ConnectorSQL connector ;

	// int id = ((int *)a)[0];


	//char * inputSTR;
	LangCompiler compiler(id);
	/*
	 * input from PHP form // not use
	 *
	 * 	stream >> inputSTR; // test input
	 char *code = stream.getFormParam("text");
	 char *name = stream.getFormParam("name");
	 */

	/*
	 * problem with CodeClear need fix
	 *
	 CodeClear clr;
	 string outStr = code;
	 clr.ClearText(outStr);*/
	logfile::addLog("before code empty check");
	if (!job.code.empty())
	{

		vector<string> labl;
		//ADD NEW STARTED COMPILING INFO TO DATABASE
		labl.push_back("id");
		labl.push_back("session");
		labl.push_back("jobid");
		labl.push_back("status");
		labl.push_back("date");
		labl.push_back("result");
		labl.push_back("warning");
		logfile::addLog("Before connect to results");
		//logfile::addLog("Connection to results successful");
		if (SqlConnectionPool::getInstance().connectToTable("results", labl))
		{
			string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
			map<int, string> temp;
			temp.insert( { 1, job.session });
			temp.insert( { 2, std::to_string(job.jobid) });
			temp.insert( { 3, "in proccess"});
			temp.insert( { 4, s_datime });
			temp.insert( { 5, "" });
			temp.insert( { 6, "" });
			SqlConnectionPool::getInstance().addRecordsInToTable(temp);

			////////////////
			labl.clear();
			labl.push_back("ID");
			labl.push_back("name");
			labl.push_back("header");
			labl.push_back("etalon");
			labl.push_back("footer");

			string table;
			if (job.lang == "c++" || job.lang == "C++")
				table = "assignment_cpp"; //Config::getInstance().getTaskJavaTableName();
			else if (job.lang == "Java" || job.lang == "java")
				table = "assignment_java";
			else if (job.lang == "Js" || job.lang == "js")
				table = "assignment_js";
			else if (job.lang == "PHP" || job.lang == "php")
				table = "assignment_php";
			else if (job.lang == "C#" || job.lang == "c#" )
				table = "assignment_cs";
			else
				table = "assignment_cpp";
			if (SqlConnectionPool::getInstance().connectToTable(table, labl))
			{
				job.code =
						SqlConnectionPool::getInstance().getCustomCodeOfProgram(
								to_string(job.task), job.code, id,job.lang);
				logfile::addLog(job.code);
			}

			logfile::addLog(to_string(id)+ " Start compiler");
			JsonValue res;

			if (job.lang == "c++" || job.lang == "C++")
				compiler.compile(job.code, true, LangCompiler::Flag_CPP);
			else if (job.lang == "Java" || job.lang == "java")
				compiler.compile(job.code, true, LangCompiler::Flag_Java);
			else if (job.lang == "JS" || job.lang == "js")
				compiler.compile(job.code, true, LangCompiler::Flag_JS);
			else if (job.lang == "PHP" || job.lang == "php")
				compiler.compile(job.code, true, LangCompiler::Flag_PHP);
			else if (job.lang == "C#" || job.lang == "c#" )
				compiler.compile(job.code, true, LangCompiler::Flag_CS);
			else
				compiler.compile(job.code, true);

			string date = logfile::getDateStamp();
			res["date"] = date;
			res["result"] = compiler.getResult();
			res["warnings"] = compiler.getWarningErr();
			logfile::addLog( res.toStyledString());


			labl.clear();
			//UPDATE COMPILING INFO IN DB
			labl.push_back("id");
			labl.push_back("session");
			labl.push_back("jobid");
			labl.push_back("status");
			labl.push_back("date");
			labl.push_back("result");
			labl.push_back("warning");
			if (SqlConnectionPool::getInstance().connectToTable("results", labl))
			{
				string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
				map<int, string> temp;
				temp.insert( { 1, job.session });
				temp.insert( { 2, to_string(job.jobid) });
				if(compiler.getResult().size() == 0)
					temp.insert( { 3, "failed"});
				else
					temp.insert( { 3, "done"});
				temp.insert( { 4, s_datime });
				temp.insert( { 5, compiler.getResult()});
				temp.insert( { 6, compiler.getWarningErr() });
				//4j
				//string where = "`results`.`jobid`='"+to_string(job.jobid)+"' AND `results`.`session`='"+job.session+"'";
				map<int,string> where;
				where.insert({1,job.session});
				where.insert({2,to_string(job.jobid)});
				//ConnectorSQL::getInstance().updateRecordsInToTable(temp,wher);
				SqlConnectionPool::getInstance().updateRecordsInToTable(temp,where);

			}


			logfile::addLog(to_string(id) + " Stop compiler");
		}
		else {

			string error = to_string(id)+"Error: Can`t connect to results table \n";
			logfile::addLog(error);
		}
	}
}


static map<string, Token> TokenList;

void *receiveTask(void *a)
{
	l12("void *receiveTask(void *a) ");
	ThreadArguments argumento = ((ThreadArguments *) a)[0];

	int rc, i;
	int id = argumento.id;
	char * inputSTR;
	FCGX_Request *request;
	FCGI_Stream stream(socketId);
	ErrorResponder errorResponder(&stream);
	request = stream.getRequest();
	//string lang;

	for (;;)
	{
		if (stream.multiIsRequest()) { /////////////!!!!!!!!!!!!!!!!!!!
			//	break;
			logfile::addLog(request);
			if (strcmp(stream.getRequestMethod(), "GET") == 0)
			{
				logfile::addLog(id, "Request Method don't POST !!!");
				errorResponder.showError(404);
				logfile::addLog("session closed");
				stream.close();
				continue;
			}
			if(!SqlConnectionPool::getInstance().isConnected()  )
			{

				errorResponder.showError(505, "DataBaseERR");
				l12("Try reconect to DB");
				stream.close();
				SqlConnectionPool::getInstance().reconect(); //124
				continue;  //////////////////////////////
			}
			logfile::addLog("Before jsonParser jSON(stream.getRequestBuffer());");
			jsonParser jSON(stream.getRequestBuffer());

			logfile::addLog("Before parsing successful check");
			bool parsingSuccessful = jSON.isJson();
			logfile::addLog("Before jSON.isJson()");
			if (parsingSuccessful)
				logfile::addLog("Before jSON.isValidFields()");
			//parsingSuccessful = jSON.isValidFields(); //reader.parse( str, parsedFromString, false);// IsJSON
			logfile::addLog("Before parsing");
			/*
			 * ALL OK STARTif (SqlConnectionPool::getInstance().connectToTable(string("results"), labl))
			 */

			if (parsingSuccessful)
			{
				string ip_usera = FCGX_GetParam("REMOTE_ADDR", request->envp);
				cout.flush();
				logfile::addLog("Parsing successful");

				string operation = jSON.getObject("operation", false).asString();
				bool succsesful = true;
				/*
				 * OPERATION ADDTASK
				 */
				if (operation == "addtask")
				{
					if(!addNewtask(stream, jSON))
						succsesful = false;
				}
				else
					if (operation == "start")
					{
						if(!start(stream, jSON, FCGX_GetParam("REMOTE_ADDR", request->envp)))
							succsesful = false;
					}
					else
						if (operation == "addtestsig")
						{
							if(!addTestSignature(stream, jSON))
								succsesful = false;
						}
						else
							if (operation == "addtestval")
							{
								if (!addTestValues(stream,jSON))
									succsesful = false;
							}
							else
								if (operation == "add_tests")
								{
									if (!addTests(stream,jSON))
										succsesful = false;
								}
								else
									if (operation == "retreive_tests")
									{
										if (!retreiveTests(stream,jSON))
											succsesful = false;
									}
									else
										if (operation == "result" || operation == "status")
										{
											if(!result_status(stream, jSON, operation))
												succsesful = false;
										}
										else
											if (operation == "getToken")
											{
												if(!generationToken(stream, jSON, TokenList))
													succsesful = false;
											}
											else
												if (operation == "getFromToken")
												{
													if(!getFromToken(stream, jSON, TokenList))
														succsesful = false;
												}

				if(!succsesful)
				{
					errorResponder.showError(505, jSON.getLastError());
					stream.close();
					continue;
				}

			}
			else
			{
				logfile::addLog(id,	"Json format is not correct!!! \n::::::::::::::::::::::::\n" + stream.getRequestBuffer() + "\n::::::::::::::::::::::::");
				errorResponder.showError(400, "Json format is not correct!!!");
				stream.close();
				continue;
			}

		}
	}
	//close session
	logfile::addLog("session closed");
	stream.close();
	return NULL;
}

/*
 *
 *  				NEW TASK
 *
 */
bool addNewtask( FCGI_Stream &stream, jsonParser &jSON)
{
	if ( !jSON.isValidFields() )
	{
		//string error = jSON.getLastError();
		//stream << error;
		//stream.close();
		return false;
	}
	string lang = jSON.getObject("lang", false).asString();
	string table;
	if (lang == "c++" || lang == "C++")
		table = "assignment_cpp"; //Config::getInstance().getTaskJavaTableName();
	else if (lang == "Java" || lang == "java")
		table = "assignment_java";
	else if (lang == "PHP" || lang == "php")
		table = "assignment_php";
	else if (lang == "Js" || lang == "js")
		table = "assignment_js";
	else
		table = "assignment_cpp";

	vector<string> labl;
	labl.push_back("ID");
	labl.push_back("name");
	labl.push_back("header");
	labl.push_back("etalon");
	labl.push_back("footer");
	l12("before connectToTable");
	if (SqlConnectionPool::getInstance().connectToTable(table, labl))
	{
		l12("connectedToTable");
		map<int, string> temp;
		FunctionData functionData;
		string etalon = jSON.getObject("etalon", false).asString();
		l12("etalon");
		string name = jSON.getObject("name", false).asString();
		l12("name");
		int id = jSON.getObject("task",false).asInt();
		l12("task");
		l12(std::to_string(id));
		Value functionValue = jSON.getObject("function",false);

		functionData.etalon = etalon;
		functionData.returnValueType = functionValue["type"].asInt();
		functionData.functionName = "function_main";//@BAG@

		functionData.isArray = functionValue["results"][0].isArray();
		functionData.size = functionValue["results"][0].size();
		functionData.isRange = jSON.isResultsRange();

		for(JsonValue value:functionValue["results"])
		{
			if (jSON.isResultsRange())
			{
				int val1 = jSON.getRangeFirst();
				int val2 = jSON.getRangeLast();

				string arrString="{";
				int elmCount =0;
				for (int j = val1; j <= val2; j++){
					if (elmCount>0)arrString+=",";
					arrString += to_string(j);

					elmCount++;
				}
				arrString+="}";
				functionData.result.push_back(arrString);  //___opo
				functionData.returnValueType = 0;
				functionData.isArray = true;
			}
			else
				if(functionData.isArray == false)///////////////@BAG@
				{
					functionData.result.push_back(value.toStyledString());

					/*switch(type_rezult)
				{
					case FunctionData::RET_VAL_BOOL:
						functionData.result.push_back(value.asBool());
											break;
					case FunctionData::RET_VAL_FLOAT:
						functionData.result.push_back(value.asFloat());
											break;
					case FunctionData::RET_VAL_INT:
						functionData.result.push_back(value.asInt());
											break;
					case FunctionData::RET_VAL_STRING:
					functionData.result.push_back(value.asString());
					break;

					l12("qwe");*/
				}
				else
				{
					string arrString="{";
					int elmCount =0;
					for (int j = 0; j < value.size(); j++){
						if (elmCount>0)arrString+=",";
						arrString+=value[j].toStyledString();

						elmCount++;
					}
					arrString+="}";
					functionData.result.push_back(arrString);  //___opo
				}
		}

		for(JsonValue value:functionValue["tests_code"])
		{
			functionData.tests_code.push_back(value.asString());
		}


		Value functionArgs = functionValue["args"];
		for (int i=0; i<functionArgs.size(); i++)
		{
			Value argumentValue = functionArgs.get(i,false);
			FunctionArgument functionArgument;
			functionArgument.isArray = argumentValue["value"][0].isArray();
			functionArgument.size = argumentValue["value"][0].size();
			functionArgument.type = argumentValue["type"].asInt();
			functionArgument.name = argumentValue["arg_name"].asString();

			for(JsonValue value:argumentValue["value"])
			{
				if(functionArgument.isArray == false)
				{
					functionArgument.value.push_back(value.toStyledString());
					l12("qwe2");
				}
				else{
					string arrString="{";
					int elmCount =0;
					for (int j = 0; j < value.size(); j++){
						if (elmCount>0)arrString+=",";
						arrString+=value[j].toStyledString();

						elmCount++;
					}
					arrString+="}";
					functionArgument.value.push_back(arrString); //_opo
				}
			}
			for(JsonValue modvalue:argumentValue["etalon_value"])
			{
				if(functionArgument.isArray == false)
					functionArgument.etalonValue.push_back(modvalue.toStyledString());
				else{
					string arrString="{";
					int elmCount =0;
					for (int j = 0; j < modvalue.size(); j++){
						if (elmCount>0)arrString+=",";
						arrString+=modvalue[j].toStyledString();

						elmCount++;
					}
					arrString+="}";
					functionArgument.etalonValue.push_back(arrString); //_opo
				}
			}



			functionData.args.push_back(functionArgument);
		}
		//new code for testcases part

		int valuesCount = 0;
		temp.insert( { valuesCount++, std::to_string(id) });
		temp.insert( { valuesCount++, name }); //str_with_spec_character(
		temp.insert( { valuesCount++, str_with_spec_character(generateHeader(functionData))});
		temp.insert( { valuesCount++, str_with_spec_character(etalon)});
		l12("qwe33");
		temp.insert( { valuesCount++, str_with_spec_character(generateFooter(functionData) )});

		l12("temp.insert");
		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
		JsonValue res;
		if (SqlConnectionPool::getInstance().addRecordsInToTable(temp))
		{

			res["status"] = "success";
			res["table"] = table;
			res["id"] = to_string(id);
		}
		else res["status"] = "failed";
		stream << res.toStyledString();
		stream.close();
		return true;
	}
	else
		return false;
}

/*
 *
 * 					START
 *
 */
bool start(FCGI_Stream &stream, jsonParser &jSON, string ip_user)
{
	string session = jSON.getObject("session", false).asString();
	int jobid = jSON.getObject("jobid", false).asInt();
	string code = jSON.getObject("code", false).asString();
	int task = jSON.getObject("task", false).asInt();
	string lang = jSON.getObject("lang", false).asString();
	Job requestedTask;
	requestedTask.code = code;
	requestedTask.jobid = jobid;
	requestedTask.lang = lang;
	requestedTask.session = session;
	requestedTask.task = task;
	l12("no threa22");
	/*
	 * BAD NEED FIX @BUDLO@ INCLUDE INTO sql
	 */

	vector<string> labl;
	labl.push_back("id");
	labl.push_back("session");
	labl.push_back("jobid");
	labl.push_back("status");
	labl.push_back("date");
	labl.push_back("result");
	labl.push_back("warning");

	bool taskComp = false;
	if (SqlConnectionPool::getInstance().connectToTable(string("results"), labl))
	{
		l12("no threa2");
		vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
				"`session`='"+session+"' AND `jobid`='"+to_string(jobid)+"'");
		if ((int)records.size()==0)
			tasksPool.push(processTask,requestedTask);
		else
			taskComp = true;
		//stream << "this job is already excist";

		//addUserToHistory(ip_usera, code);
		labl.clear();
		labl.push_back("ID");
		labl.push_back("ip");
		labl.push_back("code");
		labl.push_back("date_time");
		if (SqlConnectionPool::getInstance().connectToTable("history", labl))
		{
			string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
			vector <map<int, string> > rec;
			map<int, string> temp;
			temp.insert( { 1, ip_user});
			temp.insert( { 2, str_with_spec_character(code) });
			temp.insert( { 3, s_datime });
			rec.push_back(temp);

			//MyConnectionPool::getInstance().getAllRecordsFromTable();
			SqlConnectionPool::getInstance().addRecordsInToTable(temp);
			//MyConnectionPool::getInstance().tt();
			if(taskComp)
			{
				stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
				JsonValue res;
				res["status"] = "already exist";
				stream << res.toStyledString();
			}
			else
				stream << "Status: 204\r\n Content-type: text/html\r\n" << "\r\n";
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
	// string ip_usera = FCGX_GetParam( "REMOTE_ADDR", request->envp );

}

bool addTestSignature(FCGI_Stream &stream, jsonParser &jSON)
{
	//string session = jSON.getObject("session", false).asString();
	int task = jSON.getObject("task", false).asInt();
	string lang = jSON.getObject("lang", false).asString();
	//string signature = jSON.getObject("tests_signatures",false).asString();
	string etalon = jSON.getObject("etalon",false).asString();
	Json::FastWriter fastWriter;
	Json::Value signatureValue = jSON.getObject("signature",false);
	std::string signature = fastWriter.write(signatureValue);
	vector<string> labl;
	labl.push_back("task_id");
	labl.push_back("lang");
	labl.push_back("signature");
	labl.push_back("etalon");

	bool taskComp = true;
	if (SqlConnectionPool::getInstance().connectToTable(string("tests_signatures"), labl))
	{
		l12("no threa2");
		vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
				"`task_id`='"+std::to_string(task)+"'");
		if ((int)records.size()==0)
			taskComp=true;
		else
			taskComp = false;


		vector <map<int, string> > rec;
		map<int, string> temp;
		temp.insert( { 0, std::to_string(task)});
		temp.insert( { 1, lang});
		temp.insert( { 2, str_with_spec_character(signature) });
		temp.insert( { 3, etalon });
		//rec.push_back(temp);

		//MyConnectionPool::getInstance().getAllRecordsFromTable();
		bool res = SqlConnectionPool::getInstance().addRecordsInToTable(temp);
		//MyConnectionPool::getInstance().tt();
		if(!taskComp)
		{
			stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
			JsonValue res;
			res["status"] = "already exist";
			stream << res.toStyledString();
		}
		else //204
			stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n"
			<<"success:"<<to_string(res)<<"signature:"<<signature;


	}
	else
	{
		return false;
	}
	return true;
	// string ip_usera = FCGX_GetParam( "REMOTE_ADDR", request->envp );

}
bool addTestValues(FCGI_Stream &stream, jsonParser &jSON)
{
	//string session = jSON.getObject("session", false).asString();
	int task = jSON.getObject("task", false).asInt();
	Json::FastWriter fastWriter;
	Json::Value returnVal = jSON.getObject("return_val", false);
	string returnStr = fastWriter.write(returnVal);
	Json::Value argsValue = jSON.getObject("args",false);
	std::string args = fastWriter.write(argsValue);
	vector<string> labl;
	labl.push_back("id");
	labl.push_back("task_id");
	labl.push_back("return_value");
	labl.push_back("arguments");

	bool taskComp = true;
	if (SqlConnectionPool::getInstance().connectToTable(string("tests_values"), labl))
	{
		/*l12("no threa2");
				vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
						"`task_id`='"+std::to_string(task)+"'");
				if ((int)records.size()==0)
					taskComp=true;
				else
					taskComp = false;
		 */

		vector <map<int, string> > rec;
		map<int, string> temp;
		temp.insert( { 1, std::to_string(task)});
		temp.insert( { 2, str_with_spec_character(returnStr)});
		temp.insert( { 3, str_with_spec_character(args) });

		//rec.push_back(temp);

		//MyConnectionPool::getInstance().getAllRecordsFromTable();
		bool res = SqlConnectionPool::getInstance().addRecordsInToTable(temp);
		//MyConnectionPool::getInstance().tt();
		/*if(!taskComp)
			{
				stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
				JsonValue res;
				res["status"] = "already exist";
				stream << res.toStyledString();
			}
			else *///204
		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n" <<"success:"<<res;


	}
	else
	{
		return false;
	}
	return true;
	// string ip_usera = FCGX_GetParam( "REMOTE_ADDR", request->envp );

}

bool addTests(FCGI_Stream &stream, jsonParser &jSON)
{
	//string session = jSON.getObject("session", false).asString();
	int task = jSON.getObject("task", false).asInt();
	Json::FastWriter fastWriter;
	Json::Value jsonValue = jSON.getRoot();
	std::string json = fastWriter.write(jsonValue);
	vector<string> labl;
	labl.push_back("task_id");
	labl.push_back("json");

	bool taskComp = true;
	if (SqlConnectionPool::getInstance().connectToTable(string("tests"), labl))
	{
		/*l12("no threa2");
				vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
						"`task_id`='"+std::to_string(task)+"'");
				if ((int)records.size()==0)
					taskComp=true;
				else
					taskComp = false;
		 */

		vector <map<int, string> > rec;
		map<int, string> temp;
		temp.insert( { 0, std::to_string(task)});
		temp.insert( { 1, str_with_spec_character(json)});
		//rec.push_back(temp);
		//MyConnectionPool::getInstance().getAllRecordsFromTable();
		bool res = SqlConnectionPool::getInstance().addRecordsInToTable(temp);
		//MyConnectionPool::getInstance().tt();
		/*if(!taskComp)
			{
				stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
				JsonValue res;
				res["status"] = "already exist";
				stream << res.toStyledString();
			}
			else *///204
		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n" <<"success:"<<res;


	}
	else
	{
		return false;
	}
	return true;
	// string ip_usera = FCGX_GetParam( "REMOTE_ADDR", request->envp );

}

bool retreiveTests(FCGI_Stream &stream, jsonParser &jSON)
{
	//string session = jSON.getObject("session", false).asString();
	int task = jSON.getObject("task", false).asInt();
	vector<string> labl;
	labl.push_back("task_id");

	bool taskComp = true;
	if (SqlConnectionPool::getInstance().connectToTable(string("tests"), labl))
	{
		/*l12("no threa2");
				vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
						"`task_id`='"+std::to_string(task)+"'");
				if ((int)records.size()==0)
					taskComp=true;
				else
					taskComp = false;
		 */

		vector<map<int, string> > records = SqlConnectionPool::getInstance().getAllRecordsFromTable("`task_id`='"+std::to_string(task)+"'");
		//MyConnectionPool::getInstance().tt();
		bool recordsEmpty = records.size() == 0;
		if (recordsEmpty)stream << "Status: 204\r\n Content-type: text/html\r\n" << "\r\n" <<"task with this id doesn't excist";
		else
		{
			stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
			JsonValue res;
			res["json"] = records[0][1];
			stream << res.toStyledString();
		}

	}
	else
	{
		return false;
	}
	return true;
	// string ip_usera = FCGX_GetParam( "REMOTE_ADDR", request->envp );

}



/*
 *
 * 					RESULT_STATUS
 *
 */
bool result_status(FCGI_Stream &stream, jsonParser &jSON, string operation)
{
	string session = jSON.getObject("session", false).asString();
	int jobid = jSON.getObject("jobid", false).asInt();
	//TO BE CONTINUED ...
	vector<string> labl;

	labl.push_back("id");
	labl.push_back("session");
	labl.push_back("jobid");
	labl.push_back("status");
	labl.push_back("date");
	labl.push_back("result");
	labl.push_back("warning");
	if (SqlConnectionPool::getInstance().connectToTable("results", labl)	== true)
	{
		string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
		map<int, string> temp;
		temp.insert( { 1, session });
		temp.insert( { 2, to_string(jobid) });
		//3,skip
		temp.insert( { 4, s_datime });
		//4
		vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
				"`session`='"+session+"' AND `jobid`='"+to_string(jobid)+"'");
		//	logfile::addLog(std::to_string(records.size()));
		//for (int i=0; i< records.size(); i++)

		/*Cool start for future code, NO delete
		 * logfile::addLog("Id:"+records[i][0]);
			 logfile::addLog("Session:"+records[i][1]);
			 logfile::addLog("jobId:"+records[i][2]);
			 logfile::addLog("requested status for session:"+session+":"+records[i][3]);
			 logfile::addLog("date:"+records[i][4]);
			 logfile::addLog("result:"+records[i][5]);
			 logfile::addLog("warning:"+records[i][6]);
		 */
		/*Cool code no delete
			 stream << "Id:"+records[i][0] << "\n";
			 stream << "Session:"+records[i][1] << "\n";
			 stream << "jobId:"+records[i][2] << "\n";
		 */
		//stream << "status:" +	 records[i].find(keys[r])->second ;
		/*
		 * RESULT
		 */

		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";

		JsonValue res;
		if(records.size() > 0)
		{
			res["status"] = records[0][3];
			if (operation == "result")
			{
				res["date"] = records[0][4];
				res["warning"] = records[0][6];
				//////////////////////////////////////////////////NEW//17.11.15

				/*		string result = records[0][5];
				  smatch m;
				  regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"


				  while (std::regex_search (result,m,e)) {
				    for (auto x:m) std::cout << x << " ";
				    std::cout << std::endl;
				    result = m.suffix().str();
				  }
				 */
				res["testResult"] = JsonValue(arrayValue);

				string part = records[0][5];
				int start = part.find('@');

				if(start == string::npos)
				{
					int position = records[0][5].find("exception");
					if( string::npos != position)
					{
						int p = records[0][5].substr(0, position).find_last_of("\n");
						res["result"] = records[0][5].substr(p + 1);//records[0][5].substr(0, p - 1);
						res["done"] = false;//records[0][5].substr(p);
					}
					else
						res["result"] = records[0][5];

				}
				else
				{
					res["result"] = part.substr(0, start);
					int count = 0;
					bool done = true;
					while(start++ != string::npos)// need test after first fail?
					{
						int next = part.substr(start).find('@');
						string number;
						if(next != string::npos)
						{
							if(next -1 >= 0 && part[start + next - 1] == '!')
							{
								number = part.substr(start, next - 1);
								res["testResult"][count] = JsonValue(false);
								done = false;
							}
							else
							{
								number = part.substr(start, next );
								res["testResult"][count] = JsonValue(true);
							}
						}
						part = part.substr(start + next + 1);
						count++;
						start = part.find('@');
					}
					res["done"] = JsonValue(done);
					/*
					 *	int next = part.substr(start).find('@');
						string number;

						/*if(part[next-1] == '!')
						{
							number = part.substr(start, next - start - 1);
							res["result"][count] = JsonValue(false);
						}
						else
						{
							number = part.substr(start, next - start);
							res["result"][count] = JsonValue(true);
						}
					//	part = part.substr(next);
						l12(part);
						start = part.find('@');
						count++;
					 */
				}
			}
		}
		else
			res["status"] = "not found";

		stream << res.toStyledString();

		//	stream << "status:" + records[0][3] << "\n\n";
		/*Cool code no delete
		 stream << "date:"+records[i][4] << "\n";
		 stream << "result:"+records[i][5] << "\n";
		 stream << "warning:"+records[i][6] << "\n";
		 */
		logfile::addLog("Table 'results' outputed");
		cout.flush();
	}
	else
		return false;
	return true;
}

int main(void)
{
	Config::getInstance().makeValueStructure();
	Config::getInstance().scanConfigFile();

	//config = new Config();

	pthread_t *id = new pthread_t[Config::getInstance().getThreadCount()];
	FCGX_Init();
	logfile::clear();
	logfile::addLog("\n\n\n\nStart server ==== Lib is inited");
	// system("mkdir -m 777 src");
	// open socket unix or TCP
	string socket = "127.0.0.1:" + Config::getInstance().getPort();
	socketId = FCGX_OpenSocket(socket.c_str(), 2000);
	if (socketId < 0) {
		logfile::addLog(string("Cannot open socket	" + socket));
		return 1;
	}
	logfile::addLog(
			"Socket is opened " + socket + "...  create "
			+ to_string(Config::getInstance().getThreadCount()) + " threads");
	int i;
	//create thread
	for (i = 0; i < Config::getInstance().getThreadCount(); i++) {
		ThreadArguments argumento;
		argumento.id = i;
		pthread_create(&id[i], NULL, receiveTask, (void *) &argumento);
		// pthread_create(&id[i], NULL, doit, (void *)&i);
	}

	// wait threads
	for (i = 0; i < Config::getInstance().getThreadCount(); i++) {
		pthread_join(id[i], NULL);
	}
	delete[] id;
	logfile::addLog("Server stoped successful");
	return 0;
}

//GENERATION TOKEN
bool generationToken(FCGI_Stream &stream, jsonParser &jSON, map<string, Token> &token)
{
	string session = jSON.getObject("session", false).asString();
	int jobid = jSON.getObject("jobid", false).asInt();
	Token tok;
	tok.session = session;
	tok.jobId = jobid;
	hash<string> hash_fn;
	long hash = hash_fn(session)^(hash_fn(to_string(jobid)) << 1)^(hash_fn(to_string(time(0))) << 2);
	string value = to_string(hash);
	token[value] = tok;
	JsonValue res;

	res["token"] = value;
	stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
	stream << res.toStyledString();

	Later later_delete(Config::getInstance().getTokenTimeOut(), true, &deleteToken, value);
	//Later later_test2(1000, false, &test2, 101);

	return true;

}

bool getFromToken(FCGI_Stream &stream, jsonParser &jSON, map<string, Token> &tokenList)
{
	JsonValue res;
	string strToken = jSON.getObject("token", false).asString();
	Token value;
	if(tokenList.count( strToken ) == 0)
	{
		res["status"] = "Token time out";
		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";
		stream << res.toStyledString();
		logfile::addLog("Token time out");
		l12( "GET FROM TOKEN" );
		l12( to_string(tokenList.size()) );
		cout.flush();
		return true;
	}
	value =  tokenList[strToken];

	string session = value.session;
	int jobid = value.jobId;
	l12( "GET FROM TOKEN" );
	l12( to_string(jobid) );
	l12( session );
	//TO BE CONTINUED ...
	vector<string> labl;

	labl.push_back("id");
	labl.push_back("session");
	labl.push_back("jobid");
	labl.push_back("status");
	labl.push_back("date");
	labl.push_back("result");
	labl.push_back("warning");
	if (SqlConnectionPool::getInstance().connectToTable("results", labl)	== true)
	{
		string s_datime = getDateTime(); //'YYYY-MM-DD HH:MM:SS'
		map<int, string> temp;
		temp.insert( { 1, session });
		temp.insert( { 2, to_string(jobid) });
		//3,skip
		temp.insert( { 4, s_datime });
		//4
		vector<map<int, string> > records =	SqlConnectionPool::getInstance().getAllRecordsFromTable(
				"`session`='"+session+"' AND `jobid`='"+to_string(jobid)+"'");
		//	logfile::addLog(std::to_string(records.size()));
		//for (int i=0; i< records.size(); i++)

		/*Cool start for future code, NO delete
		 * logfile::addLog("Id:"+records[i][0]);
 			 logfile::addLog("Session:"+records[i][1]);
 			 logfile::addLog("jobId:"+records[i][2]);
 			 logfile::addLog("requested status for session:"+session+":"+records[i][3]);
 			 logfile::addLog("date:"+records[i][4]);
 			 logfile::addLog("result:"+records[i][5]);
 			 logfile::addLog("warning:"+records[i][6]);
		 */
		/*Cool code no delete
 			 stream << "Id:"+records[i][0] << "\n";
 			 stream << "Session:"+records[i][1] << "\n";
 			 stream << "jobId:"+records[i][2] << "\n";
		 */
		//stream << "status:" +	 records[i].find(keys[r])->second ;
		/*
		 * RESULT
		 */

		stream << "Status: 200\r\n Content-type: text/html\r\n" << "\r\n";


		if(records.size() > 0)
		{
			res["status"] = records[0][3];
			{
				res["date"] = records[0][4];
				res["warning"] = records[0][6];
				res["result"] = records[0][5];
			}
		}
		else
			res["status"] = "not found";

		stream << res.toStyledString();

		//	stream << "status:" + records[0][3] << "\n\n";
		/*Cool code no delete
 		 stream << "date:"+records[i][4] << "\n";
 		 stream << "result:"+records[i][5] << "\n";
 		 stream << "warning:"+records[i][6] << "\n";
		 */
		logfile::addLog("Table 'results' outputed");
		cout.flush();
	}
	else
		return false;
	return true;
}

void deleteToken(string tok)
{
	TokenList.erase(tok);
}


string generateFunctionProtorype(FunctionData functionData, LangCompiler::compilerFlag = LangCompiler::Flag_CPP, string name = "function", char divider = ',', char space = ' ')
{
	string functionStr = generateType(functionData.returnValueType, 0);
	if (functionData.isArray)
		functionStr += "* ";
	functionStr	+= name + "(";

	int argCount = 0;

	int array_cnt = 0;
	/*for(int i = 0; i < functionData.result.size(); i++)
		{
			string arrType = functionData.getReturnType();
			string arrName="array"+std::to_string(array_cnt);
			if (functionData.isArray )
			{
				string arrayDeclaration=arrType+" " + arrName + "[]=" + functionData.result[i];
				headerStr += arrayDeclaration + ";\n";
			}

			for(FunctionArgument arg : functionData.args)
			if (arg.isArray)
			{
				string argStringValue =arg.value[i];
				string arrayDeclaration;
				arrayDeclaration += arrType+" " + arrName + "[]=" + argStringValue.c_str();
				headerStr += arrayDeclaration + ";\n";
			}
			array_cnt++;
		}*/


	/*headerStr += functionData.getReturnType() + " result";
		if (functionData.isArray )
		{
			headerStr  += "[" + to_string(functionData.size) + "]";
		}
		headerStr += ";\n";*/

	for(FunctionArgument arg : functionData.args){
		if (argCount>0)
			functionStr += divider;
		string type = generateType(arg.type, 0);// 0 == C++
		functionStr += type + space;


		//headerStr += type + space +  arg.name;
		if ( arg.isArray )
		{
			functionStr += "*" + arg.name;
			//headerStr  += "[" + to_string(arg.size) + "]";
		}
		else
		{
			functionStr += "&" + arg.name;
		}
		//headerStr += ";\n";
		argCount++;
	}
	//close prototype and open body of function
	functionStr += ")\n";
	return functionStr;
}
string generateHeader(FunctionData functionData){

	string headerStr = getStandartInclude(LangCompiler::Flag_CPP) + "\n";
	headerStr += generateFunctionProtorype(functionData, LangCompiler::Flag_CPP, "function_etalon"); //create prototype for etalon function
	headerStr += "{\n" + functionData.etalon + "return NULL;\n}\n"; // add etalon function
	headerStr += generateFunctionProtorype(functionData, LangCompiler::Flag_CPP, functionData.functionName) + "{\n";
	/*l12("Yura: 2202:");
	l12(headerStr);*/
	return headerStr;
}
bool to_bool(std::string const& s) {
	return s != "0";
}
string generateFooter(FunctionData functionData){
	string footerBody = "return 0;\n}\n";//Close function body
	string space=" ";
	char divider=',';
	string modifiedArgComparsion;
	//C++
	string arrCompFuncStr="template<typename T,int size>\n\
	bool compareArrs(T arr1[size],T arr2[size])\n\
		{\n\
		for (int i=0;i<size;i++)\n\
		{\n\
		if (strcmp(typeid(T).name(), \"f\") == 0)\n\
		{\n	\
		if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n\
			return false;\n\
		}\n \
		else	\n\
			if (arr1[i] != arr2[i])\n\
				return false;\n\
			}\n\
			return true;\n\
	}\n";
	footerBody+=arrCompFuncStr;
	footerBody+="int main()\n\
			{\n";

	footerBody += functionData.getReturnType() + " result_etalon";
	if (functionData.isArray )
	{
		footerBody  += "[" + to_string(functionData.size) + "]";
	}
	footerBody += ";\n";

	/*
	 *
	 *
	 */
	footerBody += functionData.getReturnType();
	if (functionData.isArray )
	{
		footerBody  += " *";
	}
	footerBody += "result;\n";

	footerBody += functionData.getReturnType();
	if (functionData.isArray )
	{
		footerBody  += " *";
	}
	footerBody += "result" + string(ETALON_FOR_FUNCTION_ENDING) + ";\n";

	/*
	 *
	 *
	 *
	 */
	for(FunctionArgument arg : functionData.args)
	{
		string argumentDeclaration="",argumentEtalonDeclaration="",argumentForEtalonFunctionDeclaration="";
		argumentDeclaration = generateType(arg.type, 0) + " " +  arg.name;
		argumentEtalonDeclaration =  generateType(arg.type,0) + " " + arg.name + ETALON_ENDING;
		argumentForEtalonFunctionDeclaration =  generateType(arg.type,0) + " " + arg.name + string(ETALON_FOR_FUNCTION_ENDING);
		//footerBody +=
		if ( arg.isArray )
		{
			argumentDeclaration  += "[" + to_string(arg.size) + "]";
			argumentEtalonDeclaration += "[" + to_string(arg.size) + "]";
			argumentForEtalonFunctionDeclaration += "[" + to_string(arg.size) + "]";
			/*
			 * @NEED REFACTOR@
			 *
			 */
		}
		argumentDeclaration += ";\n";
		argumentEtalonDeclaration += ";\n";
		argumentForEtalonFunctionDeclaration+= ";\n";

		//add etalon variables
		footerBody += argumentDeclaration + argumentEtalonDeclaration + argumentForEtalonFunctionDeclaration;

	}


	string argsString;
	string etalongArgsString;

	bool is_float = (functionData.returnValueType == FunctionArgument::VAL_FLOAT);
	for(int i = 0; i < functionData.result.size(); i++)
	{

		if ( !functionData.isArray)
		{
			footerBody += /*"result" + string(ETALON_FOR_FUNCTION_ENDING) + " = " + */"result_etalon = " + functionData.result[i] + ";\n";
		}
		else
		{
			//footerBody += arg.name +"[" + to_string(i) + "] = " + arg.value[i] + ";\n";
			string values_u = functionData.result[i].substr(1, functionData.result[i].size() - 2 );
			string indiv_value = "";
			//values_u[0] = " ";
			int v_size = values_u.size();
			//values_u[v_size - 1] = " ";
			int rez_size = 0;
			for (int h = 0; h < v_size; h++)
			{
				if (values_u[h] != ',')
					indiv_value += values_u[h];
				else
				{
					footerBody += /*"result" + string(ETALON_FOR_FUNCTION_ENDING) + "[" + to_string(rez_size) + "] = " +*/ "result[" + to_string(rez_size) + "] = ";
					if (is_float)
						footerBody += " (float) ";
					footerBody += indiv_value + ";\n";
					indiv_value = "";
					rez_size++;
				}
			}
			if (indiv_value.size() != 0)
			{
				footerBody += /*"result" + string(ETALON_FOR_FUNCTION_ENDING) + "[" + to_string(rez_size) + "] = " + */ "result[" + to_string(rez_size) + "] = ";
				if (is_float)
					footerBody += " (float) ";
				footerBody += indiv_value + ";\n";
			}
			//for (int u=0; u < arg.value[i].size(); u++)		footerBody += arg.name +"[" + to_string(u) + "] = " + arg.value[i] + ";\n";
		}
		/*if (functionData.isRange )
		{

		}
		else*/

		string argumentDefinition;
		string argumentEtalonDefinition;
		string argForMainFunction;
		string argForEtalonFunction;

		int argCount = 0;
		string variablesCorrect = "bool variablesCorrect = ";
		// bool variablesCorrect = compareArrs<float,2>(x,x_etalon) && (vasya == vasya_etalon);
		for(FunctionArgument arg : functionData.args){
			if ( !arg.isArray )
			{
				string currentArgDef = arg.name + string(ETALON_FOR_FUNCTION_ENDING) + " = " + arg.name + " = " + arg.value[i] + ";\n";
				string currentArgEtalonDef = arg.name + string(ETALON_ENDING) + string(" = ") +
						arg.etalonValue[i] + string(";\n"); //etalon value for argument
				argumentDefinition += currentArgDef;
				argumentEtalonDefinition += currentArgEtalonDef;
				variablesCorrect += "(" + arg.name + " == " + arg.name + string(ETALON_ENDING) + ")";
				//variablesCorrect += "(" + currentArgDef + "==" + currentArgEtalonDef + ")";
				if (argCount != functionData.args.size() - 1 )
					variablesCorrect += " && ";
				else
					variablesCorrect+=";\n";
			}
			else
			{
				//footerBody += arg.name +"[" + to_string(i) + "] = " + arg.value[i] + ";\n";
				string values_u = arg.value[i].substr(1, arg.value[i].size() - 2 );
				string etalons_values_u = arg.etalonValue[i].substr(1, arg.etalonValue[i].size() - 2 );
				string indiv_value = "";
				string etal_value = "";
				//values_u[0] = " ";
				int v_size = values_u.size();
				int v_etalons_size = etalons_values_u.size();
				//values_u[v_size - 1] = " ";
				int arg_size = 0;
				int etalon_arg_size = 0;
				for (int h = 0; h < v_size; h++)
				{
					if (values_u[h] != ',')
						indiv_value += values_u[h];
					else
					{
						argumentDefinition += arg.name + string(ETALON_FOR_FUNCTION_ENDING) + "[" + to_string(arg_size) + "] = " + arg.name +"[" + to_string(arg_size) + "] = " + indiv_value + ";\n";
						indiv_value = "";
						arg_size++;
					}
				}
				for (int h = 0; h < v_etalons_size; h++)
				{
					if (etalons_values_u[h] != ',')
						etal_value += values_u[h];
					else
					{
						argumentEtalonDefinition += arg.name + ETALON_ENDING + "[" + to_string(etalon_arg_size) + "] = " + etal_value + ";\n";
						etal_value = "";
						etalon_arg_size++;
					}
				}
				variablesCorrect+= "compareArrs<"+arg.getType()+","+
						std::to_string(arg.size) + ">(" + arg.name + "," + arg.name + ETALON_ENDING + ")";
				if ( argCount != functionData.args.size() - 1 )
					variablesCorrect+=" && ";
				//	else variablesCorrect+=");";

				if (indiv_value.size() != 0)
				{
					argumentDefinition += arg.name +"[" + to_string(arg_size) + "] = " + indiv_value + ";\n";
				}
				if (etal_value.size() != 0){
					argumentEtalonDefinition  += arg.name + ETALON_ENDING +"[" + to_string(etalon_arg_size) + "] = " + etal_value + ";\n";
				}

				//for (int u=0; u < arg.value[i].size(); u++)		footerBody += arg.name +"[" + to_string(u) + "] = " + arg.value[i] + ";\n";
			}


			if(argCount > 0)
			{
				argForMainFunction += divider;
				argForEtalonFunction += divider;
			}

			string argStringValue = arg.value[i];
			string etalonStringValue = arg.etalonValue[i];
			string arrType;
			string arrName = arg.name;//    "array"+std::to_string(arraysCount);
			string etalonArrName = arrName + ETALON_FOR_FUNCTION_ENDING;
			switch(arg.type){
			case FunctionData::RET_VAL_BOOL:
				arrType="bool";//add array type
				argForMainFunction += arrName;
				argForEtalonFunction += etalonArrName;

				break;
			case FunctionData::RET_VAL_FLOAT:
				arrType="float";//add array type
				argForMainFunction += arrName;
				argForEtalonFunction += etalonArrName;
				break;
			case FunctionData::RET_VAL_INT:
				argForMainFunction += arrName;
				argForEtalonFunction += etalonArrName;
				break;
			case FunctionData::RET_VAL_STRING:
				argForMainFunction += arrName;
				argForEtalonFunction += etalonArrName;
				break;

				/*case FunctionData::RET_VAL_RANGE
						if (arg.isArray){
							arrType="string";//add array type
							argsString += arrName;
						}
						else
							argsString += '"'+argStringValue+'"';

						break;*/
			}


			//footerBody+=arg.value[0];//@BAD@
			argCount++;
		}
		footerBody += argumentDefinition;
		footerBody += argumentEtalonDefinition;
		argsString += variablesCorrect+";\n";
		argsString += "result" + string(ETALON_FOR_FUNCTION_ENDING) +  " = function_etalon(" + argForEtalonFunction +  ");\n";
		argsString += "result = " + functionData.functionName + "(" + argForMainFunction +  ");\n";
		argsString += "bool isTrue = false;\n";
		argsString += functionData.tests_code[i] + "\n";

		if (functionData.isArray )
		{
			string arrType = functionData.getReturnType();
			/*string arrayDeclaration=arrType+" "+arrName+"[]="+functionData.result[i];
			footerBody+=arrayDeclaration+";\n";*/

			//if (std::equal(std::begin(iar1), std::end(iar1), std::begin(iar2)))


			argsString += "if (compareArrs<"+arrType+","+
					std::to_string(functionData.size)+">(result_etalon, result)";

		}
		else
			argsString += "if ( result_etalon == result)";//open function call body;

		//if (functionData.isArray)
		{
			argsString+=" && variablesCorrect && isTrue)\n";
			//TODO
		}

		argsString += "std::cout << \" @" + to_string(i) + "@\";\n";
		argsString += "else\n";
		argsString += "std::cout << \" @" + to_string(i) + "!@\";\n";


	}
	footerBody+=argsString;
	footerBody += "\n}";
	//C++

	l12("Yura:: 00001");
	l12(footerBody);
	return footerBody;
}

string generateType(int type, int lang)
{
	string result;
	switch(type){
	case FunctionData::RET_VAL_BOOL:
		result += "bool";
		break;
	case FunctionData::RET_VAL_FLOAT:
		result += "float";
		break;
	case FunctionData::RET_VAL_INT:
		result += "int";
		break;
	case FunctionData::RET_VAL_STRING:
		result += "string";
		break;
	}
	result += " ";
	return result;
}
string generateVar(int type, string name, int lang, string value)
{
	string result;
	result = generateType(type, lang) + name + " ";

	/*if(value.length() > 0)
	switch(type){
		case FunctionData::RET_VAL_BOOL:
			result += to_bool(argStringValue);
					break;
				case FunctionData::RET_VAL_FLOAT:
					result += std::atof(argStringValue.c_str());
					break;
				case FunctionData::RET_VAL_INT:
					result += argStringValue.c_str();
					break;
				case FunctionData::RET_VAL_STRING:
					result += '"'+argStringValue+'"';
					break;
		}*/
	return result;

}
string getStandartInclude(int lang)
{
	string include;
	switch(lang)
	{
	case LangCompiler::Flag_CPP:{
		include = "#include <iostream>\n\
		#include <cstdlib>\n\
		#include <algorithm>\n using namespace std;\n\
		#include <cxxabi.h>\n\
		#include <cmath>\n\
		#include <stdio.h>\n\
		#include <string.h>";

	}
	case LangCompiler::Flag_Java:{
		//...
	}
	}
	return include + "\n";

}
string convertStringToType(string argStringValue, int type, int lang)
{
	string result;
	switch(type){
	case FunctionData::RET_VAL_BOOL:
		result += to_bool(argStringValue);
		break;
	case FunctionData::RET_VAL_FLOAT:
		result += argStringValue.c_str();
		break;
	case FunctionData::RET_VAL_INT:
		result += argStringValue.c_str();
		break;
	case FunctionData::RET_VAL_STRING:
		result += argStringValue;
		break;
	}
	return result;
}
string convertTypeToString(int type, int lang)
{

}
