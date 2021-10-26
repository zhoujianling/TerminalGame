#pragma once
#include <string>
#include <map>

namespace core {

class Appearance {
public:

private:
    std::string m_id;
};

class AppearanceManager {
public:
    void CreateAppearance();
    Appearance* GetAppearanceById(std::string id);

private:
    std::map<std::string, Appearance> m_appearance_map; 

};

}