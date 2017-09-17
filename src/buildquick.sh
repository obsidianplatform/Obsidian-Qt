#!/bin/bash

#################################################################
# Build obsidiand                                     #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"

make -j$NPROC -f makefile.unix
cp obsidiand /usr/bin/obsidiand

echo "Build complete...copied src/obsidiand to /usr/bin/obsidiand"
exit 0

