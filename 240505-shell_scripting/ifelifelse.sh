#!/bin/bash

if [ ${1,,} = mohamed ]; then
		echo "Welcome back $1. Need any help?"
elif [ ${1,,} = help ]; then
		echo "Can u first enter your username?"
else
		echo "Get out of here"
fi
