#include "astronomy.h"

int main() {
    // vector<Planet> planets;
    // vector<Star> stars;
    // vector<Galaxy> galaxies;

    // planets.push_back(Planet("Earth", 100, 10, 100, 20));
    // planets.push_back(Planet("Mars", 200, 20, 200, 30));
    // planets.push_back(Planet("Jupiter", 300, 30, 300, 40));

    // stars.push_back(Star("Sun", 1000, 100, 1000, 200, "Not exist"));
    // stars.push_back(Star("Alpha Centauri", 2000, 200, 2000, 300, "Centauri"));
    // stars.push_back(Star("Betelgeuse", 3000, 300, 3000, 400, "Orion"));

    // galaxies.push_back(Galaxy("Milky Way", 10000, 100, 100, 10));
    // galaxies.push_back(Galaxy("Andromeda", 20000, 200, 200, 20));
    // galaxies.push_back(Galaxy("Triangulum", 30000, 300, 300, 30));

    // Directory directory("Astronomer's directory", 3, 3, 3);
    // cout << "Directory information" << endl;
    // directory.print();

    // directory.print_constellations(stars);

    // directory.print_objects(planets, stars, galaxies, 500);

    // directory.search_objects(planets, stars, galaxies, "Mars");

    // directory.edit_objects(planets, stars, galaxies, "Mars", 500, 50, 500, 50);
    
    // directory.delete_objects(planets, stars, galaxies, "Mars");

    // directory.print_all_objects(planets, stars, galaxies);


        // Створення прикладів планет, зірок та галактик для тестування
    Planet earth("Earth", 0.0, 6371, 5.97e24, 288);
    Planet mars("Mars", 225.0e6, 3389, 0.642e24, 210);
    Star sun("Sun", 0.0, 696340, 1.989e30, 5778, "Milky Way");
    Star sirius("Sirius", 8.6, 1189640, 4.017e30, 9940, "Canis Major");
    Galaxy milkyWay("Milky Way", 0.0, 100000, 214748647, 10000);
    Galaxy andromeda("Andromeda", 2.537e6, 220000, 2147483647, 10000);

    vector<Planet> planets = { earth, mars };
    vector<Star> stars = { sun, sirius };
    vector<Galaxy> galaxies = { milkyWay, andromeda };

    Directory directory("Astronomy Directory", planets.size(), stars.size(), galaxies.size());

    int choice;
    do {
        directory.print_interface();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                directory.print();
                break;
            case 2:
                directory.print_constellations(stars);
                break;
            case 3: {
                double distance;
                cout << "Enter distance: ";
                cin >> distance;
                directory.print_objects(planets, stars, galaxies, distance);
                break;
            }
            case 4: {
                string name;
                cout << "Enter object name: ";
                cin >> name;
                directory.search_objects(planets, stars, galaxies, name);
                break;
            }
            case 5: {
                string name;
                double distance_to_star, radius, mass, temperature;
                cout << "Enter object name to edit: ";
                cin >> name;
                cout << "Enter new distance to star: ";
                cin >> distance_to_star;
                cout << "Enter new radius: ";
                cin >> radius;
                cout << "Enter new mass: ";
                cin >> mass;
                cout << "Enter new temperature: ";
                cin >> temperature;
                directory.edit_objects(planets, stars, galaxies, name, distance_to_star, radius, mass, temperature);
                break;
            }
            case 6: {
                string name;
                cout << "Enter object name to delete: ";
                cin >> name;
                directory.delete_objects(planets, stars, galaxies, name);
                break;
            }
            case 7:
                directory.print_all_objects(planets, stars, galaxies);
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;    

    return 0;
}
