#pragma once

#include "../Block.h"
#include <vector>

class ConsensusStrategy {
public:
    virtual ~ConsensusStrategy() = default;

    virtual void Mine(Block& block) = 0;

    virtual bool ValidateChain(const std::vector<Block>& blocks) = 0;
};