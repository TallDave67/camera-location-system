#!/bin/sh
DIR="/build"
if [ -d "$DIR" ]; then
  ### Take action if $DIR exists ###
  echo "${DIR} already exists"
else
  ###  Control will jump here if $DIR does NOT exists ###
  echo "Making directory${DIR}"
  mkdir build
fi
cd build
cmake ../
make VERBOSE=1
