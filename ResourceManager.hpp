#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager
{
public:
    // Konstruktor domyślny
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Metoda dostępu
    double get() const { return resource->get(); }

private:
    std::unique_ptr< Resource > resource;
};
