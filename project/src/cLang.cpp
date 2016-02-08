#include "inc/cLang.h"

LangCompiler::LangCompiler(int ID){
	thID = ID;
	timeOut = 2000/1000;
}

LangCompiler::~LangCompiler(){

}

string LangCompiler::compile(string code, bool show, compilerFlag flags)
{
	string res;
	warning_err.clear();
	result.clear();
	cout.flush();

	if(!generetionSample(code, flags))
	{
		ERROR("Canot open file with generation source code, maybe permission denied	");
		return "Canot open file with generation source code, maybe permission denied";
	}
	l12("11111111111111111111111");
	l12(code);
	cout.flush();
	cout.flush();
	string code_file_name;

	string build_str ;
	string prog_name;
	string run_str ;
	switch(flags){
	case Flag_CPP:
		code_file_name = "prog" + to_string(thID) + ".out";
		//build_str = "cd src; clang++ -Wall -stdlib=libc++ code" + to_string(thID) + ".cpp -o ../prog" + to_string(thID) + ".out";
		build_str = "g++ -Wno-deprecated -W ./src/code" + to_string(thID) + ".cpp -o prog" + to_string(thID) +
				".out 2>&1;rm ./src/code" + to_string(thID) + ".cpp";
		//".out 2>&1	";
		run_str = " ./prog" + to_string(thID) + ".out 2>&1;  rm prog" + to_string(thID) + ".out";
		prog_name = code_file_name;
		break;
	case Flag_Java:
		code_file_name = "Main" + to_string(thID) + ".class";
		build_str = "cd src; javac Main" + to_string(thID) + ".java -d ../ 2>&1";
		run_str = " java Main" + to_string(thID) + " 2>&1 ;  rm Main" + to_string(thID)+".class";
		prog_name = "Main"+to_string(thID)+".class";
		break;
	case Flag_JS:
		code_file_name = "Main" + to_string(thID) + ".js";
		build_str = "cd src; nodejs Main" + to_string(thID) + ".js ../ 2>&1";
		run_str = " node Main" + to_string(thID) + " 2>&1 ;  rm Main" + to_string(thID)+".js";
		prog_name = "Main"+to_string(thID)+".js";
		break;
	case Flag_PHP:
		code_file_name = "./src/Main" + to_string(thID) + ".php";
		build_str = "";
		run_str = "php ./src/Main" + to_string(thID) + ".php 2>&1 ;  ";
		prog_name = code_file_name;
		break;
	case Flag_CS:
		code_file_name = "./src/Main" + to_string(thID) + ".exe";
		build_str = "dmcs ./src/Main" + to_string(thID) + ".cs 2>&1";
		run_str = " mono ./src/Main" + to_string(thID) + ".exe 2>&1 " + "; rm ./src/Main" + to_string(thID) + ".exe";
		prog_name = code_file_name;
		break;
	}//java -jar js.jar myscript.js

	/*
	 * BETA // don't delete
	 *
	in.append("cd /var/www/fcgi/srs/; clang++ -Wall -stdlib=libc++ code$1.cpp -o prog$1.out; if [ -f /var/www/fcgi/srs/prog$1.out ]; then  ./prog$1.out;  rm prog$1.out; fi");
	in.append("cd /var/www/fcgi/srs/;");
	in.append("clang++ -Wall -stdlib=libc++ code" + to_string(thID) + ".cpp -o prog" + to_string(thID) + ".out;");
	in.append("if [ -f /var/www/fcgi/srs/" + code_file_name + " ]; then ./" + code_file_name) + ";";
	in.append("rm prog.out;");
	in.append("fi;");*/
	long double  comp_time;
	string warning = getStdoutFromCommand(build_str, 0, &comp_time);

	//cout << "\n\n\n" << warning;
	l12("2222222222222222222");
	l12(warning);
	if (flags == Flag_JS)
	{
		if (warning.find("project/src/Main") != string::npos)
		{
			//warning.erase(0, warning.find("\n") + 1);
			warning.erase(0, warning.find(".js:") + 4);

			string line = warning;
			line.erase(line.find("\n"), line.size() - 1);
			std::string::size_type sz;
			int error_line = std::stoi( line, &sz );
			error_line -= 12;
			warning.erase(0, warning.find("\n"));
			warning = "error in:" + to_string(error_line) + warning;
		}
	}



	warning_err.append(warning);

	INFO("build time: " + to_string(comp_time) + warning_err);
	cout.flush();
	if(fileExist(prog_name))
	{
		string std_out_string = getStdoutFromCommand(run_str, 0, &comp_time);
		result.append(std_out_string);
		l12("333333333333333333");
		l12(std_out_string);

		INFO("compute time: " + to_string(comp_time));
	}
	else
	{
		ERROR("cLang colpilation: file not exist");
	}
	cout.flush();
	/*
	 * parse error and result if not found err
	 */
	if(flags == Flag_JS)
	{
		if(std::size_t pos = warning_err.find("/var/www/fcgi/src/") != -1)      // position of "live" in str
		{
			warning_err = warning_err.substr (pos + 18); // 18 - Length of @/var/www/fcgi/src/@
			result = " ";
		}
		else
		{
			result = warning_err;
			warning_err = "";
		}

	}
	if(show)
	{
		//res.append(in);
		res.append("<form><textarea style=\"width: 100%; height: 400px;\">");
		if(result.size() <= 1 && warning_err.size() <= 1)
			res.append("=======OK=======");
		else
			res.append(warning_err + result);
		res.append("</textarea></form>");
		return res;
	}
	else
		res.append(warning_err + result);
	cout.flush();
	return res;

	/*cout << "Content-type: text/html\r\n"
						 << "\r\n"
						 << "<html>\n"
						 << "  <head>\n"
						 << "    <title>Result!</title>\n"
						 << "  </head>\n"
						 << "  <body>\n";*/
	//cout << "<form><textarea style=\"width: 100%; height: 400px;\">"  << k<< "</textarea></form>";
	/*cout << "  </body>\n"
						 << "</html>\n";*/
}

bool LangCompiler::generetionSample(string code, compilerFlag flags)
{
	// in the future
	cout.flush();
	ofstream file;
	char str[50];
	switch (flags)
	{
	case Flag_CPP:
		sprintf(str, "src/code%d.cpp\0", thID);
		INFO(str);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;

		break;
	case Flag_Java:
		replaceAll(code,"{{thId}}",to_string(thID));
		sprintf(str, "src/Main%d.java\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_PHP:
		sprintf(str, "src/Main%d.php\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_CS:
		sprintf(str, "src/Main%d.cs\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_JS:
		sprintf(str, "src/Main%d.js\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;

	}
	cout.flush();
	file << code;
	file.close();
	cout.flush();


	return true;
}

char* LangCompiler::getSystemOutput(char* cmd){
	int buff_size = 32;
	char buff[buff_size+1]; memset((char*)&buff, 0, buff_size+1);

	char* ret = NULL;
	string str = "";

	int fd[2];
	int old_fd[3];
	pipe(fd);


	old_fd[0] = !STDIN_FILENO;
	old_fd[1] = !STDOUT_FILENO;
	old_fd[2] = !STDERR_FILENO;

	old_fd[0] = dup(STDIN_FILENO);
	old_fd[1] = dup(STDOUT_FILENO);
	old_fd[2] = dup(STDERR_FILENO);

	int pid = fork();
	switch(pid){
	case 0:
		close(fd[0]);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd[1], STDERR_FILENO);
		system(cmd);
		close (fd[1]);
		exit(1);
		break;
	case -1:
		cerr << "GetSystemOutput/fork() error\n" << endl;
		exit(1);
	default:
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);

		while (read(fd[0], buff, buff_size)){
			str.append(buff);
			memset(buff, 0, buff_size);
		}

		ret = new char (strlen((char*)str.c_str()));

		strcpy(ret, (char*)str.c_str());

		waitpid(pid, NULL, 0);
		close(fd[0]);
	}

	dup2(STDIN_FILENO, old_fd[0]);
	dup2(STDOUT_FILENO, old_fd[1]);
	dup2(STDERR_FILENO, old_fd[2]);

	return ret;
}

string LangCompiler::getStdoutFromCommand(string cmd, int mTimeOut, long double *executionTime)
{
	string data="";
	FILE * stream;
	std::clock_t    start;
	start = std::clock();
	// your test
	//     std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	const int max_buffer = 256;
	char buffer[max_buffer];

	//cmd.append(" 2>&1 ");//>/dev/null
	const long double sysTime = time(0) *1000;
	//printf("%lf", sysTime);
	//  const long double sysTimeMS = sysTime*1000;
	stream = popen(cmd.c_str(), "r");


	if (stream) {
		while (!feof(stream))
		{
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
			if (mTimeOut != 0 && (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) > mTimeOut)
			{
				data = "timeout";
				break;
			}
		}
		if(executionTime != 0)
			executionTime[0] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
		INFO(to_string(time(0)));
		pclose(stream);
	}

	return data;
	/*std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
	    if (!pipe) return "ERROR";
	    char buffer[128];
	    std::string result = "";
	    while (!feof(pipe.get())) {
	        if (fgets(buffer, 128, pipe.get()) != NULL)
	            result += buffer;
	    }
	    return result;*/
}

long double LangCompiler::getTimeOut() const{
	return timeOut*1000;
}

void LangCompiler::setTimeOut(long double timeOut) {
	this->timeOut = timeOut/1000;
}

bool LangCompiler::fileExist( string name )
{
	FILE *file;
	if (file = fopen(name.c_str(), "r"))
	{
		fclose(file);
		return 1;
	}
	return 0;
	/*if( access( name.c_str(), F_OK ) != -1 ) {
	    return 1;
	} else {
		return 0;
	}*/
}

bool LangCompiler::fileRemove ( string name )
{
	remove(name.c_str() );
}

const string& LangCompiler::getResult() const {
	return result;
}

int LangCompiler::getThId() const {
	return thID;
}

const string& LangCompiler::getWarningErr() const {
	return warning_err;
}
LangCompiler::compilerFlag LangCompiler::convertFromName(string lang)
{
	if (lang == "c++" || lang == "C++")
		return LangCompiler::Flag_CPP;
	else if (lang == "Java" || lang == "java")
		return LangCompiler::Flag_Java;
	else if (lang == "JS" || lang == "js")
		return LangCompiler::Flag_JS;
	else if (lang == "PHP" || lang == "php")
		return LangCompiler::Flag_PHP;
	else if (lang == "C#" || lang == "c#" || lang == "CS" || lang == "cs" )
		return LangCompiler::Flag_CS;
	else
		return LangCompiler::Flag_CPP;
}

