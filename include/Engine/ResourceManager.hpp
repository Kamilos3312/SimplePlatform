#pragma once

#include <cassert>
#include <exception>
#include <map>
#include <memory>
#include <string>

template<typename Identifier, typename Resource>
class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    void load(Identifier key, const std::string &filePath);
    void load(Identifier key, const Resource &resource);

    Resource &get(Identifier key);
    const Resource &get(Identifier key) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> m_data;
};

#include "ResourceManager.inl"