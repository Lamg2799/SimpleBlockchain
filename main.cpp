#include <iostream>
#include <string>
#include "Blockchain.h"
#include "Consensus/ProofOfWork.h"

int main(int argc, char* argv[]) {
    // Check if exactly one command-line argument (besides the program name) is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <consensus_strategy>\n";
        std::cerr << "Example: " << argv[0] << " pow\n";
        return 1; // Indicate an error
    }

    // Access the single argument
    std::string consensus_strategy_string = argv[1];
    std::shared_ptr<ConsensusStrategy> consensus_strategy;

    if (consensus_strategy_string == "pow") {
        consensus_strategy = std::make_shared<ProofOfWork>(5);  // difficulty 4 example
    }
    else {
        std::cerr << "Unknown consensus strategy: " << consensus_strategy_string << std::endl;
        return 1;
    }

    // Valid blockchain example
    std::cout << "Valid blockchain example: " << "\n";

    Blockchain valid_chain(consensus_strategy);

    valid_chain.AddBlock("Hello");
    valid_chain.AddBlock("World");

    bool result = valid_chain.Validate();

    if (result)
    {
        std::cout << "Blockchain Validated" << "\n";
    }
    else
    {
        std::cerr << "Blockchain was invalid" << std::endl;
        return 1;
    }

    valid_chain.Print();

    // Invalid blockchain example

    std::cout << "Invalid blockchain example: " << "\n";

    Blockchain invalid_chain(consensus_strategy);

    invalid_chain.AddBlock("Hello");
    invalid_chain.AddBlock("World");

    Block fake_block(3, "Fake Data", invalid_chain.Validate() ? invalid_chain.GetChain().back().GetHash() : "0");

    // Add invalid hash (don't mine it)
    fake_block.SetHash("0000abcdef1234567890");

    invalid_chain.GetChain().push_back(fake_block);

    result = invalid_chain.Validate();

    if (result)
    {
        std::cout << "Blockchain Validated" << "\n";
    }
    else
    {
        std::cerr << "Blockchain was invalid" << std::endl;
        return 1;
    }

    invalid_chain.Print();

    return 0;
}