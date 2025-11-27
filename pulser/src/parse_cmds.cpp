
#include "parse_cmds.h"
#include "gl_setup.h"


#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>     



/***************************************/



void parse_cmds(std::string *buffer )
{
    buffer->push_back(*"HELLO KITTY\n");
};





/*
std::string input_txt(void){

    std::string sentence;
    std::cout << "Enter a sentence please: "; std::cout.flush();

    std::getline(std::cin,sentence);
    std::istringstream iss(sentence);

    std::vector<std::string> words;
    std::string word;
    while(iss >> word) {
        words.push_back(word);
    } 

    for(std::vector<std::string>::const_iterator it = words.begin();
        it != words.end();
        ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl; return 0;
    
    return sentence;
}
*/
