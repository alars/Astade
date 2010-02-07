double sinValue = sin(alpha);
double cosValue = cos(alpha);

return glVector((m_x * cosValue) - (m_y * sinValue),
				(m_y * cosValue) + (m_x * sinValue));