#include "levelSys.hpp"
#include <fstream>
#include <sstream>
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;


void Levels::loadLevel(int levelNo){
    if (levels[levelNo-1].empty()){
        std::ifstream file("levels/level"+ std::to_string(levelNo) +".json");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string jsonText = buffer.str();

        json data = json::parse(jsonText);

        for (auto& o : data["obstacles"]){
            spawnData s;

            s.spawnTime = o["spawnTime"];
            s.y = o["y"];
            s.vx = o["vx"];

            auto c = o["color"];
            s.color = sf::Color(c[0], c[1], c[2]);

            for (auto& step : o["pattern"])
            {
                PatternStep p;

                p.triggerTime = step["time"];
                p.value = step["value"];

                std::string type = step["action"];

                if (type == "SetVx") p.actionType = ActionType::SetVx;
                if (type == "SetVy") p.actionType = ActionType::SetVy;

                s.Pattern.push_back(p);
            }

            levels[levelNo-1].push_back(s);
        }

        // levels[levelNo] = {
        //     {1, 600, -400.00f, sf::Color(0, 45, 65), {{ActionType::SetVx, 2.0f, -1000.0f}, {ActionType::SetVy, 2.0f, -500.0f}}},
            
        //     {2, 200, -600.00f, sf::Color::Blue, {}},
        //     {1.5, 400, -300.00f, sf::Color::Red, {}},
        //     {3, 500, -800.00f, sf::Color::Black, {}},
        //     {5, 750, -500.00f, sf::Color(20, 100, 200), {}}
        // }; 
    }
}