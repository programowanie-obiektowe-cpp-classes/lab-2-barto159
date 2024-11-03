#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:
    
    ResourceManager() : resource(new Resource())
    {
        
    }

   
    ResourceManager(const ResourceManager& other) : resource(new Resource(*other.resource))
    {
        
    }

   
    ResourceManager& operator=(const ResourceManager& other)
    {
        
        if (this != &other) {
            delete resource;                          
            resource = new Resource(*other.resource); 
        }
        return *this;
    }

    

   
    ~ResourceManager()
    {
        
        delete resource;
    }

    
    double get() const { return resource->get(); }

private:
    Resource* resource; 
};
