// PlayingWithFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int nuke_int(int *in_var) {
    /*
        Overwrites an int variable in an attempt to secure the data
    */
    *in_var = 0;
    return 0;
}

int nuke_str(std::string *in_str) {
    /*
        Overwrites a string variable in an attempt to secure the data
    */
    *in_str = 1000;
    return 0;
}

int main()
{
    // Queries the filename
    std::cout << "Input the filename: ";
    std::string filename;
    std::getline(std::cin, filename);

    // Queries for the cipher 
    std::cout << "Input the cipher level: ";
    std::string cipher_string;
    std::getline(std::cin, cipher_string);
    int cipher = std::stoi(cipher_string);

    // Queries the data
    std::cout << "Input the data: ";
    std::string content;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, content);


    // Performs the encryption
    std::cout << "Encrypting " << content << "..." << std::endl;
    std::string final_content = "";
    for (char this_char : content) {
        final_content += this_char + cipher;
    }
    std::cout << "Encrypted into: " << final_content;

   
    // Nukes sensative variables
    nuke_int(&cipher);
    nuke_str(&content);
    nuke_str(&cipher_string);

    // Clears and overwrites the terminal
    system("CLS");
    for (int i = 0; i < 3000; i++) {
        std::cout << "--SANITIZING TERMINAL---";
    }
    system("CLS");

    // Notifies user of the status    
    std::cout << "Variables cleared" << std::endl;
    std::cout << "Process secured. Encryption complete. Saving file..." << std::endl;

    // Writes the file
    std::ofstream MyFile(filename);
    MyFile << final_content;
    MyFile.close();
    std::cout << "\nContent written to file\n\n";

}
