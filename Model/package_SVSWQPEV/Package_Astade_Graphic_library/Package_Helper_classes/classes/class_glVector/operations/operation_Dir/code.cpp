double mod = Mod();
if (mod != 0)
  return glVector(m_x/mod, m_y/mod);
else
  return glVector();
