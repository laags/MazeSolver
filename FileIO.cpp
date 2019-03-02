#include <iostream>
#include "FileIO.h"

void FileIO::writeMaze(std::string maze, std::string filepath) {
    std::ofstream myfile;

    // Open/Create the output file
    try {
        myfile.open(filepath); //output file (in the same folder)
    }catch(...){
        std::cerr << "Creating file '" << filepath << "' failed.";
        return;
    }

    // Write to the file
    try {
        myfile << maze;
    }catch(...){
        std::cerr << "Unable to write to file";
    }

    // Close file
    try {
        myfile.close();
    }catch(...){
        std::cerr << "Unable to close file";
        return;
    }
}