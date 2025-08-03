#pragma once

#include "ConsensusStrategy.h"

class ProofOfWork : public ConsensusStrategy 
{
public:
    ProofOfWork(int difficulty = 4);

    void Mine(Block& block) override;

    bool ValidateChain(const std::vector<Block>& blocks) override;

private:
    int difficulty;
};