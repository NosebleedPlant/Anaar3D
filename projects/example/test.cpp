#include <iostream>
#include "../../include/core/adder.hpp"
#include "../../include/core/subtractor.hpp"

int main(){
    std::cout<<"Hello World"<<std::endl;
    std::cout<<"5 + 3 = "<< adder::add(5, 3) <<std::endl;
    std::cout<<"5 - 3 = "<< subtractor::subtract(5, 3) <<std::endl;
}