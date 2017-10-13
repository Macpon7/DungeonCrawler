#pragma once
#include "stdafx.h"
#include "iostream"
#include "Structs.h"

class Generate {
public:
	pos Door(dimensions current);
	dimensions Map();
	pos Rock(dimensions current, pos player, pos door);
};