// Kihoon Yoo
// 2486883
// kiyoo@chapman.edu 
// CPSC-350-04
// PA 4 : Blockchain Ledgers

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <string>

// Manages the list of blocks and blockchain operations
class Blockchain {
private:
    struct Node {
        Block block;
        Node* next;
        Node(const Block& blk) : block(blk), next(nullptr) {}
    };

    Node* head;  // Genesis block
    Node* tail;  // Last block
    int size;    // Number of blocks

public:
    Blockchain();
    ~Blockchain();

    void addBlock(const std::string& data);
    void displayBlockchain() const;
    bool isValid() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // BLOCKCHAIN_H
