#include "Blockchain.h"

Blockchain::Blockchain(std::shared_ptr<ConsensusStrategy> strat)
    : strategy(std::move(strat))
{
    Block genesis(0, "0", "0");
    strategy->Mine(genesis);
    chain.push_back(genesis);
}

void Blockchain::AddBlock(const std::string& data)
{
    const Block& last = chain.back();
    Block next(static_cast<uint64_t>(chain.size()), data, last.GetHash());

    strategy->Mine(next);
    chain.push_back(next);
}

bool Blockchain::Validate() const
{
    return strategy->ValidateChain(chain);
}

void Blockchain::Print() const
{
    for (const auto& block : chain) {
        block.Print();
    }
}
