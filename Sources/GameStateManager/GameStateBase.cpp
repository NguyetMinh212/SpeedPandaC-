#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSEnd.h"
#include "GSPlay.h"
#include"GSSettings.h"
#include"GSHelp.h"
#include"GSSelectLevel.h"
#include"GSQuitGame.h"
#include "GSPause.h"
#include "GSWarningHome.h"

GameStateBase* GameStateBase::CreateState(StateTypes st)
{
		GameStateBase* gs = nullptr;
		switch (st)
		{
		case INVALID:
			break;
		case INTRO:
			gs = new GSIntro();
			break;
		case MENU:
			gs = new GSMenu();		
			break;
		case PLAY:
			gs = new GSPlay();
			break;
		case SETTINGS:
			gs = new GSSettings();
			break;
		case HELP:
			gs = new GSHelp();
			break;
		case SELECT_LEVEL:
			gs = new GSSelectLevel();
			break;
		case QUIT_GAME:
			gs = new GSQuitGame();
			break;
		case PAUSE:
			gs = new GSPause();
			break;
		case WARNING_HOME:
			gs = new GSWarningHome();
			break;
		case END:
			gs = new GSEnd();
			break;
		default:
			break;
		}
		return gs;
	
}
