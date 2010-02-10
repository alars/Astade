glVector ret(aVector);
double ModSqr = (aVector.m_x * aVector.m_x) + (aVector.m_y * aVector.m_y);
ret *= ScalarProduct(aVector);
ret /= ModSqr;
return ret;
