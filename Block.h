#pragma once

#include <string>
#include <iostream>
#include <cstdint>

class Block
{
private:
    uint64_t index;
    uint64_t timestamp;
    std::string data;
    std::string previous_hash;
    std::string hash;
    uint64_t nonce;

public:
    Block(uint64_t index, const std::string& data, const std::string& previous_hash);

    std::string CalculateHash() const;

    void IncrementNonce() { nonce++; }
    void ReinitializeNonce() { nonce = 0; }

    void SetHash(const std::string& new_hash) { hash = new_hash; }
    std::string GetHash() const { return hash; }
    std::string GetPreviousHash() const { return previous_hash; }

    void Print() const;
};