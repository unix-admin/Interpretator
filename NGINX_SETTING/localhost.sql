-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 09, 2015 at 09:37 PM
-- Server version: 5.5.43-0ubuntu0.14.04.1
-- PHP Version: 5.5.9-1ubuntu4.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `ITA-codeforce`
--

-- --------------------------------------------------------

--
-- Table structure for table `assignment_cpp`
--

CREATE TABLE IF NOT EXISTS `assignment_cpp` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  `header` text,
  `etalon` text,
  `footer` text,
  `json` text NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=302 ;

--
-- Dumping data for table `assignment_cpp`
--

INSERT INTO `assignment_cpp` (`ID`, `name`, `header`, `etalon`, `footer`, `json`) VALUES
(6, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', ''),
(7, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "twoa"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', ''),
(33, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = compareArrs<float,2>(result,result) && compareArrs<float,2>(result,result_etalon);isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = false && x==x_etalon;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', ''),
(43, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', ''),
(44, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', ''),
(45, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 45,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ ],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = true;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}'),
(46, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 46,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ ],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}"arg_nam'),
(47, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon =  compareArrs<string,2 > ( result, result ) &&  compareArrs<string,2 > ( result, result_etalon );isTrue = false;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 47,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ [ {"first":0,"second":0},{"first":0,"second":1} ]],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}uest is•'),
(48, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon =  compareArrs<string,2 > ( result, result ) && false;isTrue = false;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 48,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ [ {"first":0,"second":0},{"first":0,"second":3} ]],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}'),
(49, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon =  compareArrs<string,2 > ( result, result ) &&  compareArrs<string,2 > ( result, result_etalon );isTrue = false;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 49,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ [ {"first":0,"second":0},{"first":0,"second":1} ]],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}uest is5'),
(50, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon =  compareArrs<string,2 > ( result, result );isTrue = false;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 50,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ [ {"first":0,"second":0},{"first":0,"second":33} ]],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}est is'),
(51, 'test example', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nstring * function_etalon(float  &x,string  &vasya)\n{\nreturn NULL;\n}\nstring * function_main(float  &x,string  &vasya)\n{\n', '', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nstring result_etalon[2];\nstring * result;\nstring * result_for_etalon;\nfloat  x;\nfloat  x_etalon;\nfloat  x_for_etalon;\nstring  vasya;\nstring  vasya_etalon;\nstring  vasya_for_etalon;\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 10.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 10.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon =  compareArrs<string,2 > ( result, result ) && false;isTrue = false;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\nresult_etalon[0] = "adin"\n;\nresult_etalon[1] = "two"\n;\nx_for_etalon = x = 12.0\n;\nvasya_for_etalon = vasya = "safdasdf"\n;\nx_etalon = 12.0\n;\nvasya_etalon = "safdasdf"\n;\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\nstd::cout << " @1@";\nelse\nstd::cout << " @1!@";\n\nreturn 0;\n}', '{\n"operation": "addtask",\n"etalon": "",\n"name": "test example",\n"lang": "c++",\n"task": 51,\n"function": {\n"function_name": "function",\n"type": 3,\n"checkable_args_indexes":[ [ {"first":0,"second":0},{"first":0,"second":7} ]],\n"results": [["adin", "two" ],["adin", "two" ] ],\n"compare_mark": [0, 1],\n"tests_code":[ "isTrue = false;", "isTrue = true;"],\n"args": [\n{\n"type": 1,\n"arg_name": "x",\n"value": [10.0, 12.0],\n"compare_mark": [2, 3],\n"etalon_value": [10.0, 12.0]\n},\n{\n"type": 3,\n"arg_name": "vasya",\n"value": ["safdasdf", "safdasdf"],\n"compare_mark": [4, 0],\n"etalon_value": ["safdasdf","safdasdf"]\n}\n]\n}\n}uest is'),
(301, '', '#include <iostream>\n		#include <cstdlib>\n		#include <algorithm>\n using namespace std;\n		#include <cxxabi.h>\n		#include <cmath>\n		#include <stdio.h>\n		#include <string.h>\n\nfloat * function_etalon(float  *x,string  *vasya)\n{\n return NULL;\n}\nfloat * function_main(float  *x,string  *vasya)\n{\n', ' ', 'return 0;\n}\ntemplate<typename T,int size>\n	bool compareArrs(T arr1[size],T arr2[size])\n		{\n		for (int i=0;i<size;i++)\n		{\n		//if (strcmp(typeid(T).name(), "f") == 0)\n		//{\n			//if (fabs(arr1[i]) - arr2[i] ) > 0.009) \n		//	return false;\n		//}\n 		//else	\n			if (arr1[i] != arr2[i])\n				return false;\n			}\n			return true;\n	}\nint main()\n			{\nfloat result_etalon[2];\nfloat * result;\nfloat * result_for_etalon;\nfloat  x[2];\nfloat  x_etalon[2];\nfloat  x_for_etalon[2];\nstring  vasya[2];\nstring  vasya_etalon[2];\nstring  vasya_for_etalon[2];\nbool isTrue;\nbool variablesCorrectByEtalon,variablesCorrect;\nresult[0] =  (float) 10.0\n;\nresult[1] =  (float) 12.0\n;\nx_for_etalon[0] = x[0] = 10.0\n;\nx_for_etalon[1] = x[1] = 12.0\n;\nvasya_for_etalon[0] = vasya[0] = "20"\n;\nvasya_for_etalon[1] = vasya[1] = "5"\n;\nx_etalon[0] = 10.0\n;\nx_etalon[1] = 12.0\n;\nvasya_etalon[0] = "20"\n;\nvasya_etalon[1] = "5"\n;\nvariablesCorrect = compareArrs<float,2>(x,x_etalon) && compareArrs<string,2>(vasya,vasya_etalon);\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n result = function_main(x,vasya);\nisTrue = true;\nvariablesCorrectByEtalon = true;isTrue = true;\nif (compareArrs<float,2>(result_etalon, result) && variablesCorrect && isTrue)\nstd::cout << " @0@";\nelse\nstd::cout << " @0!@";\n\n}', '');

-- --------------------------------------------------------

--
-- Table structure for table `assignment_java`
--

CREATE TABLE IF NOT EXISTS `assignment_java` (
  `ID` int(11) NOT NULL DEFAULT '0',
  `name` varchar(20) DEFAULT NULL,
  `header` varchar(512) DEFAULT NULL,
  `etalon` varchar(512) DEFAULT NULL,
  `footer` varchar(512) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `assignment_java`
--

INSERT INTO `assignment_java` (`ID`, `name`, `header`, `etalon`, `footer`) VALUES
(0, 'hello wordl', 'class Main#NUM#\r\n{\r\npublic static void main(String args[])\r\n{', 'System.out.println("Hello World!");', '}\r\n}'),
(7, 'javaDefault', 'class Main#NUM# \r\n{ \r\n    public static void main (String[] args)  \r\n   {  ', ' System.out.println ("Hello, world.");', '}}');

-- --------------------------------------------------------

--
-- Table structure for table `assignment_js`
--

CREATE TABLE IF NOT EXISTS `assignment_js` (
  `ID` int(11) NOT NULL DEFAULT '0',
  `name` varchar(20) CHARACTER SET latin1 DEFAULT NULL,
  `header` varchar(512) CHARACTER SET latin1 DEFAULT NULL,
  `etalon` varchar(512) CHARACTER SET latin1 DEFAULT NULL,
  `footer` varchar(512) CHARACTER SET latin1 DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii;

--
-- Dumping data for table `assignment_js`
--

INSERT INTO `assignment_js` (`ID`, `name`, `header`, `etalon`, `footer`) VALUES
(0, 'hello wordl', 'class Main#NUM#\r\n{\r\npublic static void main(String args[])\r\n{', 'System.out.println("Hello World!");', '}\r\n}'),
(7, 'javaDefault', 'class Main#NUM# \r\n{ \r\n    public static void main (String[] args)  \r\n   {  ', ' System.out.println ("Hello, world.");', '}}'),
(2, 'k', NULL, NULL, NULL),
(0, '127.0.0.1', ' console.log("hh");', '2015-7-1 16:16:13', NULL),
(0, '127.0.0.1', ' console.log("hi");', '2015-7-1 17:26:26', NULL),
(0, '127.0.0.1', ' std::cout << "Hello World!" << std::endl;', '2015-7-1 20:22:37', NULL),
(0, '127.0.0.1', ' std::cout << "Hello World!" << std::endl;', '2015-7-1 20:24:54', NULL),
(0, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-7-3 21:23:38', NULL),
(0, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-7-3 21:24:24', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `assignment_php`
--

CREATE TABLE IF NOT EXISTS `assignment_php` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  `header` text,
  `etalon` text,
  `footer` text,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=549 ;

--
-- Dumping data for table `assignment_php`
--

INSERT INTO `assignment_php` (`ID`, `name`, `header`, `etalon`, `footer`) VALUES
(545, '12143', ' ', ' ', ' '),
(546, '127.0.0.1', ' ', '2015-11-13 18:43:0', NULL),
(547, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:4:54', NULL),
(548, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:47:26', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `history`
--

CREATE TABLE IF NOT EXISTS `history` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `ip` varchar(20) DEFAULT NULL,
  `code` varchar(512) DEFAULT NULL,
  `date_time` datetime DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=494 ;

--
-- Dumping data for table `history`
--

INSERT INTO `history` (`ID`, `ip`, `code`, `date_time`) VALUES
(332, '127.0.0.1', ' ', '2015-11-13 18:46:56'),
(333, '127.0.0.1', ' ', '2015-11-13 18:46:57'),
(334, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:47:14'),
(335, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:47:18'),
(336, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:47:20'),
(337, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:53:15'),
(338, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:53:16'),
(339, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:53:19'),
(340, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:53:20'),
(341, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:57:59'),
(342, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:58:04'),
(343, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 18:58:54'),
(344, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:04:20'),
(345, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:05:02'),
(346, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:05:05'),
(347, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:07:23'),
(348, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:07:26'),
(349, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-13 19:07:41'),
(350, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:01:01'),
(351, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:13'),
(352, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:39'),
(353, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:41'),
(354, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:42'),
(355, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:46'),
(356, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:47'),
(357, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:50'),
(358, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-14 11:04:55'),
(359, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:22:17'),
(360, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:22:22'),
(361, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:22:25'),
(362, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:25:34'),
(363, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:25:35'),
(364, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:25:36'),
(365, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:25:36'),
(366, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:25:37'),
(367, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:26:01'),
(368, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:26:04'),
(369, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:33:52'),
(370, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:33:53'),
(371, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:33:54'),
(372, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:34:16'),
(373, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:34:22'),
(374, '127.0.0.1', '<html>\n <head>\n  <title>Ð¢ÐµÑÑ‚Ð¸Ñ€ÑƒÐµÐ¼ PHP</title>\n </head>\n <body>\n <?php echo ''<p>ÐŸÑ€Ð¸Ð²ÐµÑ‚, Ð¼Ð¸Ñ€!</p>''; ?>\n </body>\n</html>', '2015-11-17 18:34:23'),
(375, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:35:53'),
(376, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:35:54'),
(377, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:39:41'),
(378, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:47:24'),
(379, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:47:27'),
(380, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:48:39'),
(381, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:48:40'),
(382, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:54:58'),
(383, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 18:59:45'),
(384, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:00:49'),
(385, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:00:55'),
(386, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:03:39'),
(387, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:03:43'),
(388, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:09:52'),
(389, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:09:55'),
(390, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:09:58'),
(391, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:13:40'),
(392, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:13:42'),
(393, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:13:45'),
(394, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:14:57'),
(395, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:14:57'),
(396, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:17:03'),
(397, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:17:05'),
(398, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:18:59'),
(399, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:30:29'),
(400, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:30:30'),
(401, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:30:39'),
(402, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:33:35'),
(403, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:33:39'),
(404, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:33:40'),
(405, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:42:58'),
(406, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:48:06'),
(407, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:48:07'),
(408, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:48:11'),
(409, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:48:36'),
(410, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:53:24'),
(411, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 19:54:06'),
(412, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:03:40'),
(413, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:03:43'),
(414, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:08:31'),
(415, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:08:34'),
(416, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:19:07'),
(417, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-17 20:20:19'),
(418, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10;', '2015-11-17 21:34:56'),
(419, '127.0.0.1', 'return 10;', '2015-11-18 20:10:32'),
(420, '127.0.0.1', 'return 10;', '2015-11-18 20:10:35'),
(421, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 19:56:57'),
(422, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 19:56:58'),
(423, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 20:00:51'),
(424, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 20:00:52'),
(425, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 20:15:48'),
(426, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10', '2015-11-19 20:17:25'),
(427, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10', '2015-11-19 20:17:30'),
(428, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10;', '2015-11-19 21:16:52'),
(429, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:18:31'),
(430, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:18:37'),
(431, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:18:40'),
(432, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:18:43'),
(433, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:28:11'),
(434, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:32:39'),
(435, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:32:41'),
(436, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:39:01'),
(437, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:39:04'),
(438, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:42:09'),
(439, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-19 21:42:15'),
(440, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10;', '2015-11-19 21:44:49'),
(441, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 0;', '2015-11-19 21:45:07'),
(442, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return "gdfgfdg";', '2015-11-19 21:47:12'),
(443, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return "gdfgfdg";', '2015-11-19 21:47:14'),
(444, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 0;', '2015-11-19 22:01:39'),
(445, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 0;', '2015-11-19 22:01:43'),
(446, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 0;', '2015-11-21 09:03:14'),
(447, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-21 11:00:45'),
(448, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-21 11:00:50'),
(449, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-21 11:24:15'),
(450, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-21 11:24:16'),
(451, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-11-21 11:24:17'),
(452, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 10;', '2015-11-21 11:24:53'),
(453, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 12;', '2015-11-21 11:30:50'),
(454, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return 12;', '2015-11-21 11:30:51'),
(455, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return x;', '2015-11-21 11:58:00'),
(456, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return y;', '2015-11-21 11:58:25'),
(457, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return y;', '2015-11-21 11:58:29'),
(458, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; return vasya;', '2015-11-21 11:59:39'),
(459, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; int k = 5; k /=0; return x;', '2015-11-21 12:01:23'),
(460, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; int k = 5; k /=0; return x;', '2015-11-21 12:01:26'),
(461, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; int k = 5; k /=0; return x;', '2015-11-21 12:05:14'),
(462, '127.0.0.1', 'std::cout << "Hello World!" << std::endl; int k = 5; return x;', '2015-11-21 12:08:52'),
(463, '192.168.144.1', '\n', '2015-11-28 12:51:59'),
(464, '192.168.144.1', '\n', '2015-11-28 12:52:11'),
(465, '192.168.144.1', '\n', '2015-11-28 12:52:14'),
(466, '192.168.144.1', '\n', '2015-11-28 12:52:15'),
(467, '192.168.144.1', ' return a/b;', '2015-11-28 12:59:39'),
(468, '192.168.144.1', ' if(b ==0) return 0; return a/b;', '2015-11-28 13:00:29'),
(469, '192.168.144.1', ' if(b ==0) return 0; return a/b;', '2015-11-28 13:00:32'),
(470, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 19:50:52'),
(471, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 19:52:17'),
(472, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 19:52:21'),
(473, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 21:22:47'),
(474, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 21:22:56'),
(475, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 21:25:18'),
(476, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-03 21:25:22'),
(477, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-07 17:44:35'),
(478, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-07 17:47:34'),
(479, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\n\n', '2015-12-09 14:27:24'),
(480, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\n\n', '2015-12-09 14:27:28'),
(481, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\n\n', '2015-12-09 14:34:47'),
(482, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 14:43:26'),
(483, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 14:43:31'),
(484, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 14:44:23'),
(485, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 15:20:07'),
(486, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 15:20:11'),
(487, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n\n', '2015-12-09 15:20:13'),
(488, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-09 20:20:29'),
(489, '127.0.0.1', 'std::cout << "Hello World!" << std::endl;', '2015-12-09 20:20:30'),
(490, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\n\n', '2015-12-09 20:22:11'),
(491, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\n\n', '2015-12-09 20:22:17'),
(492, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n', '2015-12-09 20:23:37'),
(493, '127.0.0.1', ' \nstring *ss=new string [2];\nss[0] = "adin";\nss[1] = "two";\nreturn ss;\n', '2015-12-09 20:25:02');

-- --------------------------------------------------------

--
-- Table structure for table `results`
--

CREATE TABLE IF NOT EXISTS `results` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `session` varchar(255) CHARACTER SET ascii NOT NULL,
  `jobid` int(11) NOT NULL,
  `status` text NOT NULL,
  `date` date NOT NULL,
  `result` text NOT NULL,
  `warning` text NOT NULL,
  PRIMARY KEY (`id`,`session`(100)),
  UNIQUE KEY `SECONDY` (`session`,`jobid`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `results`
--

INSERT INTO `results` (`id`, `session`, `jobid`, `status`, `date`, `result`, `warning`) VALUES
(1, '127.0.0.1', 0, '2015-12-9 14:23:2', '0000-00-00', '', ''),
(2, '21', 11114, 'done', '2015-12-09', 'Segmentation fault\n', './src/code2.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code2.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code2.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code2.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(3, '210', 11114, 'done', '2015-12-09', 'Segmentation fault\n', './src/code0.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code0.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code0.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code0.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(4, '21g0', 11114, 'done', '2015-12-09', 'Segmentation fault\n', './src/code2.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code2.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code2.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code2.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(5, '21g00', 11114, 'done', '2015-12-09', ' @0@ @1@', './src/code1.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code1.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code1.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code1.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(6, '21qg00', 11114, 'done', '2015-12-09', ' @0@ @1!@', './src/code0.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code0.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code0.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code0.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(7, '21q0g00', 11114, 'failed', '2015-12-09', '', 'Main3.java:1: error: illegal character: 35\n#include <iostream>\n^\nMain3.java:1: error: class, interface, or enum expected\n#include <iostream>\n         ^\nMain3.java:2: error: illegal character: 35\n		#include <cstdlib>\n		^\nMain3.java:3: error: illegal character: 35\n		#include <algorithm>\n		^\nMain3.java:5: error: illegal character: 35\n		#include <cxxabi.h>\n		^\nMain3.java:5: error: class, interface, or enum expected\n		#include <cxxabi.h>\n		         ^\nMain3.java:6: error: illegal character: 35\n		#include <cmath>\n		^\nMain3.java:7: error: illegal character: 35\n		#include <stdio.h>\n		^\nMain3.java:8: error: illegal character: 35\n		#include <string.h>\n		^\nMain3.java:13: error: class, interface, or enum expected\n}\n^\nMain3.java:19: error: class, interface, or enum expected\nss[0] = "adin";\n^\nMain3.java:20: error: class, interface, or enum expected\nss[1] = "two";\n^\nMain3.java:21: error: class, interface, or enum expected\nreturn ss;\n^\nMain3.java:24: error: class, interface, or enum expected\nreturn 0;\n^\nMain3.java:25: error: class, interface, or enum expected\n}\n^\nMain3.java:29: error: class, interface, or enum expected\n		for (int i=0;i<size;i++)\n		             ^\nMain3.java:29: error: class, interface, or enum expected\n		for (int i=0;i<size;i++)\n		                    ^\nMain3.java:39: error: class, interface, or enum expected\n			}\n			^\nMain3.java:41: error: class, interface, or enum expected\n	}\n	^\nMain3.java:45: error: class, interface, or enum expected\nstring * result;\n^\nMain3.java:46: error: class, interface, or enum expected\nstring * result_for_etalon;\n^\nMain3.java:47: error: class, interface, or enum expected\nfloat  x;\n^\nMain3.java:48: error: class, interface, or enum expected\nfloat  x_etalon;\n^\nMain3.java:49: error: class, interface, or enum expected\nfloat  x_for_etalon;\n^\nMain3.java:50: error: class, interface, or enum expected\nstring  vasya;\n^\nMain3.java:51: error: class, interface, or enum expected\nstring  vasya_etalon;\n^\nMain3.java:52: error: class, interface, or enum expected\nstring  vasya_for_etalon;\n^\nMain3.java:53: error: class, interface, or enum expected\nbool isTrue;\n^\nMain3.java:54: error: class, interface, or enum expected\nbool variablesCorrectByEtalon,variablesCorrect;\n^\nMain3.java:55: error: class, interface, or enum expected\nresult_etalon[0] = "adin"\n^\nMain3.java:57: error: class, interface, or enum expected\nresult_etalon[1] = "two"\n^\nMain3.java:59: error: class, interface, or enum expected\nx_for_etalon = x = 10.0\n^\nMain3.java:61: error: class, interface, or enum expected\nvasya_for_etalon = vasya = "safdasdf"\n^\nMain3.java:63: error: class, interface, or enum expected\nx_etalon = 10.0\n^\nMain3.java:65: error: class, interface, or enum expected\nvasya_etalon = "safdasdf"\n^\nMain3.java:67: error: class, interface, or enum expected\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n^\nMain3.java:68: error: class, interface, or enum expected\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n ^\nMain3.java:69: error: class, interface, or enum expected\n result = function_main(x,vasya);\n ^\nMain3.java:70: error: class, interface, or enum expected\nisTrue = true;\n^\nMain3.java:71: error: class, interface, or enum expected\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\n^\nMain3.java:71: error: class, interface, or enum expected\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\n                                                                                                                        ^\nMain3.java:72: error: class, interface, or enum expected\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\n^\nMain3.java:74: error: class, interface, or enum expected\nelse\n^\nMain3.java:76: error: class, interface, or enum expected\nresult_etalon[0] = "adin"\n^\nMain3.java:78: error: class, interface, or enum expected\nresult_etalon[1] = "twoa"\n^\nMain3.java:80: error: class, interface, or enum expected\nx_for_etalon = x = 12.0\n^\nMain3.java:82: error: class, interface, or enum expected\nvasya_for_etalon = vasya = "safdasdf"\n^\nMain3.java:84: error: class, interface, or enum expected\nx_etalon = 12.0\n^\nMain3.java:86: error: class, interface, or enum expected\nvasya_etalon = "safdasdf"\n^\nMain3.java:88: error: class, interface, or enum expected\nvariablesCorrect = (  ( floor(x * 100 ) - floor(x_etalon * 100 ) )  == 0 ) && ( vasya == vasya_etalon );\n^\nMain3.java:89: error: class, interface, or enum expected\n result_for_etalon = function_etalon(x_for_etalon,vasya_for_etalon);\n ^\nMain3.java:90: error: class, interface, or enum expected\n result = function_main(x,vasya);\n ^\nMain3.java:91: error: class, interface, or enum expected\nisTrue = true;\n^\nMain3.java:92: error: class, interface, or enum expected\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\n^\nMain3.java:92: error: class, interface, or enum expected\nvariablesCorrectByEtalon = (  ( floor(x * 100 ) - floor(x_for_etalon * 100 ) )  == 0 ) && ( vasya == vasya_for_etalon );isTrue = true;\n                                                                                                                        ^\nMain3.java:93: error: class, interface, or enum expected\nif ( compareArrs<string,2 > ( result_etalon, result ) && variablesCorrect && isTrue)\n^\nMain3.java:95: error: class, interface, or enum expected\nelse\n^\nMain3.java:98: error: class, interface, or enum expected\nreturn 0;\n^\nMain3.java:99: error: class, interface, or enum expected\n}\n^\n59 errors\n'),
(8, '1241q223f4f2341', 11212, 'done', '2015-12-09', 'Hello World!\nSegmentation fault\n', './src/code3.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code3.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code3.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code3.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(9, '221', 11114, 'done', '2015-12-09', 'Segmentation fault\n', './src/code2.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code2.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code2.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code2.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(10, '2211', 11114, 'done', '2015-12-09', ' @0!@ @1@', './src/code1.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code1.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code1.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code1.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n'),
(11, '22111', 11114, 'done', '2015-12-09', ' @0@ @1@', './src/code0.cpp:37:34: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                 ^\n./src/code0.cpp:37:45: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_etalon(float  &x,string  &vasya)\n                                            ^\n./src/code0.cpp:41:32: warning: unused parameter ''x'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                               ^\n./src/code0.cpp:41:43: warning: unused parameter ''vasya'' [-Wunused-parameter]\nstring * function_main(float  &x,string  &vasya)\n                                          ^\n4 warnings generated.\n');
--
-- Database: `codeForce`
--

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
