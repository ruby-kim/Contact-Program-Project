#pragma once

#ifndef MY_FUNC_H
#define MY_FUNC_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insert(struct student *p, int *n); //1. Registration
void print_all(struct student *p, int n); //2. ShowAll
void delete_tel(struct student *p, int *n); //3. Delete
void find_by_birth(struct student *p, int n); //4. FindBirth
void register_from_file(struct student *p, FILE *fp, int *n, int max_num);//5. RegFromFile
void sort(struct student *p, int *n); //이름을 사전순으로 정렬하는 함수
void free_all(struct student *p, FILE *fp, int n); //6. Exit

#endif