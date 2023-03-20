#pragma once
#include "../GameManager/Singleton.h"
#include"../GameManager/ResourceManager.h"
#include<list>

#define GSM GameStateMachine::GetInstance()
class GameStateBase;
enum StateTypes
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTINGS,
	HELP,
	SELECT_LEVEL,
	QUIT_GAME,
	PAUSE,
	WARNING_HOME,
	END,
};

class GameStateMachine : public CSingleton<GameStateMachine> {
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState();
	void PopState();

	void PerformStateChange();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;
	bool NeedToChangeState();
	bool HasState();

private:
	std::list<GameStateBase*> m_StateStack;
	GameStateBase* m_ActiveState;
	GameStateBase* m_NextState;
};