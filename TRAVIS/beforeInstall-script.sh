#!/bin/bash

if [ $TRAVIS_OS_NAME = 'osx' ]; then

# Install some custom requirements on macOS
# e.g. brew install pyenv-virtualenv
#brew update
	brew install ruby-build
	brew install rbenv
	rbenv install 2.6.3
	rbenv global 2.6.3	
	brew install qt5
	brew link qt5 --force

elif [ $TRAVIS_OS_NAME = 'linux' ]; then

# Install some custom requirements on Linux
	sudo apt-get update && upgrade --yes
	sudo apt-get install --yes build-essential qtdeclarative5-dev qt5-default sqlite3

elif [ $TRAVIS_OS_NAME = 'windows' ]; then

#Install custom requirements for Windows
#echo "Windows Placeholder"
	chocolatey upgrade chocolatey
#choco upgrade all
#choco install qt-sdk-windows-x64-mingw_opengl_seh
	choco install qtcreator
	choco update
	pwd
	ls -lah
	cd /c/
	ls -lah
	cd /c/tools/
	ls -lah
	cd /c/tools/qtcreator/
	ls -lah
	cd /c/tools/qtcreator/bin
	ls -lah
	cd /c/Users/
	ls -lah
	cd /c/Users/travis
	ls -lah
	cd /c/Users/travis/build
	ls -lah
	cd /c/Users/travis/build/supojen
	ls -lah
	cd /c/Users/travis/build/supojen/Bulk_Club
	ls -lah
	
else 

echo "No Compatible OS Specified"

fi
