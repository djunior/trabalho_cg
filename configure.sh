#!/bin/bash
echo Gerando Makefile...
case "$OSTYPE" in
	darwin*) 
		echo OS = Mac OSX
		qmake -spec macx-g++;;
	linux*)
		echo OS = Linux
		qmake -makefile;;
	*)
		echo Default = Mac OSX
		qmake -spec macx-g++;;
esac
		
echo Concluido
