#pragma once

#include <iostream>

// void user_message();

// void input();

// void parse();

// void calculate();

//2025_01_27
struct ColorBand { // this was moved from functions.cpp to here 
    std::string color;
    int value = 0;
    double multipl_val = 0;
    double tolerance_val = 0;
};

class Resistor_Color_Code {
    public:
        void user_message_N();
        void read_input(std::istream& input);
        void calculate_N();
    
    private:
        ColorBand resistor_values_N[4] = {}; //Define array to store the color bands of the resistor
        ColorBand get_color_band_by_color(const std::string& input_color); // const string -> it will not be modifiable within the function.
        void count_number_spaces();//count number of spaces in user input
    
};

