#!/bin/bash
while [ -z "$(diff test.out standard.out)" ]
do 
  ./random > in.txt
  ./test < in.txt > test.out
  ./standard < in.txt > standard.out	
done
