#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine()
{
    m_ActiveState = nullptr;
    m_NextState = nullptr;
}

GameStateMachine::~GameStateMachine()
{
    /*
    while (!m_StateStack.empty())
    {
        delete m_StateStack.back();
        m_StateStack.pop_back();
    }
    */
    for (auto it : m_StateStack) {
        if (it != nullptr) {
            delete it;
        }
    }
    m_StateStack.clear();

    if (m_NextState != nullptr)
        delete m_NextState;
    if (m_ActiveState != nullptr)
        delete m_ActiveState;
}

void GameStateMachine::ChangeState(GameStateBase* state)
{
    m_NextState = state;
}

void GameStateMachine::ChangeState(StateTypes st)
{
    GameStateBase* gs = GameStateBase::CreateState(st);
    this->ChangeState(gs);
    
}

void GameStateMachine::PushState()
{
    /*
    GameStateBase* gs = GameStateBase::CreateState(st);
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Pause();
    }
    m_NextState = gs;
    */
    m_StateStack.push_back(m_NextState);
    currentState()->Init();
    m_NextState = nullptr;
}

void GameStateMachine::PopState()
{
    /*
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Pause();
        m_StateStack.pop_back();
    }
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Resume();
    }
    m_ActiveState = m_StateStack.back();
    */
    if (!m_StateStack.empty())
    {
        m_StateStack.pop_back();
    }

}

void GameStateMachine::PerformStateChange()
{
    if (m_NextState != nullptr)
    {
        if (!m_StateStack.empty())
        {
            m_StateStack.back()->Exit();
        }
        m_StateStack.push_back(m_NextState);
        m_StateStack.back()->Init();
        m_ActiveState = m_NextState;
    }
    m_NextState = nullptr;
}

GameStateBase* GameStateMachine::currentState() const
{
    //return m_ActiveState;
    if (m_StateStack.empty()) {
        return nullptr;
    }
    return m_StateStack.back();
}

GameStateBase* GameStateMachine::nextState() const
{
    return m_NextState;
}

bool GameStateMachine::NeedToChangeState()
{
    return m_NextState!=nullptr;
}

bool GameStateMachine::HasState()
{
    return m_StateStack.size()>0;
}
