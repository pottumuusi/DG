#ifndef POSITION_H_DEFINED
#define POSITION_H_DEFINED

class Position {
public:
    Position();
    ~Position();

    Position(int _x, int _y);

private:
    const int x;
    const int y;
};

#endif // POSITION_H_DEFINED
