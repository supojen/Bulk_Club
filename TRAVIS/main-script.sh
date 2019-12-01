#!/bin/bash

if [ $TRAVIS_OS_NAME = 'osx' ]; then

    # Install some custom requirements on macOS
    # e.g. brew install pyenv-virtualenv
	qmake -spec macx-xcode bulkClub.pro
	xcodebuild -list -project bulkClub.xcodeproj
	xcodebuild -scheme bulkClub build

elif [ $TRAVIS_OS_NAME = 'linux' ]; then

    # Install some custom requirements on Linux
	qmake bulkClub.pro
	make

elif [ $TRAVIS_OS_NAME = 'windows' ]; then

	#Install custom requirements for Windows
	echo "Windows Placeholder"
	#qmake bulkClub.pro
	/tools/qtcreator/bin/qmake.exe bulkClub.pro -r -o makefile
	mingw32-make makefile
	#
	#

else 

echo "No Compatible OS Specified"

fi
