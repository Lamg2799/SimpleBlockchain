#pragma once

#include "Block.h"
#include "Consensus/ConsensusStrategy.h"
#include <vector>
#include <memory>

class Blockchain 
{
private:
    std::vector<Block> chain;
    std::shared_ptr<ConsensusStrategy> strategy;

public:
    explicit Blockchain(std::shared_ptr<ConsensusStrategy> strategy);

    void AddBlock(const std::string& data);

    bool Validate() const;

    void Print() const;

    const Block& GetLastBlock() const { return chain.back(); }

    std::vector<Block>& GetChain() { return chain; }
};