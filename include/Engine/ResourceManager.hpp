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
    void load(Identifier key, const std::string &filePath, bool override = false);
    void load(Identifier key, const Resource &resource, bool override = false);

    Resource &get(Identifier key);
    const Resource &get(Identifier key) const;

    Resource &operator[](Identifier key);
    const Resource &operator[](Identifier key) const;

    void release(Identifier key);

private:
    void loadFile(Identifier key, const std::string &filePath);
    void loadResource(Identifier key, const Resource &resource);

private:
    std::map<Identifier, std::unique_ptr<Resource>> m_data;
};

#include "ResourceManager.inl"