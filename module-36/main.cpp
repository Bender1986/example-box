#include <iostream>


#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QDesktopWidget>
#include <qt5/QtWidgets/QSlider>
#include <qt5/QtWidgets/QBoxLayout>
#include <qt5/QtGui/QPainter>

class CircleQWidget: public QWidget
{
    Q_OBJECT

    public: 

    CircleQWidget() = default;

    explicit CircleQWidget(QWidget *parent)
    {
        m_color = Qt::green;
    }

    void SetColor(Qt::GlobalColor color)
    {
        m_color = color;
    }
   

    private:

    Qt::GlobalColor m_color;
    
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);

        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

        painter.setBrush(QBrush(m_color, Qt::SolidPattern));

        painter.drawEllipse(100, 50, 150, 150);
    }
};





int main(int argc, char** argv){
    
    
    QApplication app(argc, argv);

    auto window = new QMainWindow();
    window->resize(350, 350);
    int width = window->frameGeometry().width();
    int height = window->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    window->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
    
    QWidget* parent = new QWidget(window);
    QVBoxLayout* verLayout = new QVBoxLayout(parent);

    window->setCentralWidget(parent);
    parent->setLayout(verLayout);


    CircleQWidget circle(parent);
    QSlider slider(Qt::Horizontal, parent);

    slider.setMinimum(0);
    slider.setMaximum(100);
    slider.resize(100, 10);


    verLayout->addWidget(&circle);
    verLayout->addWidget(&slider);

    QObject::connect(&slider, &QSlider::valueChanged, [&slider, &circle]()
    {
        int val = slider.value();
        
        if (val < 33)
        {   
            circle.SetColor(Qt::green);
            circle.update();
        }
        if (val > 33 & val < 66)
        {   
            circle.SetColor(Qt::yellow);
            circle.update();
        }
        if (val > 66)
        {   
            circle.SetColor(Qt::red);
            circle.update();
        }
    });  


    window->show();        
    
    return app.exec();
}

#include "main.moc"