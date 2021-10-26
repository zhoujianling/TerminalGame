#pragma once
#include <unordered_set>

namespace core {

enum class Key {
    
    A = 97, B, C, D, E, F, G, H, I, J, K, L, M, N,
    O, P, Q, R, S, T, U, V, W, X, Y, Z = 122,
    // a = 97, b, c, d, e, f, g, h, i, j, k, l, m, n,
    // o, p, q, r, s, t, u, v, w, x, y, z = 122,
    Up = 125, Down, Right, Left,
};

class KeyboardInput {
    friend class GameCore;

public:
    bool IsKeyDown(Key ch) const;

private:
    void CollectInput();

private:
    std::unordered_set<Key> m_pressed_keys;       
};

}