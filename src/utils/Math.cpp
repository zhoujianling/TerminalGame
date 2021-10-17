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
                result.m_val[3 * row + 0] * rhs.m_val[3 * 0 + col] + 
                result.m_val[3 * row + 1] * rhs.m_val[3 * 1 + col] + 
                result.m_val[3 * row + 2] * rhs.m_val[3 * 2 + col] ;
        }
    }
    return result;
}