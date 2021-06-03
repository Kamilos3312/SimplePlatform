template<typename Identifier, typename Resource>
ResourceManager<Identifier, Resource>::ResourceManager()
        : m_data()
{
}

template<typename Identifier, typename Resource>
ResourceManager<Identifier, Resource>::~ResourceManager()
{
    m_data.clear();
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::load(Identifier key, const std::string &filePath)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filePath))
    {
        throw std::runtime_error("ResourceManager::load - Failed to load " + filePath);
    }

    auto inserted = m_data.insert(std::make_pair(key, std::move(resource)));
    assert(inserted.second);
}

template<typename Identifier, typename Resource>
void ResourceManager<Identifier, Resource>::load(Identifier key, const Resource &resource)
{
    std::unique_ptr<Resource> res = std::make_unique<Resource>(resource);
    auto inserted = m_data.insert(std::make_pair(key, std::move(res)));
    assert(inserted.second);
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