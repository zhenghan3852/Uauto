#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<iostream>
 
#define BUFFER_LENGTH 8192
int IsDir(std::string path);
int CopyFile(std::string sourcePath,std::string destPath);
int Copy();
