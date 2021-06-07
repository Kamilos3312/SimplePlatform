
template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::load(Identifier key, const std::string &filePath, bool override)
{
    auto found = m_data.find(key);
    if (found == m_data.end())
    {
        loadFile(key, filePath);
        return;
    }

    if (override)
    {
        loadFile(key, filePath);
        return;
    }

    throw std::runtime_error("ResourceManager::load - Key already exists");
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::load(Identifier key, const Resource &resource, bool override)
{
    auto found = m_data.find(key);
    if (found == m_data.end())
    {
        loadResource(key, resource);
        return;
    }

    if (override)
    {
        loadResource(key, resource);
        return;
    }

    throw std::runtime_error("ResourceManager::load - Key already exists");
}

template<typename Identifier, typename Resource>
Resource &ResourceManager<Identifier, Resource>::get(Identifier key)
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}

template<typename Identifier, typename Resource>
const Resource &ResourceManager<Identifier, Resource>::get(Identifier key) const
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}

template<typename Identifier, typename Resource>
Resource &ResourceManager<Identifier, Resource>::operator[](Identifier key)
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}

template<typename Identifier, typename Resource>
const Resource &ResourceManager<Identifier, Resource>::operator[](Identifier key) const
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::loadFile(Identifier key, const std::string &filePath)
{
    std::unique_ptr<Resource> original(new Resource());
    if (!original->loadFromFile(filePath))
    {
        throw std::runtime_error("ResourceManager::load - Failed to load " + filePath);
    }

    auto inserted = m_data.insert(std::make_pair(key, std::move(original)));
    assert(inserted.second);
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::loadResource(Identifier key, const Resource &resource)
{
    std::unique_ptr<Resource> original = std::make_unique<Resource>(resource);
    auto inserted = m_data.insert(std::make_pair(key, std::move(original)));
    assert(inserted.second);
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::release(Identifier key)
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    *resource->second.reset();
    m_data.erase(resource);
}
