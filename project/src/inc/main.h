/*#include "fcgi_stdio.h"

#include <stdlib.h>

int count;

void initialize(void)
{
  count=0;
}

int main(void)
{

  initialize();


  while (FCGI_Accept() >= 0)   {
    printf("Content-type: text/html\r\n"
           "\r\n"
           "<title>FastCGI Hello! (C, fcgi_stdio library)</title>"
           "<h1>FastCGI Hello! (C, fcgi_stdio library)</h1>"
           "Request number %d running on host <i>%s</i>\n",
            ++count, getenv("SERVER_HOSTNAME"));
  }
}*/
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
#include "SQLconnector.h"
#include "config.h"
#include "ctpl_stl.h"
#include <iostream>
#include <string>
#include <regex>

#include <ctime>
using namespace std;
//#include <pstream.h>

#include <cassert>
#include <exception>
#include "FCGI_Stream.h"


//TIMER
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>



//static void *doit(void *a);
int Apache(void);



void show404()
{
	cout << "Status: 404\r\n"
		 << "Content-type: text/html\r\n"
		 << "\r\n"
		 << " <html><head>"
		 << "<title>404 Not Found</title>"
		 << "</head><body>"
		 << "<h1>Not Found</h1>";
		 cout << "<p>The requested URL /localhost was not found on this server.</p>"
		 << "<hr>"
		 << "</body></html>";
	/*
	         * ERR
	         */
	        /*cout << "Status: 404\r\n"
	                 << "Content-type: text/html\r\n"
	                 << "\r\n"
	                 << "<html><body><h1>404	Not Found	:(</h1></body></html>\n";

	*/
}


bool result_status(FCGI_Stream &stream, jsonParser &jSON, string operation);
bool start(FCGI_Stream &stream, jsonParser &jSON, string ip_user);
bool addTestValues(FCGI_Stream &stream, jsonParser &jSON);
bool addTests(FCGI_Stream &stream, jsonParser &jSON);
bool retreiveTests(FCGI_Stream &stream, jsonParser &jSON);
bool addTestSignature(FCGI_Stream &stream, jsonParser &jSON);
bool addNewtask( FCGI_Stream &stream, jsonParser &jSON);
bool editTask( FCGI_Stream &stream, jsonParser &jSON);
bool generationToken(FCGI_Stream &stream, jsonParser &jSON, map<string, Token> &token);
bool getFromToken(FCGI_Stream &stream, jsonParser &jSON, map<string, Token> &tokenList);
void deleteToken(string tok);
bool to_bool(std::string const& s);
string generateHeader(FunctionData functionData);
string generateFooter(FunctionData functionData);
string generateType(int type, int lang);
string generateVar(int type, string name, int lang, string value = string());

string convertStringToType(string argStringValue, int type, int lang);
string convertTypeToString(int type, int lang);

string getStandartInclude(int lang);

