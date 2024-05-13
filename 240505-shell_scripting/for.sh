#!/bin/bash

array=(one two three four five hi[1..21])

for item in ${array[@]}; do echo -n $item | wc -c; done
