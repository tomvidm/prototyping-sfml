#pragma once

#include <map>
#include <memory>

namespace resources
{
    

    template <class ResourceType>
    class ResourceHandler
    {
    public:
        ResourceHandler();

        typedef std::map<std::string, std::shared_ptr<ResourceType>> ResourceMap;

        virtual bool loadResourceFromFile(std::string resourceFileName) = 0;
                
        virtual ResourceType fetchResource(std::string resourceName);
        virtual void unloadResource(std::string resourceName);
    private:
        ResourceMap resourceMap;
    };

    template <class ResourceType>
    ResourceHandler<ResourceType>::ResourceHandler()
    {
        ;
    }

    template <class ResourceType>
    ResourceType ResourceHandler<ResourceType>::fetchResource(std::string resourceName)
    {
        return resourceMap[resourceName];
    }

    template <class ResourceType>
    void ResourceHandler<ResourceType>::unloadResource(std::string resourceName)
    {
        // Remove resource from resource map.
        ;
    }
}

