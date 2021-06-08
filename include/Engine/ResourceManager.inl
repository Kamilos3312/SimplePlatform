
template<typename Identifier, typename Resource>
ResourceManager<Identifier, Resource>::ResourceManager()
        : m_data()
{

}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::load(const Identifier &key, const std::string &filePath)
{
    auto found = m_data.find(key);
    if (found != m_data.end())
    {
        throw std::runtime_error("ResourceManager::load - Key already exists " + key);
    }

    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filePath))
    {
        throw std::runtime_error("ResourceManager::load - Failed to load " + filePath);
    }

    auto inserted = m_data.insert(std::make_pair(key, std::move(resource)));
    assert(inserted.second);
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::release(const Identifier &key)
{
    auto found = m_data.find(key);
    if (found == m_data.end())
    {
        throw std::runtime_error("ResourceManager::release - Key not found " + key);
    }

    m_data.erase(found);
}

template<typename Identifier, typename Resource>
Resource &ResourceManager<Identifier, Resource>::get(const Identifier &key)
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}

template<typename Identifier, typename Resource>
const Resource &ResourceManager<Identifier, Resource>::get(const Identifier &key) const
{
    auto resource = m_data.find(key);
    assert(resource != m_data.end());

    return *resource->second;
}