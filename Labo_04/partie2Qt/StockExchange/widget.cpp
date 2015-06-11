#include "widget.h"
#include "bourse.h"
#include "graph.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    Bourse* bourse = new Bourse("../data/terre_rare/cours_terres_rares.csv","../data/terre_rare/inflation.csv");
    Graph graph(bourse);
}

Widget::~Widget()
{

}
