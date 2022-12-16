#!/bin/bash
# Player 2 script for tic tac toe game

declare -i r
declare -i c

while true
do
  r = $(($RANDOM % 3 + 1))
  c = $(($RANDOM % 3 + 1))
  echo "P2 Move: Row $r, Col $c"
  sleep 1
done
