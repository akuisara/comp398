HW04
====
This program is a Markdown-to-HTML converter written in C++. Following files are contained in this folder:

- README.md - this file
- markdown_to_html.cpp - driver program including the source code
- sample.md - sample Markdown input file
- sample.html - sample HTML output file
- output.html - HTML output file of this README

####This program has the following features:
1. setext-style headers: title underlining with an equal sign : `<h1>` 
2. setext-style headers: title underlining with a hyphen : `<h2>`
3. atx-style head: title start with 1~6 asterisks : h1 ~ h6 headers
4. sentence starts with angle bracket : `<blockquote>`
5. paragraphs : `<p>`
6. emphasis: phrases within a pair of asterisk : `<em>`
7. strong emphasis: phrases within a pair of two asterisks : `<strong>`
8. unordered list: sentence starts with an asterisk, a plus sign, or a hyphen : `<li>`
9. inline links with or without title: [example link](http://example.com/)
10. code within back-ticks and angle brackets

####Limitations:
- This program cannot handle paragraphs within list tags
- Cannot recognize reference-style links or images
- Hard to recognize overlapping features within a line