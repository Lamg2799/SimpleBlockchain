# SimpleBlockchain
Simple blockchain demo that utilizes strategy pattern for consensus mechanism.

Currently only working with Proof of Work (pow)

Can specify difficulty within the code in main.cpp, multiplies difficulty of mining x16

# Build (MacOS)
g++ -std=c++17 $(find . -name '*.cpp') \
    -I/opt/homebrew/opt/openssl@3/include \
    -L/opt/homebrew/opt/openssl@3/lib -lssl -lcrypto \
    -o blockchain

# Run (MacOS)
./blockchain pow

