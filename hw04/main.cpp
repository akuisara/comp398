//
//  main.cpp
//  C++
//
//  Created by Qi Zhang on 9/7/14.
//  Copyright (c) 2014 QZ. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[])
{
    ifstream my_file("sample.md");  // opens the input file
    
    if (!my_file.is_open())
    {  //exit if cannot open the file
        cout<<"ERROR";
        exit(-1);
    }
    
    ofstream output_html;           // opens the output file
    output_html.open("output.html");
    
    if (!output_html.is_open())
    {  //exit if cannot open the file
        cout<<"ERROR";
        exit(-1);
    }
    string output_string;
    
    string my_line, last_line;  // a string contains a line
    bool blockquote = false;
    
    bool last_tag_list = false, last_tag_first_list = false;
    while(!my_file.eof()) {
        
        getline (my_file, my_line, '\n');  // takes out a line
        
        string temp = "";  // a string stores the line
        string added_tag;
        
        short i = 0;
        
        if (last_tag_list && my_line[i]!='*' && my_line[i]!='-'&&my_line[i] !='+') {
            output_string += "</ul>\n\n";
            last_tag_list = false;
            last_tag_first_list = false;
        }
        
        if (last_line[i] == '>' && my_line[i] != '>') {
            output_string += "</blockquote>\n\n";
            blockquote = false;
        }
        
        if (my_line[i] == '>' ) {
            if (blockquote == false) {
                output_string += "<blockquote>";
                blockquote = true;
            } else {
                for (int j=i; j<my_line.length(); j++) {
                    if (my_line[j] != ' ' && my_line[j] != '>'){
                        i = j;
                        break;
                    }
                }
            }
             added_tag = "blockquote";
        }
        
        
        if(my_line[i] == '=') {
            output_string += "<h1>" + last_line + "</h1>\n\n";
            added_tag = "header";
        }
        else if (my_line[i] == '-') {
            if (my_line[i+1] == '-') {
                output_string += "<h2>" + last_line + "</h2>\n\n";
                added_tag = "header";
            } else {
                string temp_line = "";
                for (short j=i+1; j < my_line.length(); j++)
                    temp_line += my_line[j];
                if ((!last_tag_list) && (!last_tag_first_list)) {
                    output_string += "<ul>";
                }
                output_string += "<li>" + temp_line + "</li>\n\n";
                added_tag = "list";
                if (!last_tag_list) {
                    last_tag_first_list = true;
                }
                last_tag_list = true;
            }
        }
        else if (my_line[i] == '#') {
            short header_num;
            if (my_line[i+1] == '#') {
                if (my_line[i+2] == '#') {
                    if (my_line[i+3] == '#') {
                        if (my_line[i+4] == '#') {
                            if (my_line[i+5] == '#')
                                header_num = 6;
                            else
                                header_num = 5;
                        } else
                            header_num = 4;
                    } else
                        header_num = 3;
                } else {
                    header_num = 2;}
            } else
                header_num = 1;
            
            string temp_line = "";
            for (short j=(i+header_num); j < my_line.length(); j++) {
                temp_line += my_line[j];
            }
            string header_num_string;          // string which will contain the result
            ostringstream convert;   // stream used for the conversion
            convert << header_num;
            header_num_string = convert.str();
            output_string += "<h" + header_num_string + ">" + temp_line + "</h" + header_num_string + ">\n\n";
            added_tag = "header";
        }
        
        string emphasis_line, emphasis_phrase;
        for(int i = 0; i < my_line.length(); i++)
        {   // within the length of this line, reads the segment
            temp += my_line[i];
            
            if (my_line[i] == '+') {
                string temp_line;
                for (short j=i+1; j < my_line.length(); j++)
                    temp_line += my_line[j];
                if ((!last_tag_list) && (!last_tag_first_list)) {
                    output_string += "<ul>";
                }
                output_string += "<li>" + temp_line + "</li>\n\n";
                added_tag = "list";
                if (!last_tag_list) {
                    last_tag_first_list = true;
                }
                last_tag_list = true;
                break;
            } else if (my_line[i] == '*') {
                if (my_line[i+1] == '*') {
                    string temp_line;
                    for (int x=0; x<i; x++) {
                        emphasis_line += my_line[x];
                    }
                    bool inside_emphasis_tags = false;
                    for (int j=i+2; j<my_line.length(); j++) {
                        if (my_line[j] == '*' && !inside_emphasis_tags) {
                            emphasis_line += "<strong>" + temp_line + "</strong>";
                            added_tag = "style";
                            inside_emphasis_tags = true;
                            break;
                        } else {
                            temp_line += my_line[j];
                        }
                        if (inside_emphasis_tags) {
                            emphasis_line += my_line[j];
                        }
                    }
                    output_string += "<p>" + emphasis_line + "</p>\n\n";
                    break;
                } else {
                    string temp_line = "";
                    bool emphasis = false;
                    bool inside_emphasis_tags = false;
                    for (int j=i+1; j<my_line.length(); j++) {
                        if (my_line[j] == '*') {
                            inside_emphasis_tags = true;
                            emphasis = true;
                            emphasis_line += "<em>" + temp_line + "</em>";
                            added_tag = "style";
                            break;
                        } else
                            temp_line += my_line[j];
                        if (inside_emphasis_tags) {
                            emphasis_line += my_line[j];
                        }
                    }
                    if (emphasis) {
                        output_string += "<p>";
                        for (int x=0; x<i; x++) {
                            output_string += my_line[x];
                        }
                        output_string += emphasis_line + "</p>\n\n";
                    }
                    if (!emphasis) {
                        if ((!last_tag_list) && (!last_tag_first_list)) {
                            output_string += "<ul>";
                        }
                        output_string += "<li>" + temp_line + "</li>\n\n";
                        added_tag = "list";
                        if (!last_tag_list) {
                            last_tag_first_list = true;
                        }
                        last_tag_list = true;
                    }
                    break;
                }
            } else if (my_line[i] == '[') {
                string temp_content, temp_link, temp_title, temp_nonlink_start = "<p>", temp_nonlink_end = "</a>";
                
                for (int x=0; x<i; x++) {
                    temp_nonlink_start += my_line[x];
                }
                temp_nonlink_start += "<a href=\"";
                
                short j = i+1;
                while (j<my_line.length() && my_line[j] != ']') {
                    temp_content += my_line[j];
                    j++;
                }

                for (int x=j;x<my_line.length();x++){
                    if (my_line[x] == '(') {
                        j = x+1;
                        break;
                    }
                }
                
                bool link_has_title = false;
                while (j<my_line.length() && my_line[j] != ')') {
                    if (my_line[j] != '\"' && !link_has_title) {
                        temp_link += my_line[j];
                    } else if (my_line[j] == '\"' && !link_has_title) {
                        link_has_title = true;
                        j++;
                    }
                    if (my_line[j] != '\"' && link_has_title)
                        temp_title +=my_line[j];
                    else if (my_line[j] == '\"' && link_has_title) {
                        for (int x=j; j<my_line.length(); x++) {
                            if (my_line[x] == '\"' && link_has_title) {
                                j = x;
                                break;
                            } else if (my_line[x] == ')' && !link_has_title) {
                                j = x;
                                break;
                            }
                        }
                    }
                    j++;
                }
                j++;
                while (j < my_line.length()) {
                    temp_nonlink_end += my_line[j];
                    j++;
                }
                temp_nonlink_end += "</p>\n\n";
                
                if (temp_title == "") {
                    output_string += temp_nonlink_start+ temp_link + "\">" +temp_content + temp_nonlink_end;
                } else
                    output_string += temp_nonlink_start + temp_link + "\" title=\"" + temp_title + "\">" +temp_content + temp_nonlink_end;
                
            }else {
                if (last_line != "" && added_tag != "style" && added_tag != "header" && added_tag !="list" && added_tag !="blockquote" && added_tag !=""){
                    output_string += "<p>" + last_line + "</p>\n\n";
                    break;
                } else if (added_tag == "blockquote") {
                    output_string += "<p>";
                    for (int j=1; j<my_line.length(); j++) {
                        output_string += my_line[j];
                    }
                    output_string += "</p>";
                    break;
                }
            }
        }
        
        last_line = my_line;
        
        
    }
    
    cout << output_string;
    output_html << output_string;
    
    my_file.close();
    output_html.close();
    
    return 0;
}

