#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager
{
public:
    // Konstruktor domy�lny
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj�cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz�cy
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz�cy
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Metoda dost�pu
    double get() const { return resource->get(); }

private:
    std::unique_ptr< Resource > resource;
};
