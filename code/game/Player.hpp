#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <unordered_map>
#include <vector>

#include <display/interface/IGameObject.hpp>
#include <io/KeyboardListener.hpp>

class Player : public event::KeyboardListener
{
    static const std::unordered_map<uint8_t, std::vector<event::Event>> sKeyboardMapping;

public:
    Player(std::string const& playerName, uint8_t const playerNumber);

protected:
    void onKeyPressed(event::KeyCodes const eventKeyCode) override;
    void onKeyReleased(event::KeyCodes const eventKeyCode) override;
    void onCleanup() override;

private:
    std::string mPlayerName;
    uint8_t     mPlayerNumber;
};

#endif  // !PLAYER_HPP
