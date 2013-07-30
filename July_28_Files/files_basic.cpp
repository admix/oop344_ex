#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){

	std::fstream f(argv[1], std::ios::in | std::ios::out | std::ios::trunc);
	//wites 3 lines to the file (command line)
	f << "Line 1" << std::endl;
	f << "Line 2" << std::endl;
	f << "Line 3" << std::endl;

	f.seekp(0, std::ios::beg); //to the start of the file
	f << "****";          //overwrite 4 characters
	f.seekp(4, std::ios::cur); //4 bytes beyond current
	f << "#";
	std::streampos p = f.tellp(); //remember current position
	f.seekp(0, std::ios::end); //to the end of file
	f << "The last line\n"; //add a line
	f.seekp(p); //to the saved position
	f << "^"; //overwrite ONE character

	char c;
	f.seekp(0, std::ios::beg);
	while(f.get(c)){ //read 1 character at a time
		std::cout << c;
	}
	f.clear(); //clear failed (eof) state
	f.seekg(-15, std::ios::end);//move 8 bytes from end (goes back)
	while(f.get(c)){ //read 1 character at a time
		std::cout << c; //display the character read
	}
	f.clear();
}