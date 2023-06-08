#include <iostream>
#include <vector>
#include <string>

class Mountain {
private:
    std::string name;
    std::string country;
    int elevation;

public:
    Mountain(const std::string& name, const std::string& country, int elevation)
        : name(name), country(country), elevation(elevation) {}

    // Getters
    std::string getName() const {
        return name;
    }

    std::string getCountry() const {
        return country;
    }

    int getElevation() const {
        return elevation;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    void setCountry(const std::string& country) {
        this->country = country;
    }

    void setElevation(int elevation) {
        this->elevation = elevation;
    }

    double toMeters() const {
        return elevation / 3.2808;
    }
};

int minElevation(const std::vector<Mountain>& mountains) {
    if (mountains.empty()) {
        return 0; 
    }

    int min = mountains[0].getElevation();
    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() < min) {
            min = mountain.getElevation();
        }
    }

    return min;
}

int main() {
    std::vector<Mountain> mountains;

    mountains.emplace_back("Chimborazo", "Ecuador", 20549);
    mountains.emplace_back("Matterhorn", "Switzerland", 14692);
    mountains.emplace_back("Olympus", "Greece (Macedonia)", 9573);
    mountains.emplace_back("Everest", "Nepal", 29029);
    mountains.emplace_back("Mount Marcy - Adirondacks", "United States", 5344);
    mountains.emplace_back("Mount Mitchell - Blue Ridge", "United States", 6684);
    mountains.emplace_back("Zugspitze", "Switzerland", 9719);

    for (const Mountain& mountain : mountains) {
        std::cout << "Mountain: " << mountain.getName() << std::endl;
        std::cout << "Country: " << mountain.getCountry() << std::endl;
        std::cout << "Elevation (feet): " << mountain.getElevation() << std::endl;
        std::cout << "Elevation (meters): " << mountain.toMeters() << std::endl;
        std::cout << std::endl;
    }

    int minElev = minElevation(mountains);
    std::cout << "Minimum Elevation: " << minElev << " feet" << std::endl;

    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() == minElev) {
            std::cout << "Shortest Mountain: " << mountain.getName() << std::endl;
            break;
        }
    }

    return 0;
}
