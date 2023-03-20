#pragma once
#include "IPState.h"
#include"HitBox.h"

class IPlayer {
public:
	virtual void changeNextStage(IPState::State nextstate)=0;
	virtual HitBox* getHitBox() = 0;
	virtual void setPath(int path) = 0;
	virtual int getPath() = 0;
	virtual void setRow(int r) = 0;
	virtual int getRow() = 0;
	virtual void setColumn(int c) = 0;
	virtual int getColumn() = 0;

};