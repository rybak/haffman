#!/bin/bash

set -u
set -e

if [[ $# -eq 0 ]]
then
	echo "No files specified."
	exit 1
fi

DIR=test
mkdir -p "$DIR"

while [[ $# -gt 0 ]]
do
	FILE="$1"
	if [[ ! -f "$FILE" ]]
	then
		echo "Warning: '$FILE' is not a regular file. Skipping."
		shift
		continue
	fi
	DEST="${DIR}/${FILE}-clone"
	ARCHIVE="${FILE}.ch"
	ARCHIVE_TMP="${DIR}/${ARCHIVE}"
	shift
	echo "Testing haff rehaff on file '$FILE'."
	./haff "$FILE"
	mv "${ARCHIVE}" "${ARCHIVE_TMP}"
	unset ARCHIVE
	echo ""
	./rehaff "$ARCHIVE_TMP" "$DEST"
	echo ""
	if diff --report-identical-files "$FILE" "$DEST"
	then
		rm -f "$DEST"
		echo "OK"
	else
		echo "Failed on file '$FILE'."
		echo "Archive: '${ARCHIVE_TMP}'."
		echo "Output: '${DEST}'."
		exit 2
	fi
done
