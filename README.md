# SimpleBlockchain
Simple blockchain demo that utilizes strategy pattern for consensus mechanism.

Currently only working with Proof of Work (pow)

Can specify difficulty within the code in main.cpp, multiplies difficulty of mining x16

# Build (MacOS)
g++ $(find . -name "*.cpp") -o main \
  -I. \
  -I/opt/homebrew/opt/openssl@3/include \
  -L/opt/homebrew/opt/openssl@3/lib \
  -lssl -lcrypto

# Run (MacOS)
./blockchain pow

# Example Output

Valid blockchain example: 
Block mined: 00000cbcda86444da95ffcb3580fd58789b910f1d0dba20cc332db7c0a7cc586
Block mined: 0000033cf481783b35d02b980cc20fc992880b1458a72316170b16f7db07e1f9
Block mined: 00000d92e530f4ab85ae2afb7be291d3ef7a16bfb1e3c357aa69e8bf6e1343a9
Blockchain Validated
Block #0
Timestamp: 1754582469
Data: 0
Nonce: 324925
Previous Hash: 0
Hash: 00000cbcda86444da95ffcb3580fd58789b910f1d0dba20cc332db7c0a7cc586
---------------------------
Block #1
Timestamp: 1754582470
Data: Hello
Nonce: 851159
Previous Hash: 00000cbcda86444da95ffcb3580fd58789b910f1d0dba20cc332db7c0a7cc586
Hash: 0000033cf481783b35d02b980cc20fc992880b1458a72316170b16f7db07e1f9
---------------------------
Block #2
Timestamp: 1754582473
Data: World
Nonce: 25272
Previous Hash: 0000033cf481783b35d02b980cc20fc992880b1458a72316170b16f7db07e1f9
Hash: 00000d92e530f4ab85ae2afb7be291d3ef7a16bfb1e3c357aa69e8bf6e1343a9
---------------------------
Invalid blockchain example: 
Block mined: 0000083f71bb6470f3089ef2c07a7a6a401834db560535b1037d2978aaa1efa7
Block mined: 000000df348b5e9ef34fc61333047f806718d2a7307fe1b519a3d2a793a2c422
Block mined: 00000e262c18f16a0511c9bdb5f58751491508dca2c2974724a36ad8175de613
Blockchain was invalid



