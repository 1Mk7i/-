#ifndef ASTRONOMY_H
#define ASTRONOMY_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

string blue = "\033[1;34m";
string yellow = "\033[1;33m";
string green = "\033[1;32m";
string red = "\033[1;31m";
string reset = "\033[0m";

class Planet {
private:
    string name;
    double distance_to_star;
    double radius;
    double mass;
    double temperature;
public:
    Planet(string name, double distance_to_star, double radius, double mass, double temperature) {
        this->name = name;
        this->distance_to_star = distance_to_star;
        this->radius = radius;
        this->mass = mass;
        this->temperature = temperature;
    }

    double get_distance_to_star() const { return distance_to_star; }
    void set_distance_to_star(double distance_to_star) { this->distance_to_star = distance_to_star; }
    string get_name() const { return name; }

    void print() const {
        cout << "---------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Distance to star: " << distance_to_star << endl;
        cout << "Radius: " << radius << endl;
        cout << "Mass: " << mass << endl;
        cout << "Temperature: " << temperature << endl;
        cout << "---------------------------------------------\n";
    }
};

class Star {
private:
    string name;
    double distance_to_earth;
    double radius;
    double mass;
    double temperature;
    string constellation;
public:
    Star(string name, double distance_to_earth, double radius, double mass, double temperature, string constellation) {
        this->name = name;
        this->distance_to_earth = distance_to_earth;
        this->radius = radius;
        this->mass = mass;
        this->temperature = temperature;
        this->constellation = constellation;
    }

    string get_constellation() const { return constellation; }
    void set_constellation(string constellation) { this->constellation = constellation; }
    void set_distance_to_earth(double distance_to_earth) { this->distance_to_earth = distance_to_earth; }
    double get_distance_to_earth() const { return distance_to_earth; }
    string get_name() const { return name; }

    void print() const {
        cout << "---------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Distance to earth: " << distance_to_earth << endl;
        cout << "Radius: " << radius << endl;
        cout << "Mass: " << mass << endl;
        cout << "Temperature: " << temperature << endl;
        cout << "Constellation: " << constellation << endl;
        cout << "---------------------------------------------\n";
    }
};

class Galaxy {
private:
    string name;
    double distance_to_earth;
    int number_of_stars;
    int number_of_planets;
    int number_of_constellations;
public:
    Galaxy(string name, double distance_to_earth, int number_of_stars, int number_of_planets, int number_of_constellations) {
        this->name = name;
        this->distance_to_earth = distance_to_earth;
        this->number_of_stars = number_of_stars;
        this->number_of_planets = number_of_planets;
        this->number_of_constellations = number_of_constellations;
    }

    double get_distance_to_earth() const { return distance_to_earth; }
    void set_distance_to_earth(double distance_to_earth) { this->distance_to_earth = distance_to_earth; }
    string get_name() const { return name; }

    void print() const {
        cout << "---------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Distance to earth: " << distance_to_earth << endl;
        cout << "Number of stars: " << number_of_stars << endl;
        cout << "Number of planets: " << number_of_planets << endl;
        cout << "Number of constellations: " << number_of_constellations << endl;
        cout << "---------------------------------------------\n";
    }
};

class Directory {
private:
    string name;
    int number_of_planets;
    int number_of_stars;
    int number_of_galaxies;
public:
    Directory(string name, int number_of_planets, int number_of_stars, int number_of_galaxies) {
        this->name = name;
        this->number_of_planets = number_of_planets;
        this->number_of_stars = number_of_stars;
        this->number_of_galaxies = number_of_galaxies;
    }

    void print() const {
        cout << "---------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Number of planets: " << number_of_planets << endl;
        cout << "Number of stars: " << number_of_stars << endl;
        cout << "Number of galaxies: " << number_of_galaxies << endl;
        cout << "---------------------------------------------\n";
    }

    void print_constellations(const vector<Star>& stars) const {
        vector<string> constellations;
        for (const auto& star : stars) {
            constellations.push_back(star.get_constellation());
        }
        sort(constellations.begin(), constellations.end());
        constellations.erase(unique(constellations.begin(), constellations.end()), constellations.end());
        cout << "Number of constellations: " << constellations.size() << endl;
        cout << "Constellations: ";
        for (const auto& constellation : constellations) {
            cout << constellation << " ";
        }
        cout << endl;
    }
    void print_objects(const vector<Planet>& planets, const vector<Star>& stars, const vector<Galaxy>& galaxies, double distance) const {
        cout << "Objects on distance less than " << distance << endl;
        for (const auto& planet : planets) {
            if (planet.get_distance_to_star() < distance) {
                planet.print();
            }
        }
        for (const auto& star : stars) {
            if (star.get_distance_to_earth() < distance) {
                star.print();
            }
        }
        for (const auto& galaxy : galaxies) {
            if (galaxy.get_distance_to_earth() < distance) {
                galaxy.print();
            }
        }
    }
    // Метод для пошуку об'єктів за якимось критерієм
    void search_objects(const vector<Planet>& planets, const vector<Star>& stars, const vector<Galaxy>& galaxies, string name) const {
        cout << "Objects with name " << name << endl;
        for (const auto& planet : planets) {
            if (planet.get_name() == name) {
                planet.print();
            }
        }
        for (const auto& star : stars) {
            if (star.get_name() == name) {
                star.print();
            }
        }
        for (const auto& galaxy : galaxies) {
            if (galaxy.get_name() == name) {
                galaxy.print();
            }
        }
    }
    // Метод для редагування об'єктів
    void edit_objects(vector<Planet>& planets, vector<Star>& stars, vector<Galaxy>& galaxies, string name, double distance_to_star, double radius, double mass, double temperature) {
        cout << "Objects with name " << name << " after editing" << endl;
        for (auto& planet : planets) {
            if (planet.get_name() == name) {
                planet.set_distance_to_star(distance_to_star);
                planet.print();
            }
        }
        for (auto& star : stars) {
            if (star.get_name() == name) {
                star.set_distance_to_earth(distance_to_star);
                star.print();
            }
        }
        for (auto& galaxy : galaxies) {
            if (galaxy.get_name() == name) {
                galaxy.set_distance_to_earth(distance_to_star);
                galaxy.print();
            }
        }
    }
    // Метод для видалення об'єктів
    void delete_objects(vector<Planet>& planets, vector<Star>& stars, vector<Galaxy>& galaxies, string name) {
        cout << red << "Objects with name " << reset << name << red << " after deleting" << reset << endl;
        for (auto it = planets.begin(); it != planets.end(); ++it) {
            if (it->get_name() == name) {
                it = planets.erase(it);
                break;
            }
        }
        for (auto it = stars.begin(); it != stars.end(); ++it) {
            if (it->get_name() == name) {
                it = stars.erase(it);
                break;
            }
        }
        for (auto it = galaxies.begin(); it != galaxies.end(); ++it) {
            if (it->get_name() == name) {
                it = galaxies.erase(it);
                break;
            }
        }
    }
    // Вивід всіх об'єктів таблично (Тип об'єкту, назва, відстань до Землі)
    void print_all_objects(const vector<Planet>& planets, const vector<Star>& stars, const vector<Galaxy>& galaxies) const {
        cout << green << "---------------------------------------------\n";
        cout << "\t\tPlanets:\n" << reset;
        int max_planet_name_length = 0;
        for (const auto& planet : planets) {
            int name_length = planet.get_name().length();
            max_planet_name_length = max(max_planet_name_length, name_length);
        }
        for (const auto& planet : planets) {
            cout << blue << "Name: " << yellow << setw(max_planet_name_length) << left << planet.get_name() << blue << "  Distance to star: " << yellow << planet.get_distance_to_star() << reset << endl;
        }
        cout << green << "---------------------------------------------\n";
        cout << "\t\tStars:\n" << reset;
        int max_star_name_length = 0;
        for (const auto& star : stars) {
            int name_length = star.get_name().length();
            max_star_name_length = max(max_star_name_length, name_length);
        }
        for (const auto& star : stars) {
            cout << blue << "Name: " << yellow << setw(max_star_name_length) << left << star.get_name() << blue << "  Distance to earth: " << yellow << star.get_distance_to_earth() << reset << endl;
        }
        cout << green << "---------------------------------------------\n";
        cout << "\t\tGalaxies:\n" << reset;
        int max_galaxy_name_length = 0;
        for (const auto& galaxy : galaxies) {
            int name_length = galaxy.get_name().length();
            max_galaxy_name_length = max(max_galaxy_name_length, name_length);
        }
        for (const auto& galaxy : galaxies) {
            cout << blue << "Name: " << yellow << setw(max_galaxy_name_length) << left << galaxy.get_name() << blue << "  Distance to earth: " << yellow << galaxy.get_distance_to_earth() << reset << endl;
        }
        cout << green << "---------------------------------------------\n" << reset;
    }
    
    void print_interface() const {
        cout << "1. Print directory information\n";
        cout << "2. Print constellations\n";
        cout << "3. Print objects on distance less than\n";
        cout << "4. Search objects\n";
        cout << "5. Edit objects\n";
        cout << "6. Delete objects\n";
        cout << "7. Print all objects\n";
        cout << "8. Exit\n";
    }
};

#endif