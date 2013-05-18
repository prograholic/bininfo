#!/bin/sh

if [ -z "$1" ]
then
  echo "usage `basename $0` input_file"
  exit 1
fi

echo "compiling sample $1" > compile_log.txt




g++ -O2 -o $1_release_static.bin -static-libgcc -static -static-libstdc++ $1 >> compile_log.txt 2>&1
if [ $? -ne 0 ]
then
  echo "compilation failed, see compile_log.txt"
  exit 2
fi

g++ -O2 -o $1_release_dynamic.bin $1 >> compile_log.txt 2>&1
if [ $? -ne 0 ]
then
  echo "compilation failed, see compile_log.txt"
  exit 2
fi

g++ -O0 -g -o $1_debug_static.bin -static-libgcc -static -static-libstdc++ $1 >> compile_log.txt 2>&1
if [ $? -ne 0 ]
then
  echo "compilation failed, see compile_log.txt"
  exit 2
fi

g++ -O0 -g -o $1_debug_dynamic.bin $1 >> compile_log.txt 2>&1
if [ $? -ne 0 ]
then
  echo "compilation failed, see compile_log.txt"
  exit 2
fi

echo "compilation successful"
