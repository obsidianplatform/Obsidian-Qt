#!/bin/bash

#################################################################
# Build obsidiand                                     #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"

make -j$NPROC -f makefile.unix
sudo cp obsidiand /usr/bin/obsidiand

echo "Build complete...copied src/obsidiand to /usr/bin/obsidiand"
echo "Run the app by typing 'obsidiand' at the command prompt"
echo "Follow the instructions to create an rpcuser and rpcpassword"
echo "and run again to sync"
exit 0

