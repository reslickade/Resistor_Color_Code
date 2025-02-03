#include <iostream>
#include <string>
#include <array>
#include "functions.h"
#include <sstream>
#include <stdexcept>

//by putting variables inside anonymous namespace, visibility is within this file only
// namespace { 
// } // namespace end tag

//define number of resistor color bands. Accepted values = 4, 5 or 6.
//const int number_of_resistor_bands[3] = {4, 5, 6}; --> to not be used. 

//define const for total number of different colors
const int number_of_colors = 12;

//ColorBand resistor_values[4] = {};

const ColorBand color_bands[number_of_colors] = {
	{
		.color = "black",   .value = 0, .multipl_val = 1,           .tolerance_val = 0
	},
	{
		.color = "brown",   .value = 1, .multipl_val = 10,          .tolerance_val = 1
	},
	{
		.color = "red",     .value = 2, .multipl_val = 100,         .tolerance_val = 2
	},
	{
		.color = "orange",  .value = 3, .multipl_val = 1000,        .tolerance_val = 4
	},
	{
		.color = "yellow",  .value = 4, .multipl_val = 10000,       .tolerance_val = 4
	},
	{
		.color = "green",   .value = 5, .multipl_val = 100000,      .tolerance_val = 0.5
	},
	{
		.color = "blue",    .value = 6, .multipl_val = 1000000,     .tolerance_val = 0.25
	},
	{
		.color = "violet",  .value = 7, .multipl_val = 10000000,    .tolerance_val = 0.1
	},
	{
		.color = "grey",    .value = 8, .multipl_val = 100000000,   .tolerance_val = 0.05
	},
	{
		.color = "white",   .value = 9, .multipl_val = 1000000000,  .tolerance_val = 0
	},
	{
		.color = "gold",    .value = 10, .multipl_val = 0.1,      .tolerance_val = 5
	},
	{
		.color = "silver",  .value = 11, .multipl_val = 0.01,     .tolerance_val = 10
	}
};

//Functions

// void user_message() {
// 	// print user message
// 	std::cout << "===== 4-Band Resistor Color Code Calculator =====" << std::endl;

// 	// print possible color values
// 	std::cout << "\nHint: The valid colors are listed below:" << std::endl;
// 	for (int i = 0; i < number_of_colors; i++) {
// 		std::cout << "* "<< color_bands[i].color << std::endl;
// 	}
// }

// void input() {
// 	// prompt user to enter the colors of the 4 resistor values
// 	std::cout << "\nEnter the 4 resistor band colors, separated by space symbol:" << std::endl;
// }


// void parse() {
// // 	// validate colors and record their numbers --> part of input
// 	for (int i = 0; i < 4; i++) {

// 		bool color_match {0};   //set to 1 when you match input to color list
// 		std::string value = {};      //store input

// 		while (color_match == 0) {

// 			std::cin >> value;       //submit color

// 			for (int j = 0; j < number_of_colors; j++) {

// 			    if (value == color_bands[j].color) {      //check for match

// 				    resistor_values[i] = color_bands[j];
// 				    color_match = true;
// 				    break;

// 					}
// 				}
// 			}

// 			if (!color_match) {
// 				std::cout << "invalid color name" << std::endl;  //TODO add verification if there are multiple colors entered, not just one
// 			}

// 	}
// }

// void calculate () {
//   double result = ((resistor_values[0].value * 10 + resistor_values[1].value) * resistor_values[2].multipl_val);

//   std::cout << result << std::endl;

//   if (result >= 1000000000) {

//          std::cout << (result/1000000000) << "G Ohms +- ";

//     } else if (result >= 1000000) {

//         std::cout << (result/1000000) << "M Ohms +- ";

//     } else if (result >= 1000) {

//         std::cout << (result/1000) << "k Ohms +- ";

//     } else {

//         std::cout << result << " ohms +- ";
//     }

//     std::cout << resistor_values[3].tolerance_val << "%"<<std::endl;
// }

//TODO 16.01.2025

//classes and member functions
//rewrite functions.cpp as a class
//add 5 and 6-band support

//2025_01_27

void Resistor_Color_Code::user_message_N() {
    std::cout << "===== 4-Band Resistor Color Code Calculator =====" << std::endl;
    
    std::cout << "\nHint: The valid colors are listed below:" << std::endl;
	for (int i = 0; i < number_of_colors; i++) {
		std::cout << "* "<< color_bands[i].color << std::endl;
	}
}

void Resistor_Color_Code::read_input(std::istream& input) {
    
	std::string user_input; //new variable to store user input
	
	std::getline(input, user_input); // reads characters from an input stream and places them into a string: 

	std::istringstream stream{user_input}; //user_input is a buffer; stream is an object which provides operators helpful for parsing
	
	std::string color;
    try  {
    	for (int i = 0; i < 4; i++) {
    	    
    	    stream >> color; // >> - the delimiter is applied here, which is according to the TYPES used.
    	
    	    resistor_values_N[i] = get_color_band_by_color(color);
    	}
    } catch (std::runtime_error& exception) {
        std::cout << "Invalid color entered. Try again" << std::endl;
        read_input (input);
    }
	
}

//^ put in try catch block TODO

// try {
//   // ...
// } catch (std::runtime_error& exc)
// {
//   // handle
// }


ColorBand Resistor_Color_Code::get_color_band_by_color(const std::string& input_color) {

	for (int j = 0; j < number_of_colors; j++) {

		if (input_color == color_bands[j].color) {      //check for match

			return color_bands[j];

		}
	}
	
	throw std::runtime_error{"Invalid Color " + input_color}; //return empty value or throw exception --> TODO 

}

void Resistor_Color_Code::count_number_spaces() {
   
}


void Resistor_Color_Code::calculate_N() {
	//test: print stored values
    std::cout << resistor_values_N[0].color << resistor_values_N[1].color << resistor_values_N[2].color << resistor_values_N[3].color << std::endl;
	
	double result = ((resistor_values_N[0].value * 10 + resistor_values_N[1].value) * resistor_values_N[2].multipl_val);
	
	if (result >= 1000000000) {

         std::cout << (result/1000000000) << "G Ohms +- ";

    } else if (result >= 1000000) {

        std::cout << (result/1000000) << "M Ohms +- ";

    } else if (result >= 1000) {

        std::cout << (result/1000) << "k Ohms +- ";

    } else {

        std::cout << result << " ohms +- ";
    }

    std::cout << resistor_values_N[3].tolerance_val << "%"<<std::endl;

}