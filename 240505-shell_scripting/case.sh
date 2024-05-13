#!/bin/bash

case ${1,,} in
		mohamed | idress | jalal)
				echo "YAY, you can join"
				;;
		help)
				echo "First provide a name"
				;;
		*)
				echo "Nah, you are out!"
				;;
esac
