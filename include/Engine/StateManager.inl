
template<typename StateType>
void StateManager::pushState()
{
    auto state = std::make_unique<StateType>(get_shared_ptr(), m_window);
    m_states.push(std::move(state));
}

template<typename StateType>
void StateManager::swapState()
{
    m_states.pop();
    pushState<StateType>();
}