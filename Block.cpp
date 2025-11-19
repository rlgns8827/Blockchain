// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 4 : Blockchain Ledgers

#include "Block.h"
#include <sstream>
#include <iomanip>

// Converts an integer to hex using stringstream
std::string intToHexStream(int num) {
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();
}

// Constructor initializes all block fields
Block::Block(int idx, const std::string& time, const std::string& data, const std::string& prevHash)
    : index(idx), timestamp(time), data(data), previousHash(prevHash) {
    currentHash = calculateHash(); // Compute hash
}

// Creates a simple hash based on the ASCII sum of all block content
std::string Block::calculateHash() const {
    std::string combined = std::to_string(index) + timestamp + data + previousHash;
    int sum = 0;
    for (char c : combined) {
        sum += static_cast<int>(c); // sum ASCII values
    }
    return intToHexStream(sum); // convert to hex
}
