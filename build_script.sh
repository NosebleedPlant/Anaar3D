#!/bin/bash

configure(){
  cmake -S ./ -B ./build
  if test -f ./compile_commands.json; then
    rm ./compile_commands.json
    echo "file renewed"
  fi
  mv ./build/compile_commands.json ./
}

build(){
  cd build/
  make
  cd ..
}

run(){
  cd bin/
  ./Anaar3D_gui
  cd ..
}

test(){
  GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j12
}

help(){
   echo "options: [-c|b|r]"
   echo "extended options: [-configure|build|run]"
   echo "c|configure|   Print the GPL license notification."
   echo "b|build    |   Print this Help."
   echo "r|run      |   Verbose mode."
   echo
}

ARG_USED=false
while [ "$#" -gt 0 ]; do
  case "$1" in
    "-h" | "-help")
      help
      ARG_USED=true
    ;;
    "-c" | "-configure")
      configure
      ARG_USED=true
    ;;
    "-b" | "-build")
      build
      ARG_USED=true
    ;;
    "-r" | "-run")
      run
      ARG_USED=true
    ;;
    "-t" | "-run")
      test
      ARG_USED=true
    ;;
    *)
      echo "$1 is not a valid command. See -h or --help"
      exit 1
    ;;
  esac
  shift 
done

if [ "$ARG_USED" = false ]; then
  configure
  build
  run
fi
