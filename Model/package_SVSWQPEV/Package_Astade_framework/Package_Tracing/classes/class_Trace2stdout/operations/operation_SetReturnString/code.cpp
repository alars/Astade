delete [] m_returnString;
m_returnString = new char[strlen(text)+1];
strcpy(m_returnString, text);
