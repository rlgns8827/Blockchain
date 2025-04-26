// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 4 : Blockchain Ledgers

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

// Represents a single block in the blockchain
class Block {
public:
    int index;                  // Position of the block
    std::string timestamp;      // Time of creation
    std::string data;           // Block's content
    std::string previousHash;   // Hash of the previous block
    std::string currentHash;    // Computed hash of this block

    Block(int idx, const std::string& time, const std::string& data, const std::string& prevHash);
    std::string calculateHash() const;
};

#endif // BLOCK_H

