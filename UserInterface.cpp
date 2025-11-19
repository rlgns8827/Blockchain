// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 4 : Blockchain Ledgers

#include "UserInterface.h"
#include "Blockchain.h"
#include <iostream>

// Menu-driven interface for interacting with blockchain
void UserInterface::run() {
    Blockchain blockchain; // create the blockchain instance
    int choice; // user menu selection
    std::string data, filename;

    while (true) {
         // Display the main menu
        std::cout << "Menu:\n";
        std::cout << "1. Add a New Block\n";
        std::cout << "2. Display the Blockchain\n";
        std::cout << "3. Validate the Blockchain\n";
        std::cout << "4. Save Blockchain to File\n";
        std::cout << "5. Load Blockchain from File\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                // Option 1: Add a new block to the chain
                std::cout << "Enter block data: ";
                std::getline(std::cin, data);
                std::cout << "\n";
                blockchain.addBlock(data);
                break;
            case 2:
                // Option 2: Show all blocks in the chain
                blockchain.displayBlockchain();
                break;
            case 3:
                // Option 3: Validate blockchain integrity
                blockchain.isValid();
                break;
            case 4:
                // Option 4: Save current blockchain state to a file
                std::cout << "Enter filename to save the blockchain: ";
                std::getline(std::cin, filename);
                blockchain.saveToFile(filename);
                std::cout << "\n";
                break;
            case 5:
                // Option 5: Load blockchain from a file
                std::cout << "Enter filename to load the blockchain: ";
                std::getline(std::cin, filename);
                blockchain.loadFromFile(filename);
                std::cout << "\n";
                break;
            case 6:
                // Option 6: Exit the program
                return;
            default:
                // Handle invalid input
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}


