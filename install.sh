#!/bin/bash

make clean

make

if [ $? -ne 0 ]; then
  echo "failed to build. exiting..."
  exit 1
fi

sudo cp shell /usr/bin/sssh

if [ $? -ne 0 ]; then
  echo "failed installation. exiting..."
  exit 1
fi

if ! echo "$PATH" | grep -q "/usr/bin/sssh"; then
  echo "addding /usr/bin/sssh to path"
  export PATH=$PATH:/usr/bin/sssh
fi

echo "sssh installed successfully. to run, type 'sssh'."

cd ~
sssh
