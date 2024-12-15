#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager
{
public:
    // Konstruktor domyœlny
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj¹cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz¹cy
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz¹cy
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Metoda dostêpu
    double get() const { return resource->get(); }

private:
    std::unique_ptr< Resource > resource;
};
