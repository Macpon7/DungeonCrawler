#pragma once
#include "stdafx.h"
#include "Structs.h"

class Generate {
public:
	Position door(Dimensions current);
	Dimensions map();
	Position player(Dimensions current);
	Position enemy(Dimensions current);
};