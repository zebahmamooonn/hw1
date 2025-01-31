#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

ULListStr data;
data.push_back("7");
data.push_front("8");
data.push_back("9");

std::cout<<data.front() << " " << data.back() << std::endl;
std::cout << "Size:" << data.size() << std::endl;
data.pop_back();
data.pop_front();

std::cout<<data.front() << " " << data.back() << std::endl;
std::cout<<"Size:" << data.size() << std::endl; 
}

