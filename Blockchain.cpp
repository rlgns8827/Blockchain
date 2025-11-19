// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 4 : Blockchain Ledgers

#include "Blockchain.h"
#include "Block.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

// Helper function to get current time as a string without trailing newline
std::string getCurrentTimestamp() {
    time_t now = time(0);
    std::string ts = std::string(ctime(&now));
    ts.pop_back(); // remove trailing newline character
    return ts;
}

// Constructor creates the Genesis Block and initializes linked list
Blockchain::Blockchain() : head(nullptr), tail(nullptr), size(0) {
    Block genesis(0, getCurrentTimestamp(), "Genesis Block", "0");
    head = new Node(genesis);  // First node
    tail = head;               // Tail is same as head at start
    size = 1;                  // Initialize size

    // Output Genesis Block info
    std::cout << "Genesis Block Created\n";
    std::cout << "Index: " << genesis.index << "\n";
    std::cout << "Timestamp: " << genesis.timestamp << "\n";
    std::cout << "Data: " << genesis.data << "\n";
    std::cout << "Previous Hash: " << genesis.previousHash << "\n";
    std::cout << "Hash: " << genesis.currentHash << "\n\n";
}

// Destructor to clean up linked list memory
Blockchain::~Blockchain() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Adds a new block to the end of the blockchain
void Blockchain::addBlock(const std::string& data) {
    int index = size;
    std::string timestamp = getCurrentTimestamp();
    std::string prevHash = tail->block.currentHash;

    Block newBlock(index, timestamp, data, prevHash);
    Node* newNode = new Node(newBlock);
    tail->next = newNode;
    tail = newNode;
    size++;

    std::cout << "New Block Added\n";
    std::cout << "Index: " << newBlock.index << "\n";
    std::cout << "Timestamp: " << newBlock.timestamp << "\n";
    std::cout << "Data: " << newBlock.data << "\n";
    std::cout << "Previous Hash: " << newBlock.previousHash << "\n";
    std::cout << "Hash: " << newBlock.currentHash << "\n\n";
}

// Prints out the details of each block in the blockchain
void Blockchain::displayBlockchain() const {
    std::cout << "\nBlockchain State\n";
    Node* current = head;
    while (current) {
        const Block& block = current->block;
        std::cout << "Index: " << block.index << "\n";
        std::cout << "Timestamp: " << block.timestamp << "\n";
        std::cout << "Data: " << block.data << "\n";
        std::cout << "Previous Hash: " << block.previousHash << "\n";
        std::cout << "Hash: " << block.currentHash << "\n\n";
        current = current->next;
    }
}

// Verifies the integrity of the blockchain
bool Blockchain::isValid() const {
    std::cout << "\nPerforming blockchain validation...\n";
    Node* current = head;

    while (current && current->next) {
        const Block& currentBlock = current->next->block;
        const Block& previousBlock = current->block;

        if (currentBlock.previousHash != previousBlock.currentHash ||
            currentBlock.calculateHash() != currentBlock.currentHash) {
            std::cout << "Block " << currentBlock.index << " has an invalid current hash!\n";
            std::cout << "Result: Blockchain is invalid \n\n";
            return false;
        }
        current = current->next;
    }

    std::cout << "Result: Blockchain is valid \n\n"; 
    return true;
}

// Writes each block to file in pipe-separated format
void Blockchain::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    Node* current = head;
    while (current) {
        const Block& block = current->block;
        out << block.index << "|" << block.timestamp
            << "|" << block.data << "|" << block.previousHash << "|" << block.currentHash << "\n";
        current = current->next;
    }
    std::cout << "Blockchain saved to file: " << filename << "\n";
}

// Loads blocks from file and reconstructs the linked list
void Blockchain::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "File could not be opened!\n";
        return;
    }

    // Clear existing list
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string indexStr, time, data, prevHash, currHash;

        std::getline(ss, indexStr, '|');
        std::getline(ss, time, '|');
        std::getline(ss, data, '|');
        std::getline(ss, prevHash, '|');
        std::getline(ss, currHash);

        Block block(std::stoi(indexStr), time, data, prevHash);
        block.currentHash = currHash;

        Node* newNode = new Node(block);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    std::cout << "Blockchain loaded from file: " << filename << "\n";
}
