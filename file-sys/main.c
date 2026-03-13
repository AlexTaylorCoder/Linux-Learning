
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_BUFFER_SIZE 16384


typedef struct {
	char name[50];
	char metaData1[100];
	char metaData2[100];
} DeviceFacade;

typedef struct {
	int id;
	DeviceFacade *deviceFacade;
} Device;


typedef struct {
	unsigned int id;
	unsigned int links;
	unsigned long lastRead;
	unsigned long lastWrite;
	unsigned long lastModified;

	unsigned char *buffer;
} INode;

typedef struct {
	unsigned char node[50];
	INode *iNode;
} File;

typedef struct {
	File *current;
	File *parent;
} DirLevel;

typedef struct {
	unsigned char *paths;
	unsigned char *home;
	int shellUID;
	int userID;
	DirLevel *dirLevel;
} Env;

int incrementId(int *id) {
	*id = *id + 1;
}
// With c mem and instructions are more seperated.
// First consider algorithimic approach
// Then memory managment considerations
void ls() {
}

int main() {
	// inode id gen
	// inode -> points to fn facade
	printf("compiles\n");
	int devId = 0;
	DeviceFacade fac = {"NVME1", "/test", "moremeta"};
	incrementId(&devId);
  	Device device = { devId, &fac};
	// env -> ptr to self, ptr to parent	
	int nodeId = 0;
	incrementId(&nodeId);

	//template or somethin, int test) to fill to at runtimewould be ideal
	unsigned char currentDataBuffer[INIT_BUFFER_SIZE] = {"awbfjawbfawljbfawjfbawfbawubgawugawbigawg"};
	INode currentNode = {nodeId, 45, 1251251l, 1251253l, 1251253l, currentDataBuffer};

	incrementId(&nodeId);
	unsigned char parentDataBuffer[INIT_BUFFER_SIZE] = {"awbfjawbfawljbfawjfbawfbawubgawugawbigawg"};
	INode parentNode = {nodeId, 45, 1251251l, 1251253l, 1251253l, parentDataBuffer};

	File currentDir = {"Current dir", &currentNode};
	File parentDir = {"Parent dir", &parentNode};

	DirLevel dirLevel = {&currentDir, &parentDir};

	unsigned char paths[1000][200] = {{"/fbi"}, {"/cia"}};
	unsigned char home[] = {"/home/fbi"};
	Env env = {
		&paths[0][0],	
		home,
		91259,
		1002, // Userspace between 1000 - 2000 
		&dirLevel
		};

	char commands[50];


	fgets("%c", &commands)
	return 0;
}
//
//
