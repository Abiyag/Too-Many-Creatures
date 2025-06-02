#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
public:
    // Category and School enums
    enum class Category { MAGICAL, UNDEAD, ANIMAL, HUMANOID, UNKNOWN };
    enum class School { FIRE, ICE, STORM, LIFE, MYTH, DEATH, UNKNOWN };

    // Constructors
    Creature(); // Default constructor
    Creature(const std::string& name, 
             Category category = Category::UNKNOWN, 
             School school = School::UNKNOWN, 
             int health = 1, 
             int level = 1, 
             bool isHostile = false);

    // Setters
    bool setName(const std::string& name);
    void setCategory(const Category& category);
    void setSchool(const School& school);
    bool setHealth(const int& health);
    bool setLevel(const int& level);
    void setHostility(const bool& isHostile);

    // Getters
    std::string getName() const;
    std::string getCategory() const;
    std::string getSchool() const;
    int getHealth() const;
    int getLevel() const;
    bool isHostile() const;

    // Display function
    void display() const;

private:
    std::string name_;
    Category category_;
    School school_;
    int health_;
    int level_;
    bool isHostile_;
};

#endif // CREATURE_H
