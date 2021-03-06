#include "inc/cLang.h"

#include <stdio.h>

LangCompiler::LangCompiler(int ID){
	thID = ID;
	timeOut = 120;
}

LangCompiler::~LangCompiler(){

}

//compilerFlag

bool LangCompiler::beautyErrorOutputCpp(string &warning,compilerFlag flags, int student__teacher_programer )
{
	string output = "";
	int div_by_zero = warning.find(": warning: division by zero");

	string excep = warning;
	if (div_by_zero > -1)
	{
		excep.erase(0,div_by_zero - 10);
		excep.erase(  excep.find("[-Wdiv") , excep.size() - 1);

		string line = excep;

		int line_begin = line.find("p:");

		int line_int;
		if (line_begin > -1)
		{
			line_begin += 2;

			line.erase(0,  line_begin );

			int line_end = line.find(":");
			line.erase(  line_end ,line.size() - 1);

			excep.erase(0, excep.find("warning:") + 8 );

			sscanf(line.c_str(),"%d", &line_int);
			if (student__teacher_programer == 1)
				line_int -= 34;
			else
				if (student__teacher_programer == 0)
					line_int -= 29;

			line = to_string(line_int);

			excep = "warning in line " + line + ": " + excep + "\n";
		}
		else
			excep = "";
	}
	else
		excep = "";

	int error_begin = warning.find("error: ");
	while  (error_begin != -1)
	{
		warning.erase(0, error_begin - 11);

		string war_temp = warning;
		string num_s = war_temp;
		//cout << "\n\n\n\n" << num_s;
		int num_s_begin = num_s.find("p:") + 2;
		int num_s_end;// = num_s.find(": er");

		num_s.erase(0, num_s_begin);
		//cout << "\n\n\n\n" << num_s;

		num_s_end = num_s.find(":");
		/*if (num_s[0] <'0' || num_s[0] > '9')
					{
						num_s_begin = num_s.find(".p:") + 2;
						num_s.erase(0, num_s_begin);

						num_s_end = num_s.find(":");

						cout << "\n\n\n\n" << num_s;
					}*/
		num_s.erase(num_s_end, num_s.size() - 1 );
		//cout << "\n\n\n\n" << num_s;

		std::string::size_type sz;
		int error_line = std::stoi( num_s, &sz );

		if (student__teacher_programer == 0)
			error_line -= 29;
		else
			if (student__teacher_programer == 1)
				error_line -= 34;

		war_temp.erase(0, war_temp.find("error: ") + 7);
		warning = war_temp;




		int first_n = war_temp.find("\n");
		int second_n =  war_temp.find("\n",first_n + 1);
		int third_n =  war_temp.find("\n",second_n +1 );
		int forth_n =  war_temp.find("\n",third_n + 1);
		int fifth_n =  war_temp.find("\n",forth_n + 1);

		war_temp.erase(first_n, war_temp.size() - 1);
		string temp_error = "error in line " + to_string(error_line) + ": " +  war_temp ;//+ "\n";
		output += temp_error + "\n";
		warning.erase(0, third_n)	 ;

		error_begin = warning.find("error: ");
	}
	warning = excep;
	warning += output;
	return true;
}

bool LangCompiler::beautyErrorOutputCs(string &warning,compilerFlag flags, int student__teacher_programer )
{
	string output = "";

	string last = warning;
	int border = last.find("Compilation ");
	last.erase(0, border);
	warning.erase(border, warning.size() - 1);

	if (last.find("succ") != string::npos )
		warning = "";
	else
	{

		while  (warning.find(" error ") != string::npos)
		{
			string war_temp = warning;
			string num_s = war_temp;
			int num_s_begin = num_s.find(".cs(") + 4;
			int num_s_end = num_s.find(": er");
			war_temp.erase(0, war_temp.find(" error ") + 7);

			num_s.erase(0, num_s_begin);
			num_s.erase(num_s_end - num_s_begin -1, num_s.size() - 1 );

			int num_line;
			int num_char;
			sscanf(num_s.c_str(),"%d,%d", &num_line, &num_char);
			if (student__teacher_programer == 0)
				num_line -= 11; //it have 8 lines behind student code
			else
				if (student__teacher_programer == 1)
					num_line -= 16;

			num_s = std::to_string(num_line) + ":" + to_string(num_char);
			/*if (num_s[0] <'0' || num_s[0] > '9')
								{
									num_s_begin = num_s.find(".cpp:") + 5;
									num_s_end = num_s.find(": er");
									num_s.erase(0, num_s_begin);
								}*/
			warning = war_temp;

			string error_cod = war_temp;
			error_cod.erase(error_cod.find(":"),error_cod.size() - 1);

			int first_n = war_temp.find("\n");
			/*int second_n =  war_temp.find("\n",first_n + 1);
								int third_n =  war_temp.find("\n",second_n +1 );
								int forth_n =  war_temp.find("\n",third_n + 1);
								int fifth_n =  war_temp.find("\n",forth_n + 1);*/

			war_temp.erase(first_n , war_temp.size() - 1);
			war_temp.erase(0, war_temp.find(":") + 2);
			string temp_error = "error in " + num_s + " (" + error_cod + "): " +  war_temp ;//+ "\n";
			output += temp_error + "\n";
			warning.erase(0, first_n)	 ;
		}
		warning = output;// + last;
	}
	return true;
}

bool LangCompiler::beautyErrorOutputPhp(string &warning,compilerFlag flags, int student__teacher_programer )
{
	string error_s = "on line ";
	int lines_begind = 6;

	if (warning.find("Failed loading /usr/lib/php5/20100525/xcache.so") != string::npos)
	{
		warning.erase(0, warning.find("directory\n") + 11);
	}

	if  (warning.find(error_s) != string::npos)
	{
		string war_temp = warning;

		string num_s = war_temp;

		war_temp.erase(war_temp.find(" in /"), war_temp.size() - 1);
		/*if (war_temp.find(error_s) != string::npos)
							{
								war_temp.erase(0, war_temp.find(error_s) + error_s.size());
							}*/


		int num_s_begin = num_s.find("on line ") + error_s.size();

		num_s.erase(0, num_s_begin);

		int num_line;
		sscanf(num_s.c_str(),"%d\n", &num_line);
		if (student__teacher_programer == 0)
			num_line -= lines_begind;
		else
			if (student__teacher_programer == 1)
				num_line -= 11;
		num_s = to_string(num_line);


		//war_temp.erase(war_temp.find(" in "),war_temp.size() - 1);

		warning = war_temp + " in line " + num_s +  "\n";
	}
	else
	{
		return false;
	}
	return true;
}

bool LangCompiler::beautyErrorOutputJs(string &warning,compilerFlag flags, int student__teacher_programer )
{
	if (warning.find("project/temp/Main") != string::npos)
	{
		warning.erase(0, warning.find(".js:") + 4);



		string line = warning;
		line.erase(line.find("\n"), line.size() - 1);
		std::string::size_type sz;
		int error_line = std::stoi( line, &sz );
		if (student__teacher_programer == 0)
			error_line -= 5;
		else
			if (student__teacher_programer == 1)
				error_line -= 10;

		warning.erase(0, warning.find("\n"));

		int begin = warning.find("at function");
		int end = warning.size() - 1;
		if (begin == -1)
		{
			begin = warning.find("at Object");
		}

		if (begin > -1)
			warning.erase(begin, end);
		warning = "error in:" + to_string(error_line) + warning;
	}
	return true;
}

bool LangCompiler::beautyErrorOutputJava(string &warning,compilerFlag flags, int student__teacher_programer )
{
	string output = "";
	while  (warning.find("error: ") != string::npos)
	{
		string war_temp = warning;
		string num_s = war_temp;
		int num_s_begin = num_s.find(".java:") + 6;
		int num_s_end = num_s.find(": er");
		war_temp.erase(0, war_temp.find("error: ") + 7);
		num_s.erase(0, num_s_begin);

		warning = war_temp;

		num_s.erase(num_s_end - num_s_begin, num_s.size() - 1 );

		int num_line;
		sscanf(num_s.c_str(),"%d\n", &num_line);
		if (student__teacher_programer == 0)
			num_line -= 14;//12
		else
			if (student__teacher_programer == 1)
				num_line -= 15;
		num_s = to_string(num_line);

		int first_n = war_temp.find("\n");
		int second_n =  war_temp.find("\n",first_n + 1);
		int third_n =  war_temp.find("\n",second_n +1 );
		int forth_n =  war_temp.find("\n",third_n + 1);
		int fifth_n =  war_temp.find("\n",forth_n + 1);

		int next_er = war_temp.find("^\n  symbol:");
		if (next_er == -1)
			next_er = war_temp.find("symbol:");
		if (next_er == -1)
			next_er = war_temp.find("\n     ^\nMain");
		if (next_er == -1)
			next_er = second_n;


		war_temp.erase(next_er, war_temp.size() - 1);
		string temp_error = "error in line " + num_s + ": " +  war_temp ;//+ "\n";
		output += temp_error + "\n";
		warning.erase(0, next_er)	 ;
	}
	warning = output;
	return true;
}

bool LangCompiler::beautyErrorOutput(string &warning,compilerFlag flags, int student__teacher_programer )
{
	//return true;
	if (flags == Flag_JS)
		return beautyErrorOutputJs(warning,flags, student__teacher_programer );
	else
		if (flags == Flag_CPP)
			return beautyErrorOutputCpp(warning,flags, student__teacher_programer );
		else
			if (flags == Flag_CS)
				return beautyErrorOutputCs(warning,flags, student__teacher_programer );
			else
				if (flags == Flag_PHP)
					return beautyErrorOutputPhp(warning,flags, student__teacher_programer );
				else
					if (flags == Flag_Java)
						return beautyErrorOutputJava(warning,flags, student__teacher_programer );
					else
						return false;
	return true;
}

string LangCompiler::compile(string code, bool show, compilerFlag flags, int student__teacher_programer)
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
	//l12("11111111111111111111111");
	//l12(code);
	cout.flush();
	cout.flush();
	string code_file_name;

	string build_str ;
	string prog_name;
	string run_str ;
	switch(flags){
	case Flag_CPP:  //  &> results.txt
		code_file_name = "prog" + to_string(thID) + ".out";
		//build_str = "cd src; clang++ -Wall -stdlib=libc++ code" + to_string(thID) + ".cpp -o ../prog" + to_string(thID) + ".out";
		build_str = "g++ -std=c++0x  -Wno-deprecated -W ./temp/code" + to_string(thID) + ".cpp -o prog" + to_string(thID) + //
				".out 2>&1 |  tee -a cout.txt;";// rm ./src/code" + to_string(thID) + ".cpp";// shashka.txt -i";  // 2>&1 | tee -a cout.txt
		//".out 2>&1	";
		run_str = " ./prog" + to_string(thID) + ".out  2>&1 |  tee -a cout.txt;  rm prog" + to_string(thID) + ".out";
		prog_name = code_file_name;
		break;

		/*case Flag_CPP:  //  &> results.txt
		code_file_name = "prog" + to_string(thID) + ".out";
		//build_str = "cd src; clang++ -Wall -stdlib=libc++ code" + to_string(thID) + ".cpp -o ../prog" + to_string(thID) + ".out";
		build_str = "g++ -Wno-deprecated -W ./src/code" + to_string(thID) + ".cpp -o prog" + to_string(thID) +
				".out 2>&1 | tee -a cout.txt;rm ./src/code" + to_string(thID) + ".cpp";  // 2>&1 | tee -a cout.txt
		//".out 2>&1	";
		run_str = " ./prog" + to_string(thID) + ".out 2>&1 | tee -a cout.txt;  rm prog" + to_string(thID) + ".out";
		prog_name = code_file_name;
		break;*/
	case Flag_Java:
		code_file_name = "Main" + to_string(thID) + ".class";
		build_str = "cd temp; javac Main" + to_string(thID) + ".java -d ../ 2>&1 |  tee -a cout.txt";
		run_str = "java Main" + to_string(thID) + " 2>&1 |  tee -a cout.txt ; rm Main" + to_string(thID)+".class";
		prog_name = "Main"+to_string(thID)+".class";
		break;
	case Flag_JS:
		code_file_name = "Main" + to_string(thID) + ".js";
		build_str = "cd temp; nodejs Main" + to_string(thID) + ".js ../ 2>&1 |  tee -a cout.txt";
		run_str = " node Main" + to_string(thID) + " 2>&1 |  tee -a cout.txt ;  rm Main" + to_string(thID)+".js";
		prog_name = "Main"+to_string(thID)+".js";
		break;
	case Flag_PHP:
		code_file_name = "./temp/Main" + to_string(thID) + ".php";
		build_str = "";
		run_str ="php ./temp/Main"
				+ to_string(thID) + ".php 2>&1 |  tee -a cout.txt ; ";// rm  /src/Main" + to_string(thID) + ".php; ";
		prog_name = code_file_name;
		break;
	case Flag_CS:
		code_file_name = "./temp/Main" + to_string(thID) + ".exe";
		build_str = "dmcs ./temp/Main" + to_string(thID) + ".cs 2>&1 |  tee -a cout.txt";
		run_str = " mono ./temp/Main" + to_string(thID) + ".exe 2>&1 |  tee -a cout.txt " + "; rm ./temp/Main" + to_string(thID) + ".exe";
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

	cout << "\n\nerror:\n" << warning;
	//l12("2222222222222222222");
	//l12(warning);
	//compilerFlag
	if (flags != compilerFlag::Flag_PHP)
		beautyErrorOutput(warning, flags , student__teacher_programer);

	warning_err.append(warning);



	INFO("build time: " + to_string(comp_time) + warning_err);
	cout.flush();
	if (warning.size())
	{
		switch(flags)
		{
		case Flag_CPP:
			run_str = "rm prog" + to_string(thID) + ".out";
			getStdoutFromCommand(run_str, 0, &comp_time);
			break;
		}
	}



	if(fileExist(prog_name))
	{
		string std_out_string = getStdoutFromCommand(run_str, -1, &comp_time);

		cout << "\\n\n\n\n\n" << std_out_string;

		if (flags == compilerFlag::Flag_PHP)
		{
			if (beautyErrorOutput(std_out_string, flags, student__teacher_programer ))
			{
				warning_err.append(std_out_string);
				ERROR("cLang colpilation: php return error");
			}
			else
			{
				result.append(std_out_string);
				INFO("compute time: " + to_string(comp_time));
			}
		}
		if (flags == compilerFlag::Flag_Java)
		{
			int exp_begin = std_out_string.find("*** ");
			if (exp_begin == -1)
				result.append(std_out_string);
			else
			{
				exp_begin += 4;
				std_out_string.erase(0, exp_begin);

				std_out_string.erase(std_out_string.find("***"), std_out_string.size() - 1);
				warning_err.append("exeption " + std_out_string);
			}

		}
		else
		{
			result.append(std_out_string);
			INFO("compute time: " + to_string(comp_time));
		}
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
		if(std::size_t pos = warning_err.find("error in:") != -1)      // position of "live" in str
		{
			//	warning_err = warning_err.substr (pos + 18); // 18 - Length of @/var/www/fcgi/src/@
			result = "";
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
	std::ofstream cout("cout.txt", std::ios::out);
	// in the future
	cout.flush();
	ofstream file;
	char str[50];
	switch (flags)
	{
	case Flag_CPP:
		sprintf(str, "temp/code%d.cpp\0", thID);
		INFO(str);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;

		break;
	case Flag_Java:
		replaceAll(code,"{{thId}}",to_string(thID));
		sprintf(str, "temp/Main%d.java\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_PHP:
		sprintf(str, "temp/Main%d.php\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_CS:
		sprintf(str, "temp/Main%d.cs\0", thID);
		file.open(str, fstream::out);
		if(!file.is_open())
			return false;
		break;
	case Flag_JS:
		sprintf(str, "temp/Main%d.js\0", thID);
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

#define READ   0
#define WRITE  1
FILE * popen2(string command, string type, int & pid)
{
    pid_t child_pid;
    int fd[2];
    pipe(fd);

    if((child_pid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    /* child process */
    if (child_pid == 0)
    {
        if (type == "r")
        {
            close(fd[READ]);    //Close the READ end of the pipe since the child's fd is write-only
            dup2(fd[WRITE], 1); //Redirect stdout to pipe
        }
        else
        {
            close(fd[WRITE]);    //Close the WRITE end of the pipe since the child's fd is read-only
            dup2(fd[READ], 0);   //Redirect stdin to pipe
        }

        setpgid(child_pid, child_pid); //Needed so negative PIDs can kill children of /bin/sh
        execl("/bin/sh", "/bin/sh", "-c", command.c_str(), NULL);
        exit(0);
    }
    else
    {
        if (type == "r")
        {
            close(fd[WRITE]); //Close the WRITE end of the pipe since parent's fd is read-only
        }
        else
        {
            close(fd[READ]); //Close the READ end of the pipe since parent's fd is write-only
        }
    }

    pid = child_pid;

    if (type == "r")
    {
        return fdopen(fd[READ], "r");
    }

    return fdopen(fd[WRITE], "w");
}

int pclose2(FILE * fp, pid_t pid)
{
    int stat;

    fclose(fp);
	/*std::clock_t    start;
	start = std::clock();

    while (waitpid(pid, &stat, 0) == -1)
    {

        if (errno != EINTR)
        {
            stat = -1;
            break;
        }
    }

    return stat;*/

    	cout << "pid:" << pid << " resPID:" << kill (pid + 1, SIGKILL);

    return 0;
}

string LangCompiler::getStdoutFromCommand(string cmd, int mTimeOut, long double *executionTime)
{
	if(mTimeOut == -1)
		mTimeOut = timeOut;

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
	//stream =
	int pId = 0;
	stream = popen2(cmd.c_str(), "r", pId);

	if (stream) {
		while (!feof(stream))
		{/*
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
			double j = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
			INFO(std::to_string(j));
			if (mTimeOut != 0 && (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) > mTimeOut)
			{
				INFO("TIMEOUT");
				data = "timeout";
				break;
			}
		 */
			fd_set read_fds, write_fds, except_fds;
			FD_ZERO(&read_fds);
			FD_ZERO(&write_fds);
			FD_ZERO(&except_fds);
			FD_SET(fileno(stream), &read_fds);

			// Set timeout to 1.0 seconds
			struct timeval timeoutObj;
			timeoutObj.tv_sec = timeOut;
			timeoutObj.tv_usec = 0;

			// Wait for input to become ready or until the time out; the first parameter is
			// 1 more than the largest file descriptor in any of the sets
			if (select(fileno(stream) + 1, &read_fds, &write_fds, &except_fds, &timeoutObj) == 1)
			{
				if (fgets(buffer, max_buffer, stream) != NULL)
					data.append(buffer);
			}
			else
			{
				INFO("TIMEOUT");
				data = "timeout";
				break;
			}
		}
		if(executionTime != 0)
			executionTime[0] = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
		int k = pclose2(stream, pId);
	}

	if (data == "")
	{
		//popen(cmd.c_str(), "r");
		std::ifstream in;
		in.open("cout.txt", std::ifstream::in);
		if (in.good())
		{
			std::string contents((std::istreambuf_iterator<char>(in)),
					std::istreambuf_iterator<char>());
			data = contents;
		}
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

