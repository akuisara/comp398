This file contains the evaluations of [omigayy's HW02 assignment](https://github.com/omigayy/comp398/tree/master/hw02)

1. Style Guide Evaluation:
---
omigayy follows the [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml) in this assignment.
- Header files: These are good since they have the #define Guard, and orders of the included libraries and files are correct. 
- Scoping: Scopes are good.
- Classes: Class follows the declaration requirement, which means private part is followed by public part
- Naming: All the names are good in general, but sometimes one variable has two names.
- Comments: Spellings and grammars are good. Each file has summary at the beginning. However, class does not have a descriptive summary; functions lack of descriptions of definitions and operations. 
- Format: Formats of all the files are clear and readable.


2. Code Evaluation:
---
398hw01.cpp: 
- This driver program file is very clear and easy to follow the steps
- This file does not have this line: "using namespace std;", but the following code still uses "cout"
- linklist's identifier is ambiguous, since it has two names "a" and "test_ctor"

linklist.h: This file is well written.

linklist.cpp: 
- One variable's identifier is ambiguous, since it has two names "in_file" and "inFile"
- omigayy says that the code of PopulateList() is not working, after I have tried to cout certain elements stored in a node and pointed by a pointer inside the while loop, I find that there may be something wrong with .csv formatting and the methods while collecting data from database, since two data could be separated by not only comma but also new lines, which makes data uneasy to be read and then stored in nodes.

node.h: 
- This file contains "typedef" without a name
- Comment of node is a bit off, and names as well as numbers of the variable are not consistent as the input file

readme.me: It would be better to use capital letters like this: README.md

Plaintext: Cannot generate plaintext file

