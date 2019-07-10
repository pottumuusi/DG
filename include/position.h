#ifndef POSITION_H_DEFINED
#define POSITION_H_DEFINED

class Position {
public:
    Position() = delete;
    ~Position();

    Position(const int _x, const int _y);

    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif // POSITION_H_DEFINED
