#!/bin/bash

set -u
set -e

if [[ $# -eq 0 ]]
then
	echo "No files specified."
	exit 1
fi

source scripts/colors.sh # for colored output

DIR=test
mkdir -p "$DIR"

while [[ $# -gt 0 ]]
do
	FILE="$1"
	if [[ ! -f "$FILE" ]]
	then
		echo -ne "${YELLOW_FG}Warning${RESET_FONT}: "
		echo "'$FILE' is not a regular file. Skipping."
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
		echo -e "${GREEN_FG}OK${RESET_FONT}"
	else
		echo -e "${RED_FG}FAIL${RESET_FONT}"
		echo -e "\tFailed on file '$FILE'."
		echo -e "\tArchive: '${ARCHIVE_TMP}'."
		echo -e "\tOutput: '${DEST}'."
		exit 2
	fi
done
