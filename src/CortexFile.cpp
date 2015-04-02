/*
 * CortexFile.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: guywenck
 */

#include "TRL/CortexFile.h"

namespace TRL {

CortexFile::CortexFile() {
	this->fileName = "";
	this->fileMode = FILE_MODE_UNSET;
	this->cooldownTimer = 0;
	this->resetTime = millis();
	this->fileHandle = 0;
}

CortexFile::CortexFile(string fileName) {
	this->fileName = fileName;
	this->fileMode = FILE_MODE_UNSET;
	this->cooldownTimer = 0;
	this->resetTime = millis();
	this->fileHandle = 0;
}

CortexFile::~CortexFile() {
	// TODO Auto-generated destructor stub
}

//Overwrites the existing contents of the file
//Writing to files will halt all tasks so don't use
//this function when the robot is competing or moving.
void CortexFile::writeStringToFile(string textToWrite) {
	updateCooldownTimer();
	if (cooldownTimer > 0) {
		return;
	}
	println(LOG, "CortexFile", "writeStringToFile", "Writing file. Don't turn off the cortex!");
	fileMode = WRITE;
	fileHandle = fopen(fileName, "w");

	{
		fprint(textToWrite, fileHandle);
		fflush(fileHandle);
	}
	fclose(fileHandle);
	fileMode = FILE_MODE_UNSET;
	println(LOG, "CortexFile", "writeStringToFile", "Finished writing file.");
	resetCooldownTimer();
}

string CortexFile::readFileContents() {
	//TODO readFileContents is not working properly
	char *contents = 0;
	fileMode = READ;
	fileHandle = fopen(fileName, "r");
	{
		int fileChars = fcount(fileHandle) + 1;
		char tempStr[fileChars];
		contents = tempStr;
		contents = fgets(contents, fileChars, fileHandle);
	}
	fclose(fileHandle);
	fileMode = FILE_MODE_UNSET;
	return contents;
}

void CortexFile::resetCooldownTimer() {
	cooldownTimer = FILE_WRITE_COOLDOWN_TIME;
	resetTime = millis();
}

void CortexFile::updateCooldownTimer() {
	int elapsedTime = millis() - resetTime;
	int newTimerValue = FILE_WRITE_COOLDOWN_TIME - elapsedTime;
	if(cooldownTimer > newTimerValue){
		cooldownTimer = newTimerValue;
	}
	if(cooldownTimer < 0){
		cooldownTimer = 0;
	}
}

int CortexFile::getFileWriteCooldownMillis(){
	updateCooldownTimer();
	return cooldownTimer;
}

} /* namespace TRL */
