HW04
====
This program is a Markdown-to-HTML converter written in C++. Following files are contained in this folder:

- README.md - this file
- main.cpp - driver program
- sample.md - sample Markdown input file
- output.html - sample HTML output file

****These program has the following features:
- setext-style headers:
1. title underlining with "=" -> <h1>
2. title underlining with "-" -> <h2>
- atx-style head: title start with 1~6 "*" -> <h1> ~ <h2>
- sentence starts with ">" -> <blockquote>
- paragraphs -> <p>
- emphasis: phrases within "*" -> <em>
- strong emphasis: phrases within "**" -> <strong>
- list: sentence starts with "*", "+", or "-" -> <ul><li>

****Limitations:
- This program cannot handle paragraphs within list tags