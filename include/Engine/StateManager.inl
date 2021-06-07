
template<typename StateType>
void StateManager::pushState()
{
    auto state = std::make_unique<StateType>(*this, m_context);
    m_states.push(std::move(state));
}

template<typename StateType>
void StateManager::swapState()
{
    m_states.pop();
    pushState<StateType>();
}

template<typename StateType, typename T>
void StateManager::pushState(T data)
{
    auto state = std::make_unique<StateType>(*this, m_context, data);
    m_states.push(std::move(state));
}

template<typename StateType, typename T>
void StateManager::swapState(T data)
{
    m_states.pop();
    pushState<StateType>(data);
}