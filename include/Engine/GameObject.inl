
template<typename T>
std::shared_ptr<T> GameObject::addComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &component : m_components)
    {
        if (std::dynamic_pointer_cast<T>(component))
        {
            return std::dynamic_pointer_cast<T>(component);
        }
    }

    std::shared_ptr<T> newComponent = std::make_shared<T>(this);
    m_components.emplace_back(newComponent);

    return newComponent;
}

template<typename T>
std::shared_ptr<T> GameObject::getComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &component : m_components)
    {
        if (std::dynamic_pointer_cast<T>(component))
        {
            return std::dynamic_pointer_cast<T>(component);
        }
    }

    return nullptr;
}