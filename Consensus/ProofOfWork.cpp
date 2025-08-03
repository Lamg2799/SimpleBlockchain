#include "ProofOfWork.h"

ProofOfWork::ProofOfWork(int difficulty) : difficulty(difficulty) {}

void ProofOfWork::Mine(Block& block) 
{
    std::string target(difficulty, '0');
    std::string hash;

    block.ReinitializeNonce();

    while (true) {
        hash = block.CalculateHash();

        if (hash.substr(0, difficulty) == target) {
            block.SetHash(hash);
            std::cout << "Block mined: " << hash << std::endl;
            break;
        }

        block.IncrementNonce();
    }
}

bool ProofOfWork::ValidateChain(const std::vector<Block>& blocks)
{
    for (size_t i = 0; i < blocks.size(); ++i)
    {
        std::string recalculated_hash = blocks[i].CalculateHash();
        if (recalculated_hash != blocks[i].GetHash())
        {
            return false; // Hash mismatch — data tampered
        }

        std::string target(difficulty, '0');
        if (recalculated_hash.substr(0, difficulty) != target)
        {
            return false; // Block not properly mined
        }

        // Check chain linkage (skip for genesis block)
        if (i > 0)
        {
            if (blocks[i].GetPreviousHash() != blocks[i-1].GetHash())
            {
                return false; // Chain linkage broken
            }
        }
    }
    return true;
}