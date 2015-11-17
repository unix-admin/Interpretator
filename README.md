# Interpretator
Just interpret it

# MANUAL :)
1.	запускаєм термінал
2.	наступною командою ставимо необхідні для роботи сервера бібліотеки
3.	sudo apt-get fcgi pthread jsoncpp lmysqlcppconn lmysql-server clang openjdk-7-jdk libmysql++-dev node.js 
4.	заходимо в директорію з ісходніками і мейкфайлом:  cd /dir..
5.	запускаєм компіляцію:	 make -f Makefile
6.	як зібралося, має з*явитися файл test.fcgi
7.	відкрити папку /etc/init.d/ 
8.	скопіювати любий із скритів, задавши ім*я interpreter
9.	скопіювати весь код з Interpretator/init.d/interpreter.sh в скопійований скріпт.
10.	в стрічці  DAEMON_DIR= вказати директорію, де буде знаходитись виконуваний файл сервака і його  файлики
11.	скопіювати файл Interpretator/NGINX_SETTING/default.txt в  /etc/nginx/sites-available/  (замінити)
12.	створити папку, де буде лежати сервер, туди закинути скомпільований test.fcgi
13.	файл  test.fcgi зробити виконуваним
14.	імпортуйте базу  Interpretator/NGINX_SETTING/ITA-codeforce.sql
15.	sudo service interpreter start
16.	відкрийте /server_location/settings.conf   вкажіть юзера, пароль, ім*я бази і т.п, збережіть.
17.	sudo service interpreter restart
18.	всьо, має робити.

JSON sample:
{
"operation": "result",
"session" : "1241q223f4f2341",
"jobid" : 11212,
"code" : "std::cout << \"Hello World!\" << std::endl;",
"task": 1,
"lang": "c++"
}

{
"operation": "getFromToken",
"token": "-8668338574358268261",
"session" : "1054003",
"jobid" : 54554,
"code" : "<html>
 <head>
  <title>Тестируем PHP</title>
 </head>
 <body>
 <?php echo '<p>Привет, мир!</p>'; ?>
 </body>
</html>",
"etalon" : " j",
"header" : " j",
"footer" : " j",
"name" : "12143",
"task": 545,
"lang": "php"
}

{
"operation": "addtask",
  "etalon": "hff",
  "name": "test example",
  "lang": "c++",
  "task": 209,
  "function": {
    "function_name": "function",
    "args": 	[
	{
      "is_array": false,
      "size": 1,
      "type": 1,
      "arg_name": "x",
      "value": "2"
    	},
	{
      "is_array": false,
      "size": 1,
      "type": 3,
      "arg_name": "vasya",
      "value": true
    	}
		]
  }
}
