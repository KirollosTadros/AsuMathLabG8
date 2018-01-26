#include "reader.h"

Reader::Reader() : readingMode(console) {}

Reader::Reader(std::string filepath, mode m) : readingMode(m) {
	//although should not happen, but it's possible
	//that the caller specify readingMode to be console,
	//while using this constructor that takes a filepath
	if(readingMode != console){
		ifstream inputFile;                         
		  inputFile.open(filepath.c_str());  
	}
}

Reader::~Reader(){
	if(inputFile.is_open()){
		inputFile.close();
	}
}

std::string Reader::readConsole(){
	string s;
	if(inputFile.is_open())
       {
           getline(inputFile,s);
           if(s=="exit")
            return "";
           return s;
       }
}

std::string Reader::readFile(){
	string filestring,ss;
	while(ss!="")
    {
        ss=readConsole();
         filestring += ss;
         filestring += '\n'; //for adding a new line between strings ss
    }

	return filestring;
}

std::string Reader::read(){
	switch(readingMode){
	case file:
		return readFile();
		break;
	case console:
		return readConsole();
		break;
	case file_console:
		/*
		 * read the whole file first, return it as a string,
		 * then start reading from the console
		 */
		std::string tmp = readFile();
		if(tmp != ""){
			return tmp;
		}else{
			return readConsole();
		}
		break;
	}
}