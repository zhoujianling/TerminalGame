#pragma once

struct Vector2 {
public:
    Vector2(float x, float y) : m_x(x), m_y(y) 
    {}

public:
    float m_x;

    float m_y;

};

struct Vector3 {
public:
    Vector3(float x, float y, float z) : 
        m_x(x), 
        m_y(y),
        m_z(z)
    {}

public:
    float m_x;

    float m_y;

    float m_z;

};

struct Matrix2 {

public:
    float m_val[4];
};

struct Matrix3 {
public:
    void SetIdentity();

    Matrix3 operator* (const Matrix3& rhs) const;

public:
    float m_val[9];
};

struct BoundingBox {

    Vector2 m_center;

    Vector2 m_extent;

};
