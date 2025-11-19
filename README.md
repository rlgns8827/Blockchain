# Blockchain

#### Overview
This project is a C++ simulation of a basic blockchain ledger, where each block contains an index, timestamp, transaction data, and cryptographic hashes linking it to the previous block. The program allows users to add new blocks, validate the blockchain's integrity, and save/load the blockchain from files. A simple custom hash function is used, and no STL containers are allowed—only primitive data structures like arrays.

#### Key features
- Block Class: Each block stores an index, timestamp, transaction data, previous hash, and its own computed hash.
- Blockchain Class: Manages a linked sequence of blocks, starting with a genesis block and supporting new block additions.
- Simple Custom Hash Function: Generates hashes by summing ASCII values of block content and converting to hexadecimal.
- Blockchain Validation: Verifies the integrity of the blockchain by checking that each block's previous hash matches the actual hash of the previous block.
- File I/O Operations: Save the blockchain to a file and load an existing blockchain from a file.
- Console-Based User Interface: Add new blocks, display the blockchain, validate the chain, save to file, load from file, and exit.

#### How to Run
To compile and run the program:

1. **Compile**: Use g++ to compile the `main.cpp` file.
   ```bash
   g++ main.cpp -o blockchain
   ```

2. **Run**: Execute the compiled program with the input file name as a command-line argument.
   ```bash
   ./blockchain
   ```

#### Requirements
- C++ compiler (tested with g++)
- Text editor or IDE (e.g., VSCode) for code editing
- Terminal or command prompt for running compiled executable

#### References
- No external libraries or non-primitive data structures (e.g., vectors) are used, as per project requirements.

