#include "Player.hpp"

const std::unordered_map<uint8_t, std::vector<event::Event>> Player::sKeyboardMapping{
    { { 1,
        { event::Event{ event::EventType::kKeyboardKeyPressed, event::KeyCodes::W },
          event::Event{ event::EventType::kKeyboardKeyReleased, event::KeyCodes::W },
          event::Event{ event::EventType::kKeyboardKeyPressed, event::KeyCodes::S },
          event::Event{ event::EventType::kKeyboardKeyReleased, event::KeyCodes::S } } },
      { 2,
        { event::Event{ event::EventType::kKeyboardKeyPressed, event::KeyCodes::W },
          event::Event{ event::EventType::kKeyboardKeyReleased, event::KeyCodes::W },
          event::Event{ event::EventType::kKeyboardKeyPressed, event::KeyCodes::S },
          event::Event{ event::EventType::kKeyboardKeyReleased, event::KeyCodes::S } } } }
};

Player::Player(std::string const& playerName, uint8_t const playerNumber)  //
    : event::KeyboardListener{ sKeyboardMapping.at(playerNumber) }
    , mPlayerName{ playerName }
    , mPlayerNumber{ playerNumber }
{
}

void Player::onKeyPressed(event::KeyCodes const eventKeyCode)
{
    std::cout << "GOT KEY PRESSED " << std::endl;
}

void Player::onKeyReleased(event::KeyCodes const eventKeyCode)
{
    std::cout << "GOT KEY RELEASE" << std::endl;
}

void Player::onCleanup()
{
}