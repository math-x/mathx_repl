#!/bin/bash

echo "Setting up MathX REPL"
make -s
sudo cp repl /usr/bin/mathx
rm repl
echo "Setup complete"
