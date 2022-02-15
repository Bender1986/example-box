#ifndef RAM_H
#define RAM_H

class Ram { 

    private:

    const int m_max = 8;

    int *m_buf;

    int m_ptr;

    public: 

    Ram(); 

    ~ Ram();

    /* reset memory */
    void clear();


    /* write memory */
    bool write(const int &value);

     /* write memory */
    int &write();


    /* read memory */
    bool read(int buf[]) const;

};

#endif
