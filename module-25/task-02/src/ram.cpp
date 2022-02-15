#include "ram.h"

/* allocate memory */
Ram::Ram() {

    m_buf = new int[m_max];

    m_ptr = -1;

    for (int i = 0; i < m_max; i++)
         m_buf[i] = 0;  
};

/* deallocate memory */
Ram::~Ram() {

    delete[] m_buf;
}

/* reset memory */
void Ram::clear() {
    m_ptr = -1;
}

/* write to memory */
bool Ram::write(const int &value) {
    if (m_ptr == 7) {
        m_ptr = -1;
    }

    m_buf[++m_ptr] = value;

    return true;
}

int &Ram::write()
{
    if (m_ptr == 7) {
        m_ptr = -1;
    }

    return m_buf[++m_ptr];
}

/* read from memory */
bool Ram::read(int buf[]) const {

     for (int i = 0; i < m_max; i++)  {
        buf[i] = m_buf[i];
     }

    return true;
}
