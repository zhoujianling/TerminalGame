#pragma once

#include "../utils/Math.h"

namespace scene {

struct Transform {

public:
    Transform();

    void Translate(const Vector2& translation);

    void Scale(const Vector2& scaling);

    void Rotate(float delta_radian);

    Vector2 GetTranslation() const;

    Vector2 GetScaling() const;

    float GetRotation() const;

    Matrix3 m_matrix;
};

}