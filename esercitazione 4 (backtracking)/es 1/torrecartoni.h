#pragma once
#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	unsigned p;  // peso
	unsigned a;  // altezza
	unsigned l;  // limite
} cartone;

void TorreCartoni(cartone* c, int n);