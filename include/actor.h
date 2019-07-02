#ifndef ACTOR_H_DEFINED
#define ACTOR_H_DEFINED

#include <string>

class Actor {
public:
    Actor();
    ~Actor();
    Actor(std::string);

    std::string getName() const;

private:
    std::string name;
};

#endif // ACTOR_H_DEFINED
