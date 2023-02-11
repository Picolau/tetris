#ifndef TETRIS_TETRIMINO_HPP
#define TETRIS_TETRIMINO_HPP

#include <color.hpp>
#include <array>
#include <pos.hpp>
#include <map>
#include <SDL2/SDL.h>

using namespace std;

enum Orientation
{
    N, // 0
    W, // 1
    S, // 2
    E // 3
};

enum TetriminoAction 
{
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_UP,
    ROTATE_LEFT,
    ROTATE_RIGHT,
};

class Tetrimino
{
public:
    Tetrimino();

    // Rotates tetrimino using rot, and rotationPoint (number from 1 to 5)
    void rotateAction(TetriminoAction rot, int rotationPoint);

    // Moves tetrimino using mov
    void moveAction(TetriminoAction mov);

    // Undoes last movement or rotation
    void undoPreviousAction();

    // Returns minos positions
    virtual array<Pos, 4> getMinos() = 0;

    Pos &pos();
    const Pos &pos() const;

    // Draw tetrimino using SDL_Renderer
    void draw(SDL_Renderer *renderer);

    char t_name;

protected:
    Pos m_pos;
    Pos prev_pos;

    Orientation m_orientation; // 0 for East, 1 for North, 2 for West, 3 for South
    Orientation prev_orientation;

    Color m_color;

    // Returns rotation map
    virtual map<Orientation, map<int, Pos>> getRotationMap() = 0;
};


class TetriminoI : public Tetrimino
{
public:
    TetriminoI();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoJ : public Tetrimino
{
public:
    TetriminoJ();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoL : public Tetrimino
{
public:
    TetriminoL();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoO : public Tetrimino
{
public:
    TetriminoO();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoS : public Tetrimino
{
public:
    TetriminoS();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoT : public Tetrimino
{
public:
    TetriminoT();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

class TetriminoZ : public Tetrimino
{
public:
    TetriminoZ();
    virtual array<Pos, 4> getMinos();
    virtual map<Orientation, map<int, Pos>> getRotationMap();
};

#endif