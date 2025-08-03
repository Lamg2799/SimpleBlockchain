#include "Block.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <ctime>

namespace 
{

    std::string SHA256(const std::string& input)
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        return ss.str();
    }
}

Block::Block(uint64_t idx, const std::string& data, const std::string& previous_hash)
    : index(idx), timestamp(static_cast<uint64_t>(std::time(nullptr))),
      data(data), previous_hash(previous_hash), nonce(0), hash("")
{}

std::string Block::CalculateHash() const
{
    std::string block_string =
        std::to_string(index) +
        std::to_string(timestamp) +
        data +
        previous_hash +
        std::to_string(nonce);

    return SHA256(block_string);
}

void Block::Print() const
{
    std::cout << "Block #" << index << "\n";
    std::cout << "Timestamp: " << timestamp << "\n";
    std::cout << "Data: " << data << "\n";
    std::cout << "Nonce: " << nonce << "\n";
    std::cout << "Previous Hash: " << previous_hash << "\n";
    std::cout << "Hash: " << hash << "\n";
    std::cout << "---------------------------\n";
}