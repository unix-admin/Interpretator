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
#include "includes.h"
#include "fcgio.h"
#include <sstream>
#include "cLang.h"
#include "codeclear.h"
#include "errorresponder.h"
#include "logfile.h"
//#include <pstream.h>
/*
 * BOOST
 */
/*
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
*/
#include <cassert>
#include <exception>

#include <jsoncpp/json/json.h>
#include "FCGI_Stream.h"

static void *doit(void *a);
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


//void print(boost::property_tree::ptree const& pt);

