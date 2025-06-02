/**
 * @file Creature.cpp
 * @author Abiyag
 * @brief Implementation of the Creature class.
 */

#include "Creature.h"
#include <iostream>
#include <cctype> // for std::toupper

// Default constructor
Creature::Creature() {
    // TODO: Default-initialize all members
    name_ = "NAMELESS";
    category_ = Category::UNKNOWN;
    school_ = School::UNKNOWN;
    health_ = 1;
    level_ = 1;
    isHostile_ = false;

}

// Parameterized constructor
Creature::Creature(const std::string& name, Category category, School school, int health, int level, bool isHostile) {
    // TODO: Initialize members using parameters with validations/defaults
    name_ = name;
    category_ = category;
    school_ = school;
    health_ = health;
    level_ = level;
    isHostile_ = isHostile;
}

/**
 * @param name The name of the creature
 * @post Sets the name to uppercase if it's alphabetic only
 * @return true if name was set, false otherwise
 */
bool Creature::setName(const std::string& name) {
    // Check if the name is alphabetic and not empty
    if (name.empty()) {
        return false; // Invalid name
    }

    for(const char& c : name) {
        if (!std::isalpha(c)) {
            return false; // Name contains non-alphabetic characters
        }
    }

    // Set the name to uppercase
    name_ = name;
    for (char& c : name_) {
        c = std::toupper(c);
    }
    
    return true; 
}

/**
 * @param category The category to assign to the creature
 * @post Sets the category of the creature
 */
void Creature::setCategory(const Category& category) {
    category_ = category;
}

/**
 * @param school The school to assign to the creature
 * @post Sets the school of the creature
 */
void Creature::setSchool(const School& school) {
    school_ = school;
}

/**
 * @param health The health to assign
 * @pre Must be > 0
 * @post Sets the creature’s health
 * @return true if health was set, false otherwise
 */
bool Creature::setHealth(const int& health) {
    if(health_ > 0) {
        health_ = health;
        return true; 
    }

    return false;
}

/**
 * @param level The level to assign
 * @pre Must be > 0
 * @post Sets the creature’s level
 * @return true if level was set, false otherwise
 */
bool Creature::setLevel(const int& level) {
    if(level_ > 0){
        level_ = level;
        return true;
    }
    return false;
}

/**
 * @param isHostile Whether or not the creature is hostile
 * @post Sets the creature’s hostility
 */
void Creature::setHostility(const bool& isHostile) {
    // TODO
    isHostile_ = isHostile;
}
/**
 * @return The creature's name
 */
std::string Creature::getName() const {

    return name_;
}

/**
 * @return The creature's category as a string
 */
std::string Creature::getCategory() const {
    //convert category_ to string

    switch (category_) {
        case Category::MAGICAL: return "MAGICAL";
        case Category::UNDEAD: return "UNDEAD";
        case Category::ANIMAL: return "ANIMAL";
        case Category::HUMANOID: return "HUMANOID";
        default: return "UNKNOWN";
    }
}

/**
 * @return The creature's school as a string
 */
std::string Creature::getSchool() const {
    //convert school_ to string
    switch (school_) {
        case School::FIRE: return "FIRE";
        case School::ICE: return "ICE";
        case School::STORM: return "STORM";
        case School::LIFE: return "LIFE";
        case School::MYTH: return "MYTH";
        case School::DEATH: return "DEATH";
        default: return "UNKNOWN";
    }
}

/**
 * @return The creature's health
 */
int Creature::getHealth() const {
    return health_;
}

/**
 * @return The creature's level
 */
int Creature::getLevel() const {
    return level_;
}

/**
 * @return true if the creature is hostile, false otherwise
 */
bool Creature::isHostile() const {
    if  (isHostile_) {
        return true;
    }
    return false;
}

/**
 * @post Displays the creature’s attributes in the specified format:
 * [NAME]
 * Category: [CATEGORY]
 * School: [SCHOOL]
 * Health: [HEALTH]
 * Level: [LEVEL]
 * Hostile: [TRUE/FALSE]
 */
void Creature::display() const {
    std::cout << "[" << name_ << "]" << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "School: " << getSchool() << std::endl;
    std::cout << "Health: " << health_ << std::endl;
    std::cout << "Level: " << level_ << std::endl;
    std::cout << "Hostile: " << (isHostile_ ? "TRUE" : "FALSE") << std::endl;
}
