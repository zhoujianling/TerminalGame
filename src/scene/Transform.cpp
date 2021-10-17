#include "Transform.h"
#include <memory>
#include <exception>

namespace scene {

    Transform::Transform() {
        // std::memset(& m_matrix, 0, sizeof(m_matrix));
        m_matrix.SetIdentity();
    }

    void Transform::Translate(const Vector2& translation) {
        m_matrix.m_val[3 * 0 + 2] += translation.m_x;
        m_matrix.m_val[3 * 1 + 2] += translation.m_y;
    }

    void Transform::Scale(const Vector2& scaling) {
        throw new std::bad_exception();
    }

    void Transform::Rotate(float delta_radian) {
        throw new std::bad_exception();
    }

    Vector2 Transform::GetTranslation() const {
        return { m_matrix.m_val[3 * 0 + 2], m_matrix.m_val[3 * 1 + 2]};
    }

    // Vector2 Transform::GetScaling() const {
    //     throw new std::bad_exception();
    // }

    // float Transform::GetRotation() const {
    // }

}