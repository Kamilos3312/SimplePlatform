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
    void load(const Identifier &key, const std::string &filePath);
    void release(const Identifier &key);

    Resource &get(const Identifier &key);
    const Resource &get(const Identifier &key) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> m_data;
};

#include "ResourceManager.inl"