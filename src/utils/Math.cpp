#include "Math.h"
#include <memory>


void Matrix3::SetIdentity() {
    std::memset(&m_val, 0, sizeof(m_val));
    m_val[3 * 0 + 0] = 1.0f;
    m_val[3 * 1 + 1] = 1.0f;
    m_val[3 * 2 + 2] = 1.0f;
}

Matrix3 Matrix3::operator* (const Matrix3& rhs) const {
    Matrix3 result;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            result.m_val[3 * row + col] = 
                m_val[3 * row + 0] * rhs.m_val[3 * 0 + col] + 
                m_val[3 * row + 1] * rhs.m_val[3 * 1 + col] + 
                m_val[3 * row + 2] * rhs.m_val[3 * 2 + col] ;
        }
    }
    return result;
}

Vector3 Matrix3::operator* (const Vector3& rhs) const {
    const float x = m_val[3 * 0 + 0] * rhs.m_x + m_val[3 * 0 + 1] * rhs.m_y + m_val[3 * 0 + 2] * rhs.m_z; 
    const float y = m_val[3 * 1 + 0] * rhs.m_x + m_val[3 * 1 + 1] * rhs.m_y + m_val[3 * 1 + 2] * rhs.m_z; 
    const float z = m_val[3 * 2 + 0] * rhs.m_x + m_val[3 * 2 + 1] * rhs.m_y + m_val[3 * 2 + 2] * rhs.m_z; 
    return { x, y, z };
}