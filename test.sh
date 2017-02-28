#!/bin/bash

set -u
set -e

if [[ $# -eq 0 ]]
then
	echo "No files specified."
	exit 1
fi

while [[ $# -gt 0 ]]
do
	FILE="$1"
	if [[ ! -f "$FILE" ]]
	then
		echo "Warning: '$FILE' is not a regular file. Skipping."
		shift
		continue
	fi
	DEST="/tmp/${FILE}-clone"
	shift
	echo "Testing haff rehaff on file '$FILE'."
	./haff "$FILE"
	echo ""
	./rehaff "${FILE}.ch" "$DEST"
	echo ""
	if diff --report-identical-files "$FILE" "$DEST"
	then
		rm -f "$DEST"
		echo "OK"
	else
		echo "Failed on file '$FILE'."
		echo "Archive: '$DEST'."
		exit 2
	fi
done
