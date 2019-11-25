#!/bin/bash

if [ $TRAVIS_OS_NAME = 'osx' ]; then

    # Install some custom requirements on macOS
    # e.g. brew install pyenv-virtualenv
	qmake -spec macx-xcode bulkClub.pro
	xcodebuild -list -project bulkClub.xcodeproj
	xcodebuild -scheme bulkClub build


else

    # Install some custom requirements on Linux
	qmake bulkClub.pro
	make

fi
